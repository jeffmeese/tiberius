#include "herdpointitem.h"

#include "map/location.h"

HerdPointItem::HerdPointItem(Location * location)
  : mLocation(location)
{

}

QWidget * HerdPointItem::createView() const
{
  return nullptr;
}

QList<Property> HerdPointItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("X", QString::number(mLocation->x())));
  propertyList.append(Property("Y", QString::number(mLocation->y())));
  return propertyList;
}
