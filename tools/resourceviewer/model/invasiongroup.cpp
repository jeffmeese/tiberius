#include "invasiongroup.h"
#include "invasionitem.h"

#include "mission/invasion.h"
#include "mission/mission.h"

#include <QTableWidget>

InvasionGroup::InvasionGroup(Mission * mission)
  : mMission(mission)
{
  setText("Invasions");
  for (int i = 0; i < mMission->totalInvasions(); i++) {
    QString text = "Invasion " + QString::number(i+1);
    Invasion * invasion = mMission->getInvasion(i);
    InvasionItem * item = new InvasionItem(invasion);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * InvasionGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalRequests());
  widget->setColumnCount(7);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Year"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Month"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Total Attackers"));
  widget->setHorizontalHeaderItem(3, new QTableWidgetItem("Invasion Type"));
  widget->setHorizontalHeaderItem(4, new QTableWidgetItem("Attack Type"));
  widget->setHorizontalHeaderItem(5, new QTableWidgetItem("Enemy ID"));
  widget->setHorizontalHeaderItem(6, new QTableWidgetItem("Attack Point"));
  for (int i = 0; i < mMission->totalInvasions(); i++) {
    Invasion * invasion = mMission->getInvasion(i);
    QTableWidgetItem * yearItem = new QTableWidgetItem(QString::number(invasion->year()));
    QTableWidgetItem * monthItem = new QTableWidgetItem(QString::number(invasion->month()));
    QTableWidgetItem * amountItem = new QTableWidgetItem(QString::number(invasion->amount()));
    QTableWidgetItem * typeItem = new QTableWidgetItem(QString::number(invasion->type()));
    QTableWidgetItem * attackItem = new QTableWidgetItem(QString::number(invasion->attackType()));
    QTableWidgetItem * enemyItem = new QTableWidgetItem(QString::number(invasion->enemyId()));
    QTableWidgetItem * pointItem = new QTableWidgetItem(QString::number(invasion->attackPoint()));

    widget->setItem(i, 0, yearItem);
    widget->setItem(i, 1, monthItem);
    widget->setItem(i, 2, amountItem);
    widget->setItem(i, 3, typeItem);
    widget->setItem(i, 4, attackItem);
    widget->setItem(i, 5, enemyItem);
    widget->setItem(i, 6, pointItem);
  }
  return widget;
}

QList<Property> InvasionGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Invasions", QString::number(mMission->totalInvasions())));
  return propertyList;
}

