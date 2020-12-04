#ifndef BUILDINGDATA_H
#define BUILDINGDATA_H

#include "datamodel.h"

#include <memory>
#include <vector>

class Building;
class BuildingData
    : public DataModel
{
public:
  static const int32_t MAX_BUILDINGS = 2000;

public:
  TIBERIUS_LIB_DECL BuildingData();
  TIBERIUS_LIB_DECL ~BuildingData();

public:
  TIBERIUS_LIB_DECL int32_t totalBuildings() const;

private:
  TIBERIUS_LIB_DECL bool addBuilding(std::unique_ptr<Building> building);
  TIBERIUS_LIB_DECL Building * getBuilding(int32_t index);
  TIBERIUS_LIB_DECL const Building * getBuilding(int32_t index) const;
  TIBERIUS_LIB_DECL bool removeBuiding(Building * building);

private:
  using BuildingPtr = std::unique_ptr<Building>;
  using BuildingVector = std::vector<BuildingPtr>;

private:
  BuildingVector mBuildings;
};

#endif // BUILDINGDATA_H
