#ifndef INVASIONGROUP_H
#define INVASIONGROUP_H

#include "resourceitem.h"

class Scenario;

class InvasionGroup : public ResourceItem
{
public:
  InvasionGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // INVASIONGROUP_H
