#ifndef SCENARIODATA_H
#define SCENARIODATA_H

#include "tiberius.h"

#include "resource/resource.h"

#include <memory>
#include <vector>

class Earthquake;
class EmperorRequest;
class Goal;
class Invasion;
class Location;
class PriceChange;

class ScenarioData
{
public:
  TIBERIUS_LIB_DECL ScenarioData();

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  using EarthquakePtr = std::unique_ptr<Earthquake>;
  using EmperorRequestPtr = std::unique_ptr<EmperorRequest>;
  using GoalPtr = std::unique_ptr<Goal>;
  using LocationPtr = std::unique_ptr<Location>;
  using AllowedBuildingVector = std::vector<int16_t>;
  using EmperorRequestVector = std::vector<EmperorRequestPtr>;
  using LocationVector = std::vector<LocationPtr>;


private:
  bool mEmperorChange; //
  bool mFloodedClayPits; //
  bool mGladiatorRevolt; //
  bool mIronMineCollapse; //
  bool mLandTradeProblem; //
  bool mRomeLowersWages; //
  bool mRomeRaisesWages; //
  bool mSeaTradeProblem; //
  bool mWaterContamination; //
  int16_t mMilestone25Year;
  int16_t mMilestone50Year;
  int16_t mMilestone75Year;
  int32_t mEmperorChangeYear;
  int32_t mEnemyId;
  int32_t mGladiatorRevoltYear;
  int32_t mMapHeight;
  int32_t mMapWidth;
  int32_t mRandomSeed1;
  int32_t mRandomSeed2;
  int32_t mRescueLoan;
  int32_t mStartingDate;
  int32_t mStartingFunds;
  int32_t mBuyPrices[Resource::MAX_RESOURCES];
  int32_t mSellPrices[Resource::MAX_RESOURCES];
  EarthquakePtr mEarthquake;
  GoalPtr mPopulationGoal;
  GoalPtr mProsperityGoal;
  GoalPtr mCultureGoal;
  GoalPtr mPeaceGoal;
  GoalPtr mFavorGoal;
  LocationPtr mEntryPoint;
  LocationPtr mExitPoint;
  LocationPtr mRiverEntryPoint;
  LocationPtr mRiverExitPoint;
  AllowedBuildingVector mAllowedBuildings;
  EmperorRequestVector mEmperorRequests;
  LocationVector mFishingPoints;
  LocationVector mHerdPoints;
  LocationVector mInvasionPoints;
  QString mMapDescription;
  QString mMapSubtitle;

};

#endif // SCENARIODATA_H
