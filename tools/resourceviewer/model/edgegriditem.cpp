#include "edgegriditem.h"

#include "views/gridview.h"

EdgeGridItem::EdgeGridItem(UnsignedByteGrid * grid)
  : mGrid(grid)
{
  setText("Edge");
}

QWidget * EdgeGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayEdgeGrid(mGrid);
  return gridView;
}

QList<Property> EdgeGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
