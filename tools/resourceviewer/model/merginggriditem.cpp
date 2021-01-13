#include "merginggriditem.h"

#include "views/gridview.h"

MergingGridItem::MergingGridItem(const UnsignedByteGrid * grid)
  : mGrid(grid)
{
  setText("Merging");
}

QWidget * MergingGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayMergingGrid(mGrid);
  return gridView;
}

QList<Property> MergingGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
