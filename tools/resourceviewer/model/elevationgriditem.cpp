#include "elevationgriditem.h"

#include "views/gridview.h"

ElevationGridItem::ElevationGridItem(UnsignedByteGrid * grid)
  : mGrid(grid)
{
  setText("Elevation");
}

QWidget * ElevationGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayElevationGrid(mGrid);
  return gridView;
}

QList<Property> ElevationGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
