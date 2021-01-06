#include "mission.h"

#include "demandchange.h"
#include "earthquake.h"
#include "emperorchange.h"
#include "emperorrequest.h"
#include "empireexpansion.h"
#include "gladiatorrevolt.h"
#include "goal.h"
#include "invasion.h"
#include "pricechange.h"

#include "core/streamio.h"

#include "map/location.h"

#include <QFile>

#include <sstream>
#include <stdexcept>

Mission::Mission()
{
  init();
}

Mission::~Mission()
{

}

int32_t Mission::campaignMission() const
{
  return mCampaignMission;
}

int32_t Mission::cameraX() const
{
  return mCameraX;
}

int32_t Mission::cameraY() const
{
  return mCameraY;
}

Goal * Mission::cultureGoal()
{
  return mCultureGoal.get();
}

const Goal * Mission::cultureGoal() const
{
  return mCultureGoal.get();
}

QString Mission::description() const
{
  return mDescription;
}

UnsignedByteGrid * Mission::edgeGrid()
{
  return mEdgeGrid.get();
}

const UnsignedByteGrid * Mission::edgeGrid() const
{
  return mEdgeGrid.get();
}

UnsignedByteGrid * Mission::elevationGrid()
{
  return mElevationGrid.get();
}

const UnsignedByteGrid * Mission::elevationGrid() const
{
  return mElevationGrid.get();
}

bool Mission::emperorChange() const
{
  return mEmperorChange;
}

int16_t Mission::emperorChangeYear() const
{
  return mEmperorChangeYear;
}

uint8_t Mission::empireLocation() const
{
  return mEmpireLocation;
}

int32_t Mission::enemyId() const
{
  return mEnemyId;
}

Goal * Mission::favorGoal()
{
  return mFavorGoal.get();
}

const Goal * Mission::favorGoal() const
{
  return mFavorGoal.get();
}

bool Mission::floodedClayPits() const
{
  return mFloodedClayPits;
}

bool Mission::flotsam() const
{
  return mFlotsam;
}

DemandChange * Mission::getDemandChange(int index)
{
  return mDemandChanges[index].get();
}

const DemandChange * Mission::getDemandChange(int index) const
{
  return mDemandChanges[index].get();
}

Location * Mission::getFishingPoint(int index)
{
  return mFishingPoints[index].get();
}

const Location * Mission::getFishingPoint(int index) const
{
  return mFishingPoints[index].get();
}

Location * Mission::getHerdPoint(int index)
{
  return mHerdPoints[index].get();
}

const Location * Mission::getHerdPoint(int index) const
{
  return mHerdPoints[index].get();
}

Invasion * Mission::getInvasion(int index)
{
  return mInvasions[index].get();
}

const Invasion * Mission::getInvasion(int index) const
{
  return mInvasions[index].get();
}

Location * Mission::getInvasionPoint(int index)
{
  return mInvasionPoints[index].get();
}

const Location * Mission::getInvasionPoint(int index) const
{
  return mInvasionPoints[index].get();
}

PriceChange * Mission::getPriceChange(int index)
{
  return mPriceChanges[index].get();
}

const PriceChange * Mission::getPriceChange(int index) const
{
  return mPriceChanges[index].get();
}

EmperorRequest * Mission::getRequest(int index)
{
  return mEmperorRequests[index].get();
}

const EmperorRequest * Mission::getRequest(int index) const
{
  return mEmperorRequests[index].get();
}

bool Mission::gladiatorRevolt() const
{
  return mGladiatorRevolt;
}

int16_t Mission::gladiatorRevoltYear() const
{
  return mGladiatorRevoltYear;
}

UnsignedShortGrid * Mission::graphicGrid()
{
  return mGraphicGrid.get();
}

const UnsignedShortGrid * Mission::graphicGrid() const
{
  return mGraphicGrid.get();
}

int16_t Mission::imageId() const
{
  return mImageId;
}

void Mission::init()
{
  mEmperorChange = false;
  mEmpireExpanded = false;
  mGladiatorRevolt = false;
  mOpenPlay = false;
  mFloodedClayPits = false;
  mFlotsam = false;
  mPeaceful = false;
  mIronMineCollapse = false;
  mLandTradeProblem = false;
  mLosingTimeEnabled = false;
  mMilestone25Enabled = false;
  mMilestone50Enabled = false;
  mMilestone75Enabled = false;
  mSeaTradeProblem = false;
  mRomeLowersWages = false;
  mRomeRaisesWages = false;
  mRomeSuppliesWheat = false;
  mSeaTradeProblem = false;
  mSurvivalTimeEnabled = false;
  mWaterContamination = false;

  mCameraX = 0;
  mCameraY = 0;
  mClimateId = 0;
  mEmpireLocation = 0;
  mEmperorChangeYear = 0;
  mEnemyId = 0;
  mImageId = 0;
  mInitialRank = 0;
  mLosingTime = 0;
  mSurvivalTime = 0;
  mMilestone25Year = 0;
  mMilestone50Year = 0;
  mMilestone75Year = 0;
  mRescueLoan = 0;
  mStartYear = 0;
  mInitialFunds = 0;
  mMapWidth = 0;
  mMapHeight = 0;
  mMapGridSize = 0;
  mMapGridStart = 0;
  mNativeHutId = 0;
  mNativeCropsId = 0;
  mNativeMeetingId = 0;
  mRomanArmyTravelMonths = 0;
  mEnemyArmyTravelMonths = 0;
  mEmpireExpansionYear = 0;

  mEdgeGrid.reset(new UnsignedByteGrid);
  mElevationGrid.reset(new UnsignedByteGrid);
  mRandomGrid.reset(new UnsignedByteGrid);
  mTerrainRandomGrid.reset(new UnsignedByteGrid);
  mGraphicGrid.reset(new UnsignedShortGrid);
  mTerrainGrid.reset(new UnsignedShortGrid);
  mEarthquake.reset(new Earthquake);
  mPopulationGoal.reset(new Goal);
  mProsperityGoal.reset(new Goal);
  mCultureGoal.reset(new Goal);
  mPeaceGoal.reset(new Goal);
  mFavorGoal.reset(new Goal);
  mEntryPoint.reset(new Location);
  mExitPoint.reset(new Location);
  mRiverEntryPoint.reset(new Location);
  mRiverExitPoint.reset(new Location);

  mAllowedBuildings.resize(Mission::MAX_ALLOWED_BUILDINGS);
  for (int i = 0; i < Mission::MAX_ALLOWED_BUILDINGS; i++) {
    mAllowedBuildings[i] = 0;
  }

  mEmperorRequests.resize(Mission::MAX_REQUESTS);
  for (int i = 0; i < Mission::MAX_REQUESTS; i++) {
    mEmperorRequests[i].reset(new EmperorRequest);
  }

  mInvasions.resize(Mission::MAX_INVASIONS);
  for (int i = 0; i < Mission::MAX_INVASIONS; i++) {
    mInvasions[i].reset(new Invasion);
  }

//  mPriceChanges.resize(Mission::MAX_PRICE_CHANGES);
//  for (int i = 0; i < Mission::MAX_PRICE_CHANGES; i++) {
//    mPriceChanges[i].reset(new PriceChange);
//  }

//  mHerdPoints.resize(Mission::MAX_HERD_POINTS);
//  for (int i = 0; i < Mission::MAX_HERD_POINTS; i++) {
//    mHerdPoints[i].reset(new Location);
//  }

//  mFishingPoints.resize(Mission::MAX_FISHING_POINTS);
//  for (int i = 0; i < Mission::MAX_FISHING_POINTS; i++) {
//    mFishingPoints[i].reset(new Location);
//  }

//  mInvasionPoints.resize(Mission::MAX_INVASION_POINTS);
//  for (int i = 0; i < Mission::MAX_INVASION_POINTS; i++) {
//    mInvasion*Points[i].reset(new Location);
//  }
}

int32_t Mission::initialFunds() const
{
  return mInitialFunds;
}

int8_t Mission::initialRank() const
{
  return mInitialRank;
}

bool Mission::ironMineCollapse() const
{
  return mIronMineCollapse;
}

bool Mission::landTradeProblem() const
{
  return mLandTradeProblem;
}

void Mission::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  loadFromStream(dataStream, false);
}

void Mission::loadFromStream(QDataStream &dataStream, bool compressedGrids)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  mGraphicGrid->loadFromDataStream(dataStream, 52488, compressedGrids);
  mEdgeGrid->loadFromDataStream(dataStream, 26244, compressedGrids);
  mTerrainGrid->loadFromDataStream(dataStream, 52488, compressedGrids);
  mTerrainRandomGrid->loadFromDataStream(dataStream, 26244, compressedGrids);
  mRandomGrid->loadFromDataStream(dataStream, 26244, compressedGrids);
  mElevationGrid->loadFromDataStream(dataStream, 26244, compressedGrids);

  mRandomSeed1 = streamio::readInt32(dataStream);
  mRandomSeed2 = streamio::readInt32(dataStream);
  mCameraX = streamio::readInt32(dataStream);
  mCameraY = streamio::readInt32(dataStream);
  mStartYear = streamio::readInt16(dataStream);
  dataStream.skipRawData(2);
  mEmpireLocation = streamio::readUInt16(dataStream);
  dataStream.skipRawData(8);

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setYear(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setResourceId(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setAmount(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setMonthsLeft(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setYear(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setType(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setAmount(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setAttackPoint(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setAttackType(streamio::readInt16(dataStream));
  }

  dataStream.skipRawData(2);
  mInitialFunds = streamio::readInt32(dataStream);
  mEnemyId = streamio::readInt32(dataStream);
  dataStream.skipRawData(4);

  mMapWidth = streamio::readInt32(dataStream);
  mMapHeight = streamio::readInt32(dataStream);
  mMapGridSize = streamio::readInt32(dataStream);
  mMapGridStart = streamio::readInt32(dataStream);

  char description[MAX_MISSION_DESCRIPTION];
  dataStream.readRawData(description, MAX_MISSION_DESCRIPTION);
  mDescription = description;

  char briefing[MAX_MISSION_BRIEFING];
  dataStream.readRawData(briefing, MAX_MISSION_BRIEFING);
  mBriefing = briefing;

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setCanComply(streamio::readInt8(dataStream) == 1);
  }

  mImageId = streamio::readInt16(dataStream);
  mOpenPlay = streamio::readInt16(dataStream);
  mInitialRank = streamio::readInt16(dataStream);

  for (int i = 0; i < MAX_HERD_POINTS; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mHerdPoints[i]->setX(value);
  }

  for (int i = 0; i < MAX_HERD_POINTS; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mHerdPoints[i]->setY(value);
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mDemandChanges[i]->setYear(value);
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mDemandChanges[i]->setMonth(value);
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mDemandChanges[i]->setResourceId(value);
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mDemandChanges[i]->setRouteId(value);
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mDemandChanges[i]->setRise(value>0);
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mPriceChanges[i]->setYear(value);
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mPriceChanges[i]->setMonth(value);
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mPriceChanges[i]->setResourceId(value);
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mPriceChanges[i]->setAmount(value);
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mPriceChanges[i]->setRise(value>0);
  }

  mGladiatorRevolt = streamio::readInt32(dataStream);
  mGladiatorRevoltYear = streamio::readInt32(dataStream);
  mEmperorChange = streamio::readInt32(dataStream);
  mEmperorChangeYear = streamio::readInt32(dataStream);
  mSeaTradeProblem = streamio::readInt32(dataStream);
  mLandTradeProblem = streamio::readInt32(dataStream);
  mRomeRaisesWages = streamio::readInt32(dataStream);
  mRomeLowersWages = streamio::readInt32(dataStream);
  mWaterContamination = streamio::readInt32(dataStream);
  mIronMineCollapse = streamio::readInt32(dataStream);
  mFloodedClayPits = streamio::readInt32(dataStream);

  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    mFishingPoints[i]->setX(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    mFishingPoints[i]->setY(streamio::readInt16(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setFavor(streamio::readInt8(dataStream));
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i]->setMonth(streamio::readInt8(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setMonth(streamio::readInt8(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setState(streamio::readInt8(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setVisible(streamio::readInt8(dataStream));
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i]->setMonthsLeft(streamio::readInt8(dataStream));
  }

  mRomeSuppliesWheat = streamio::readInt32(dataStream);

  for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) {
    mAllowedBuildings[i] = streamio::readInt16(dataStream);
  }

  mCultureGoal->setTarget(streamio::readInt32(dataStream));
  mProsperityGoal->setTarget(streamio::readInt32(dataStream));
  mPeaceGoal->setTarget(streamio::readInt32(dataStream));
  mFavorGoal->setTarget(streamio::readInt32(dataStream));
  mCultureGoal->setEnabled(streamio::readUInt8(dataStream));
  mProsperityGoal->setEnabled(streamio::readUInt8(dataStream));
  mPeaceGoal->setEnabled(streamio::readUInt8(dataStream));
  mFavorGoal->setEnabled(streamio::readUInt8(dataStream));
  mLosingTimeEnabled = streamio::readInt32(dataStream);
  mLosingTime = streamio::readInt32(dataStream);
  mSurvivalTimeEnabled = streamio::readInt32(dataStream);
  mSurvivalTime = streamio::readInt32(dataStream);

  mEarthquake->setSeverity(Earthquake::Severity(streamio::readInt32(dataStream)));
  mEarthquake->setYear(streamio::readInt32(dataStream));

  mPopulationGoal->setEnabled(streamio::readInt32(dataStream));
  mPopulationGoal->setTarget(streamio::readInt32(dataStream));

  mEarthquake->setX(streamio::readInt16(dataStream));
  mEarthquake->setY(streamio::readInt16(dataStream));

  mEntryPoint->setX(streamio::readInt16(dataStream));
  mEntryPoint->setY(streamio::readInt16(dataStream));
  mExitPoint->setX(streamio::readInt16(dataStream));
  mExitPoint->setY(streamio::readInt16(dataStream));

  for (int i = 0; i < MAX_INVASION_POINTS; i++) {
    mInvasionPoints[i]->setX(streamio::readInt16(dataStream));
    mInvasionPoints[i]->setY(streamio::readInt16(dataStream));
  }

  mRiverEntryPoint->setX(streamio::readInt16(dataStream));
  mRiverEntryPoint->setY(streamio::readInt16(dataStream));
  mRiverExitPoint->setX(streamio::readInt16(dataStream));
  mRiverExitPoint->setY(streamio::readInt16(dataStream));

  mRescueLoan = streamio::readInt32(dataStream);

  mMilestone25Year = streamio::readInt32(dataStream);
  mMilestone50Year = streamio::readInt32(dataStream);
  mMilestone75Year = streamio::readInt32(dataStream);

  mNativeHutId = streamio::readInt32(dataStream);
  mNativeMeetingId = streamio::readInt32(dataStream);
  mNativeCropsId = streamio::readInt32(dataStream);

  mClimateId = streamio::readUInt8(dataStream);
  mFlotsam = streamio::readUInt8(dataStream);

  dataStream.skipRawData(2);

  mEmpireExpanded = streamio::readInt32(dataStream);
  mEmpireExpansionYear = streamio::readInt32(dataStream);

  mRomanArmyTravelMonths = streamio::readUInt8(dataStream);
  mEnemyArmyTravelMonths = streamio::readUInt8(dataStream);
  mOpenPlayId = streamio::readUInt8(dataStream);

  dataStream.skipRawData(4);

  mSaved = true;
}

int32_t Mission::mapHeight() const
{
  return mMapHeight;
}

int32_t Mission::mapWidth() const
{
  return mMapWidth;
}

bool Mission::openPlay() const
{
  return mOpenPlay;
}

int8_t Mission::openPlayId() const
{
  return mOpenPlayId;
}

Goal * Mission::peaceGoal()
{
  return mPeaceGoal.get();
}

const Goal * Mission::peaceGoal() const
{
  return mPeaceGoal.get();
}

Goal * Mission::populationGoal()
{
  return mPopulationGoal.get();
}

const Goal * Mission::populationGoal() const
{
  return mPopulationGoal.get();
}

Goal * Mission::prosperityGoal()
{
  return mProsperityGoal.get();
}

const Goal * Mission::prosperityGoal() const
{
  return mProsperityGoal.get();
}

UnsignedByteGrid * Mission::randomGrid()
{
  return mRandomGrid.get();
}

const UnsignedByteGrid * Mission::randomGrid() const
{
  return mRandomGrid.get();
}

int32_t Mission::rescueLoan() const
{
  return mRescueLoan;
}

bool Mission::romeLowersWages() const
{
  return mRomeLowersWages;
}

bool Mission::romeRaisesWages() const
{
  return mRomeRaisesWages;
}

bool Mission::romeSuppliesWheat() const
{
  return mRomeSuppliesWheat;
}

void Mission::saveToFile(const QString &fileName, bool compressed) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToStream(dataStream, compressed);
}

void Mission::saveToStream(QDataStream & dataStream, bool compressed) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);
}

bool Mission::seaTradeProblem() const
{
  return mSeaTradeProblem;
}

void Mission::setCampaignMission(int32_t value)
{
  mCampaignMission = value;
}

int32_t Mission::startYear() const
{
  return mStartYear;
}

UnsignedShortGrid * Mission::terrainGrid()
{
  return mTerrainGrid.get();
}

const UnsignedShortGrid * Mission::terrainGrid() const
{
  return mTerrainGrid.get();
}

UnsignedByteGrid * Mission::terrainRandomGrid()
{
  return mTerrainRandomGrid.get();
}

const UnsignedByteGrid * Mission::terrainRandomGrid() const
{
  return mTerrainRandomGrid.get();
}

int Mission::totalDemandChanges() const
{
  return MAX_DEMAND_CHANGES;
}

int Mission::totalFishingPoints() const
{
  return MAX_FISHING_POINTS;
}

int Mission::totalHerdPoints() const
{
  return MAX_HERD_POINTS;
}

int Mission::totalInvasions() const
{
  return MAX_INVASIONS;
}

int Mission::totalInvasionPoints() const
{
  return MAX_INVASION_POINTS;
}

int Mission::totalPriceChanges() const
{
  return MAX_PRICE_CHANGES;
}

int Mission::totalRequests() const
{
  return MAX_REQUESTS;
}

bool Mission::waterContamination() const
{
  return mWaterContamination;
}
