#ifndef ROUTE_H
#define ROUTE_H

#include "tiberius.h"

#include <QDataStream>

class Route
{
public:
  TIBERIUS_LIB_DECL Route();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
};

#endif // ROUTE_H
