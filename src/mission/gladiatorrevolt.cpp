#include "gladiatorrevolt.h"

#include "core/streamio.h"

GladiatorRevolt::GladiatorRevolt()
{
  mYear = -1;
}

void GladiatorRevolt::loadFromDataStream(QDataStream & dataStream)
{
  mYear = streamio::readInt32(dataStream);
  mMonth = streamio::readInt32(dataStream);
  mEndMonth = streamio::readInt32(dataStream);
  mState = streamio::readInt32(dataStream);
}

void GladiatorRevolt::saveToDataStream(QDataStream & dataStream) const
{
  dataStream << mYear << mMonth << mEndMonth << mState;
}
