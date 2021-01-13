#ifndef GRIDGROUP_H
#define GRIDGROUP_H

#include "resourceitem.h"

class Scenario;

class GridGroup
    : public ResourceItem
{
public:
  GridGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mScenario;
};

#endif // GRIDGROUP_H
