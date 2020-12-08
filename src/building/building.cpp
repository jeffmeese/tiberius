#include "building.h"

#include "core/streamio.h"

Building::Building(int32_t id)
{
  mId = id;
  mType = Type::None;
}

QPixmap Building::getImage() const
{
  return QPixmap();
}

QString Building::getName() const
{
  return "";
}

int32_t Building::id() const
{
  return mId;
}

void Building::loadFromDataStream(QDataStream & dataStream)
{
  int8_t c;
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
}

void Building::saveToDataStream(QDataStream & dataStream) const
{
}

void Building::setType(Type value)
{
  mType = value;
}

Building::Type Building::type() const
{
  return mType;
}
