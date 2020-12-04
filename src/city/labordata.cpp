#include "labordata.h"

#include <map>
#include <vector>

LaborData::LaborData()
{
  mWage = 30;
  mRomeWage = 30;
  for (int i = 0; i < MAX_LABOR_CATEGORIES; i++) {
    mCategories[i].priority = mCategories[i].workersAvaialble = mCategories[i].workersNeeded = 0;
  }
}

void LaborData::decreaseWage()
{
  setWage(mWage-1);
  emit changed();
}

int32_t LaborData::estimateAnnualBill() const
{
  return 4000;
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

void LaborData::setWage(int32_t value)
{
  if (value < MIN_WAGE || value >= MAX_WAGE)
    return;

  mWage = value;
  emit changed();
}

int32_t LaborData::totalEmployed() const
{
  return 100;
}

int32_t LaborData::totalUnemployed() const
{
  return 0;
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

int32_t LaborData::workersNeeded() const
{
  return 100;
}
