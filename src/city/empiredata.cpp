#include "empiredata.h"

#include "core/streamio.h"

#include "empire/city.h"

static const int32_t DATA_SIZE = 2706;

EmpireData::EmpireData()
{
  for (int32_t i = 0; i < MAX_CITIES; i++) {
    CityPtr city(new Empire::City);
    mCities.push_back(std::move(city));
  }
}

EmpireData::~EmpireData()
{

}

void EmpireData::loadFromStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_CITIES; i++) {
    mCities.at(i)->loadFromStream(byteStream);
  }
}

void EmpireData::saveToStream(QDataStream & dataStream) const
{
  QByteArray byteArray;
  QDataStream byteStream(&byteArray, QIODevice::WriteOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_CITIES; i++) {
    mCities.at(i)->saveToStream(byteStream);
  }

  streamio::writeCompressedData(dataStream, byteArray);
}
