#include "invasionpointsitem.h"

#include "map/location.h"

InvasionPointsItem::InvasionPointsItem(Location * location)
  : mLocation(location)
{

}

QWidget * InvasionPointsItem::createView() const
{
  return nullptr;
}

QList<Property> InvasionPointsItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("X", QString::number(mLocation->x())));
  propertyList.append(Property("Y", QString::number(mLocation->y())));
  return propertyList;
}
