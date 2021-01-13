#include "burningbuildingdata.h"

#include "core/streamio.h"

static const int32_t DATA_SIZE = 1000;

BurningBuildingData::BurningBuildingData()
{
  for (int32_t i = 0; i < MAX_BURNING_BUILDINGS; i++) {
    mIdList[i] = 0;
  }
}

void BurningBuildingData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);

  for (int32_t i = 0; i < MAX_BURNING_BUILDINGS; i++) {
    mIdList[i] = streamio::readInt16(byteStream);
  }
}

void BurningBuildingData::saveToDataStream(QDataStream & dataStream) const
{

}
