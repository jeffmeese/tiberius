#include "festival.h"

Festival::Festival(Type type)
  : mType(type)
{
  mGodType = God::Type::Ceres;
  mCost = 0;
  mWineRequired = 0;
}

int32_t Festival::cost() const
{
  return mCost;
}

God::Type Festival::god() const
{
  return mGodType;
}

void Festival::setCost(int32_t value)
{
  mCost = value;
}

void Festival::setGod(God::Type value)
{
  mGodType = value;
}

void Festival::setWineRequired(int32_t value)
{
  mWineRequired = value;
}

Festival::Type Festival::type() const
{
  return mType;
}

int32_t Festival::wineRequired() const
{
  return mWineRequired;
}
