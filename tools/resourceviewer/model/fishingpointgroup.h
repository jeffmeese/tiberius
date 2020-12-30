#ifndef FISHINGPOINTGROUP_H
#define FISHINGPOINTGROUP_H

#include "resourceitem.h"

class Mission;

class FishingPointGroup
    : public ResourceItem
{
public:
  FishingPointGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // FISHINGPOINTGROUP_H
