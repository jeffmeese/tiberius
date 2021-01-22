#include "scenariodata.h"

#include "core/streamio.h"

#include "scenario/scenario.h"

#include <QDataStream>
#include <QDebug>

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

void ScenarioData::loadFromDataStream(QDataStream &dataStream)
{
  qDebug() << Resource::MAX_RESOURCES;

  dataStream.skipRawData(128); // 128 bytes unused
  dataStream.skipRawData(8); // Unused trade price pair

  // Read trade prices
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    mBuyPrices[i] = streamio::readInt32(dataStream);
    mSellPrices[i] = streamio::readInt32(dataStream);
  }

  dataStream.skipRawData(84); // Figure names
  dataStream.skipRawData(60); // Culture count

  // The rest of the data is the same as the mission data without the grids and some of the initial data
  mMission->loadFromStream(dataStream, false);
}

void ScenarioData::saveToDataStream(QDataStream &dataStream) const
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
