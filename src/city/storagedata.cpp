#include "storagedata.h"

#include "core/streamio.h"

static const int32_t DATA_SIZE = 6544;

StorageData::StorageData()
{

}

void StorageData::loadFromDataStream(QDataStream &dataStream)
{
  streamio::readCompressedData(dataStream, DATA_SIZE);
}

void StorageData::saveToDataStream(QDataStream &dataStream) const
{

}
