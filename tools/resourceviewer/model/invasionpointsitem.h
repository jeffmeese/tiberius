#ifndef INVASIONPOINTSITEM_H
#define INVASIONPOINTSITEM_H

#include "resourceitem.h"

class Location;

class InvasionPointsItem
    : public ResourceItem
{
public:
  InvasionPointsItem(Location * location);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Location * mLocation;
};

#endif // INVASIONPOINTSITEM_H
