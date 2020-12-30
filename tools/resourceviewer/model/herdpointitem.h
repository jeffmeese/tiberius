#ifndef HERDPOINTITEM_H
#define HERDPOINTITEM_H

#include "resourceitem.h"

class Location;

class HerdPointItem
    : public ResourceItem
{
public:
  HerdPointItem(Location * location);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Location * mLocation;
};

#endif // HERDPOINTITEM_H
