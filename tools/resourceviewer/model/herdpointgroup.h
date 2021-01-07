#ifndef HERDPOINTGROUP_H
#define HERDPOINTGROUP_H

#include "resourceitem.h"

class Scenario;

class HerdPointGroup
    : public ResourceItem
{
public:
  HerdPointGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // HERDPOINTGROUP_H
