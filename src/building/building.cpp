#include "building.h"

Building::Building()
{
  mType = Type::None;
  mWorkers = 0;
  mWorkersNeeded = 0;
}

QPixmap Building::getImage() const
{
  return QPixmap();
}

QString Building::getName() const
{
  return "";
}

void Building::loadFromDataStream(QDataStream & dataStream)
{
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
