#ifndef BUILDINGDATA_H
#define BUILDINGDATA_H

#include "tiberius.h"

#include <cstdint>
#include <memory>

class BuildingData
{
public:
  static const int32_t MAX_BUILDINGS = 2000;

public:
  TIBERIUS_LIB_DECL BuildingData();
};

#endif // BUILDINGDATA_H
