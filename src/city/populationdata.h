#ifndef POPULATIONDATA_H
#define POPULATIONDATA_H

#include "datamodel.h"

class PopulationData
    : public DataModel
{
public:
  static const int32_t MAX_MONTHLY_POPULATION_COUNT = 2400;
  static const int32_t MAX_AGE = 100;
  static const int32_t MAX_STATUS_CATEGORIES = 20;

public:
  TIBERIUS_LIB_DECL PopulationData();

public:
  TIBERIUS_LIB_DECL int32_t academyAgedPopulation() const;
  TIBERIUS_LIB_DECL int32_t monthlyPopulation(int32_t index) const;
  TIBERIUS_LIB_DECL int32_t monthlyPopulationIndex() const;
  TIBERIUS_LIB_DECL int32_t populationByAge(int32_t age) const;
  TIBERIUS_LIB_DECL int32_t populationByStatus(int32_t status) const;
  TIBERIUS_LIB_DECL int32_t populationCapacity() const;
  TIBERIUS_LIB_DECL int32_t previousYearPopulation() const;
  TIBERIUS_LIB_DECL int32_t schoolAgedPopulation() const;
  TIBERIUS_LIB_DECL int32_t totalPopulation() const;
  TIBERIUS_LIB_DECL void setAcademyAgedChildren(int32_t value);
  TIBERIUS_LIB_DECL void setMonthlyPopulation(int32_t index, int32_t value);
  TIBERIUS_LIB_DECL void setMonthlyPopulationIndex(int32_t index);
  TIBERIUS_LIB_DECL void setPopulationByAge(int32_t age, int32_t value);
  TIBERIUS_LIB_DECL void setPopulatonByStatus(int32_t status, int32_t value);
  TIBERIUS_LIB_DECL void setPopulationCapacity(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearPopulation(int32_t value);
  TIBERIUS_LIB_DECL void setSchoolAgedChildren(int32_t value);
  TIBERIUS_LIB_DECL void setTotalPopulation(int32_t value);

public:
  TIBERIUS_LIB_DECL int32_t availablePopulationSpace() const;
  TIBERIUS_LIB_DECL void decreasePopulation(int32_t value);
  TIBERIUS_LIB_DECL void increasePopulation(int32_t value);

private:
  int32_t mAcademyAgedChildren;
  int32_t mPopulationCapacity;
  int32_t mPreviousYearPopulation;
  int32_t mSchoolAgedChildren;
  int32_t mTotalPopulation;
  int32_t mMonthlyPopulationIndex;
  int32_t mMonthlyPopulation[MAX_MONTHLY_POPULATION_COUNT];
  int32_t mPopulationByAge[MAX_AGE];
  int32_t mPopulationByStatus[MAX_STATUS_CATEGORIES];
};

#endif // POPULATIONDATA_H
