#include "empiredata.h"

#include "core/streamio.h"

#include "empire/city.h"

static const int32_t DATA_SIZE = 2706;

EmpireData::EmpireData()
  : DataVector<Empire::City>(MAX_CITIES)
{
}

EmpireData::~EmpireData()
{

}

void EmpireData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_CITIES; i++) {
    Empire::City * city = get(i);
    city->loadFromStream(byteStream);
  }
}

void EmpireData::saveToDataStream(QDataStream & dataStream) const
{
  QByteArray byteArray;
  QDataStream byteStream(&byteArray, QIODevice::WriteOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_CITIES; i++) {
    get(i)->saveToStream(byteStream);
  }

  streamio::writeCompressedData(dataStream, byteArray);
}
