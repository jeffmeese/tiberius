#include "empirecityitem.h"

#include "city/city.h"
#include "city/resourcedata.h"

#include "empire/city.h"

#include <QTableWidget>

EmpireCityItem::EmpireCityItem(Empire::City * city)
  : mCity(city)
{
  setText(city->getName());
}

QWidget * EmpireCityItem::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(Resource::MAX_RESOURCES);
  widget->setColumnCount(3);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Resource"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Buying?"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Selling?"));
  for (int i = 0; i < Resource::MAX_RESOURCES; i++) {
    QString resourceName = Resource::getString(Resource::Type(i));

    uint8_t buy = mCity->buyFlag(i);
    uint8_t sell = mCity->sellFlag(i);
    QTableWidgetItem * nameItem = new QTableWidgetItem(resourceName);
    QTableWidgetItem * buyItem = new QTableWidgetItem(QString::number(buy));
    QTableWidgetItem * sellItem = new QTableWidgetItem(QString::number(sell));

    widget->setItem(i, 0, nameItem);
    widget->setItem(i, 1, buyItem);
    widget->setItem(i, 2, sellItem);
  }
  return widget;
}

QList<Property> EmpireCityItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
