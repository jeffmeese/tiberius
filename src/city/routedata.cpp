#include "routedata.h"

#include "route/route.h"

static const int32_t FIGURE_SIZE = 1200;
static const int32_t PATH_SIZE = 300000;

RouteData::RouteData()
  : DataVector<Route>(MAX_ROUTES)
{

}

RouteData::~RouteData()
{

}

void RouteData::loadFromDataStream(QDataStream &dataStream)
{
  QByteArray routeFigures = streamio::readCompressedData(dataStream, FIGURE_SIZE); // Route figures
  QByteArray routePaths = streamio::readCompressedData(dataStream, PATH_SIZE); // Route paths
}

void RouteData::saveToDataStream(QDataStream &dataStream, bool compressed) const
{

}
