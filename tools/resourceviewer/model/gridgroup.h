#ifndef GRIDGROUP_H
#define GRIDGROUP_H

#include "resourceitem.h"

class Mission;

class GridGroup
    : public ResourceItem
{
public:
  GridGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // GRIDGROUP_H
