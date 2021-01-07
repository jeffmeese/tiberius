#ifndef REQUESTGROUP_H
#define REQUESTGROUP_H

#include "resourceitem.h"

class Scenario;

class RequestGroup
    : public ResourceItem
{
public:
  RequestGroup(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // REQUESTGROUP_H
