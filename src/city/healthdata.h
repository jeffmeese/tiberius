#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include "datamodel.h"

class HealthData
    : public DataModel
{
public:
  static const int32_t COVERARGE_PER_HOSPITAL = 1000;

public:
  TIBERIUS_LIB_DECL HealthData();

public:
  TIBERIUS_LIB_DECL int32_t healthAdvice() const;
  TIBERIUS_LIB_DECL int32_t totalBarbers() const;
  TIBERIUS_LIB_DECL int32_t totalBathHouses() const;
  TIBERIUS_LIB_DECL int32_t totalClinics() const;
  TIBERIUS_LIB_DECL int32_t totalHospitals() const;
  TIBERIUS_LIB_DECL int32_t workingBarbers() const;
  TIBERIUS_LIB_DECL int32_t workingBathHouses() const;
  TIBERIUS_LIB_DECL int32_t workingClinics() const;
  TIBERIUS_LIB_DECL int32_t workingHospitals() const;
  TIBERIUS_LIB_DECL void setHealthAdvice(int32_t value);
  TIBERIUS_LIB_DECL void setTotalBarbers(int32_t value);
  TIBERIUS_LIB_DECL void setTotalBaths(int32_t value);
  TIBERIUS_LIB_DECL void setTotalClincs(int32_t value);
  TIBERIUS_LIB_DECL void setTotalHospitals(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingBarbers(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingBaths(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingClincs(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingHospitals(int32_t value);

public:
  TIBERIUS_LIB_DECL int32_t healthScore() const;
  TIBERIUS_LIB_DECL int32_t hosptialCoverage(int32_t population) const;

private:
  int32_t mHealthAdvice;
  int32_t mTotalBarbers;
  int32_t mTotalBathHouses;
  int32_t mTotalClinics;
  int32_t mTotalHospitals;
  int32_t mWorkingBarbers;
  int32_t mWorkingBathHouses;
  int32_t mWorkingClinics;
  int32_t mWorkingHospitals;
};

#endif // HEALTHDATA_H
