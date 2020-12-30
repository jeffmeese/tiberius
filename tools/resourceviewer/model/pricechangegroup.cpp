#include "pricechangegroup.h"
#include "pricechangeitem.h"

#include "mission/mission.h"
#include "mission/pricechange.h"

#include <QTableWidget>

PriceChangeGroup::PriceChangeGroup(Mission * mission)
  : mMission(mission)
{
  setText("Price Changes");
  for (int i = 0; i < mMission->totalPriceChanges(); i++) {
    QString text = "Price Change " + QString::number(i+1);
    PriceChange * priceChange = mMission->getPriceChange(i);
    PriceChangeItem * item = new PriceChangeItem(priceChange);
    item->setText(text);
    appendRow(item);
  }
}

QWidget * PriceChangeGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalPriceChanges());
  widget->setColumnCount(5);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Year"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Month"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Resource"));
  widget->setHorizontalHeaderItem(3, new QTableWidgetItem("Amount"));
  widget->setHorizontalHeaderItem(4, new QTableWidgetItem("Rise/Fall"));
  for (int i = 0; i < mMission->totalPriceChanges(); i++) {
    PriceChange * priceChange = mMission->getPriceChange(i);
    QTableWidgetItem * yearItem = new QTableWidgetItem(QString::number(priceChange->year()));
    QTableWidgetItem * monthItem = new QTableWidgetItem(QString::number(priceChange->month()));
    QTableWidgetItem * resourceItem = new QTableWidgetItem(QString::number(priceChange->resourceId()));
    QTableWidgetItem * amountItem = new QTableWidgetItem(QString::number(priceChange->amount()));
    QTableWidgetItem * riseItem = new QTableWidgetItem(QString::number(priceChange->rise()));

    widget->setItem(i, 0, yearItem);
    widget->setItem(i, 1, monthItem);
    widget->setItem(i, 2, resourceItem);
    widget->setItem(i, 3, amountItem);
    widget->setItem(i, 4, riseItem);
  }
  return widget;
}

QList<Property> PriceChangeGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Price Changes", QString::number(mMission->totalPriceChanges())));
  return propertyList;
}
