#ifndef AQUEDUCTGRIDITEM_H
#define AQUEDUCTGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class AqueductGridItem
    : public ResourceItem
{
public:
  AqueductGridItem(UnsignedByteGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  UnsignedByteGrid * mGrid;
};

#endif // AQUEDUCTGRIDITEM_H
