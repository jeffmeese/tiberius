#include "earthquake.h"

Earthquake::Earthquake()
{

}

void Earthquake::loadFromDataStream(QDataStream & dataStream)
{
  int32_t year, month;
  dataStream >> year >> month;

  setYear(year);
  setMonth(month);
  dataStream >> mState;
  dataStream >> mDuration;
  dataStream >> mMaxDuration;
  dataStream >> mMaxDelay;
  dataStream >> mDelay;
  for (int i = 0; i < 4; i++) {
    dataStream >> mExpandX[i];
    dataStream >> mExpandY[i];
  }
}

void Earthquake::saveToDataStream(QDataStream &dataStream) const
{
  dataStream << year();
  dataStream << month();
  dataStream << mState;
  dataStream << mDuration;
  dataStream << mMaxDuration;
  dataStream << mMaxDelay;
  dataStream << mDelay;
  for (int i = 0; i < 4; i++) {
    dataStream << mExpandX[i];
    dataStream << mExpandY[i];
  }
}
