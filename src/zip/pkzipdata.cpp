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

static const int offsetToRepr[64] = {
  3,  11, 10, 19, 18, 17, 16, 31,
  30, 29, 28, 27, 26, 25, 24, 23,
  22, 21, 20, 19, 18, 17, 33, 32,
  31, 30, 29, 28, 27, 26, 25, 24,
  23, 22, 21, 20, 19, 18, 17, 16,
  15, 14, 13, 12, 11, 10,  9,  8,
  15, 14, 13, 12, 11, 10,  9,  8,
   7,  6,  5,  4,  3,  2,  1,  0
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
  static const uint16_t lengthValues[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 32, 64, 128, 255};

  for (int i = 0; i < 16; i++) {
    int offsetValue = lengthBaseValue[i];
    int reprValue = lengthRepr[i];
    for (int j = 1; j <= lengthValues[i]; j++) {
      mLengthToRepr[offsetValue] = reprValue;
      mLengthBits[offsetValue] = lengthBits[i];
      mLengthPadBits[offsetValue] = lengthFillBits[i];
      offsetValue++;
      reprValue++;
    }
  }

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
}

QByteArray PkZipData::compress(const QByteArray &byteArray, uint8_t literalEncoding, uint8_t windowSize)
{
  // Create the bit array
  // For now we just print out all literal bytes
  std::vector<bool> bits;
  writeLiteralByte(bits, 65);
  writeLiteralByte(bits, 73);
  writeCopyOffset(bits, 1, 11);

  //for (int i = 0; i < byteArray.size(); i++) {
  //  uint8_t c = byteArray.at(i);
  //  writeLiteralByte(bits, c);
  //}

  // Write the end of stream marker and pad
  // to a multiple of 8 bits
  writeValue(bits, 1, 8);
  writeValue(bits, 255, 8);
  while (bits.size() % 8)
    bits.push_back(0);

  // Write the compressed array
  QByteArray compressedArray;
  compressedArray.append(literalEncoding);
  compressedArray.append(windowSize);
  writeCompressedArray(bits, compressedArray);

  return compressedArray;

//  QByteArray output;
//  QDataStream dataStream(&output, QIODevice::WriteOnly);
//  dataStream.setByteOrder(QDataStream::LittleEndian);

//  dataStream << literalEncoding << windowSize;

//  std::vector<uint8_t> decodedBytes;
//  QString bitString;
//  writeLiteralByte(bitString, byteArray.at(0));
//  decodedBytes.push_back(byteArray.at(0));
//  writeLiteralByte(bitString, byteArray.at(1));
//  decodedBytes.push_back(byteArray.at(1));
//  int i = 2;
//  while (i < byteArray.size()) {
//    uint8_t byte = byteArray.at(i);
//    int32_t j = decodedBytes.size();
//    int32_t offset = -1;
//    while (--j >= 0) {
//      uint8_t decodedByte = decodedBytes.at(j);
//      if (decodedByte == byte) {
//        offset = decodedBytes.size()-j-1;
//        break;
//      }
//    }

//    if (offset == -1) {
//      writeLiteralByte(bitString, byte);
//      decodedBytes.push_back(byte);
//      i++;
//    }
//    else {
//      int matchedBytes = 0;
//      while (matchedBytes <= 516) {
//        matchedBytes++;

//        if (++i == byteArray.size())
//          break;

//        uint8_t byte2 = byteArray.at(i);
//        if (byte2 != byte)
//          break;
//      }

//      if (matchedBytes == 1) {
//        writeLiteralByte(bitString, byte);
//        decodedBytes.push_back(byte);
//      }
//      else {
//        writeCopyOffset(bitString, offset, matchedBytes, windowSize);
//        for (int j = 0; j < matchedBytes; j++) {
//          decodedBytes.push_back(byte);
//        }
//      }
//    }
//  }

//  bitString += "1000000011111111";

//  // Make the bit string a multiple of 8
//  while (bitString.size() % 8) {
//    bitString += "0";
//  }

//  i = 0;
//  while (i < bitString.size()) {
//    QString s = bitString.mid(i, 8);
//    //std::reverse(s.begin(), s.end());
//    uint8_t v = s.toUInt(nullptr, 2);
//    dataStream << v;
//    i += 8;
//  }

//  return output;
}

QByteArray PkZipData::decompress(QByteArray &byteArray)
{
  QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
  dataStream.setByteOrder(QDataStream::LittleEndian);

  int sz = byteArray.size();

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

void PkZipData::writeCopyOffset(std::vector<bool> & bits, int32_t offset, int32_t length)
{
  int32_t offsetIndex = 0;//mOffsetIndexTable[offset];
  int32_t numOffsetBits = offsetBits[offsetIndex];
  int32_t offsetValue = offsetRepr[offsetIndex];
  uint8_t lengthIndex = 8;// mLengthIndexTable[length];
  int32_t numLengthBits = lengthBits[lengthIndex];
  int32_t numPadBits = lengthFillBits[lengthIndex];
  int32_t lengthValue = lengthRepr[lengthIndex];

  // Marker
  bits.push_back(1);

  // Length
  bits.push_back(0);
  bits.push_back(0);
  bits.push_back(1);
  bits.push_back(0);
  bits.push_back(0);
  bits.push_back(1);

  // Offset repr
  bits.push_back(1);
  bits.push_back(1);

  // Offset value
  bits.push_back(1);
  bits.push_back(0);
  bits.push_back(0);
  bits.push_back(0);

  //writeValue(bits, lengthValue, numLengthBits+numPadBits);
  //writeValue(bits, offsetValue, numOffsetBits);
  //writeValue(bits, (offset & 0x3f), 6);
}

void PkZipData::writeLiteralByte(std::vector<bool> & bits, uint32_t byte)
{
  bits.push_back(0);
  writeValue(bits, byte, 8);
}

void PkZipData::writeValue(std::vector<bool> & bits, uint32_t byte, int32_t length)
{
  for (int j = 0; j < length; j++) {
    bool bit = byte & (1 << j);
    bits.push_back(bit);
  }
}
