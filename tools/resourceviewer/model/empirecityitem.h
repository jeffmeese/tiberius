#ifndef EMPIRECITYITEM_H
#define EMPIRECITYITEM_H

#include "resourceitem.h"

namespace Empire
{
  class City;
}

class EmpireCityItem
    : public ResourceItem
{
public:
  EmpireCityItem(Empire::City * city);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Empire::City * mCity;
};

#endif // EMPIRECITYITEM_H
