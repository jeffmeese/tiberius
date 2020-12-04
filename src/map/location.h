#ifndef LOCATION_H
#define LOCATION_H

#include <cstdint>

#include "tiberius.h"

#include <QDataStream>

class Location
{
public:
  TIBERIUS_LIB_DECL Location();
  TIBERIUS_LIB_DECL Location(int32_t x, int32_t y);

public:
  TIBERIUS_LIB_DECL int32_t x() const;
  TIBERIUS_LIB_DECL int32_t y() const;
  TIBERIUS_LIB_DECL void setX(int32_t value);
  TIBERIUS_LIB_DECL void setY(int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mX;
  int32_t mY;
};

inline int32_t Location::x() const
{
  return mX;
}

inline int32_t Location::y() const
{
  return mY;
}

inline void Location::setX(int32_t value)
{
  mX = value;
}

inline void Location::setY(int32_t value)
{
  mY = value;
}

#endif // LOCATION_H
