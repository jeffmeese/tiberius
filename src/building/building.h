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
    None = 0
  };

public:
  TIBERIUS_LIB_DECL Building();

public:
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getName() const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mWorkers;
  int32_t mWorkersNeeded;
  Type mType;
};

#endif // BUILDING_H
