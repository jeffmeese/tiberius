#ifndef PKZIPDATA_H
#define PKZIPDATA_H

#include <QByteArray>
#include <QString>

#include <string>
#include <vector>

#include "tiberius.h"

class PkZipData
{
public:
  TIBERIUS_LIB_DECL PkZipData();
  TIBERIUS_LIB_DECL ~PkZipData();

public:
  TIBERIUS_LIB_DECL QByteArray compress(const QByteArray & byteArray, uint8_t literalEncoding = 0, uint8_t windowSize = 6);
  TIBERIUS_LIB_DECL QByteArray decompress(QByteArray & byteArray, bool debug = false);

private:
  void buildLookupTables();
  void processBits(uint16_t & value, int32_t numBits, uint8_t * dataBuffer, int32_t & nextBufferPos, int32_t & bitsRemaining);
  void writeCompressedArray(std::vector<bool> & bits, QByteArray & byteArray);
  void writeCopyOffset(std::vector<bool> & bits, int32_t offset, int32_t length, int32_t windowSize);
  void writeLiteralByte(std::vector<bool> & bits, uint32_t byte);
  void writeValue(std::vector<bool> & bits, uint32_t byte, int32_t length);
  //void writeCopyOffset(QString & bitString, int32_t offset, int32_t length, uint8_t windowSize);
  //void writeLiteralByte(QString & bitString, uint8_t value);

private:
  uint8_t mLengthToIndex[256];
  uint8_t mOffsetToIndex[256];
  int8_t mLengthToBase[519];
  QString mLengthReprString[519];
  QString mBaseOffset[64];
};

#endif // PKZIPDATA_H
