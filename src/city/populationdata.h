#ifndef POPULATIONDATA_H
#define POPULATIONDATA_H

#include "datamodel.h"

class PopulationData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL PopulationData();

public:
  TIBERIUS_LIB_DECL int32_t academyAgedPopulation() const;
  TIBERIUS_LIB_DECL int32_t schoolAgedPopulation() const;
  TIBERIUS_LIB_DECL int32_t totalPopulation() const;
  TIBERIUS_LIB_DECL void setAcademyAgedChildren(int32_t value);
  TIBERIUS_LIB_DECL void setSchoolAgedChildren(int32_t value);
  TIBERIUS_LIB_DECL void setTotalPopulation(int32_t value);

public:
  TIBERIUS_LIB_DECL void decreasePopulation(int32_t value);
  TIBERIUS_LIB_DECL void increasePopulation(int32_t value);

private:
  int32_t mAcademyAgedChildren;
  int32_t mSchoolAgedChildren;
  int32_t mTotalPopulation;
};

#endif // POPULATIONDATA_H
