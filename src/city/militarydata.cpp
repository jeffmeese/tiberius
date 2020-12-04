#include "militarydata.h"

#include "military/legion.h"
#include "military/soldier.h"

MilitaryData::MilitaryData()
{
  std::unique_ptr<Legion> legion(new Legion(Legion::Type::Legionnaires, 1));
  addLegion(std::move(legion));
}

MilitaryData::~MilitaryData()
{
}

void MilitaryData::addLegion(std::unique_ptr<Legion> legion)
{
  mLegions.push_back(std::move(legion));
}

Legion * MilitaryData::legionAt(int32_t index)
{
  return mLegions.at(index).get();
}

const Legion * MilitaryData::legionAt(int32_t index) const
{
  return mLegions.at(index).get();
}

bool MilitaryData::removeLegion(Legion *legion)
{
  for (LegionVector::iterator itr = mLegions.begin(); itr != mLegions.end(); ++itr) {
    if (itr->get() == legion) {
      mLegions.erase(itr);
      return true;
    }
  }
  return false;
}

int32_t MilitaryData::totalLegions() const
{
  return static_cast<int32_t>(mLegions.size());
}
