#include "terraingriditem.h"

#include "views/gridview.h"

TerrainGridItem::TerrainGridItem(UnsignedShortGrid * grid)
  : mGrid(grid)
{
  setText("Terrain");
}

QWidget * TerrainGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayTerrainGrid(mGrid);
  return gridView;
}

QList<Property> TerrainGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
