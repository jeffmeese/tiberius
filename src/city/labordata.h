#ifndef LABORDATA_H
#define LABORDATA_H

#include "datamodel.h"

#include <cstdint>

class LaborData
    : public DataModel
{
public:
  static const int32_t MAX_LABOR_CATEGORIES = 9;
  static const int32_t MIN_WAGE = 0;
  static const int32_t MAX_WAGE = 100;

  enum class Type
  {
    Industry = 0,
    Food = 1,
    Engineering = 2,
    Water = 3,
    Prefectures = 4,
    Military = 5,
    Entertainment = 6,
    Health = 7,
    Governance = 8
  };

public:
  struct Category
  {
    int32_t priority;
    int32_t workersAvaialble;
    int32_t workersNeeded;
    int32_t numBuildings;
  };

public:
  TIBERIUS_LIB_DECL LaborData();

public:
  TIBERIUS_LIB_DECL Category & category(Type type);
  TIBERIUS_LIB_DECL const Category & category(Type type) const;
  TIBERIUS_LIB_DECL int32_t romeWage() const;
  TIBERIUS_LIB_DECL int32_t totalEmployed() const;
  TIBERIUS_LIB_DECL int32_t totalUnemployed() const;
  TIBERIUS_LIB_DECL int32_t wage() const;
  TIBERIUS_LIB_DECL int32_t wageExpenseLastYear() const;
  TIBERIUS_LIB_DECL int32_t wageExpenseThisMonth() const;
  TIBERIUS_LIB_DECL int32_t wageExpenseThisYear() const;
  TIBERIUS_LIB_DECL int32_t workingAgePopulation() const;
  TIBERIUS_LIB_DECL void setRomeWage(int32_t wage);
  TIBERIUS_LIB_DECL void setTotalEmployed(int32_t value);
  TIBERIUS_LIB_DECL void setTotalUnemployed(int32_t value);
  TIBERIUS_LIB_DECL void setWage(int32_t value);
  TIBERIUS_LIB_DECL void setWageExpenseLastYear(int32_t value);
  TIBERIUS_LIB_DECL void setWageExpenseThisMonth(int32_t value);
  TIBERIUS_LIB_DECL void setWageExpenseThisYear(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingAgePopulation(int32_t value);

public:
  TIBERIUS_LIB_DECL void decreaseWage();
  TIBERIUS_LIB_DECL int32_t estimateAnnualBill() const;
  TIBERIUS_LIB_DECL void increaseWage();
  TIBERIUS_LIB_DECL int32_t minPriorityAvaiable() const;
  TIBERIUS_LIB_DECL int32_t unemploymentPercentage() const;
  TIBERIUS_LIB_DECL void updatePriority(Type type, int newPriority);
  TIBERIUS_LIB_DECL int32_t workersNeeded() const;

private:
  int32_t mRomeWage;
  int32_t mTotalEmployed;
  int32_t mTotalUnemployed;
  int32_t mWage;
  int32_t mWageExpenseLastYear;
  int32_t mWageExpenseThisMonth;
  int32_t mWageExpenseThisYear;
  int32_t mWorkingAgePopulation;
  Category mCategories[MAX_LABOR_CATEGORIES];
};

inline LaborData::Category & LaborData::category(Type type)
{
  return mCategories[static_cast<int>(type)];
}

inline const LaborData::Category & LaborData::category(Type type) const
{
  return mCategories[static_cast<int>(type)];
}

inline int32_t LaborData::romeWage() const
{
  return mRomeWage;
}

inline int32_t LaborData::wage() const
{
  return mWage;
}

#endif // LABORDATA_H
