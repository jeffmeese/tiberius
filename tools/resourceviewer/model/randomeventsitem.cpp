#include "randomeventsitem.h"

#include "mission/mission.h"

#include <QTableWidget>

RandomEventsItem::RandomEventsItem(Mission * mission)
  : mMission(mission)
{
  setText("Random Events");
}

QWidget * RandomEventsItem::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(7);
  widget->setColumnCount(2);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Event"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Enabled"));
  widget->setItem(0, 0, new QTableWidgetItem("Sea Trade Problem"));
  widget->setItem(1, 0, new QTableWidgetItem("Land Trade Problem"));
  widget->setItem(2, 0, new QTableWidgetItem("Rome Raises Wages"));
  widget->setItem(3, 0, new QTableWidgetItem("Rome Lowers Wages"));
  widget->setItem(4, 0, new QTableWidgetItem("Contaminated Water"));
  widget->setItem(5, 0, new QTableWidgetItem("Iron Mine Collapse"));
  widget->setItem(6, 0, new QTableWidgetItem("Clay Pits Flooded"));
  widget->setItem(0, 1, new QTableWidgetItem(QString::number(mMission->seaTradeProblem())));
  widget->setItem(1, 1, new QTableWidgetItem(QString::number(mMission->landTradeProblem())));
  widget->setItem(2, 1, new QTableWidgetItem(QString::number(mMission->romeRaisesWages())));
  widget->setItem(3, 1, new QTableWidgetItem(QString::number(mMission->romeLowersWages())));
  widget->setItem(4, 1, new QTableWidgetItem(QString::number(mMission->waterContamination())));
  widget->setItem(5, 1, new QTableWidgetItem(QString::number(mMission->ironMineCollapse())));
  widget->setItem(6, 1, new QTableWidgetItem(QString::number(mMission->floodedClayPits())));
  return widget;
}

QList<Property> RandomEventsItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
