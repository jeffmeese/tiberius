#ifndef SMKITEM_H
#define SMKITEM_H

#include "resourceitem.h"

class SmkItem
    : public ResourceItem
{
public:
  SmkItem(const QString & pathName);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;
};

#endif // SMKITEM_H
