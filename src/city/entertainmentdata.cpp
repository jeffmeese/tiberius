#include "entertainmentdata.h"

#include "application/tiberiusapplication.h"

#include "entertainment/festival.h"

#include "language/language.h"
#include "language/stringdata.h"

EntertainmentData::EntertainmentData()
{
  mTotalAmpitheaters = mTotalColosseums = mTotalHippodromes = mTotalTheaters = 0;
  mWorkingAmpitheaters = mWorkingColosseums = mWorkingHippodromes = mWorkingTheaters = 0;
  mAmpitheaterShows = mColosseumShows = mHippodromeShows = mTheaterShows = 0;
  mFestivalGod = God::Type::Ceres;

  mEntertainmentNeeds = 0;
  mFestivalSentiment = 0;
  mMonthsSinceFestival = 0;
  mTotalTheaters = mWorkingTheaters = 2;
  mTotalHippodromes = mWorkingHippodromes = 1;
}

EntertainmentData::~EntertainmentData()
{

}

int32_t EntertainmentData::ampitheaterCapacity() const
{
  return mTotalAmpitheaters * COVERAGE_PER_AMPITHEATER;
}

int32_t EntertainmentData::ampitheaterCoverage(int32_t population) const
{
  return calcPercent(ampitheaterCapacity(), population);
}

int32_t EntertainmentData::ampitheaterShows() const
{
  return mAmpitheaterShows;
}

int32_t EntertainmentData::colosseumCapacity() const
{
  return mWorkingColosseums * COVERAGE_PER_COLOSSEUM;
}

int32_t EntertainmentData::colosseumCoverage(int32_t population) const
{
  return calcPercent(colosseumCapacity(), population);
}

int32_t EntertainmentData::colosseumShows() const
{
  return mColosseumShows;
}

int32_t EntertainmentData::enterainmentNeeds() const
{
  return mEntertainmentNeeds;
}

Festival * EntertainmentData::festival() const
{
  return mFestival.get();
}

God::Type EntertainmentData::festivalGod() const
{
  return mFestivalGod;
}

int32_t EntertainmentData::festivalSentiment() const
{
  return mFestivalSentiment;
}

int32_t EntertainmentData::hippodromeCoverage(int32_t) const
{
  return mWorkingHippodromes > 0 ? 100 : 0;
}

int32_t EntertainmentData::hippodromeShows() const
{
  return mHippodromeShows;
}

int32_t EntertainmentData::monthsSinceFestival() const
{
  return mMonthsSinceFestival;
}

QString EntertainmentData::needsString() const
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(58, 7+mEntertainmentNeeds);
}

void EntertainmentData::setAmpitheaterShows(int32_t value)
{
  mAmpitheaterShows = value;
  emit changed();
}

void EntertainmentData::setColosseumShows(int32_t value)
{
  mColosseumShows = value;
  emit changed();
}

void EntertainmentData::setEntertainmentNeeds(int32_t value)
{
  mEntertainmentNeeds = value;
  emit changed();
}

void EntertainmentData::setFestival(std::unique_ptr<Festival> festival)
{
  mFestival = std::move(festival);
  emit changed();
}

void EntertainmentData::setFestivalGod(God::Type type)
{
  mFestivalGod = type;
  emit changed();
}

void EntertainmentData::setFestivalSentiment(int32_t value)
{
  mFestivalSentiment = value;
  emit changed();
}

void EntertainmentData::setHippodromeShows(int32_t value)
{
  mHippodromeShows = value;
  emit changed();
}

void EntertainmentData::setMonthsSinceFestival(int32_t value)
{
  mMonthsSinceFestival = value;
  emit changed();
}

void EntertainmentData::setTheaterShows(int32_t value)
{
  mTheaterShows = value;
  emit changed();
}

void EntertainmentData::setTotalAmpitheaters(int32_t value)
{
  mTotalAmpitheaters = value;
  emit changed();
}

void EntertainmentData::setTotalColosseums(int32_t value)
{
  mTotalColosseums = value;
  emit changed();
}

void EntertainmentData::setTotalHippodromes(int32_t value)
{
  mTotalHippodromes = value;
  emit changed();
}

void EntertainmentData::setTotalTheaters(int32_t value)
{
  mTotalTheaters = value;
  emit changed();
}

void EntertainmentData::setWorkingAmpitheaters(int32_t value)
{
  mWorkingAmpitheaters = value;
  emit changed();
}

void EntertainmentData::setWorkingColosseums(int32_t value)
{
  mWorkingColosseums = value;
}

void EntertainmentData::setWorkingHippodromes(int32_t value)
{
  mWorkingHippodromes = value;
}

void EntertainmentData::setWorkingTheaters(int32_t value)
{
  mWorkingTheaters = value;
}

int32_t EntertainmentData::theaterCapacity() const
{
  return mWorkingTheaters * COVERAGE_PER_THEATER;
}

int32_t EntertainmentData::theaterCoverage(int32_t population) const
{
  return calcPercent(theaterCapacity(), population);
}

int32_t EntertainmentData::theaterShows() const
{
  return mTheaterShows;
}

int32_t EntertainmentData::totalAmpitheaters() const
{
  return mTotalAmpitheaters;
}

int32_t EntertainmentData::totalColosseums() const
{
  return mTotalColosseums;
}

int32_t EntertainmentData::totalHippodromes() const
{
  return mTotalHippodromes;
}

int32_t EntertainmentData::totalTheaters() const
{
  return mTotalTheaters;
}

int32_t EntertainmentData::workingAmpitheaters() const
{
  return mWorkingAmpitheaters;
}

int32_t EntertainmentData::workingColosseums() const
{
  return mWorkingColosseums;
}

int32_t EntertainmentData::workingHippodromes() const
{
  return mWorkingHippodromes;
}

int32_t EntertainmentData::workingTheaters() const
{
  return mWorkingTheaters;
}

