#ifndef ROUTE_H
#define ROUTE_H

#include "tiberius.h"

#include <QDataStream>

class Route
{
public:
  static const int MAX_ROUTE_LENGTH = 500;

public:
  TIBERIUS_LIB_DECL Route(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL int16_t walkerId() const;
  TIBERIUS_LIB_DECL void setWalkerId(int16_t id);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mId;
  int16_t mWalkerId;
  int8_t mDirection[MAX_ROUTE_LENGTH];
};

#endif // ROUTE_H
