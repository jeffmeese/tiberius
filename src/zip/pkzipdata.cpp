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

PkZipData::PkZipData()
{  
  buildLookupTables();
}

PkZipData::~PkZipData()
{
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

QByteArray PkZipData::compress(const QByteArray &byteArray, uint8_t literalEncoding, uint8_t windowSize)
{
  QByteArray output;
  QDataStream dataStream(&output, QIODevice::WriteOnly);
  dataStream.setByteOrder(QDataStream::LittleEndian);

  //int32_t dictionarySize = pow(2, windowSize) - 1;
  dataStream << literalEncoding << windowSize;

  QString bitString;
  //bitString += QStringLiteral("%1").arg(literalEncoding, 8, 2, QChar('0'));
  //bitString += QStringLiteral("%1").arg(windowSize, 8, 2, QChar('0'));

  std::map<char, int> indexMap;
  for (int i = 0; i < byteArray.size(); i++) {

    char byte = byteArray.at(i);
    if (indexMap.find(byte) == indexMap.end()) {
      indexMap[byte] = indexMap.size();
      writeLiteralByte(bitString, byte);
    }
    else {
      int byteOffset = indexMap.size() - 1 - indexMap[byte];
      int numBytesMatched = 1;
      while (true) {
        if (++i == byteArray.size())
          break;

        char byte2 = byteArray.at(i);
        if (byte2 != byte)
          break;

        numBytesMatched++;
        if (numBytesMatched == 518)
          break;
      }

      if (numBytesMatched == 1) {
        writeLiteralByte(bitString, byte);
      }
      else {
        int32_t offset = byteOffset;
        writeCopyOffset(bitString, offset, numBytesMatched);
        //indexMap[byte] = i;
      }
    }
  }

  bitString += "1000000011111111";

  // Make the bit string a multiple of 8
  while (bitString.size() % 8) {
    bitString += "0";
  }

  //output = bitString.toUtf8();
  int numBytes = bitString.size() / 16;
  for (int i = 0; i < numBytes; i++) {
    int index = i*16;
    QString s = bitString.mid(index, 16);
    uint16_t v = (s.toUInt(nullptr, 2) & 0xff);
    dataStream << v;
  }

//  QByteArray arr = bitString.toUtf8();
//  for (int i = 0; i < arr.size(); i++) {
//    unsigned char v = arr[i];
//    QString s(v);
//    uint8_t value = s.toUInt();
//    //uint8_t value = ;
//    dataStream << value;
//  }
  return output;
  //return arr;
  //dataStream.writeBytes(arr.data(), arr.size());
  //dataStream << outputArray;

//  while (bitString.size() > 0) {
//    QString byteString = bitString.mid(0, 8);
//    uint8_t value = byteString.toUInt();
//    dataStream << value;
//    bitString.remove(0, 8);
//  }

  //return output;
}

QByteArray PkZipData::decompress(QByteArray &byteArray)
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

      qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
      processBits(currentByteValue, 1, dataBuffer, nextBufferPos, bitsRemaining);
      int32_t lengthIndex = mLengthIndexTable[currentByteValue & 0xff];
      int32_t numLengthBits = lengthBits[lengthIndex];
      qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
      processBits(currentByteValue, numLengthBits, dataBuffer, nextBufferPos, bitsRemaining);
      qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));

      int32_t length = lengthBaseValue[lengthIndex];
      int32_t numPadBits = lengthFillBits[lengthIndex];
      if (numPadBits > 0) {
        int32_t padValue = currentByteValue & ((1 << numPadBits) - 1);

        // Check for the end of the data
        if (padValue == 0xff) {
          break;
        }
        processBits(currentByteValue, numPadBits, dataBuffer, nextBufferPos, bitsRemaining);
        qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
        length = lengthBaseValue[lengthIndex] + padValue;
      }

      qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0x3f), 16, 2, QChar('0'));
      qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
      uint8_t offsetIndex = mOffsetIndexTable[currentByteValue & 0xff];
      int32_t numOffsetBits = offsetBits[offsetIndex];
      processBits(currentByteValue, numOffsetBits, dataBuffer, nextBufferPos, bitsRemaining);
      //qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));

      int32_t offset = 0;
      uint16_t byteVal = (currentByteValue & dictionarySize);
      uint16_t offsetWin = (offsetIndex << windowSize);
      if (length == 2) {
        offset = (currentByteValue & 3) | (offsetIndex << 2);
        processBits(currentByteValue, 2, dataBuffer, nextBufferPos, bitsRemaining);
        qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
      }
      else {
        offset = (currentByteValue & dictionarySize) | (offsetIndex << windowSize);
        processBits(currentByteValue, windowSize, dataBuffer, nextBufferPos, bitsRemaining);
        qDebug() << QStringLiteral("%1").arg( (currentByteValue & 0xff), 16, 2, QChar('0'));
      }
      qDebug() << "\n";

      // Copy the data
      int32_t outputPos = output.size()-1-offset;
//      std::ostringstream oss;
//      oss << std::setw(4) << (int)offsetIndex << " ";
//      oss << std::setw(18) << QStringLiteral("%1").arg(byteVal, 12, 2, QChar('0')).toStdString() << " ";
//      oss << std::setw(18) <<  QStringLiteral("%1").arg(offsetWin, 12, 2, QChar('0')).toStdString() << " ";
//      oss << std::setw(18) << QStringLiteral("%1").arg(offset, 12, 2, QChar('0')).toStdString() << " ";
//      oss << std::setw(18) << QStringLiteral("%1").arg(length, 16, 2, QChar('0')).toStdString() << " ";
//      oss << std::setw(6) << length << " ";
//      oss << std::setw(6) << offset << " ";
//      qDebug() << QString::fromStdString(oss.str());

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

void PkZipData::writeCopyOffset(QString & bitString, int32_t offset, int32_t length)
{
  int32_t offsetIndex = 0;//mOffsetIndexTable[offset];
  int32_t numOffsetBits = offsetBits[offsetIndex];
  int32_t offsetValue = offsetRepr[offsetIndex];
  uint8_t lengthIndex = 8;// mLengthIndexTable[length];
  int32_t numLengthBits = lengthBits[lengthIndex];
  int32_t numPadBits = lengthFillBits[lengthIndex];
  int32_t lengthValue = lengthRepr[lengthIndex];

  QString s = "1";
  s += QStringLiteral("%1").arg(lengthValue, numLengthBits+numPadBits, 2, QChar('0'));
  s += QStringLiteral("%1").arg(offsetValue, numOffsetBits, 2, QChar('0'));
  s += QStringLiteral("%1").arg( (offset & 0x3f), 6, 2, QChar('0')); // Assuming a window size of 6 right now
  bitString += s;
}

void PkZipData::writeLiteralByte(QString & bitString, uint8_t value)
{
  bitString += "0";
  bitString += QStringLiteral("%1").arg(value, 8, 2, QChar('0'));
}
