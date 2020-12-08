#include "walkerdata.h"

#include "core/streamio.h"

#include "figure/figure.h"

static const int32_t DATA_SIZE = 128000;

WalkerData::WalkerData()
  : DataVector<Figure>(MAX_FIGURES)
{
}

WalkerData::~WalkerData()
{

}

void WalkerData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_FIGURES; i++) {
    get(i)->loadFromDataStream(byteStream);
  }
}

void WalkerData::saveToDataStream(QDataStream & dataStream, bool compressed) const
{
  QDataStream byteStream;
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int i = 0; i < MAX_FIGURES; i++) {
    get(i)->saveToDataStream(byteStream);
  }

  QByteArray byteArray;
  streamio::writeCompressedData(byteStream, byteArray);
  dataStream.device()->write(byteArray);
}
