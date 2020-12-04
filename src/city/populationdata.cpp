#include "populationdata.h"

PopulationData::PopulationData()
{
  mAcademyAgedChildren = 150;
  mSchoolAgedChildren = 400;
  mTotalPopulation = 1000;
}

int32_t PopulationData::academyAgedPopulation() const
{
  return mAcademyAgedChildren;
}

int32_t PopulationData::schoolAgedPopulation() const
{
  return mSchoolAgedChildren;
}

void PopulationData::decreasePopulation(int32_t value)
{
  mTotalPopulation -= value;
  if (mTotalPopulation < 0)
    mTotalPopulation = 0;

  emit changed();
}

void PopulationData::increasePopulation(int32_t value)
{
  mTotalPopulation += value;
  if (mTotalPopulation < 0)
    mTotalPopulation = 0;

  emit changed();
}

void PopulationData::setAcademyAgedChildren(int32_t value)
{
  mAcademyAgedChildren = value;
  emit changed();
}

void PopulationData::setSchoolAgedChildren(int32_t value)
{
  mSchoolAgedChildren = value;
  emit changed();
}

void PopulationData::setTotalPopulation(int32_t value)
{
  mTotalPopulation = value;
  emit changed();
}

int32_t PopulationData::totalPopulation() const
{
  return mTotalPopulation;
}
