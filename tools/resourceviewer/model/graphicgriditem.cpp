#include "graphicgriditem.h"

#include "views/gridview.h"

GraphicGridItem::GraphicGridItem(UnsignedShortGrid * grid)
  : mGrid(grid)
{
  setText("Graphic");
}

QWidget * GraphicGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayGraphicGrid(mGrid);
  return gridView;
}

QList<Property> GraphicGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
