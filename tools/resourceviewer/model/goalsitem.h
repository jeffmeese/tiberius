#ifndef GOALSITEM_H
#define GOALSITEM_H

#include "resourceitem.h"

class Scenario;

class GoalsItem : public ResourceItem
{
public:
  GoalsItem(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // GOALSITEM_H
