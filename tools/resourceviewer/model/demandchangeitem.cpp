#include "demandchangeitem.h"

#include "event/demandchange.h"

DemandChangeItem::DemandChangeItem(DemandChange * demandChange)
  : mDemandChange(demandChange)
{

}

QWidget * DemandChangeItem::createView() const
{
  return nullptr;
}

QList<Property> DemandChangeItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Year", QString::number(mDemandChange->year())));
  propertyList.append(Property("Month", QString::number(mDemandChange->month())));
  propertyList.append(Property("Resource", QString::number(mDemandChange->resourceId())));
  propertyList.append(Property("Route", QString::number(mDemandChange->routeId())));
  propertyList.append(Property("Rise/Fall", QString::number(mDemandChange->rise())));
  return propertyList;
}
