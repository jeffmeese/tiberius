#ifndef STORAGEDATA_H
#define STORAGEDATA_H

#include "tiberius.h"

class StorageData
{
public:
  TIBERIUS_LIB_DECL StorageData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
};

#endif // STORAGEDATA_H
