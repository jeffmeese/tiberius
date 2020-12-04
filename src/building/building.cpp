#include "building.h"

Building::Building(Type type)
  : mType(type)
{
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
