#include "requestgroup.h"
#include "requestitem.h"

#include "properties/property.h"

#include "scenario/emperorrequest.h"
#include "scenario/scenario.h"

#include <QTableWidget>

RequestGroup::RequestGroup(Scenario * mission)
  : mMission(mission)
{
  setText("Requests");
  for (int i = 0; i < mMission->totalRequests(); i++) {
    QString text = "Request " + QString::number(i+1);
    EmperorRequest * request = mMission->getRequest(i);
    RequestItem * requestItem = new RequestItem(request);
    requestItem->setText(text);
    appendRow(requestItem);
  }
}

QWidget * RequestGroup::createView() const
{
  QTableWidget * widget = new QTableWidget;
  widget->setRowCount(mMission->totalRequests());
  widget->setColumnCount(6);
  widget->setHorizontalHeaderItem(0, new QTableWidgetItem("Year"));
  widget->setHorizontalHeaderItem(1, new QTableWidgetItem("Month"));
  widget->setHorizontalHeaderItem(2, new QTableWidgetItem("Resource"));
  widget->setHorizontalHeaderItem(3, new QTableWidgetItem("Amount"));
  widget->setHorizontalHeaderItem(4, new QTableWidgetItem("Deadline"));
  widget->setHorizontalHeaderItem(5, new QTableWidgetItem("Favor"));
  for (int i = 0; i < mMission->totalRequests(); i++) {
    EmperorRequest * request = mMission->getRequest(i);
    QTableWidgetItem * yearItem = new QTableWidgetItem(QString::number(request->year()));
    QTableWidgetItem * monthItem = new QTableWidgetItem(QString::number(request->month()));
    QTableWidgetItem * favorItem = new QTableWidgetItem(QString::number(request->favor()));
    QTableWidgetItem * amountItem = new QTableWidgetItem(QString::number(request->amount()));
    QTableWidgetItem * resourceItem = new QTableWidgetItem(QString::number(request->resourceId()));
    QTableWidgetItem * deadlineItem = new QTableWidgetItem(QString::number(request->deadline()));

    widget->setItem(i, 0, yearItem);
    widget->setItem(i, 1, monthItem);
    widget->setItem(i, 2, resourceItem);
    widget->setItem(i, 3, amountItem);
    widget->setItem(i, 4, deadlineItem);
    widget->setItem(i, 5, favorItem);
  }
  return widget;
}

QList<Property> RequestGroup::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Total Requests", QString::number(mMission->totalRequests())));
  return propertyList;
}
