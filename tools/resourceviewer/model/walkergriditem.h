#ifndef WALKERGRIDITEM_H
#define WALKERGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class WalkerGridItem : public ResourceItem
{
public:
  WalkerGridItem(const UnsignedShortGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const UnsignedShortGrid * mGrid;
};

#endif // WALKERGRIDITEM_H
