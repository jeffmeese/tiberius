#include "scenario.h"

#include "goal.h"

#include "core/streamio.h"

#include "event/demandchange.h"
#include "event/earthquake.h"
#include "event/emperorchange.h"
#include "event/emperorrequest.h"
#include "event/empireexpansion.h"
#include "event/gladiatorrevolt.h"
#include "event/pricechange.h"

#include "map/location.h"

#include "military/invasion.h"

#include <QFile>
#include <sstream>
#include <stdexcept>

Scenario::Scenario()
{
  init();
}

Scenario::~Scenario()
{

}

int32_t Scenario::campaignMission() const
{
  return mCampaignMission;
}

int32_t Scenario::cameraX() const
{
  return mCameraX;
}

int32_t Scenario::cameraY() const
{
  return mCameraY;
}

Goal * Scenario::cultureGoal()
{
  return mCultureGoal.get();
}

const Goal * Scenario::cultureGoal() const
{
  return mCultureGoal.get();
}

QString Scenario::description() const
{
  return mDescription;
}

UnsignedByteGrid * Scenario::edgeGrid()
{
  return mEdgeGrid.get();
}

const UnsignedByteGrid * Scenario::edgeGrid() const
{
  return mEdgeGrid.get();
}

UnsignedByteGrid * Scenario::elevationGrid()
{
  return mElevationGrid.get();
}

const UnsignedByteGrid * Scenario::elevationGrid() const
{
  return mElevationGrid.get();
}

bool Scenario::emperorChange() const
{
  return mEmperorChange;
}

int16_t Scenario::emperorChangeYear() const
{
  return mEmperorChangeYear;
}

uint8_t Scenario::empireLocation() const
{
  return mEmpireLocation;
}

int32_t Scenario::enemyId() const
{
  return mEnemyId;
}

Goal * Scenario::favorGoal()
{
  return mFavorGoal.get();
}

const Goal * Scenario::favorGoal() const
{
  return mFavorGoal.get();
}

bool Scenario::floodedClayPits() const
{
  return mFloodedClayPits;
}

bool Scenario::flotsam() const
{
  return mFlotsam;
}

DemandChange * Scenario::getDemandChange(int index)
{
  return mDemandChanges[index].get();
}

const DemandChange * Scenario::getDemandChange(int index) const
{
  return mDemandChanges[index].get();
}

Location * Scenario::getFishingPoint(int index)
{
  return mFishingPoints[index].get();
}

const Location * Scenario::getFishingPoint(int index) const
{
  return mFishingPoints[index].get();
}

Location * Scenario::getHerdPoint(int index)
{
  return mHerdPoints[index].get();
}

const Location * Scenario::getHerdPoint(int index) const
{
  return mHerdPoints[index].get();
}

Invasion * Scenario::getInvasion(int index)
{
  return mInvasions[index].get();
}

const Invasion * Scenario::getInvasion(int index) const
{
  return mInvasions[index].get();
}

Location * Scenario::getInvasionPoint(int index)
{
  return mInvasionPoints[index].get();
}

const Location * Scenario::getInvasionPoint(int index) const
{
  return mInvasionPoints[index].get();
}

PriceChange * Scenario::getPriceChange(int index)
{
  return mPriceChanges[index].get();
}

const PriceChange * Scenario::getPriceChange(int index) const
{
  return mPriceChanges[index].get();
}

EmperorRequest * Scenario::getRequest(int index)
{
  return mEmperorRequests[index].get();
}

const EmperorRequest * Scenario::getRequest(int index) const
{
  return mEmperorRequests[index].get();
}

bool Scenario::gladiatorRevolt() const
{
  return mGladiatorRevolt;
}

int16_t Scenario::gladiatorRevoltYear() const
{
  return mGladiatorRevoltYear;
}

UnsignedShortGrid * Scenario::graphicGrid()
{
  return mGraphicGrid.get();
}

const UnsignedShortGrid * Scenario::graphicGrid() const
{
  return mGraphicGrid.get();
}

int16_t Scenario::imageId() const
{
  return mImageId;
}

void Scenario::init()
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

  mAllowedBuildings.resize(Scenario::MAX_ALLOWED_BUILDINGS);
  for (int i = 0; i < Scenario::MAX_ALLOWED_BUILDINGS; i++) {
    mAllowedBuildings[i] = 0;
  }

  mDemandChanges.resize(Scenario::MAX_DEMAND_CHANGES);
  for (int i = 0; i < Scenario::MAX_DEMAND_CHANGES; i++) {
    mDemandChanges[i].reset(new DemandChange);
  }

  mEmperorRequests.resize(Scenario::MAX_REQUESTS);
  for (int i = 0; i < Scenario::MAX_REQUESTS; i++) {
    mEmperorRequests[i].reset(new EmperorRequest);
  }

  mInvasions.resize(Scenario::MAX_INVASIONS);
  for (int i = 0; i < Scenario::MAX_INVASIONS; i++) {
    mInvasions[i].reset(new Invasion);
  }

  mPriceChanges.resize(Scenario::MAX_PRICE_CHANGES);
  for (int i = 0; i < Scenario::MAX_PRICE_CHANGES; i++) {
    mPriceChanges[i].reset(new PriceChange);
  }

  mHerdPoints.resize(Scenario::MAX_HERD_POINTS);
  for (int i = 0; i < Scenario::MAX_HERD_POINTS; i++) {
    mHerdPoints[i].reset(new Location);
  }

  mFishingPoints.resize(Scenario::MAX_FISHING_POINTS);
  for (int i = 0; i < Scenario::MAX_FISHING_POINTS; i++) {
    mFishingPoints[i].reset(new Location);
  }

  mInvasionPoints.resize(Scenario::MAX_INVASION_POINTS);
  for (int i = 0; i < Scenario::MAX_INVASION_POINTS; i++) {
    mInvasionPoints[i].reset(new Location);
  }
}

int32_t Scenario::initialFunds() const
{
  return mInitialFunds;
}

int8_t Scenario::initialRank() const
{
  return mInitialRank;
}

bool Scenario::ironMineCollapse() const
{
  return mIronMineCollapse;
}

bool Scenario::landTradeProblem() const
{
  return mLandTradeProblem;
}

void Scenario::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  loadFromStream(dataStream, true);
}

void Scenario::loadFromStream(QDataStream &dataStream, bool includeGrids)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  if (includeGrids) {
    mGraphicGrid->loadFromDataStream(dataStream, 52488, false);
    mEdgeGrid->loadFromDataStream(dataStream, 26244, false);
    mTerrainGrid->loadFromDataStream(dataStream, 52488, false);
    mTerrainRandomGrid->loadFromDataStream(dataStream, 26244, false);
    mRandomGrid->loadFromDataStream(dataStream, 26244, false);
    mElevationGrid->loadFromDataStream(dataStream, 26244, false);
  }

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

int32_t Scenario::mapHeight() const
{
  return mMapHeight;
}

int32_t Scenario::mapWidth() const
{
  return mMapWidth;
}

bool Scenario::openPlay() const
{
  return mOpenPlay;
}

int8_t Scenario::openPlayId() const
{
  return mOpenPlayId;
}

Goal * Scenario::peaceGoal()
{
  return mPeaceGoal.get();
}

const Goal * Scenario::peaceGoal() const
{
  return mPeaceGoal.get();
}

Goal * Scenario::populationGoal()
{
  return mPopulationGoal.get();
}

const Goal * Scenario::populationGoal() const
{
  return mPopulationGoal.get();
}

Goal * Scenario::prosperityGoal()
{
  return mProsperityGoal.get();
}

const Goal * Scenario::prosperityGoal() const
{
  return mProsperityGoal.get();
}

UnsignedByteGrid * Scenario::randomGrid()
{
  return mRandomGrid.get();
}

const UnsignedByteGrid * Scenario::randomGrid() const
{
  return mRandomGrid.get();
}

int32_t Scenario::rescueLoan() const
{
  return mRescueLoan;
}

bool Scenario::romeLowersWages() const
{
  return mRomeLowersWages;
}

bool Scenario::romeRaisesWages() const
{
  return mRomeRaisesWages;
}

bool Scenario::romeSuppliesWheat() const
{
  return mRomeSuppliesWheat;
}

void Scenario::saveToFile(const QString &fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToStream(dataStream, true);
}

void Scenario::saveToStream(QDataStream & dataStream, bool includeGrids) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  if (includeGrids) {
    mGraphicGrid->saveToDataStream(dataStream, 52488, false);
    mEdgeGrid->saveToDataStream(dataStream, 26244, false);
    mTerrainGrid->saveToDataStream(dataStream, 52488, false);
    mTerrainRandomGrid->saveToDataStream(dataStream, 26244, false);
    mRandomGrid->saveToDataStream(dataStream, 26244, false);
    mElevationGrid->saveToDataStream(dataStream, 26244, false);
  }

  streamio::writeInt32(dataStream, mRandomSeed1);
  streamio::writeInt32(dataStream, mRandomSeed2);
  streamio::writeInt32(dataStream, mCameraX);
  streamio::writeInt32(dataStream, mCameraY);
  streamio::writeInt16(dataStream, mStartYear);

  for (int i = 0; i < 2; i++)
    dataStream << static_cast<uint8_t>(0);

  streamio::writeUInt16(dataStream, mEmpireLocation);

  for (int i = 0; i < 8; i++)
    dataStream << static_cast<uint8_t>(0);

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeInt16(dataStream, mEmperorRequests[i]->year());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeInt16(dataStream, mEmperorRequests[i]->resourceId());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeInt16(dataStream, mEmperorRequests[i]->amount());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeInt16(dataStream, mEmperorRequests[i]->monthsLeft());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeInt16(dataStream, mInvasions[i]->year());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeInt16(dataStream, mInvasions[i]->type());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeInt16(dataStream, mInvasions[i]->amount());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeInt16(dataStream, mInvasions[i]->attackPoint());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeInt16(dataStream, mInvasions[i]->attackType());
  }

  for (int i = 0; i < 2; i++)
    dataStream << static_cast<uint8_t>(0);

  streamio::writeInt32(dataStream, mInitialFunds);
  streamio::writeInt32(dataStream, mEnemyId);
  for (int i = 0; i < 4; i++)
    dataStream << static_cast<uint8_t>(0);

  streamio::writeInt32(dataStream, mMapWidth);
  streamio::writeInt32(dataStream, mMapHeight);
  streamio::writeInt32(dataStream, mMapGridSize);
  streamio::writeInt32(dataStream, mMapGridStart);

  char description[MAX_MISSION_DESCRIPTION];
  strcpy(description, mDescription.toStdString().c_str());
  dataStream.writeRawData(description, MAX_MISSION_DESCRIPTION);

  char briefing[MAX_MISSION_BRIEFING];
  strcpy(briefing, mBriefing.toStdString().c_str());
  dataStream.writeRawData(description, MAX_MISSION_BRIEFING);

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mEmperorRequests[i]->canComply());
  }

  streamio::writeInt16(dataStream, mImageId);
  streamio::writeInt16(dataStream, mOpenPlay);
  streamio::writeInt16(dataStream, mInitialRank);

  for (int i = 0; i < MAX_HERD_POINTS; i++) {
    streamio::writeInt16(dataStream, mHerdPoints[i]->x());
  }

  for (int i = 0; i < MAX_HERD_POINTS; i++) {
    streamio::writeInt16(dataStream, mHerdPoints[i]->y());
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    streamio::writeInt16(dataStream, mDemandChanges[i]->year());
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mDemandChanges[i]->month());
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mDemandChanges[i]->resourceId());
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mDemandChanges[i]->routeId());
  }

  for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mDemandChanges[i]->rise());
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    streamio::writeInt16(dataStream, mPriceChanges[i]->year());
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mPriceChanges[i]->month());
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mPriceChanges[i]->resourceId());
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mPriceChanges[i]->amount());
  }

  for (int i = 0; i < MAX_PRICE_CHANGES; i++) {
    streamio::writeUInt8(dataStream, mPriceChanges[i]->rise());
  }

  streamio::writeInt32(dataStream, mGladiatorRevolt);
  streamio::writeInt32(dataStream, mGladiatorRevoltYear);
  streamio::writeInt32(dataStream, mEmperorChange);
  streamio::writeInt32(dataStream, mEmperorChangeYear);
  streamio::writeInt32(dataStream, mSeaTradeProblem);
  streamio::writeInt32(dataStream, mLandTradeProblem);
  streamio::writeInt32(dataStream, mRomeRaisesWages);
  streamio::writeInt32(dataStream, mRomeLowersWages);
  streamio::writeInt32(dataStream, mWaterContamination);
  streamio::writeInt32(dataStream, mIronMineCollapse);
  streamio::writeInt32(dataStream, mFloodedClayPits);

  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    streamio::writeInt16(dataStream, mFishingPoints[i]->x());
  }

  for (int i = 0; i < MAX_FISHING_POINTS; i++) {
    streamio::writeInt16(dataStream, mFishingPoints[i]->y());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mEmperorRequests[i]->favor());
  }

  for (int i = 0; i < MAX_INVASIONS; i++) {
    streamio::writeUInt8(dataStream, mInvasions[i]->month());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mInvasions[i]->month());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mEmperorRequests[i]->state());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mEmperorRequests[i]->visible());
  }

  for (int i = 0; i < MAX_REQUESTS; i++) {
    streamio::writeUInt8(dataStream, mEmperorRequests[i]->monthsLeft());
  }

  streamio::writeInt32(dataStream, mRomeSuppliesWheat);

  for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) {
    streamio::writeInt16(dataStream, mAllowedBuildings[i]);
  }

  streamio::writeInt32(dataStream, mCultureGoal->target());
  streamio::writeInt32(dataStream, mProsperityGoal->target());
  streamio::writeInt32(dataStream, mPeaceGoal->target());
  streamio::writeInt32(dataStream, mFavorGoal->target());
  streamio::writeInt32(dataStream, mCultureGoal->enabled());
  streamio::writeInt32(dataStream, mProsperityGoal->enabled());
  streamio::writeInt32(dataStream, mPeaceGoal->enabled());
  streamio::writeInt32(dataStream, mFavorGoal->enabled());

  streamio::writeInt32(dataStream, mLosingTimeEnabled);
  streamio::writeInt32(dataStream, mLosingTime);
  streamio::writeInt32(dataStream, mSurvivalTimeEnabled);
  streamio::writeInt32(dataStream, mSurvivalTime);

  streamio::writeInt32(dataStream, mEarthquake->severity());
  streamio::writeInt32(dataStream, mEarthquake->year());

  streamio::writeInt32(dataStream, mPopulationGoal->enabled());
  streamio::writeInt32(dataStream, mPopulationGoal->target());

  streamio::writeInt16(dataStream, mEarthquake->x());
  streamio::writeInt16(dataStream, mEarthquake->y());

  streamio::writeInt16(dataStream, mEntryPoint->x());
  streamio::writeInt16(dataStream, mEntryPoint->y());
  streamio::writeInt16(dataStream, mExitPoint->x());
  streamio::writeInt16(dataStream, mExitPoint->y());

  for (int i = 0; i < MAX_INVASION_POINTS; i++) {
    streamio::writeInt16(dataStream, mInvasionPoints[i]->x());
    streamio::writeInt16(dataStream, mInvasionPoints[9]->y());
  }

  streamio::writeInt16(dataStream, mRiverEntryPoint->x());
  streamio::writeInt16(dataStream, mRiverEntryPoint->y());
  streamio::writeInt16(dataStream, mRiverExitPoint->x());
  streamio::writeInt16(dataStream, mRiverExitPoint->y());

  streamio::writeInt32(dataStream, mRescueLoan);
  streamio::writeInt32(dataStream, mMilestone25Year);
  streamio::writeInt32(dataStream, mMilestone50Year);
  streamio::writeInt32(dataStream, mMilestone75Year);

  streamio::writeInt32(dataStream, mNativeHutId);
  streamio::writeInt32(dataStream, mNativeMeetingId);
  streamio::writeInt32(dataStream, mNativeCropsId);

  streamio::writeUInt8(dataStream, mClimateId);
  streamio::writeUInt8(dataStream, mFlotsam);

  for (int i = 0; i < 2; i++)
    dataStream << static_cast<uint8_t>(0);

  streamio::writeInt32(dataStream, mEmpireExpanded);
  streamio::writeInt32(dataStream, mEmpireExpansionYear);

  streamio::writeUInt8(dataStream, mRomanArmyTravelMonths);
  streamio::writeUInt8(dataStream, mEnemyArmyTravelMonths);
  streamio::writeUInt8(dataStream, mOpenPlayId);

  for (int i = 0; i < 4; i++)
    dataStream << static_cast<uint8_t>(0);
}

bool Scenario::seaTradeProblem() const
{
  return mSeaTradeProblem;
}

void Scenario::setCampaignMission(int32_t value)
{
  mCampaignMission = value;
}

int32_t Scenario::startYear() const
{
  return mStartYear;
}

UnsignedShortGrid * Scenario::terrainGrid()
{
  return mTerrainGrid.get();
}

const UnsignedShortGrid * Scenario::terrainGrid() const
{
  return mTerrainGrid.get();
}

UnsignedByteGrid * Scenario::terrainRandomGrid()
{
  return mTerrainRandomGrid.get();
}

const UnsignedByteGrid * Scenario::terrainRandomGrid() const
{
  return mTerrainRandomGrid.get();
}

int Scenario::totalDemandChanges() const
{
  return MAX_DEMAND_CHANGES;
}

int Scenario::totalFishingPoints() const
{
  return MAX_FISHING_POINTS;
}

int Scenario::totalHerdPoints() const
{
  return MAX_HERD_POINTS;
}

int Scenario::totalInvasions() const
{
  return MAX_INVASIONS;
}

int Scenario::totalInvasionPoints() const
{
  return MAX_INVASION_POINTS;
}

int Scenario::totalPriceChanges() const
{
  return MAX_PRICE_CHANGES;
}

int Scenario::totalRequests() const
{
  return MAX_REQUESTS;
}

bool Scenario::waterContamination() const
{
  return mWaterContamination;
}
