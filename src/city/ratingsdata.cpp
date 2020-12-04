#include "ratingsdata.h"

RatingsData::RatingsData()
{
  mCulture = mFavor = mPeace = mProsperity = 0;
  mTargetCulture = mTargetFavor = mTargetPeace = mTargetPopulation = mTargetProsperity = 0;
  mCulture = 95;
  mFavor = 95;
  mPeace = 95;
  mProsperity = 95;
  mTargetCulture = 60;
  mTargetFavor = 50;
  mTargetPeace = 45;
  mTargetProsperity = 35;
  mTargetPopulation = 2500;
}

int32_t RatingsData::culture() const
{
  return mCulture;
}

int32_t RatingsData::favor() const
{
  return mFavor;
}

int32_t RatingsData::peace() const
{
  return mPeace;
}

int32_t RatingsData::prosperity() const
{
  return mProsperity;
}

void RatingsData::setCulture(int32_t value)
{
  mCulture = value;
  emit changed();
}

void RatingsData::setFavor(int32_t value)
{
  mFavor = value;
  emit changed();
}

void RatingsData::setPeace(int32_t value)
{
  mPeace = value;
  emit changed();
}

void RatingsData::setProsperity(int32_t value)
{
  mProsperity = value;
  emit changed();
}

void RatingsData::setTargetCulture(int32_t value)
{
  mTargetCulture = value;
  emit changed();
}

void RatingsData::setTargetFavor(int32_t value)
{
  mTargetFavor = value;
  emit changed();
}

void RatingsData::setTargetPeace(int32_t value)
{
  mTargetPeace = value;
  emit changed();
}

void RatingsData::setTargetPopulation(int32_t value)
{
  mTargetPopulation = value;
  emit changed();
}

void RatingsData::setTargetProsperity(int32_t value)
{
  mTargetProsperity = value;
  emit changed();
}

int32_t RatingsData::targetCulture() const
{
  return mTargetCulture;
}

int32_t RatingsData::targetFavor() const
{
  return mTargetFavor;
}

int32_t RatingsData::targetPeace() const
{
  return mTargetPeace;
}

int32_t RatingsData::targetPopulation() const
{
  return mTargetPopulation;
}

int32_t RatingsData::targetProsperity() const
{
  return mTargetProsperity;
}

