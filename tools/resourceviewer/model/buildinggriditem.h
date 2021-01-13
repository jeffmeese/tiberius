#ifndef BUILDINGGRIDITEM_H
#define BUILDINGGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class BuildingGridItem : public ResourceItem
{
public:
  BuildingGridItem(const UnsignedShortGrid * grid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const UnsignedShortGrid * mGrid;
};

#endif // BUILDINGGRIDITEM_H
