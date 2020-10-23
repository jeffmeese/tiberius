#include "emperorchange.h"

EmperorChange::EmperorChange()
{
  mYear = mMonth = mState = 0;
}

void EmperorChange::loadFromDataStream(QDataStream & dataStream)
{
  dataStream >> mYear;
  dataStream >> mMonth;
  dataStream >> mState;
}

void EmperorChange::saveToDataStream(QDataStream & dataStream) const
{
  dataStream << mYear;
  dataStream << mMonth;
  dataStream << mState;
}
