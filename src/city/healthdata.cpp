#include "healthdata.h"

HealthData::HealthData()
{
  mHealthAdvice = 7;
  mTotalBarbers = mWorkingBarbers = 0;
  mTotalBathHouses = mWorkingBathHouses = 0;
  mTotalClinics = mWorkingClinics = 0;
  mTotalHospitals = mWorkingHospitals = 1;
}

int32_t HealthData::healthAdvice() const
{
  return mHealthAdvice;
}

int32_t HealthData::healthScore() const
{
  return 70;
}

int32_t HealthData::hosptialCoverage(int32_t population) const
{
  int32_t percent = 0;
  if (population > 0) {
    int32_t coverage = mWorkingHospitals * COVERARGE_PER_HOSPITAL;
    percent = static_cast<int>(static_cast<float>(coverage) / population * 100);
  }
  return percent;
}

void HealthData::setHealthAdvice(int32_t value)
{
  mHealthAdvice = value;
  emit changed();
}

void HealthData::setTotalBarbers(int32_t value)
{
  mTotalBarbers = value;
  emit changed();
}

void HealthData::setTotalBaths(int32_t value)
{
  mTotalBathHouses = value;
  emit changed();
}

void HealthData::setTotalClincs(int32_t value)
{
  mTotalClinics = value;
  emit changed();
}

void HealthData::setTotalHospitals(int32_t value)
{
  mTotalHospitals = value;
  emit changed();
}

void HealthData::setWorkingBarbers(int32_t value)
{
  mWorkingBarbers = value;
  emit changed();
}

void HealthData::setWorkingBaths(int32_t value)
{
  mWorkingBathHouses = value;
  emit changed();
}

void HealthData::setWorkingClincs(int32_t value)
{
  mWorkingClinics = value;
  emit changed();
}

void HealthData::setWorkingHospitals(int32_t value)
{
  mWorkingHospitals = value;
  emit changed();
}

int32_t HealthData::totalBarbers() const
{
  return mTotalBarbers;
}

int32_t HealthData::totalBathHouses() const
{
  return mTotalBathHouses;
}

int32_t HealthData::totalClinics() const
{
  return mTotalClinics;
}

int32_t HealthData::totalHospitals() const
{
  return mTotalHospitals;
}

int32_t HealthData::workingBarbers() const
{
  return mWorkingBarbers;
}

int32_t HealthData::workingBathHouses() const
{
  return mWorkingBathHouses;
}

int32_t HealthData::workingClinics() const
{
  return mWorkingClinics;
}

int32_t HealthData::workingHospitals() const
{
  return mWorkingHospitals;
}
