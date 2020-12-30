#ifndef HERDPOINTGROUP_H
#define HERDPOINTGROUP_H

#include "resourceitem.h"

class Mission;

class HerdPointGroup
    : public ResourceItem
{
public:
  HerdPointGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // HERDPOINTGROUP_H
