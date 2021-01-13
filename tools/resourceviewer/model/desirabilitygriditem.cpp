#include "desirabilitygriditem.h"

#include "views/gridview.h"

DesirabilityGridItem::DesirabilityGridItem(const ByteGrid * grid)
  : mGrid(grid)
{
  setText("Desirability");
}

QWidget * DesirabilityGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayDesirabilityGrid(mGrid);
  return gridView;
}

QList<Property> DesirabilityGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
