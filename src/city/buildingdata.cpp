#include "buildingdata.h"

#include "building/building.h"

#include "core/streamio.h"

static const int32_t DATA_SIZE = 256000;

BuildingData::BuildingData()
  : DataVector<Building>(MAX_BUILDINGS)
{
  mHighestId = mHighestIdInUse = 0;
}

BuildingData::~BuildingData()
{

}

int32_t BuildingData::highestIdInUse() const
{
  return mHighestIdInUse;
}

int32_t BuildingData::highestIdUsed() const
{
  return mHighestId;
}

void BuildingData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_BUILDINGS; i++) {
    get(i)->loadFromDataStream(byteStream);
  }
}

void BuildingData::saveToDataStream(QDataStream & dataStream) const
{
  QDataStream byteStream;
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int i = 0; i < MAX_BUILDINGS; i++) {
    get(i)->saveToDataStream(byteStream);
  }

  QByteArray byteArray;
  streamio::writeCompressedData(byteStream, byteArray);
  dataStream.device()->write(byteArray);
}

void BuildingData::setHighestIdInUse(int32_t value)
{
  mHighestIdInUse = value;
}

void BuildingData::setHighestIdUsed(int32_t value)
{
  mHighestId = value;
}
