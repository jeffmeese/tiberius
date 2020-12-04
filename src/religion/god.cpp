#include "god.h"

#include "application/tiberiusapplication.h"

#include "language/language.h"
#include "language/stringdata.h"

God::God(Type type)
  : mType(type)
{
  mAngerBolts = 0;
  mLargeTemples = 0;
  mSmallTemples = 0;
  mMonthsSinceFestival = 0;
  mSentiment = Sentiment::Indifferent;
}

int32_t God::largeTemples() const
{
  return mLargeTemples;
}

int32_t God::monthsSinceFestival() const
{
  return mMonthsSinceFestival;
}

QString God::description() const
{
  return description(mType);
}

QString God::description(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(59, 16 + static_cast<int>(type));
}

QString God::name() const
{
  return name(mType);
}

QString God::name(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(28, 60 + static_cast<int>(type));
}

QString God::sentimentString() const
{
  return sentimentString(mSentiment);
}

QString God::sentimentString(Sentiment type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(59, 32 + static_cast<int>(type));
}

void God::setLargeTemples(int32_t value)
{
  mLargeTemples = value;
}

void God::setMonthsSinceFestival(int32_t value)
{
  mMonthsSinceFestival = value;
}

void God::setSmallTemples(int32_t value)
{
  mSmallTemples = value;
}

int32_t God::smallTemples() const
{
  return mSmallTemples;
}
