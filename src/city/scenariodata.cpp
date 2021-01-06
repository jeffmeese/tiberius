#include "scenariodata.h"

#include "core/streamio.h"

#include "map/location.h"
#include "mission/earthquake.h"
#include "mission/goal.h"
#include <QDataStream>

ScenarioData::ScenarioData()
{
  mEmperorChange = false;
  mGladiatorRevolt = false;
  mFloodedClayPits = false;
  mIronMineCollapse = false;
  mLandTradeProblem = false;
  mSeaTradeProblem = false;
  mRomeLowersWages = false;
  mRomeRaisesWages = false;
  mSeaTradeProblem = false;
  mWaterContamination = false;

  mEmperorChangeYear = 0;
  mEnemyId = 0;
  mMilestone25Year = 0;
  mMilestone50Year = 0;
  mMilestone75Year = 0;
  mRescueLoan = 0;
  mMapWidth = 0;
  mMapHeight = 0;

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

  //mAllowedBuildings.resize(MAX_ALLOWED_BUILDINGS);
  //for (int i = 0; i < MAX_ALLOWED_BUILDINGS; i++) {
  //  mAllowedBuildings[i] = 0;
  //}

  //mDemandChanges.resize(MAX_DEMAND_CHANGES);
  //for (int i = 0; i < MAX_DEMAND_CHANGES; i++) {
  //  mDemandChanges[i].reset(new DemandChange);
  //}

  mEmperorRequests.resize(MAX_REQUESTS);
  for (int i = 0; i < MAX_REQUESTS; i++) {
    mEmperorRequests[i].reset(new EmperorRequest);
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

void ScenarioData::loadFromStream(QDataStream &dataStream)
{
  dataStream.skipRawData(128); // Unknown
  dataStream.skipRawData(8); // Unused trade price pair
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    mBuyPrices[i] = streamio::readInt32(dataStream);
    mSellPrices[i] = streamio::readInt32(dataStream);
  }

  mRandomSeed1 = streamio::readInt32(dataStream);
  mRandomSeed2 = streamio::readInt32(dataStream);
  mStartingDate = streamio::readInt32(dataStream);
  dataStream.skipRawData(8); // Unknownz
  mStartingDate = streamio::readInt32(dataStream);
  dataStream.skipRawData(10); // Unknown
}

void ScenarioData::saveToStream(QDataStream &dataStream) const
{

}
