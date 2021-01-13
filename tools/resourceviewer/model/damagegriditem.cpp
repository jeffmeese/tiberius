#include "damagegriditem.h"

#include "views/gridview.h"

DamageGridItem::DamageGridItem(const UnsignedByteGrid * grid)
  : mGrid(grid)
{
  setText("Damage");
}

QWidget * DamageGridItem::createView() const
{
  GridView * gridView = new GridView;
  gridView->displayDamageGrid(mGrid);
  return gridView;
}

QList<Property> DamageGridItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
