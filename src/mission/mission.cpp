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
  mEmperorChange = false;
  mEmpireExpanded = false;
  mOpenPlay = false;
  mFloodedClayPits = false;
  mFlotsam = false;
  mGladiatorRevolt = false;
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
  mGladiatorRevoltYear = 0;
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

  mEdgeGrid.reset(new UnsigedByteGrid);
  mElevationGrid.reset(new UnsigedByteGrid);
  mRandomGrid.reset(new UnsigedByteGrid);
  mTerrainRandomGrid.reset(new UnsigedByteGrid);
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

  mAllowedBuildings.resize(MAX_ALLOWED_BUILDINGS);
  for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) {
    mAllowedBuildings[i] = 0;
  }

  mDemandChanges.resize(MAX_DEMAND_CHANGES);
  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    mDemandChanges[i].reset(new DemandChange);
  }

  mEmpeorRequests.resize(MAX_REQUESTS);
  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmpeorRequests[i].reset(new EmperorRequest);
  }

  mInvasions.resize(MAX_INVASIONS);
  for (int i = 0; i < MAX_INVASIONS; i++) {
    mInvasions[i].reset(new Invasion);
  }

  mPriceChanges.resize(MAX_PRICE_CHANGES);
  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    mPriceChanges[i].reset(new PriceChange);
  }

  mHerdPoints.resize(MAX_HERD_POINTS);
  for (int i = 0; i < MAX_HERD_POINTS; i++) {
    mHerdPoints[i].reset(new Location);
  }

  mFishingPoints.resize(MAX_FISHING_POINTS);
  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    mFishingPoints[i].reset(new Location);
  }

  mInvasionPoints.resize(MAX_INVASION_POINTS);
  for (int i = 0; i < MAX_INVASION_POINTS; i++) {
    mInvasionPoints[i].reset(new Location);
  }
}

Mission::~Mission()
{

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

  // Map size
  dataStream.skipRawData(8);

  mCameraX = streamio::readInt32(dataStream);
  mCameraY = streamio::readInt32(dataStream);
  mStartYear = streamio::readInt16(dataStream);
  mEmpireLocation = streamio::readInt8(dataStream);

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int16_t year = streamio::readInt16(dataStream);
    mEmpeorRequests[i]->setYear(year);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int16_t resourceId = streamio::readInt16(dataStream);
    mEmpeorRequests[i]->setResourceId(resourceId);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int16_t amount = streamio::readInt16(dataStream);
    mEmpeorRequests[i]->setAmount(amount);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int16_t timeToFulfill = streamio::readInt16(dataStream);
    mEmpeorRequests[i]->setMonthsLeft(timeToFulfill);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int16_t year = streamio::readInt16(dataStream);
    mInvasions[i]->setYear(year);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int16_t invasionType = streamio::readInt16(dataStream);
    mInvasions[i]->setType(invasionType);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int16_t numberOfInvaders = streamio::readInt16(dataStream);
    mInvasions[i]->setAmount(numberOfInvaders);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int16_t attackPoint = streamio::readInt16(dataStream);
    mInvasions[i]->setAttackPoint(attackPoint);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int16_t attackType = streamio::readInt16(dataStream);
    mInvasions[i]->setAttackType(attackType);
  }

  mInitialFunds = streamio::readInt32(dataStream);
  mEnemyId = streamio::readInt16(dataStream);

  dataStream.skipRawData(6);

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
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setCanComply(value == 1);
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
    int16_t value = streamio::readInt16(dataStream);
    mFishingPoints[i]->setX(value);
  }

  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mFishingPoints[i]->setY(value);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setFavor(value);
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mInvasions[i]->setMonth(value);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setMonth(value);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setState(value);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setVisible(value);
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    int8_t value = streamio::readInt8(dataStream);
    mEmpeorRequests[i]->setMonthsLeft(value);
  }

  mRomeSuppliesWheat = streamio::readInt32(dataStream);

  for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) {
    int16_t value = streamio::readInt16(dataStream);
    mAllowedBuildings[i] = value;
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

void Mission::saveToFile(const QString &fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToStream(dataStream, false);
}

void Mission::saveToStream(QDataStream & dataStream, bool compressedGrids) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);
}
