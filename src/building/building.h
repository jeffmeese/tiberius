#ifndef BUILDING_H
#define BUILDING_H

#include "tiberius.h"

#include <QPixmap>
#include <QString>

class Building
{
public:
  enum class Type
  {

  };

public:
  TIBERIUS_LIB_DECL Building(Type type);

public:
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getName() const;

private:
  int32_t mWorkers;
  int32_t mWorkersNeeded;
  Type mType;
};

#endif // BUILDING_H
