#ifndef INVASIONPOINTSGROUP_H
#define INVASIONPOINTSGROUP_H

#include "resourceitem.h"

class Scenario;

class InvasionPointsGroup
    : public ResourceItem
{
public:
  InvasionPointsGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // INVASIONPOINTSGROUP_H
