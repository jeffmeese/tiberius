#ifndef STREAMIO_H
#define STREAMIO_H

#include <cstdint>
#include <QByteArray>
#include <QDataStream>

namespace streamio
{
  QByteArray readCompressedData(QDataStream & dataStream, int32_t size);
  int8_t readInt8(QDataStream & dataStream);
  int16_t readInt16(QDataStream & dataStream);
  int32_t readInt32(QDataStream & dataStream);
  uint8_t readUInt8(QDataStream & dataStream);
  uint16_t readUInt16(QDataStream & dataStream);
  uint32_t readUInt32(QDataStream & dataStream);
  QByteArray readUncompressedData(QDataStream & dataStream, int32_t size);

  void writeCompressedData(QDataStream & dataStream, QByteArray & byteArray);
  void writeInt32(QDataStream & dataStream, int32_t value);
  void writeUInt8(QDataStream & dataStream, uint8_t value);
}

#endif // STREAMIO_H
