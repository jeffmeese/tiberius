#ifndef FISHINGPOINTITEM_H
#define FISHINGPOINTITEM_H

#include "resourceitem.h"

class Location;

class FishingPointItem
    : public ResourceItem
{
public:
  FishingPointItem(Location * location);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Location * mLocation;
};

#endif // FISHINGPOINTITEM_H
