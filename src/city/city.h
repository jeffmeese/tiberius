#ifndef CITY_H
#define CITY_H

#include "tiberius.h"

#include <memory>

class BuildingData;
class EducationData;
class EntertainmentData;
class FigureData;
class FinanceData;
class HealthData;
class ImperialData;
class LaborData;
class MilitaryData;
class PopulationData;
class RatingsData;
class ReligionData;
class TradeData;

class City
{
public:
  TIBERIUS_LIB_DECL City();
  TIBERIUS_LIB_DECL ~City();

public:
  TIBERIUS_LIB_DECL BuildingData * buildingData();
  TIBERIUS_LIB_DECL const BuildingData * buildingData() const;
  TIBERIUS_LIB_DECL EducationData * educationData();
  TIBERIUS_LIB_DECL const EducationData * educationData() const;
  TIBERIUS_LIB_DECL EntertainmentData * entertainmentData();
  TIBERIUS_LIB_DECL const EntertainmentData * entertainmentData() const;
  TIBERIUS_LIB_DECL FigureData * figureData();
  TIBERIUS_LIB_DECL const FigureData * figureData() const;
  TIBERIUS_LIB_DECL FinanceData * financeData();
  TIBERIUS_LIB_DECL const FinanceData * financeData() const;
  TIBERIUS_LIB_DECL HealthData * healthData();
  TIBERIUS_LIB_DECL const HealthData * healthData() const;
  TIBERIUS_LIB_DECL ImperialData * imperialData();
  TIBERIUS_LIB_DECL const ImperialData * imperialData() const;
  TIBERIUS_LIB_DECL LaborData * laborData();
  TIBERIUS_LIB_DECL const LaborData * laborData() const;
  TIBERIUS_LIB_DECL MilitaryData * militaryData();
  TIBERIUS_LIB_DECL const MilitaryData * militaryData() const;
  TIBERIUS_LIB_DECL PopulationData * populationData();
  TIBERIUS_LIB_DECL const PopulationData * populationData() const;
  TIBERIUS_LIB_DECL RatingsData * ratingsData();
  TIBERIUS_LIB_DECL const RatingsData * ratingsData() const;
  TIBERIUS_LIB_DECL ReligionData * religionData();
  TIBERIUS_LIB_DECL const ReligionData * religionData() const;
  TIBERIUS_LIB_DECL TradeData * tradeData();
  TIBERIUS_LIB_DECL const TradeData * tradeData() const;

private:
  std::unique_ptr<BuildingData> mBuildingData;
  std::unique_ptr<EducationData> mEducationData;
  std::unique_ptr<EntertainmentData> mEntertainmentData;
  std::unique_ptr<FigureData> mFigureData;
  std::unique_ptr<FinanceData> mFinanceData;
  std::unique_ptr<HealthData> mHealthData;
  std::unique_ptr<ImperialData> mImperialData;
  std::unique_ptr<LaborData> mLaborData;
  std::unique_ptr<MilitaryData> mMilitaryData;
  std::unique_ptr<PopulationData> mPopulationData;
  std::unique_ptr<RatingsData> mRatingsData;
  std::unique_ptr<ReligionData> mReligionData;
  std::unique_ptr<TradeData> mTradeData;
};

inline BuildingData * City::buildingData()
{
  return mBuildingData.get();
}

inline const BuildingData * City::buildingData() const
{
  return mBuildingData.get();
}

inline EducationData * City::educationData()
{
  return mEducationData.get();
}

inline const EducationData * City::educationData() const
{
  return mEducationData.get();
}

inline EntertainmentData * City::entertainmentData()
{
  return mEntertainmentData.get();
}

inline const EntertainmentData * City::entertainmentData() const
{
  return mEntertainmentData.get();
}

inline FigureData * City::figureData()
{
  return mFigureData.get();
}

inline const FigureData * City::figureData() const
{
  return mFigureData.get();
}

inline FinanceData * City::financeData()
{
  return mFinanceData.get();
}

inline const FinanceData * City::financeData() const
{
  return mFinanceData.get();
}

inline HealthData * City::healthData()
{
  return mHealthData.get();
}

inline const HealthData * City::healthData() const
{
  return mHealthData.get();
}

inline ImperialData * City::imperialData()
{
  return mImperialData.get();
}

inline const ImperialData * City::imperialData() const
{
  return mImperialData.get();
}

inline LaborData * City::laborData()
{
  return mLaborData.get();
}

inline const LaborData * City::laborData() const
{
  return mLaborData.get();
}

inline MilitaryData * City::militaryData()
{
  return mMilitaryData.get();
}

inline const MilitaryData * City::militaryData() const
{
  return mMilitaryData.get();
}

inline PopulationData * City::populationData()
{
  return mPopulationData.get();
}

inline const PopulationData * City::populationData() const
{
  return mPopulationData.get();
}

inline RatingsData * City::ratingsData()
{
  return mRatingsData.get();
}

inline const RatingsData * City::ratingsData() const
{
  return mRatingsData.get();
}

inline ReligionData * City::religionData()
{
  return mReligionData.get();
}

inline const ReligionData * City::religionData() const
{
  return mReligionData.get();
}

inline TradeData * City::tradeData()
{
  return mTradeData.get();
}

inline const TradeData * City::tradeData() const
{
  return mTradeData.get();
}

#endif // CITY_H
