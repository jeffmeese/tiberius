#include "legion.h"

#include "soldier.h"

Legion::Legion(Type type)
  : mType(type)
{
  mAcademyTrained = false;
  mEmpireService = false;
}

Legion::~Legion()
{

}

bool Legion::academyTrained() const
{
  return mAcademyTrained;
}

void Legion::addSolider(std::unique_ptr<Soldier> soldier)
{
  mSoldiers.push_back(std::move(soldier));
}

bool Legion::empireService() const
{
  return mEmpireService;
}

QString Legion::name() const
{
  return mName;
}

void Legion::removeSolider(const QString & name)
{
  for (SoldierVector::iterator itr = mSoldiers.begin(); itr != mSoldiers.end(); ++itr) {
    if (itr->get()->name() == name) {
      mSoldiers.erase(itr);
      return;
    }
  }
}

void Legion::setAcademyTrained(bool value)
{
  mAcademyTrained = value;
}

void Legion::setEmpireService(bool value)
{
  mEmpireService = value;
}

void Legion::setName(const QString & name)
{
  mName = name;
}

int32_t Legion::totalSoldiers() const
{
  return static_cast<int32_t>(mSoldiers.size());
}

Legion::Type Legion::type()
{
  return mType;
}
