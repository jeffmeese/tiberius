#ifndef ROUTE_H
#define ROUTE_H

#include "tiberius.h"

#include <QDataStream>

class Route
{
public:
  TIBERIUS_LIB_DECL Route(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mId;
};

#endif // ROUTE_H
