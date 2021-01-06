#include "pkzipdata.h"

#include <bitset>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QString>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string.h>
#include <unordered_map>
#include <vector>

// The number of bits for each copy length range
static const int lengthBits[16] = {
  3, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7
};

// The decimal value of the bit representation of each copy length range
static const int lengthRepr[16] = {
  5, 3, 1, 6, 10, 2, 12, 20, 4, 24, 8, 48, 16, 32, 64, 0
};

// The decimal value for the base length for each copy length range
static const int lengthBaseValue[16] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 16, 24, 40, 72, 136, 264
};

// The number of additional bits for each copy length range (to get to 8)
static const int lengthFillBits[16] = {
  0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8
};

static const int baseRepr[16] = {
  5, 3, 4, 3, 5, 4, 3, 5, 4, 3, 2, 3, 2, 1, 1, 0
};

static const int offsetBits[64] = {
  2, 4, 4, 5, 5, 5, 5, 6,
  6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8
};

static const int offsetRepr[64] = {
  3,   13,   5,  25,   9,  17,   1,  62,
  30,  46,  14,  54,  22,  38,   6,  58,
  26,  42,  10,  50,  18,  34,  66,   2,
 124,  60,  92,  28, 108,  44,  76,  12,
 116,  52,  84,  20, 100,  36,  68,   4,
 120,  56,  88,  24, 104,  40,  72,   8,
 240, 112, 176,  48, 208,  80, 144,  16,
 224,  96, 160,  32, 192,  64, 128,   0
};

PkZipData::PkZipData()
{  
  buildLookupTables();
}

PkZipData::~PkZipData()
{
}

void PkZipData::buildLookupTables()
{
  for (int i = 0; i < 16; i++) {
    int bits = lengthBits[i];
    int value = lengthRepr[i];
    while (value < 256) {
      mLengthToIndex[value] = static_cast<uint8_t>(i);
      value += (1 << bits);
    }
  }

  for (int i = 0; i < 64; i++) {
    int bits = offsetBits[i];
    int value = offsetRepr[i];
    while (value < 256) {
      mOffsetToIndex[value] = static_cast<uint8_t>(i);
      value += (1 << bits);
    }
  }

  for (int i = 0; i < 16; i++) {
    int reprValue = baseRepr[i];
    int baseValue = lengthBaseValue[i];
    int fillBits = lengthFillBits[i];
    int bits = lengthBits[i];
    int numValues = std::pow(2, fillBits);

    for (int j = 0; j < numValues; j++) {
      int length = baseValue + j;
      QString sLength = QStringLiteral("%1").arg(reprValue, bits, 2, QChar('0'));
      if (fillBits > 0) {
        QString sFill = QStringLiteral("%1").arg(j, fillBits, 2, QChar('0'));
        std::reverse(sFill.begin(), sFill.end());
        sLength += sFill;
      }
      mLengthValues[length] = sLength.toUInt(nullptr, 2);
      mLengthBits[length] = bits + fillBits;
    }
  }
}

QByteArray PkZipData::compress(const QByteArray &byteArray, uint8_t literalEncoding, uint8_t windowSize)
{
  QByteArray compressedArray;
  compressedArray.append(literalEncoding);
  compressedArray.append(windowSize);

  int maxCopyLength = 516;
  int dictionarySize = std::pow(2, 6+windowSize) - 1;

  // Create the bit array
  // This algorithm does not represent an optimized compression
  // Only single bytes are used the dictionary, adding more
  // bits to the dictionary would improve the compression
  std::vector<bool> bits;
  std::unordered_map<uint8_t, int> dictionary;
  int32_t i = 0;
  while (i < byteArray.size()) {
    uint8_t byte = byteArray.at(i);
    bool writeLiteral = false;
    int32_t length = 0;
    int32_t offset = 0;
    std::unordered_map<uint8_t, int>::iterator itr = dictionary.find(byte);
    if (itr != dictionary.end()) {
      int32_t index = itr->second + 1;
      offset = i - index;
      if (offset >= dictionarySize) {
        writeLiteral = true;
      }
      else {
        length = 1;
        int32_t j = i+1;
        while (j < byteArray.size() && length < maxCopyLength) {
          uint8_t newByte = byteArray.at(j);
          uint8_t origByte = byteArray.at(index);
          if (newByte != origByte) {
            break;
          }
          j++;
          index++;
          length++;
        }
      }
    }

    if (length < 2) {
      writeLiteral = true;
    }

    if (length == 2 && offset >= 256) {
      writeLiteral = true;
    }

    if (writeLiteral) {
      writeLiteralByte(bits, byte);
      dictionary[byte] = i++;
    }
    else {
      writeCopyOffset(bits, offset, length, windowSize);
      i += length;
    }
  }

  // Write the end of stream marker and pad to a multiple of 8 bits
  writeBits(bits, 1, 8);
  writeBits(bits, 255, 8);
  while (bits.size() % 8)
    bits.push_back(0);

  // Write the compressed array
  writeCompressedArray(bits, compressedArray);

  return compressedArray;
}

QByteArray PkZipData::decompress(QByteArray &byteArray, bool debug)
{
  QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
  dataStream.setByteOrder(QDataStream::LittleEndian);

  // Read the header
  uint8_t literalEncoding = 0;
  uint8_t windowSize = 0;
  dataStream >> literalEncoding >> windowSize;

  int32_t bufferLength = byteArray.size()-2;
  uint8_t * dataBuffer = new uint8_t[bufferLength];
  int32_t dictionarySize = pow(2, windowSize) - 1;
  dataStream.readRawData((char*)dataBuffer, bufferLength);

  int32_t nextBufferPos = 1;
  int32_t bitsRemaining = 0;
  QByteArray output;
  uint16_t currentByteValue = static_cast<uint16_t>(dataBuffer[0]);
  while (true) {

    if (currentByteValue & 1) {
      // Length-Offset pair

      processBits(currentByteValue, 1, dataBuffer, nextBufferPos, bitsRemaining);
      int32_t lengthIndex = mLengthToIndex[currentByteValue & 0xff];
      int32_t numLengthBits = lengthBits[lengthIndex];
      int32_t numPadBits = lengthFillBits[lengthIndex];
      int32_t length = lengthBaseValue[lengthIndex];
      processBits(currentByteValue, numLengthBits, dataBuffer, nextBufferPos, bitsRemaining);
      if (numPadBits > 0) {
        int32_t padValue = currentByteValue & ((1 << numPadBits) - 1);

        // Check for the end of the data
        if (padValue == 0xff) {
          break;
        }
        processBits(currentByteValue, numPadBits, dataBuffer, nextBufferPos, bitsRemaining);
        length = lengthBaseValue[lengthIndex] + padValue;
      }

      uint8_t offsetIndex = mOffsetToIndex[currentByteValue & 0xff];
      int32_t numOffsetBits = offsetBits[offsetIndex];
      processBits(currentByteValue, numOffsetBits, dataBuffer, nextBufferPos, bitsRemaining);
      int32_t offset = 0;
      if (length == 2) {
        offset = (currentByteValue & 3) | (offsetIndex << 2);
        processBits(currentByteValue, 2, dataBuffer, nextBufferPos, bitsRemaining);
      }
      else {
        offset = (currentByteValue & dictionarySize) | (offsetIndex << windowSize);
        processBits(currentByteValue, windowSize, dataBuffer, nextBufferPos, bitsRemaining);
      }

      // Copy the data
      int32_t outputPos = output.size()-1-offset;
      for (int32_t i = 0; i < length; i++) {
        output.push_back(output[outputPos+i]);
      }
    }
    else {
      // Literal Byte
      processBits(currentByteValue, 1, dataBuffer, nextBufferPos, bitsRemaining);
      output += currentByteValue & 0xff;
      processBits(currentByteValue, 8, dataBuffer, nextBufferPos, bitsRemaining);
    }
  }

  // Delete the data buffer
  delete [] dataBuffer;

  return output;
}

void PkZipData::processBits(uint16_t &value, int32_t numBits, uint8_t * dataBuffer, int32_t & nextBufferPos, int32_t & bitsRemaining)
{
  if (bitsRemaining >= numBits) {
    bitsRemaining -= numBits;
    value >>= numBits;
    return;
  }

  value >>= bitsRemaining;
  value |= (dataBuffer[nextBufferPos++] << 8);
  value >>= (numBits - bitsRemaining);
  bitsRemaining += 8 - numBits;
}

void PkZipData::writeBits(std::vector<bool> & bits, int32_t value, int32_t numBits)
{
  for (int i = 0; i < numBits; i++) {
    bool bit = value & (1 << i);
    bits.push_back(bit);
  }
}

void PkZipData::writeCompressedArray(std::vector<bool> & bits, QByteArray & byteArray)
{
  int bitIndex = 7;
  int totalBytes = bits.size() / 8;
  for (int j = 0; j < totalBytes; j++) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
      int bit = bits.at(bitIndex-i);
      byte |= (bit << (7-i));
    }
    bitIndex += 8;
    byteArray.append(byte);
  }
}

void PkZipData::writeCopyOffset(std::vector<bool> & bits, int32_t offset, int32_t length, int32_t windowSize)
{
  // Add marker
  bits.push_back(1);

  // Create the length bits
  std::vector<bool> b;
  int numLengthBits = mLengthBits[length];
  int lengthRep = mLengthValues[length];
  for (int i = numLengthBits - 1; i >= 0; i--) {
    bool bit = lengthRep & (1 << i);
    bits.push_back(bit);
  }

  // Add the offset difference representation
  if (length == 2) {
    int offsetValue = offsetRepr[offset >> 2];
    int numBits = offsetBits[offset >> 2];
    int diff = offset & 3;
    writeBits(bits, offsetValue, numBits);
    writeBits(bits, diff, 2);
  }
  else {
    int offsetValue = offsetRepr[offset >> windowSize];
    int numBits = offsetBits[offset >> windowSize];
    int diff = offset & 0x3f;
    writeBits(bits, offsetValue, numBits);
    writeBits(bits, diff, windowSize);
  }
}

void PkZipData::writeLiteralByte(std::vector<bool> & bits, uint32_t byte)
{
  bits.push_back(0);
  writeBits(bits, byte, 8);
}

