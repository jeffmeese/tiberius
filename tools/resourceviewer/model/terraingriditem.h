#ifndef TERRAINGRIDITEM_H
#define TERRAINGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class TerrainGridItem : public ResourceItem
{
public:
  TerrainGridItem(UnsignedShortGrid * terrainGrid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  UnsignedShortGrid * mGrid;
};

#endif // TERRAINGRIDITEM_H
