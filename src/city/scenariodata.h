#ifndef SCENARIODATA_H
#define SCENARIODATA_H

#include "tiberius.h"

#include "resource/resource.h"

#include <memory>

class Scenario;

class ScenarioData
{
public:
  TIBERIUS_LIB_DECL ScenarioData();
  TIBERIUS_LIB_DECL ~ScenarioData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mBuyPrices[Resource::MAX_RESOURCES];
  int32_t mSellPrices[Resource::MAX_RESOURCES];
  std::unique_ptr<Scenario> mMission;
};

#endif // SCENARIODATA_H
