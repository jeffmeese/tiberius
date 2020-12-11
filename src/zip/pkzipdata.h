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
  TIBERIUS_LIB_DECL QByteArray compress(const QByteArray & byteArray, uint8_t literalEncoding = 0, uint8_t windowSize = 6);
  TIBERIUS_LIB_DECL QByteArray decompress(QByteArray & byteArray);

private:
  void buildLookupTables();
  QString binaryString(uint8_t value);
  QString binaryString(uint16_t value);
  QString binaryString(uint8_t *buffer, int length);
  void processBits(uint16_t & value, int32_t numBits, uint8_t * dataBuffer, int32_t & nextBufferPos, int32_t & bitsRemaining);
  void writeCopyOffset(QString & bitString, int32_t offset, int32_t length);
  void writeLiteralByte(QString & bitString, uint8_t value);

private:
  uint8_t mLengthIndexTable[256];
  uint8_t mOffsetIndexTable[256];
};

#endif // PKZIPDATA_H
