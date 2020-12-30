#ifndef INVASIONITEM_H
#define INVASIONITEM_H

#include "resourceitem.h"

class Invasion;

class InvasionItem
    : public ResourceItem
{
public:
  InvasionItem(Invasion * invasion);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Invasion * mInvasion;
};

#endif // INVASIONITEM_H
