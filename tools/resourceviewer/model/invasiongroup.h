#ifndef INVASIONGROUP_H
#define INVASIONGROUP_H

#include "resourceitem.h"

class Mission;

class InvasionGroup : public ResourceItem
{
public:
  InvasionGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // INVASIONGROUP_H
