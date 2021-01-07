#ifndef RANDOMEVENTSITEM_H
#define RANDOMEVENTSITEM_H

#include "resourceitem.h"

class Scenario;

class RandomEventsItem
    : public ResourceItem
{
public:
  RandomEventsItem(Scenario * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Scenario * mMission;
};

#endif // RANDOMEVENTSITEM_H
