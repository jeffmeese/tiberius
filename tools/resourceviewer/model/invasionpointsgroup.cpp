#include "invasionpointsgroup.h"
#include "invasionpointsitem.h"

#include "map/location.h"

#include "scenario/scenario.h"

#include <QTableWidget>

InvasionPointsGroup::InvasionPointsGroup(Scenario * mission)
  : mMission(mission)
{
  setText("Invasion Points");
  for (int i = 0; i < mMission->totalInvasionPoints(); i++) {
    QString text = "Point " + QString::number(i+1);
    Location * location = mMission->getHerdPoint(i);
    InvasionPointsItem * item = new InvasionPointsItem(location);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * InvasionPointsGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalInvasionPoints());
  widget->setColumnCount(2);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("X"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Y"));
  for (int i = 0; i < mMission->totalInvasionPoints(); i++) {
    Location * location = mMission->getInvasionPoint(i);
    QTableWidgetItem * xItem = new QTableWidgetItem(QString::number(location->x()));
    QTableWidgetItem * yItem = new QTableWidgetItem(QString::number(location->y()));

    widget->setItem(i, 0, xItem);
    widget->setItem(i, 1, yItem);
  }
  return widget;
}

QList<Property> InvasionPointsGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Invasion Points", QString::number(mMission->totalInvasionPoints())));
  return propertyList;
}
