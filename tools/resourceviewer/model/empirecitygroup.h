#ifndef EMPIRECITYGROUP_H
#define EMPIRECITYGROUP_H

#include "resourceitem.h"

class City;

class EmpireCityGroup
    : public ResourceItem
{
public:
  EmpireCityGroup(City * city);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  City * mCity;
};

#endif // EMPIRECITYGROUP_H
