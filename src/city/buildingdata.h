#ifndef BUILDINGDATA_H
#define BUILDINGDATA_H

#include "datamodel.h"
#include "datavector.h"
#include "building/building.h"

#include <memory>
#include <vector>

class Building;
class BuildingData
    : public DataModel
    , public DataVector<Building>
{
public:
  static const int32_t MAX_BUILDINGS = 2000;

public:
  TIBERIUS_LIB_DECL BuildingData();
  TIBERIUS_LIB_DECL ~BuildingData();

public:
  TIBERIUS_LIB_DECL int32_t highestIdInUse() const;
  TIBERIUS_LIB_DECL int32_t highestIdUsed() const;
  TIBERIUS_LIB_DECL void setHighestIdInUse(int32_t value);
  TIBERIUS_LIB_DECL void setHighestIdUsed(int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mHighestId;
  int32_t mHighestIdInUse;
};

#endif // BUILDINGDATA_H
