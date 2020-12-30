#include "populationdata.h"

PopulationData::PopulationData()
{
  mAcademyAgedChildren = 0;
  mPopulationCapacity = 0;
  mPreviousYearPopulation = 0;
  mSchoolAgedChildren = 0;
  mTotalPopulation = 0;

  mMonthlyPopulationIndex = 0;
  for (int32_t i = 0; i < MAX_MONTHLY_POPULATION_COUNT; i++) {
    mMonthlyPopulation[i] = 0;
  }

  for (int32_t i = 0; i < MAX_AGE; i++) {
    mPopulationByAge[i] = 0;
  }

  for (int32_t i = 0; i < MAX_STATUS_CATEGORIES; i++) {
    mPopulationByStatus[i] = 0;
  }
}

int32_t PopulationData::academyAgedPopulation() const
{
  return mAcademyAgedChildren;
}

int32_t PopulationData::availablePopulationSpace() const
{
  return mPopulationCapacity - mTotalPopulation;
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

int32_t PopulationData::monthlyPopulation(int32_t index) const
{
  return mMonthlyPopulation[index];
}

int32_t PopulationData::monthlyPopulationIndex() const
{
  return mMonthlyPopulationIndex;
}

int32_t PopulationData::populationByAge(int32_t age) const
{
  return mPopulationByAge[age];
}

int32_t PopulationData::populationByStatus(int32_t status) const
{
  return mPopulationByStatus[status];
}

int32_t PopulationData::populationCapacity() const
{
  return mPopulationCapacity;
}

int32_t PopulationData::previousYearPopulation() const
{
  return mPreviousYearPopulation;
}

int32_t PopulationData::schoolAgedPopulation() const
{
  return mSchoolAgedChildren;
}

void PopulationData::setAcademyAgedChildren(int32_t value)
{
  mAcademyAgedChildren = value;
  emit changed();
}

void PopulationData::setMonthlyPopulation(int32_t index, int32_t value)
{
  mMonthlyPopulation[index] = value;
  emit changed();
}

void PopulationData::setMonthlyPopulationIndex(int32_t index)
{
  mMonthlyPopulationIndex = index;
  emit changed();
}

void PopulationData::setPopulationByAge(int32_t age, int32_t value)
{
  mPopulationByAge[age] = value;
  emit changed();
}

void PopulationData::setPopulatonByStatus(int32_t status, int32_t value)
{
  mPopulationByStatus[status] = value;
  emit changed();
}

void PopulationData::setPopulationCapacity(int32_t value)
{
  mPopulationCapacity = value;
  emit changed();
}

void PopulationData::setPreviousYearPopulation(int32_t value)
{
  mPreviousYearPopulation = value;
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
