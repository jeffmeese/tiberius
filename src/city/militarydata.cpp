#include "militarydata.h"

#include "military/legion.h"
#include "military/soldier.h"

MilitaryData::MilitaryData()
{

}

MilitaryData::~MilitaryData()
{

}

int32_t MilitaryData::totalLegions() const
{
  return static_cast<int32_t>(mLegions.size());
}
