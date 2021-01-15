#include "empirecitygroup.h"
#include "empirecityitem.h"

#include "city/city.h"
#include "city/empiredata.h"

#include "empire/city.h"

#include <QTableWidget>

EmpireCityGroup::EmpireCityGroup(City * city)
  : mCity(city)
{
  setText("Empire Cities");
  for (int i = 0; i < EmpireData::MAX_CITIES; i++) {
    appendRow(new EmpireCityItem(mCity->empireData()->get(i)));
  }
}

QWidget * EmpireCityGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(EmpireData::MAX_CITIES);
  widget->setColumnCount(6);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name ID"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Is Use"));
  widget->setHorizontalHeaderItem(3, new QTableWidgetItem("Trade Route Cost"));
  widget->setHorizontalHeaderItem(4, new QTableWidgetItem("Number of resources sold"));
  widget->setHorizontalHeaderItem(5, new QTableWidgetItem("Number of resources bought"));
  for (int i = 0; i < EmpireData::MAX_CITIES; i++) {
    Empire::City * city = mCity->empireData()->get(i);
    QTableWidgetItem * nameItem = new QTableWidgetItem(city->getName());
    QTableWidgetItem * typeItem = new QTableWidgetItem(city->getType());
    QTableWidgetItem * inUseItem = new QTableWidgetItem(QString::number(city->inUse()));
    QTableWidgetItem * tradeCostItem = new QTableWidgetItem(QString::number(city->tradeRouteCode()));
    int32_t numBought = 0;
    int32_t numSold = 0;
    for (int j = 0; j < Resource::MAX_RESOURCES; j++) {
      if (city->buyFlag(j)) numBought++;
      if (city->sellFlag(j)) numSold++;
    }

    QTableWidgetItem * soldItem = new QTableWidgetItem(QString::number(numSold));
    QTableWidgetItem * boughtItem = new QTableWidgetItem(QString::number(numBought));

    widget->setItem(i, 0, nameItem);
    widget->setItem(i, 1, typeItem);
    widget->setItem(i, 2, inUseItem);
    widget->setItem(i, 3, tradeCostItem);
    widget->setItem(i, 4, soldItem);
    widget->setItem(i, 5, boughtItem);
  }
  return widget;
}

QList<Property> EmpireCityGroup::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
