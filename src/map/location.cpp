#include "location.h"

#include "core/streamio.h"

Location::Location()
  : mX(0)
  , mY(0)
{
}

Location::Location(int32_t x, int32_t y)
  : mX(x)
  , mY(y)
{
}

void Location::loadFromDataStream(QDataStream & dataStream)
{
  setX(streamio::readUInt8(dataStream));
  setY(streamio::readUInt8(dataStream));
}

void Location::saveToDataStream(QDataStream & dataStream) const
{
  streamio::writeUInt8(dataStream, mX);
  streamio::writeUInt8(dataStream, mY);
}
