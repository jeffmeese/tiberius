#ifndef BURNINGBUILDINGDATA_H
#define BURNINGBUILDINGDATA_H

#include "tiberius.h"

class BurningBuildingData
{
public:
  TIBERIUS_LIB_DECL BurningBuildingData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  static const int32_t MAX_BURNING_BUILDINGS = 500;

private:
  int16_t mIdList[MAX_BURNING_BUILDINGS];
};

#endif // BURNINGBUILDINGDATA_H
