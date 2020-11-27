#include "smkitem.h"

#include <QFileInfo>

SmkItem::SmkItem(const QString & pathName)
{
  QFileInfo fileInfo(pathName);
  setText(fileInfo.fileName());
}

QWidget * SmkItem::createView() const
{
  return nullptr;
}

QList<Property> SmkItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
