#ifndef DESIRABILITYGRIDITEM_H
#define DESIRABILITYGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class DesirabilityGridItem : public ResourceItem
{
public:
  DesirabilityGridItem(const ByteGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const ByteGrid * mGrid;
};

#endif // DESIRABILITYGRIDITEM_H
