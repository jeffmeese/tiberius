#ifndef DAMAGEGRIDITEM_H
#define DAMAGEGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class DamageGridItem : public ResourceItem
{
public:
  DamageGridItem(const UnsignedByteGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const UnsignedByteGrid * mGrid;
};

#endif // DAMAGEGRIDITEM_H
