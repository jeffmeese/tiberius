#ifndef PRICECHANGEGROUP_H
#define PRICECHANGEGROUP_H

#include "resourceitem.h"

class Scenario;

class PriceChangeGroup
    : public ResourceItem
{
public:
  PriceChangeGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // PRICECHANGEGROUP_H
