#ifndef EDUCATIONDATA_H
#define EDUCATIONDATA_H

#include "datamodel.h"

class EducationData
    : public DataModel
{
public:
  static const int32_t COVERAGE_PER_ACADEMY = 100;
  static const int32_t COVERAGE_PER_LIBRARY = 800;
  static const int32_t COVERAGE_PER_SCHOOL = 75;

public:
  TIBERIUS_LIB_DECL EducationData();

public:
  TIBERIUS_LIB_DECL int32_t totalAcademies() const;
  TIBERIUS_LIB_DECL int32_t totalLibraries() const;
  TIBERIUS_LIB_DECL int32_t totalSchools() const;
  TIBERIUS_LIB_DECL int32_t workingAcademies() const;
  TIBERIUS_LIB_DECL int32_t workingLibraries() const;
  TIBERIUS_LIB_DECL int32_t workingSchools() const;
  TIBERIUS_LIB_DECL void setTotalAcademies(int32_t value);
  TIBERIUS_LIB_DECL void setTotalLibraries(int32_t value);
  TIBERIUS_LIB_DECL void setTotalSchools(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingAcademies(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingLibraries(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingSchools(int32_t value);

public:
  TIBERIUS_LIB_DECL int32_t academyCoverage(int32_t population) const;
  TIBERIUS_LIB_DECL int32_t educationNeeds() const;
  TIBERIUS_LIB_DECL int32_t libraryCoverage(int32_t population) const;
  TIBERIUS_LIB_DECL int32_t schoolCoverage(int32_t population) const;

private:
  int32_t mEducationNeeds;
  int32_t mTotalAcademies;
  int32_t mTotalLibraries;
  int32_t mTotalSchools;
  int32_t mWorkingAcademies;
  int32_t mWorkingLibraries;
  int32_t mWorkingSchools;
};

#endif // EDUCATIONDATA_H
