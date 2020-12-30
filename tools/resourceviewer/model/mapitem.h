#ifndef MAPITEM_H
#define MAPITEM_H

#include "resourceitem.h"

class DemandChangeGroup;
class FishingPointGroup;
class GoalsItem;
class GridGroup;
class HerdPointGroup;
class InvasionGroup;
class InvasionPointsGroup;
class Mission;
class PriceChangeGroup;
class RandomEventsItem;
class RequestGroup;

class MapItem
    : public ResourceItem
{
public:
  MapItem(const QString & pathName);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  std::unique_ptr<Mission> mMission;
  DemandChangeGroup * mDemandChangeGroup;
  FishingPointGroup * mFishingPointGroup;
  GoalsItem * mGoalsItem;
  GridGroup * mGridGroup;
  HerdPointGroup * mHerdPointGroup;
  InvasionGroup * mInvasionGroup;
  InvasionPointsGroup * mInvasionPointGroup;
  PriceChangeGroup * mPriceChangeGroup;
  RandomEventsItem * mRandomEventsItem;
  RequestGroup * mRequestGroup;
};

#endif // MAPITEM_H
