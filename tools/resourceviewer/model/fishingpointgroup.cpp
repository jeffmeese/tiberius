#include "fishingpointgroup.h"
#include "fishingpointitem.h"

#include "map/location.h"

#include "scenario/scenario.h"

#include <QTableWidget>

FishingPointGroup::FishingPointGroup(Scenario * mission)
  : mMission(mission)
{
  setText("Fishing Points");
  for (int i = 0; i < mMission->totalFishingPoints(); i++) {
    QString text = "Point " + QString::number(i+1);
    Location * location = mMission->getFishingPoint(i);
    FishingPointItem * item = new FishingPointItem(location);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * FishingPointGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalFishingPoints());
  widget->setColumnCount(2);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("X"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Y"));
  for (int i = 0; i < mMission->totalFishingPoints(); i++) {
    Location * location = mMission->getFishingPoint(i);
    QTableWidgetItem * xItem = new QTableWidgetItem(QString::number(location->x()));
    QTableWidgetItem * yItem = new QTableWidgetItem(QString::number(location->y()));

    widget->setItem(i, 0, xItem);
    widget->setItem(i, 1, yItem);
  }
  return widget;
}

QList<Property> FishingPointGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Fishing Points", QString::number(mMission->totalFishingPoints())));
  return propertyList;
}
