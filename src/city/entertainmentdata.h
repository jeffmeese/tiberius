#ifndef ENTERTAINMENTDATA_H
#define ENTERTAINMENTDATA_H

#include "datamodel.h"

#include "religion/god.h"

#include <QString>

#include <memory>

class Festival;
class EntertainmentData
    : public DataModel
{
public:
  static const int32_t COVERAGE_PER_THEATER = 500;
  static const int32_t COVERAGE_PER_AMPITHEATER = 750;
  static const int32_t COVERAGE_PER_COLOSSEUM = 1000;

public:
  TIBERIUS_LIB_DECL EntertainmentData();
  TIBERIUS_LIB_DECL ~EntertainmentData();

public:
  TIBERIUS_LIB_DECL int32_t ampitheaterShows() const;
  TIBERIUS_LIB_DECL int32_t colosseumShows() const;
  TIBERIUS_LIB_DECL int32_t enterainmentNeeds() const;
  TIBERIUS_LIB_DECL Festival * festival() const;
  TIBERIUS_LIB_DECL God::Type festivalGod() const;
  TIBERIUS_LIB_DECL int32_t festivalSentiment() const;
  TIBERIUS_LIB_DECL int32_t hippodromeShows() const;
  TIBERIUS_LIB_DECL int32_t monthsSinceFestival() const;
  TIBERIUS_LIB_DECL int32_t theaterShows() const;
  TIBERIUS_LIB_DECL int32_t totalAmpitheaters() const;
  TIBERIUS_LIB_DECL int32_t totalColosseums() const;
  TIBERIUS_LIB_DECL int32_t totalHippodromes() const;
  TIBERIUS_LIB_DECL int32_t totalTheaters() const;
  TIBERIUS_LIB_DECL int32_t workingAmpitheaters() const;
  TIBERIUS_LIB_DECL int32_t workingColosseums() const;
  TIBERIUS_LIB_DECL int32_t workingHippodromes() const;
  TIBERIUS_LIB_DECL int32_t workingTheaters() const;
  TIBERIUS_LIB_DECL void setAmpitheaterShows(int32_t value);
  TIBERIUS_LIB_DECL void setColosseumShows(int32_t value);
  TIBERIUS_LIB_DECL void setEntertainmentNeeds(int32_t value);
  TIBERIUS_LIB_DECL void setFestival(std::unique_ptr<Festival> festival);
  TIBERIUS_LIB_DECL void setFestivalGod(God::Type type);
  TIBERIUS_LIB_DECL void setFestivalSentiment(int32_t value);
  TIBERIUS_LIB_DECL void setHippodromeShows(int32_t value);
  TIBERIUS_LIB_DECL void setMonthsSinceFestival(int32_t value);
  TIBERIUS_LIB_DECL void setTheaterShows(int32_t value);
  TIBERIUS_LIB_DECL void setTotalAmpitheaters(int32_t value);
  TIBERIUS_LIB_DECL void setTotalColosseums(int32_t value);
  TIBERIUS_LIB_DECL void setTotalHippodromes(int32_t value);
  TIBERIUS_LIB_DECL void setTotalTheaters(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingAmpitheaters(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingColosseums(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingHippodromes(int32_t value);
  TIBERIUS_LIB_DECL void setWorkingTheaters(int32_t value);

public:
  TIBERIUS_LIB_DECL int32_t ampitheaterCapacity() const;
  TIBERIUS_LIB_DECL int32_t ampitheaterCoverage(int32_t population) const;
  TIBERIUS_LIB_DECL int32_t colosseumCapacity() const;
  TIBERIUS_LIB_DECL int32_t colosseumCoverage(int32_t population) const;
  TIBERIUS_LIB_DECL int32_t hippodromeCoverage(int32_t population) const;
  TIBERIUS_LIB_DECL QString needsString() const;
  TIBERIUS_LIB_DECL int32_t theaterCapacity() const;
  TIBERIUS_LIB_DECL int32_t theaterCoverage(int32_t population) const;

private:
  int32_t mAmpitheaterShows;
  int32_t mColosseumShows;
  int32_t mEntertainmentNeeds;
  int32_t mFestivalSentiment;
  int32_t mHippodromeShows;
  int32_t mMonthsSinceFestival;
  int32_t mTheaterShows;
  int32_t mTotalAmpitheaters;
  int32_t mTotalColosseums;
  int32_t mTotalHippodromes;
  int32_t mTotalTheaters;
  int32_t mWorkingAmpitheaters;
  int32_t mWorkingColosseums;
  int32_t mWorkingHippodromes;
  int32_t mWorkingTheaters;
  God::Type mFestivalGod;
  std::unique_ptr<Festival> mFestival;
};

#endif // ENTERTAINMENTDATA_H
