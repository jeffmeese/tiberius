#ifndef HOUSINGDATA_H
#define HOUSINGDATA_H

#include "tiberius.h"

class HousingData
{
public:
  TIBERIUS_LIB_DECL HousingData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
};

#endif // HOUSINGDATA_H
