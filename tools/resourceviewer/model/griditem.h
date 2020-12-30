#ifndef GRIDITEM_H
#define GRIDITEM_H

#include "resourceitem.h"

class GridItem
    : public ResourceItem
{
public:
  GridItem();

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;
};

#endif // GRIDITEM_H
