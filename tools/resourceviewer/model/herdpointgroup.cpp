#include "herdpointgroup.h"
#include "herdpointitem.h"

#include "map/location.h"

#include "scenario/scenario.h"

#include <QTableWidget>

HerdPointGroup::HerdPointGroup(Scenario * mission)
  : mMission(mission)
{
  setText("Herd Points");
  for (int i = 0; i < mMission->totalHerdPoints(); i++) {
    QString text = "Point " + QString::number(i+1);
    Location * location = mMission->getHerdPoint(i);
    HerdPointItem * item = new HerdPointItem(location);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * HerdPointGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalHerdPoints());
  widget->setColumnCount(2);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("X"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Y"));
  for (int i = 0; i < mMission->totalHerdPoints(); i++) {
    Location * location = mMission->getHerdPoint(i);
    QTableWidgetItem * xItem = new QTableWidgetItem(QString::number(location->x()));
    QTableWidgetItem * yItem = new QTableWidgetItem(QString::number(location->y()));

    widget->setItem(i, 0, xItem);
    widget->setItem(i, 1, yItem);
  }
  return widget;
}

QList<Property> HerdPointGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Herd Points", QString::number(mMission->totalHerdPoints())));
  return propertyList;
}
