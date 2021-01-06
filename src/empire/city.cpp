#include "city.h"

#include "core/streamio.h"

namespace Empire
{

City::City()
{

}

void City::loadFromStream(QDataStream &dataStream)
{
  mInUse = streamio::readUInt8(dataStream);
  dataStream.skipRawData(1);
  mType = streamio::readUInt8(dataStream);
  mNameId = streamio::readUInt8(dataStream);
  dataStream.skipRawData(2);

  for (int32_t i = 0; i < Resource::MAX_RESOURCES+1; i++) {
    mBuyFlags[i] = streamio::readUInt8(dataStream);
  }

  for (int32_t i = 0; i < Resource::MAX_RESOURCES+1; i++) {
    mSellFlags[i] = streamio::readUInt8(dataStream);
  }

  mTradeRouteCost = streamio::readUInt16(dataStream);
  dataStream.skipRawData(26);
}

void City::saveToStream(QDataStream &dataStream) const
{

}

}
