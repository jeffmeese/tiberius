#ifndef SCENARIODATA_H
#define SCENARIODATA_H

#include "tiberius.h"

class ScenarioData
{
public:
  TIBERIUS_LIB_DECL ScenarioData();

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
};

#endif // SCENARIODATA_H
