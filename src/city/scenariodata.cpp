#include "scenariodata.h"

#include "core/streamio.h"

#include "scenario/scenario.h"

#include <QDataStream>

ScenarioData::ScenarioData()
{
  mMission.reset(new Scenario);
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    mBuyPrices[i] = 0;
    mSellPrices[i] = 0;
  }
}

ScenarioData::~ScenarioData()
{

}

void ScenarioData::loadFromStream(QDataStream &dataStream)
{
  // 128 bytes unused + 1 unused trade price pair
  dataStream.skipRawData(130);

  // Read trade prices
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    mBuyPrices[i] = streamio::readInt32(dataStream);
    mSellPrices[i] = streamio::readInt32(dataStream);
  }

  // The rest of the data is the same as the mission data without the grids
  mMission->loadFromStream(dataStream, false);
}

void ScenarioData::saveToStream(QDataStream &dataStream) const
{
  // 128 bytes unused + 1 unused trade price pair
  for (int i = 0; i < 130; i++) {
    dataStream << static_cast<uint8_t>(0);
  }

  // Write trade prices
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    streamio::writeInt32(dataStream, mBuyPrices[i]);
    streamio::writeInt32(dataStream, mSellPrices[i]);
  }

  // The rest of the data is the same as the mission data without the grids
  mMission->saveToStream(dataStream, false);
}
