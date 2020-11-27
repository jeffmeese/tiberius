#include "mapitem.h"

#include <QFileInfo>

MapItem::MapItem(const QString & pathName)
{
  QFileInfo fileInfo(pathName);
  setText(fileInfo.fileName());
}

QWidget * MapItem::createView() const
{
  return nullptr;
}

QList<Property> MapItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
