#include "aqueductgriditem.h"

#include "views/gridview.h"

AqueductGridItem::AqueductGridItem(UnsignedByteGrid * grid)
  : mGrid(grid)
{
  setText("Aqueduct");
}

QWidget * AqueductGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayAqueductGrid(mGrid);
  return gridView;
}

QList<Property> AqueductGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
