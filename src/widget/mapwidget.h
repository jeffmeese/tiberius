#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "tiberius.h"

#include <QWidget>

class City;
class Map;

class MapWidget
    : public QWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit MapWidget(QWidget *parent = nullptr);

public:
  TIBERIUS_LIB_DECL City * city();
  TIBERIUS_LIB_DECL const City * city() const;
  TIBERIUS_LIB_DECL Map * map();
  TIBERIUS_LIB_DECL const Map * map() const;
  TIBERIUS_LIB_DECL void setCity(City * city);
  TIBERIUS_LIB_DECL void setMap(Map * map);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  void drawCity(QPainter & painter);
  void drawMap(QPainter & painter);

signals:

private:
  City * mCity;
  Map * mMap;
};

#endif // MAPWIDGET_H
