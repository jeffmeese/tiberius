#ifndef ROUTEDATA_H
#define ROUTEDATA_H

#include "datamodel.h"
#include "datavector.h"

#include "route/route.h"

#include <memory>
#include <vector>

class Route;
class RouteData
    : public DataModel
    , public DataVector<Route>
{
public:
  static const int32_t MAX_ROUTES = 600;
  static const int32_t MAX_PATH_LENGTH = 500;

public:
  TIBERIUS_LIB_DECL RouteData();
  TIBERIUS_LIB_DECL ~RouteData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream, bool compressed = true) const;
};

#endif // ROUTEDATA_H
