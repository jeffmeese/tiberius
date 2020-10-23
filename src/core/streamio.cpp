#include "streamio.h"

#include "zip/pkzipdata.h"

QByteArray streamio::readCompressedData(QDataStream &dataStream, int32_t size)
{
  static const int32_t UNCOMPRESSED = 0x80000000;

  QByteArray byteArray;
  int32_t dataSize = 0;
  dataStream >> dataSize;
  if (dataSize == UNCOMPRESSED) {
    return readUncompressedData(dataStream, size);
  }

  PkZipData zipData;
  QByteArray compressedData = dataStream.device()->read(dataSize);
  byteArray = zipData.decompress(compressedData);

  return byteArray;
}

int8_t streamio::readInt8(QDataStream & dataStream)
{
  int8_t value = 0;
  dataStream >> value;
  return value;
}

int16_t streamio::readInt16(QDataStream & dataStream)
{
  int16_t value = 0;
  dataStream >> value;
  return value;
}

int32_t streamio::readInt32(QDataStream & dataStream)
{
  int32_t value = 0;
  dataStream >> value;
  return value;
}

uint8_t streamio::readUInt8(QDataStream & dataStream)
{
  uint8_t value = 0;
  dataStream >> value;
  return value;
}

uint16_t streamio::readUInt16(QDataStream & dataStream)
{
  uint16_t value = 0;
  dataStream >> value;
  return value;
}

uint32_t streamio::readUInt32(QDataStream & dataStream)
{
  uint32_t value = 0;
  dataStream >> value;
  return value;
}

QByteArray streamio::readUncompressedData(QDataStream &dataStream, int32_t size)
{
  return dataStream.device()->read(size);
}
