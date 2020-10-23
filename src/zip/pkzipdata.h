#ifndef PKZIPDATA_H
#define PKZIPDATA_H

#include <QByteArray>

#include <string>

#include "tiberius.h"

class PkZipData
{
public:
  TIBERIUS_LIB_DECL PkZipData();
  TIBERIUS_LIB_DECL ~PkZipData();

public:
  TIBERIUS_LIB_DECL QByteArray decompress(QByteArray & byteArray);

private:
  void buildLookupTables();
  QString binaryString(uint8_t value);
  QString binaryString(uint16_t value);
  QString binaryString(uint8_t *buffer, int length);
  void processBits(uint16_t & value, int32_t numBits);

private:
  uint8_t mLiteralEncoding;
  uint8_t mWindowSize;
  int32_t mDictionarySize;
  int32_t mBitsRemaining;
  int32_t mNextBufferPos;
  uint8_t * mDataBuffer;
  uint8_t mLengthIndexTable[256];
  uint8_t mOffsetIndexTable[256];
};

#endif // PKZIPDATA_H
