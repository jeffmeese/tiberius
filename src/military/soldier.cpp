#include "soldier.h"

Soldier::Soldier()
{
  mAcademyTrained = false;
}

bool Soldier::academyTrained() const
{
  return mAcademyTrained;;
}

QString Soldier::name() const
{
  return mName;
}

void Soldier::setAcademyTrained(bool value)
{
  mAcademyTrained = value;
}

void Soldier::setName(const QString & name)
{
  mName = name;
}
