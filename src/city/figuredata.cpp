#include "figuredata.h"

#include "core/streamio.h"

#include "figure/figure.h"

static const int32_t DATA_SIZE = 128000;

FigureData::FigureData()
  : DataVector<Figure>(MAX_CHARACTERS)
{
}

FigureData::~FigureData()
{

}

void FigureData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_CHARACTERS; i++) {
    get(i)->loadFromDataStream(dataStream);
  }
}

void FigureData::saveToDataStream(QDataStream & dataStream) const
{
  QDataStream byteStream;
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int i = 0; i < MAX_CHARACTERS; i++) {
    get(i)->saveToDataStream(byteStream);
  }

  QByteArray byteArray;
  streamio::writeCompressedData(byteStream, byteArray, DATA_SIZE);
  dataStream.device()->write(byteArray);
}
