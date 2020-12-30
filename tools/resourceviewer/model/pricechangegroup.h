#ifndef PRICECHANGEGROUP_H
#define PRICECHANGEGROUP_H

#include "resourceitem.h"

class Mission;

class PriceChangeGroup
    : public ResourceItem
{
public:
  PriceChangeGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // PRICECHANGEGROUP_H
