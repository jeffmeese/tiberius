#include "buildingdata.h"

#include "building/building.h"

BuildingData::BuildingData()
{

}

BuildingData::~BuildingData()
{

}

bool BuildingData::addBuilding(std::unique_ptr<Building> building)
{
  if (totalBuildings() == MAX_BUILDINGS)
    return false;

  mBuildings.push_back(std::move(building));
  emit changed();
  return true;
}

Building * BuildingData::getBuilding(int32_t index)
{
  return mBuildings.at(index).get();
}

const Building * BuildingData::getBuilding(int32_t index) const
{
  return mBuildings.at(index).get();
}

bool BuildingData::removeBuiding(Building * building)
{
  for (BuildingVector::iterator itr = mBuildings.begin(); itr != mBuildings.end(); ++itr) {
    if (itr->get() == building) {
      mBuildings.erase(itr);
      emit changed();
      return true;
    }
  }
  return false;
}

int32_t BuildingData::totalBuildings() const
{
  return static_cast<int32_t>(mBuildings.size());
}
