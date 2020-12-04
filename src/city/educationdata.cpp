#include "educationdata.h"

EducationData::EducationData()
{
  mTotalAcademies = mWorkingAcademies = 1;
  mTotalLibraries = mWorkingLibraries = 2;
  mTotalSchools = mWorkingSchools = 4;
  mEducationNeeds = 2;
}

int32_t EducationData::academyCoverage(int32_t population) const
{
  int32_t percent = 0;
  if (population > 0) {
    int32_t coverage = mWorkingAcademies * COVERAGE_PER_ACADEMY;
    percent = static_cast<int>(static_cast<float>(coverage) / population * 100);
  }
  return percent;
}

int32_t EducationData::educationNeeds() const
{
  return mEducationNeeds;
}

int32_t EducationData::libraryCoverage(int32_t population) const
{
  int32_t percent = 0;
  if (population > 0) {
    int32_t coverage = mWorkingLibraries * COVERAGE_PER_LIBRARY;
    percent = static_cast<int>(static_cast<float>(coverage) / population * 100);
  }
  return percent;
}

int32_t EducationData::schoolCoverage(int32_t population) const
{
  int32_t percent = 0;
  if (population > 0) {
    int32_t coverage = mWorkingSchools * COVERAGE_PER_SCHOOL;
    percent = static_cast<int>(static_cast<float>(coverage) / population * 100);
  }
  return percent;
}

void EducationData::setTotalAcademies(int32_t value)
{
  mTotalAcademies = value;
  emit changed();
}

void EducationData::setTotalLibraries(int32_t value)
{
  mTotalLibraries = value;
  emit changed();
}

void EducationData::setTotalSchools(int32_t value)
{
  mTotalSchools = value;
  emit changed();
}

void EducationData::setWorkingAcademies(int32_t value)
{
  mWorkingAcademies = value;
  emit changed();
}

void EducationData::setWorkingLibraries(int32_t value)
{
  mWorkingLibraries = value;
  emit changed();
}

void EducationData::setWorkingSchools(int32_t value)
{
  mWorkingSchools = value;
  emit changed();
}

int32_t EducationData::totalAcademies() const
{
  return mTotalAcademies;
}

int32_t EducationData::totalLibraries() const
{
  return mTotalLibraries;
}

int32_t EducationData::totalSchools() const
{
  return mTotalSchools;
}

int32_t EducationData::workingAcademies() const
{
  return mWorkingAcademies;
}

int32_t EducationData::workingLibraries() const
{
  return mWorkingLibraries;
}

int32_t EducationData::workingSchools() const
{
  return mWorkingSchools;
}
