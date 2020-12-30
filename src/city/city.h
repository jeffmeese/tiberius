#ifndef CITY_H
#define CITY_H

#include "tiberius.h"

#include <memory>

class BuildingData;
class Camera;
class Data;
class EducationData;
class EmpireData;
class EntertainmentData;
class FinanceData;
class HealthData;
class ImperialData;
class LaborData;
class MilitaryData;
class Player;
class PopulationData;
class RatingsData;
class ReligionData;
class ResourceData;
class RouteData;
class ScenarioData;
class TradeData;
class WalkerData;

class City
{
public:
  enum class Orientation
  {
    North = 0,
    South = 1,
    East = 2,
    West = 3
  };

public:
  TIBERIUS_LIB_DECL City();
  TIBERIUS_LIB_DECL ~City();

public:
  TIBERIUS_LIB_DECL Camera * camera();
  TIBERIUS_LIB_DECL const Camera * camera() const;
  TIBERIUS_LIB_DECL Orientation orientation() const;
  TIBERIUS_LIB_DECL void setOrientation(Orientation value);

public:
  TIBERIUS_LIB_DECL BuildingData * buildingData();
  TIBERIUS_LIB_DECL const BuildingData * buildingData() const;
  TIBERIUS_LIB_DECL Data * data();
  TIBERIUS_LIB_DECL const Data * data() const;
  TIBERIUS_LIB_DECL EducationData * educationData();
  TIBERIUS_LIB_DECL const EducationData * educationData() const;
  TIBERIUS_LIB_DECL EmpireData * empireData();
  TIBERIUS_LIB_DECL const EmpireData * empireData() const;
  TIBERIUS_LIB_DECL EntertainmentData * entertainmentData();
  TIBERIUS_LIB_DECL const EntertainmentData * entertainmentData() const;
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
  TIBERIUS_LIB_DECL ResourceData * resourceData();
  TIBERIUS_LIB_DECL const ResourceData * resourceData() const;
  TIBERIUS_LIB_DECL RouteData * routeData();
  TIBERIUS_LIB_DECL const RouteData * routeData() const;
  TIBERIUS_LIB_DECL ScenarioData * scenarioData();
  TIBERIUS_LIB_DECL const ScenarioData * scenarioData() const;
  TIBERIUS_LIB_DECL TradeData * tradeData();
  TIBERIUS_LIB_DECL const TradeData * tradeData() const;
  TIBERIUS_LIB_DECL WalkerData * walkerData();
  TIBERIUS_LIB_DECL const WalkerData * walkerData() const;

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream, Player * player);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  Orientation mOrientation;
  std::unique_ptr<BuildingData> mBuildingData;
  std::unique_ptr<Camera> mCamera;
  std::unique_ptr<Data> mData;
  std::unique_ptr<EducationData> mEducationData;
  std::unique_ptr<EmpireData> mEmpireData;
  std::unique_ptr<EntertainmentData> mEntertainmentData;
  std::unique_ptr<FinanceData> mFinanceData;
  std::unique_ptr<HealthData> mHealthData;
  std::unique_ptr<ImperialData> mImperialData;
  std::unique_ptr<LaborData> mLaborData;
  std::unique_ptr<MilitaryData> mMilitaryData;
  std::unique_ptr<PopulationData> mPopulationData;
  std::unique_ptr<RatingsData> mRatingsData;
  std::unique_ptr<ReligionData> mReligionData;
  std::unique_ptr<ResourceData> mResourceData;
  std::unique_ptr<RouteData> mRouteData;
  std::unique_ptr<ScenarioData> mScenarioData;
  std::unique_ptr<TradeData> mTradeData;
  std::unique_ptr<WalkerData> mWalkerData;
};

#endif // CITY_H
