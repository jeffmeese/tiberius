#ifndef PRICECHANGEITEM_H
#define PRICECHANGEITEM_H

#include "resourceitem.h"

class PriceChange;

class PriceChangeItem
    : public ResourceItem
{
public:
  PriceChangeItem(PriceChange * priceChange);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  PriceChange * mPriceChange;
};

#endif // PRICECHANGEITEM_H
