#ifndef RANDOMEVENTSITEM_H
#define RANDOMEVENTSITEM_H

#include "resourceitem.h"

class Mission;

class RandomEventsItem
    : public ResourceItem
{
public:
  RandomEventsItem(Mission * mission);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Mission * mMission;
};

#endif // RANDOMEVENTSITEM_H
