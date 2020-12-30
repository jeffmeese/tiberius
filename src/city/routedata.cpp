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

  // Read the walker IDs
  QDataStream walkerStream(&routeFigures, QIODevice::ReadOnly);
  for (int32_t i = 0; i < MAX_ROUTES; i++) {
    get(i)->setWalkerId(streamio::readInt16(walkerStream));
  }

  QDataStream pathStream(&routePaths, QIODevice::ReadOnly);
  for (int32_t i = 0; i < MAX_ROUTES; i++) {
    get(i)->loadFromDataStream(pathStream);
  }
}

void RouteData::saveToDataStream(QDataStream &dataStream, bool compressed) const
{
  QByteArray figureArray;
  QDataStream figureStream(&figureArray, QIODevice::WriteOnly);
  for (int32_t i = 0; i < MAX_ROUTES; i++) {
    figureStream << get(i)->walkerId();
  }
  streamio::writeCompressedData(dataStream, figureArray);

  QByteArray pathArray;
  QDataStream pathStream(&pathArray, QIODevice::WriteOnly);
  for (int32_t i = 0; MAX_ROUTES; i++) {
    get(i)->saveToDataStream(pathStream);
  }
  streamio::writeCompressedData(dataStream, pathArray);
}
