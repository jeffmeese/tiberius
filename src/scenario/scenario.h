#ifndef MISSION_H
#define MISSION_H

#include "tiberius.h"

#include "map/grid.h"

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

class DemandChange;
class Earthquake;
class EmperorChange;
class EmperorRequest;
class Goal;
class Invasion;
class Location;
class PriceChange;

class Scenario
{
public:
  TIBERIUS_LIB_DECL Scenario();
  TIBERIUS_LIB_DECL ~Scenario();

public:
  TIBERIUS_LIB_DECL QString briefing() const;
  TIBERIUS_LIB_DECL int32_t cameraX() const;
  TIBERIUS_LIB_DECL int32_t cameraY() const;
  TIBERIUS_LIB_DECL int32_t campaignMission() const;
  TIBERIUS_LIB_DECL QString campaignPlayerName() const;
  TIBERIUS_LIB_DECL int32_t campaignRank() const;
  TIBERIUS_LIB_DECL int8_t climateId() const;
  TIBERIUS_LIB_DECL bool custom() const;
  TIBERIUS_LIB_DECL QString description() const;
  TIBERIUS_LIB_DECL bool emperorChange() const;
  TIBERIUS_LIB_DECL int16_t emperorChangeYear() const;
  TIBERIUS_LIB_DECL bool empireExpanded() const;
  TIBERIUS_LIB_DECL int32_t empireExpansionYear() const;
  TIBERIUS_LIB_DECL uint8_t empireLocation() const;
  TIBERIUS_LIB_DECL int32_t enemyId() const;
  TIBERIUS_LIB_DECL int8_t enemyTravelMonths() const;
  TIBERIUS_LIB_DECL bool floodedClayPits() const;
  TIBERIUS_LIB_DECL bool flotsam() const;
  TIBERIUS_LIB_DECL bool gladiatorRevolt() const;
  TIBERIUS_LIB_DECL int16_t gladiatorRevoltYear() const;
  TIBERIUS_LIB_DECL int16_t imageId() const;
  TIBERIUS_LIB_DECL int32_t initialFavor() const;
  TIBERIUS_LIB_DECL int32_t initialFunds() const;
  TIBERIUS_LIB_DECL int8_t initialRank() const;
  TIBERIUS_LIB_DECL bool ironMineCollapse() const;
  TIBERIUS_LIB_DECL bool landTradeProblem() const;
  TIBERIUS_LIB_DECL int32_t losingTime() const;
  TIBERIUS_LIB_DECL bool losingTimeEnabled() const;
  TIBERIUS_LIB_DECL int32_t mapGridSize() const;
  TIBERIUS_LIB_DECL int32_t mapGridStart() const;
  TIBERIUS_LIB_DECL int32_t mapHeight() const;
  TIBERIUS_LIB_DECL int32_t mapWidth() const;
  TIBERIUS_LIB_DECL bool milestone25Enabled() const;
  TIBERIUS_LIB_DECL int32_t milestone25Year() const;
  TIBERIUS_LIB_DECL bool milestone50Enabled() const;
  TIBERIUS_LIB_DECL int32_t milestone50Year() const;
  TIBERIUS_LIB_DECL bool milestone75Enabled() const;
  TIBERIUS_LIB_DECL int32_t milestone75Year() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL int32_t nativeCropsId() const;
  TIBERIUS_LIB_DECL int32_t nativeMeetingId() const;
  TIBERIUS_LIB_DECL int32_t nativeHutId() const;
  TIBERIUS_LIB_DECL bool openPlay() const;
  TIBERIUS_LIB_DECL int8_t openPlayId() const;
  TIBERIUS_LIB_DECL bool peaceful() const;
  TIBERIUS_LIB_DECL QString playerName() const;
  TIBERIUS_LIB_DECL int32_t rescueLoan() const;
  TIBERIUS_LIB_DECL int8_t romanTravelMonths() const;
  TIBERIUS_LIB_DECL bool romeLowersWages() const;
  TIBERIUS_LIB_DECL bool romeRaisesWages() const;
  TIBERIUS_LIB_DECL bool romeSuppliesWheat() const;
  TIBERIUS_LIB_DECL bool saved() const;
  TIBERIUS_LIB_DECL QString scenarioName() const;
  TIBERIUS_LIB_DECL bool seaTradeProblem() const;
  TIBERIUS_LIB_DECL int32_t startYear() const;
  TIBERIUS_LIB_DECL int32_t survivalTime() const;
  TIBERIUS_LIB_DECL bool survivalTimeEnabled() const;
  TIBERIUS_LIB_DECL int totalDemandChanges() const;
  TIBERIUS_LIB_DECL int totalFishingPoints() const;
  TIBERIUS_LIB_DECL int totalHerdPoints() const;
  TIBERIUS_LIB_DECL int totalInvasions() const;
  TIBERIUS_LIB_DECL int totalInvasionPoints() const;
  TIBERIUS_LIB_DECL int totalPriceChanges() const;
  TIBERIUS_LIB_DECL int totalRequests() const;
  TIBERIUS_LIB_DECL bool waterContamination() const;

  // Grids
public:
  TIBERIUS_LIB_DECL UnsignedByteGrid * edgeGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * edgeGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * elevationGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * elevationGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * graphicGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * graphicGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * randomGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * randomGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * terrainGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * terrainGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * terrainRandomGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * terrainRandomGrid() const;

  // Goals
public:
  TIBERIUS_LIB_DECL Goal * cultureGoal();
  TIBERIUS_LIB_DECL const Goal * cultureGoal() const;
  TIBERIUS_LIB_DECL Goal * favorGoal();
  TIBERIUS_LIB_DECL const Goal * favorGoal() const;
  TIBERIUS_LIB_DECL Goal * peaceGoal();
  TIBERIUS_LIB_DECL const Goal * peaceGoal() const;
  TIBERIUS_LIB_DECL Goal * prosperityGoal();
  TIBERIUS_LIB_DECL const Goal * prosperityGoal() const;
  TIBERIUS_LIB_DECL Goal * populationGoal();
  TIBERIUS_LIB_DECL const Goal * populationGoal() const;

public:
  TIBERIUS_LIB_DECL DemandChange * getDemandChange(int index);
  TIBERIUS_LIB_DECL const DemandChange * getDemandChange(int index) const;
  TIBERIUS_LIB_DECL Location * getFishingPoint(int index);
  TIBERIUS_LIB_DECL const Location * getFishingPoint(int index) const;
  TIBERIUS_LIB_DECL Location * getHerdPoint(int index);
  TIBERIUS_LIB_DECL const Location * getHerdPoint(int index) const;
  TIBERIUS_LIB_DECL Invasion * getInvasion(int index);
  TIBERIUS_LIB_DECL const Invasion * getInvasion(int index) const;
  TIBERIUS_LIB_DECL Location * getInvasionPoint(int index);
  TIBERIUS_LIB_DECL const Location * getInvasionPoint(int index) const;
  TIBERIUS_LIB_DECL PriceChange * getPriceChange(int index);
  TIBERIUS_LIB_DECL const PriceChange * getPriceChange(int index) const;
  TIBERIUS_LIB_DECL EmperorRequest * getRequest(int index);
  TIBERIUS_LIB_DECL const EmperorRequest * getRequest(int index) const;
  TIBERIUS_LIB_DECL void setBriefDescription(const QString & value);
  TIBERIUS_LIB_DECL void setCampaignMission(int32_t value);
  TIBERIUS_LIB_DECL void setCampaignRank(int32_t value);
  TIBERIUS_LIB_DECL void setInitialFavor(int32_t value);
  TIBERIUS_LIB_DECL void setInitialSavings(int32_t value);
  TIBERIUS_LIB_DECL void setName(const QString & value);
  TIBERIUS_LIB_DECL void setOpenPlay(bool value);
  TIBERIUS_LIB_DECL void setPeaceful(bool value);
  TIBERIUS_LIB_DECL void setPlayerName(const QString & name);
  TIBERIUS_LIB_DECL void setScenarioName(const QString & name);

public:
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream, bool includeGrids = true);
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream, bool includeGrids = true) const;

public:
  static const int MAX_ALLOWED_BUILDINGS = 50;
  static const int MAX_DEMAND_CHANGES = 20;
  static const int MAX_FISHING_POINTS = 8;
  static const int MAX_HERD_POINTS = 4;
  static const int MAX_INVASIONS = 20;
  static const int MAX_INVASION_POINTS = 8;
  static const int MAX_MISSION_BRIEFING = 522;
  static const int MAX_MISSION_DESCRIPTION = 64;
  static const int MAX_PRICE_CHANGES = 20;
  static const int MAX_REQUESTS = 20;

private:
  void init();

private:
  using ByteGridPtr = std::unique_ptr<UnsignedByteGrid>;
  using DemandChangePtr = std::unique_ptr<DemandChange>;
  using EarthquakePtr = std::unique_ptr<Earthquake>;
  using EmperorRequestPtr = std::unique_ptr<EmperorRequest>;
  using GoalPtr = std::unique_ptr<Goal>;
  using InvasionPtr = std::unique_ptr<Invasion>;
  using LocationPtr = std::unique_ptr<Location>;
  using PriceChangePtr = std::unique_ptr<PriceChange>;
  using ShortGridPtr = std::unique_ptr<UnsignedShortGrid>;
  using DemandChangeVector = std::vector<DemandChangePtr>;
  using EmperorRequestVector = std::vector<EmperorRequestPtr>;
  using InvasionVector = std::vector<InvasionPtr>;
  using PriceChangeVector = std::vector<PriceChangePtr>;
  using LocationVector = std::vector<LocationPtr>;
  using AllowedBuildingVector = std::vector<int16_t>;

private:
  bool mCustom;
  bool mEmperorChange;
  bool mEmpireExpanded;
  bool mFloodedClayPits;
  bool mFlotsam;
  bool mGladiatorRevolt;
  bool mIronMineCollapse;
  bool mLandTradeProblem;
  bool mLosingTimeEnabled;
  bool mMilestone25Enabled;
  bool mMilestone50Enabled;
  bool mMilestone75Enabled;
  bool mOpenPlay;
  bool mPeaceful;
  bool mRomeLowersWages;
  bool mRomeRaisesWages;
  bool mRomeSuppliesWheat;
  bool mSaved;
  bool mSeaTradeProblem;
  bool mSurvivalTimeEnabled;
  bool mWaterContamination;

  int8_t mClimateId;
  uint8_t mEmpireLocation;
  int8_t mEnemyArmyTravelMonths;
  int8_t mInitialRank;
  int8_t mOpenPlayId;
  int8_t mRomanArmyTravelMonths;

  int16_t mEmperorChangeYear;
  int16_t mGladiatorRevoltYear;
  int16_t mImageId;
  int32_t mStartYear;

  int32_t mCameraX;
  int32_t mCameraY;
  int32_t mCampaignMission;
  int32_t mEmpireExpansionYear;
  int32_t mEnemyId;
  int32_t mInitialFavor;
  int32_t mInitialFunds;
  int32_t mInitialPersonalSavings;
  int32_t mLosingTime;
  int32_t mMapGridSize;
  int32_t mMapGridStart;
  int32_t mMapHeight;
  int32_t mMapWidth;
  int16_t mMilestone25Year;
  int16_t mMilestone50Year;
  int16_t mMilestone75Year;
  int32_t mNativeCropsId;
  int32_t mNativeMeetingId;
  int32_t mNativeHutId;
  int32_t mRandomSeed1;
  int32_t mRandomSeed2;
  int32_t mRescueLoan;
  int32_t mSurvivalTime;

  ByteGridPtr mEdgeGrid;
  ByteGridPtr mElevationGrid;
  ByteGridPtr mRandomGrid;
  ByteGridPtr mTerrainRandomGrid;
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
  ShortGridPtr mGraphicGrid;
  ShortGridPtr mTerrainGrid;
  AllowedBuildingVector mAllowedBuildings;
  DemandChangeVector mDemandChanges;
  EmperorRequestVector mEmperorRequests;
  InvasionVector mInvasions;
  PriceChangeVector mPriceChanges;
  LocationVector mHerdPoints;
  LocationVector mInvasionPoints;
  LocationVector mFishingPoints;
  QString mCampaignPlayerName;
  QString mDescription;
  QString mBriefing;
  QString mName;
  QString mPlayerName;
  QString mScenarioName;
};

#endif // MISSION_H
