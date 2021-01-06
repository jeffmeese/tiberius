#include "mapwidget.h"

#include "city/city.h"

#include "map/bookmark.h"
#include "map/grid.h"
#include "map/location.h"
#include "map/map.h"

#include <QPainter>

MapWidget::MapWidget(QWidget *parent)
  : QWidget(parent)
  , mCity(nullptr)
  , mMap(nullptr)
{
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

City * MapWidget::city()
{
  return mCity;
}

const City * MapWidget::city() const
{
  return mCity;
}

void MapWidget::drawCity(QPainter & painter)
{

}

void MapWidget::drawMap(QPainter & painter)
{

}

Map * MapWidget::map()
{
  return mMap;
}

const Map * MapWidget::map() const
{
  return mMap;
}

void MapWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  QImage image(width(), height(), QImage::Format_ARGB32);
  image.fill(Qt::black);

  QPainter imagePainter(&image);

  if (mMap != nullptr) {
    drawMap(imagePainter);
  }
  if (mCity != nullptr) {
    drawCity(imagePainter);
  }

  painter.drawImage(0, 0, image);
}


void MapWidget::setCity(City * city)
{
  mCity = city;
}

void MapWidget::setMap(Map * map)
{
  mMap = map;
}
