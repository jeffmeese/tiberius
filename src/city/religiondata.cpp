#include "religiondata.h"

#include "application/tiberiusapplication.h"

#include "entertainment/festival.h"

#include "language/language.h"
#include "language/stringdata.h"

ReligionData::ReligionData()
{
  mReligionNeeds = 0;
  mOracles = 0;

  mGods[0].reset(new God(God::Type::Ceres));
  mGods[1].reset(new God(God::Type::Neptune));
  mGods[2].reset(new God(God::Type::Mercury));
  mGods[3].reset(new God(God::Type::Mars));
  mGods[4].reset(new God(God::Type::Venus));

  mGodToIndex[God::Type::Ceres] = 0;
  mGodToIndex[God::Type::Neptune] = 1;
  mGodToIndex[God::Type::Mercury] = 2;
  mGodToIndex[God::Type::Mars] = 3;
  mGodToIndex[God::Type::Venus] = 4;
}

God * ReligionData::getGod(God::Type type)
{
  std::map<God::Type, int>::iterator itr = mGodToIndex.find(type);
  return mGods[itr->second].get();
}

const God * ReligionData::getGod(God::Type type) const
{
  std::map<God::Type, int>::const_iterator itr = mGodToIndex.find(type);
  return mGods[itr->second].get();
}

QString ReligionData::needString() const
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(59, 21+mReligionNeeds);
}

int32_t ReligionData::oracles() const
{
  return mOracles;
}

int32_t ReligionData::relgionNeeds() const
{
  return mReligionNeeds;
}

void ReligionData::setOracles(int32_t value)
{
  mOracles = value;
  emit changed();
}

void ReligionData::throwFestival(Festival *festival)
{
  God * god = getGod(festival->god());
  god->setMonthsSinceFestival(0);
  emit changed();
}

