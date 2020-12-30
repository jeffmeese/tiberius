#ifndef GRAPHICGRIDITEM_H
#define GRAPHICGRIDITEM_H

#include "resourceitem.h"

#include "map/grid.h"

class GraphicGridItem
    : public ResourceItem
{
public:
  GraphicGridItem(UnsignedShortGrid * graphicGrid);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  UnsignedShortGrid * mGrid;
};

#endif // GRAPHICGRIDITEM_H
