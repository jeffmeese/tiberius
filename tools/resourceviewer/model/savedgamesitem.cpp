#include "savedgamesitem.h"

SavedGamesItem::SavedGamesItem()
{
  setText("Saved Games");
}

QWidget * SavedGamesItem::createView() const
{
  return nullptr;
}

QList<Property> SavedGamesItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
