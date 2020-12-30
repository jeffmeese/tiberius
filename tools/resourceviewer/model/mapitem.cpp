#include "mapitem.h"

#include "demandchangegroup.h"
#include "fishingpointgroup.h"
#include "goalsitem.h"
#include "gridgroup.h"
#include "herdpointgroup.h"
#include "invasiongroup.h"
#include "invasionpointsgroup.h"
#include "pricechangegroup.h"
#include "randomeventsitem.h"
#include "requestgroup.h"

#include "game/player.h"

#include "mission/emperorrequest.h"
#include "mission/mission.h"

#include <QFileInfo>

MapItem::MapItem(const QString & pathName)
{
  QFileInfo fileInfo(pathName);
  setText(fileInfo.fileName());

  mMission.reset(new Mission);
  mMission->loadFromFile(pathName);

  mDemandChangeGroup = new DemandChangeGroup(mMission.get());
  mFishingPointGroup = new FishingPointGroup(mMission.get());
  mGoalsItem = new GoalsItem(mMission.get());
  mGridGroup = new GridGroup(mMission.get());
  mHerdPointGroup = new HerdPointGroup(mMission.get());
  mInvasionGroup = new InvasionGroup(mMission.get());
  mInvasionPointGroup = new InvasionPointsGroup(mMission.get());
  mPriceChangeGroup = new PriceChangeGroup(mMission.get());
  mRandomEventsItem = new RandomEventsItem(mMission.get());
  mRequestGroup = new RequestGroup(mMission.get());

  appendRow(mDemandChangeGroup);
  appendRow(mFishingPointGroup);
  appendRow(mGoalsItem);
  appendRow(mGridGroup);
  appendRow(mHerdPointGroup);
  appendRow(mInvasionGroup);
  appendRow(mInvasionPointGroup);
  appendRow(mPriceChangeGroup);
  appendRow(mRandomEventsItem);
  appendRow(mRequestGroup);
}

QWidget * MapItem::createView() const
{
  return nullptr;
}

QList<Property> MapItem::getProperties() const
{
  QList<Property> propertyList;

  propertyList.append(Property("Camera X", QString::number(mMission->cameraX())));
  propertyList.append(Property("Camera Y", QString::number(mMission->cameraY())));
  propertyList.append(Property("Description", mMission->description()));
  propertyList.append(Property("Start Year", QString::number(mMission->startYear())));
  propertyList.append(Property("Empire Location", QString::number(mMission->empireLocation())));
  propertyList.append(Property("Enemy Nationality", QString::number(mMission->enemyId())));
  propertyList.append(Property("Image ID", QString::number(mMission->imageId())));
  propertyList.append(Property("Is Open Play", QString::number(mMission->openPlay())));
  propertyList.append(Property("Initial Funds", QString::number(mMission->initialFunds())));
  propertyList.append(Property("Initial Rank", QString::number(mMission->initialRank())));
  propertyList.append(Property("Map Width", QString::number(mMission->mapWidth())));
  propertyList.append(Property("Map Height", QString::number(mMission->mapHeight())));
  propertyList.append(Property("Emperor Change", QString::number(mMission->emperorChange())));
  propertyList.append(Property("Emperor Change Year", QString::number(mMission->emperorChangeYear())));
  propertyList.append(Property("Gladiator Revolt", QString::number(mMission->gladiatorRevolt())));
  propertyList.append(Property("Gladiator Revolt Year", QString::number(mMission->gladiatorRevoltYear())));
  propertyList.append(Property("Rome Supplies Wheat", QString::number(mMission->romeSuppliesWheat())));
  propertyList.append(Property("Rescue Loan", QString::number(mMission->rescueLoan())));
  propertyList.append(Property("Flotsam", QString::number(mMission->flotsam())));
  propertyList.append(Property("Open Play ID", QString::number(mMission->openPlayId())));

  return propertyList;
}
