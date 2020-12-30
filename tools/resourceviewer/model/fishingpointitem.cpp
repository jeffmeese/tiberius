#include "fishingpointitem.h"

#include "map/location.h"

FishingPointItem::FishingPointItem(Location * location)
  : mLocation(location)
{

}

QWidget * FishingPointItem::createView() const
{
  return nullptr;
}

QList<Property> FishingPointItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("X", QString::number(mLocation->x())));
  propertyList.append(Property("Y", QString::number(mLocation->y())));
  return propertyList;
}
