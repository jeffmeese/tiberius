#include "housingdata.h"

#include "core/streamio.h"

static const int32_t DATA_SIZE = 4000;

HousingData::HousingData()
{

}

void HousingData::loadFromDataStream(QDataStream &dataStream)
{
  streamio::readCompressedData(dataStream, DATA_SIZE);
}

void HousingData::saveToDataStream(QDataStream &dataStream) const
{

}
