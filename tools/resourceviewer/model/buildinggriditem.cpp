#include "buildinggriditem.h"

#include "views/gridview.h"

BuildingGridItem::BuildingGridItem(const UnsignedShortGrid * grid)
  : mGrid(grid)
{
  setText("Building");
}

QWidget * BuildingGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayBuildingGrid(mGrid);
  return gridView;
}

QList<Property> BuildingGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
