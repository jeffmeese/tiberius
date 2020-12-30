#ifndef ELEVATIONGRIDITEM_H
#define ELEVATIONGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class ElevationGridItem
    : public ResourceItem
{
public:
  ElevationGridItem(UnsignedByteGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
    UnsignedByteGrid * mGrid;
};

#endif // ELEVATIONGRIDITEM_H
