#ifndef DEMANDCHANGEGROUP_H
#define DEMANDCHANGEGROUP_H

#include "resourceitem.h"

class Mission;

class DemandChangeGroup
    : public ResourceItem
{
public:
  DemandChangeGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // DEMANDCHANGEGROUP_H
