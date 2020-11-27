#ifndef RESOURCEITEM_H
#define RESOURCEITEM_H

#include <QStandardItem>

#include "properties/property.h"

class ResourceItem
    : public QStandardItem
{
public:
  ResourceItem();

public:
  virtual QWidget * createView() const = 0;
  virtual QList<Property> getProperties() const = 0;
};

#endif // RESOURCEITEM_H
