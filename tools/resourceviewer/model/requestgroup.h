#ifndef REQUESTGROUP_H
#define REQUESTGROUP_H

#include "resourceitem.h"

class Mission;

class RequestGroup
    : public ResourceItem
{
public:
  RequestGroup(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // REQUESTGROUP_H
