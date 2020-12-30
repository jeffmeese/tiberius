#ifndef EDGEGRIDITEM_H
#define EDGEGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class EdgeGridItem
    : public ResourceItem
{
public:
  EdgeGridItem(UnsignedByteGrid * edgeGrid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  UnsignedByteGrid * mGrid;
};

#endif // EDGEGRIDITEM_H
