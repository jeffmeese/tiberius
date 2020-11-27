#ifndef RESOURCE_H
#define RESOURCE_H

#include "tiberius.h"

#include <QPixmap>

#include <cstdint>

class Resource
{
public:
  enum class Type
  {
    None = 0,
    Wheat = 1,
    Vegetables = 2,
    Fruit = 3,
  };

public:
  TIBERIUS_LIB_DECL Resource();

public:
  TIBERIUS_LIB_DECL Type type() const;

public:
  TIBERIUS_LIB_DECL static QPixmap getImage(Type type);
  TIBERIUS_LIB_DECL static QString getString(Type type);

private:
  Type mType;
};

#endif // RESOURCE_H
