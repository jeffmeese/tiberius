#include "labordata.h"

#include <map>
#include <vector>

LaborData::LaborData()
{
  mRomeWage = 0;
  mTotalEmployed = 0;
  mTotalUnemployed = 0;
  mWage = 0;
  mWageExpenseLastYear = 0;
  mWageExpenseThisMonth = 0;
  mWageExpenseThisYear = 0;
  mWorkingAgePopulation = 0;
  for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
    mCategories[i].priority = 0;
    mCategories[i].workersAvaialble = 0;
    mCategories[i].workersNeeded = 0;
    mCategories[i].numBuildings = 0;
  }
}

void LaborData::decreaseWage()
{
  setWage(mWage-1);
  emit changed();
}

int32_t LaborData::estimateAnnualBill() const
{
  return mTotalEmployed * mWage;
}

void LaborData::increaseWage()
{
  setWage(mWage+1);
  emit changed();
}

int32_t LaborData::minPriorityAvaiable() const
{
  int32_t maxValue = 0;
  for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
    if (mCategories[i].priority > maxValue)
      maxValue = mCategories[i].priority;
  }

  return maxValue + 1;
}

void LaborData::setRomeWage(int32_t wage)
{
  mRomeWage = wage;
  emit changed();
}

void LaborData::setTotalEmployed(int32_t value)
{
  mTotalEmployed = value;
  emit changed();
}

void LaborData::setTotalUnemployed(int32_t value)
{
  mTotalUnemployed = value;
  emit changed();
}

void LaborData::setWorkingAgePopulation(int32_t value)
{
  mWorkingAgePopulation = value;
  emit changed();
}

void LaborData::setWage(int32_t value)
{
  if (value < MIN_WAGE || value >= MAX_WAGE)
    return;

  mWage = value;
  emit changed();
}

void LaborData::setWageExpenseLastYear(int32_t value)
{
  mWageExpenseLastYear = value;
  emit changed();
}

void LaborData::setWageExpenseThisMonth(int32_t value)
{
  mWageExpenseThisMonth = value;
  emit changed();
}

void LaborData::setWageExpenseThisYear(int32_t value)
{
  mWageExpenseThisYear = value;
  emit changed();
}

int32_t LaborData::totalEmployed() const
{
  return mTotalEmployed;
}

int32_t LaborData::totalUnemployed() const
{
  return mTotalUnemployed;
}

int32_t LaborData::unemploymentPercentage() const
{
  int32_t percent = 0;
  int32_t totalWorkers = totalEmployed() + totalUnemployed();
  if (totalWorkers > 0) {
    percent = static_cast<int>( static_cast<float>(totalUnemployed()) / totalWorkers * 100);
  }

  return percent;
}

// There is probably a more elegant way to do this, maybe I'll think of it eventually
void LaborData::updatePriority(Type type, int newPriority)
{
  int index = static_cast<int>(type);
  int oldPriority = mCategories[index].priority;

  // Update the category
  mCategories[index].priority = newPriority;

  // Priority is being removed
  if (newPriority == 0) {
     for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
       if (index != i && mCategories[i].priority > 0 && mCategories[i].priority > oldPriority) {
         mCategories[i].priority--;
       }
     }
  }
  // A priority is being added
  else if (oldPriority == 0) {
    for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
      int priority = mCategories[i].priority;
      if (index != i && priority > 0 && newPriority <= priority) {
        mCategories[i].priority++;
      }
    }
  }
  // A priority is being changed
  else {
    for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
      int priority = mCategories[i].priority;
      if (index != i && priority > 0 && newPriority <= priority && priority < oldPriority) {
        mCategories[i].priority++;
      }
    }
  }
  emit changed();
}

int32_t LaborData::wageExpenseLastYear() const
{
  return mWageExpenseLastYear;
}

int32_t LaborData::wageExpenseThisMonth() const
{
  return mWageExpenseThisMonth;
}

int32_t LaborData::wageExpenseThisYear() const
{
  return mWageExpenseThisYear;
}

int32_t LaborData::workingAgePopulation() const
{
  return mWorkingAgePopulation;
}

int32_t LaborData::workersNeeded() const
{
  return 100;
}
