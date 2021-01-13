#ifndef MERGINGGRIDITEM_H
#define MERGINGGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class MergingGridItem : public ResourceItem
{
public:
  MergingGridItem(const UnsignedByteGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const UnsignedByteGrid * mGrid;
};

#endif // MERGINGGRIDITEM_H
