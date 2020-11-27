#ifndef MAPITEM_H
#define MAPITEM_H

#include "resourceitem.h"

class MapItem
    : public ResourceItem
{
public:
  MapItem(const QString & pathName);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;
};

#endif // MAPITEM_H
