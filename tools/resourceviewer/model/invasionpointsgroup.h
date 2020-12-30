#ifndef INVASIONPOINTSGROUP_H
#define INVASIONPOINTSGROUP_H

#include "resourceitem.h"

class Mission;

class InvasionPointsGroup
    : public ResourceItem
{
public:
  InvasionPointsGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // INVASIONPOINTSGROUP_H
