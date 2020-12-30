#include "route.h"

#include "core/streamio.h"

Route::Route(int32_t id)
{
  mId = id;
  mWalkerId = 0;
}

int32_t Route::id() const
{
  return mId;
}

void Route::loadFromDataStream(QDataStream & dataStream)
{
  for (int32_t i = 0; i < MAX_ROUTE_LENGTH; i++) {
    mDirection[i] = streamio::readInt8(dataStream);
  }
}

void Route::saveToDataStream(QDataStream & dataStream) const
{
  for (int32_t i = 0; i < MAX_ROUTE_LENGTH; i++) {
    dataStream << mDirection[i];
  }
}

void Route::setWalkerId(int16_t id)
{
  mWalkerId = id;
}

int16_t Route::walkerId() const
{
  return mWalkerId;
}
