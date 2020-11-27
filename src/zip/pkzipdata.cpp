#include "pkzipdata.h"

#include <bitset>
#include <QDataStream>
#include <QDebug>
#include <QFile>

#include <cmath>
#include <map>

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

PkZipData::PkZipData()
  : mLiteralEncoding(0)
  , mWindowSize(0)
  , mDictionarySize(0)
  , mBitsRemaining(0)
  , mNextBufferPos(0)
  , mDataBuffer(0)
{  
  buildLookupTables();
}

PkZipData::~PkZipData()
{
  if (mDataBuffer != nullptr) {
    delete [] mDataBuffer;
  }
}

void PkZipData::buildLookupTables()
{
  for (int i = 0; i < 16; i++) {
    int bits = lengthBits[i];
    int value = lengthRepr[i];
    while (value < 256) {
      mLengthIndexTable[value] = static_cast<uint8_t>(i);
      value += (1 << bits);
    }
  }

  for (int i = 0; i < 64; i++) {
    int bits = offsetBits[i];
    int value = offsetRepr[i];
    while (value < 256) {
      mOffsetIndexTable[value] = static_cast<uint8_t>(i);
      value += (1 << bits);
    }
  }
}

QByteArray PkZipData::decompress(QByteArray &byteArray)
{
  QDataStream dataStream(&byteArray, QIODevice::ReadOnly);
  dataStream.setByteOrder(QDataStream::LittleEndian);

  // Read the header
  dataStream >> mLiteralEncoding >> mWindowSize;

  // Delete any current data
  if (mDataBuffer != nullptr) {
    delete [] mDataBuffer;
  }

  int32_t bufferLength = byteArray.size()-2;
  mDataBuffer = new uint8_t[bufferLength];
  mDictionarySize = pow(2, mWindowSize) - 1;
  dataStream.readRawData((char*)mDataBuffer, bufferLength);

  mNextBufferPos = 1;
  mBitsRemaining = 0;
  QByteArray output;
  uint16_t currentByteValue = static_cast<uint16_t>(mDataBuffer[0]);
  while (true) {

    if (currentByteValue & 1) {
      // Length-Offset pair

      processBits(currentByteValue, 1);

      int32_t lengthIndex = mLengthIndexTable[currentByteValue & 0xff];
      int32_t numLengthBits = lengthBits[lengthIndex];
      processBits(currentByteValue, numLengthBits);
      int length = lengthBaseValue[lengthIndex];

      int32_t numPadBits = lengthFillBits[lengthIndex];
      if (numPadBits > 0) {
        int padValue = currentByteValue & ((1 << numPadBits) - 1);

        // Check for the end of the data
        if (padValue == 0xff) {
          break;
        }
        processBits(currentByteValue, numPadBits);
        length = lengthBaseValue[lengthIndex] + padValue;
      }

      int32_t offsetIndex = mOffsetIndexTable[currentByteValue & 0xff];
      int32_t numOffsetBits = offsetBits[offsetIndex];
      processBits(currentByteValue, numOffsetBits);

      int offset = 0;
      if (length == 2) {
        offset = (currentByteValue & 3) | (offsetIndex << 2);
        processBits(currentByteValue, 2);
      }
      else {
        offset = (currentByteValue & mDictionarySize) | (offsetIndex << mWindowSize);
        processBits(currentByteValue, mWindowSize);
      }

      // Copy the data
      int outputPos = output.size()-1-offset;
      for (int32_t i = 0; i < length; i++) {
        output.push_back(output[outputPos+i]);
      }
    }
    else {

      // Literal Byte
      processBits(currentByteValue, 1);
      output += currentByteValue & 0xff;
      processBits(currentByteValue, 8);
    }
  }

  // Delete any current data
  if (mDataBuffer != nullptr) {
    delete [] mDataBuffer;
    mDataBuffer = nullptr;
  }

  return output;
}

void PkZipData::processBits(uint16_t &value, int32_t numBits)
{
  if (mBitsRemaining >= numBits) {
    mBitsRemaining -= numBits;
    value >>= numBits;
    return;
  }

  value >>= mBitsRemaining;
  value |= (mDataBuffer[mNextBufferPos++] << 8);
  value >>= (numBits - mBitsRemaining);
  mBitsRemaining += 8 - numBits;
}

QString PkZipData::binaryString(uint8_t *buffer, int length)
{
  QString s;
  for (int i = 0; i < length; i++) {
    uint8_t digit = buffer[i];
    s += binaryString(digit) + " ";
  }
  return s;
}

QString PkZipData::binaryString(uint16_t value)
{
  uint8_t b1 = value & 0x00ff;
  uint8_t b2 = (value & 0xff00) >> 8;
  QString s1 = binaryString(b1);
  QString s2 = binaryString(b2);
  QString s = s1 + s2;
  return s;
}

QString PkZipData::binaryString(uint8_t value)
{
  std::string s = std::bitset<8>(value).to_string();
  std::reverse(s.begin(), s.end());
  return QString::fromStdString(s);
}
