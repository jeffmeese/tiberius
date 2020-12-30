#include "demandchangegroup.h"
#include "demandchangeitem.h"

#include "mission/demandchange.h"
#include "mission/mission.h"

#include <QTableWidget>

DemandChangeGroup::DemandChangeGroup(Mission * mission)
  : mMission(mission)
{
  setText("Demand Changes");
  for (int i = 0; i < mMission->totalDemandChanges(); i++) {
    QString text = "Demand Change " + QString::number(i+1);
    DemandChange * change = mMission->getDemandChange(i);
    DemandChangeItem * item = new DemandChangeItem(change);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * DemandChangeGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalDemandChanges());
  widget->setColumnCount(5);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Year"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Month"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Resource"));
  widget->setHorizontalHeaderItem(3, new QTableWidgetItem("Route"));
  widget->setHorizontalHeaderItem(4, new QTableWidgetItem("Rise/Fall"));
  for (int i = 0; i < mMission->totalDemandChanges(); i++) {
    DemandChange * demandChange = mMission->getDemandChange(i);
    QTableWidgetItem * yearItem = new QTableWidgetItem(QString::number(demandChange->year()));
    QTableWidgetItem * monthItem = new QTableWidgetItem(QString::number(demandChange->month()));
    QTableWidgetItem * resourceItem = new QTableWidgetItem(QString::number(demandChange->resourceId()));
    QTableWidgetItem * routeItem = new QTableWidgetItem(QString::number(demandChange->routeId()));
    QTableWidgetItem * riseItem = new QTableWidgetItem(QString::number(demandChange->rise()));

    widget->setItem(i, 0, yearItem);
    widget->setItem(i, 1, monthItem);
    widget->setItem(i, 2, resourceItem);
    widget->setItem(i, 3, routeItem);
    widget->setItem(i, 4, riseItem);
  }
  return widget;
}

QList<Property> DemandChangeGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Demand Changes", QString::number(mMission->totalDemandChanges())));
  return propertyList;
}
