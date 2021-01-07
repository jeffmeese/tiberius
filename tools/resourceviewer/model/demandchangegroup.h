#ifndef DEMANDCHANGEGROUP_H
#define DEMANDCHANGEGROUP_H

#include "resourceitem.h"

class Scenario;

class DemandChangeGroup
    : public ResourceItem
{
public:
  DemandChangeGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // DEMANDCHANGEGROUP_H
