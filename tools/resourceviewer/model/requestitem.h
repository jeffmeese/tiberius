#ifndef REQUESTITEM_H
#define REQUESTITEM_H

#include "resourceitem.h"

class EmperorRequest;

class RequestItem
    : public ResourceItem
{
public:
  RequestItem(EmperorRequest * request);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  EmperorRequest * mRequest;
};

#endif // REQUESTITEM_H
