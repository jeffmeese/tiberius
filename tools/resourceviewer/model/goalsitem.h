#ifndef GOALSITEM_H
#define GOALSITEM_H

#include "resourceitem.h"

class Mission;

class GoalsItem : public ResourceItem
{
public:
  GoalsItem(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // GOALSITEM_H
