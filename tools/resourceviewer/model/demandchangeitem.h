#ifndef DEMANDCHANGEITEM_H
#define DEMANDCHANGEITEM_H

#include "resourceitem.h"

class DemandChange;

class DemandChangeItem
    : public ResourceItem
{
public:
  DemandChangeItem(DemandChange * demandChange);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  DemandChange * mDemandChange;
};

#endif // DEMANDCHANGEITEM_H
