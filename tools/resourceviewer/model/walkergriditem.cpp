#include "walkergriditem.h"

#include "views/gridview.h"

WalkerGridItem::WalkerGridItem(const UnsignedShortGrid * grid)
  : mGrid(grid)
{
  setText("Walker");
}

QWidget * WalkerGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayWalkerGrid(mGrid);
  return gridView;
}

QList<Property> WalkerGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
