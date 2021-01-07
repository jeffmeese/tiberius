#include "invasionitem.h"

#include "scenario/invasion.h"

InvasionItem::InvasionItem(Invasion * invasion)
  : mInvasion(invasion)
{
}

QWidget * InvasionItem::createView() const
{
  return nullptr;
}

QList<Property> InvasionItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Year", QString::number(mInvasion->year())));
  propertyList.append(Property("Month", QString::number(mInvasion->month())));
  propertyList.append(Property("Attackers", QString::number(mInvasion->amount())));
  propertyList.append(Property("Invasion Type", QString::number(mInvasion->type())));
  propertyList.append(Property("Attack Type", QString::number(mInvasion->attackType())));
  propertyList.append(Property("Enemy", QString::number(mInvasion->enemyId())));
  return propertyList;
}
