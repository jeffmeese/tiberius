#ifndef FISHINGPOINTGROUP_H
#define FISHINGPOINTGROUP_H

#include "resourceitem.h"

class Scenario;

class FishingPointGroup
    : public ResourceItem
{
public:
  FishingPointGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // FISHINGPOINTGROUP_H
