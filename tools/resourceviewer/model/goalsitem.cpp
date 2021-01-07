#include "goalsitem.h"

#include "scenario/goal.h"
#include "scenario/scenario.h"

#include <QTableWidget>

GoalsItem::GoalsItem(Scenario * mission)
  : mMission(mission)
{
  setText("Goals");
}

QWidget * GoalsItem::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(5);
  widget->setColumnCount(3);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Goal"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Enabled"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Target"));
  widget->setItem(0, 0, new QTableWidgetItem("Population"));
  widget->setItem(1, 0, new QTableWidgetItem("Culture"));
  widget->setItem(2, 0, new QTableWidgetItem("Favor"));
  widget->setItem(3, 0, new QTableWidgetItem("Peace"));
  widget->setItem(4, 0, new QTableWidgetItem("Prosperity"));
  widget->setItem(0, 1, new QTableWidgetItem(QString::number(mMission->populationGoal()->enabled())));
  widget->setItem(1, 1, new QTableWidgetItem(QString::number(mMission->cultureGoal()->enabled())));
  widget->setItem(2, 1, new QTableWidgetItem(QString::number(mMission->favorGoal()->enabled())));
  widget->setItem(3, 1, new QTableWidgetItem(QString::number(mMission->peaceGoal()->enabled())));
  widget->setItem(4, 1, new QTableWidgetItem(QString::number(mMission->prosperityGoal()->enabled())));
  widget->setItem(0, 2, new QTableWidgetItem(QString::number(mMission->populationGoal()->target())));
  widget->setItem(1, 2, new QTableWidgetItem(QString::number(mMission->cultureGoal()->target())));
  widget->setItem(2, 2, new QTableWidgetItem(QString::number(mMission->favorGoal()->target())));
  widget->setItem(3, 2, new QTableWidgetItem(QString::number(mMission->peaceGoal()->target())));
  widget->setItem(4, 2, new QTableWidgetItem(QString::number(mMission->prosperityGoal()->target())));

  return widget;
}

QList<Property> GoalsItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
