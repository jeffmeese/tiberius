#include "player.h"

#include "application/tiberiusapplication.h"

#include "language/language.h"
#include "language/stringdata.h"

static const int32_t RANK_SALARY[] =
{
  0, 2, 5, 8, 12, 20, 30, 40, 60, 80, 100
};

Player::Player()
{
  mRank = Rank::Citizen;
  mSalaryRank = Rank::Citizen;
  mPersonalSavings = 2245;
  mSalary = 0;
}

void Player::decreaseSavings(int32_t value)
{
  mPersonalSavings -= value;
  if (mPersonalSavings < 0)
    mPersonalSavings = 0;
}

void Player::increaseSavings(int32_t value)
{
  mPersonalSavings += value;
  if (mPersonalSavings < 0) // Just in case someone throws a negative in
    mPersonalSavings = 0;
}

QString Player::name() const
{
  return mName;
}

int32_t Player::personalSavings() const
{
  return mPersonalSavings;
}

Player::Rank Player::rank() const
{
  return mRank;
}

int32_t Player::rankSalary(Rank rank)
{
  return RANK_SALARY[static_cast<int32_t>(rank)];
}

QString Player::rankString() const
{
  return rankString(mRank);
}

QString Player::rankString(Rank rank)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(32, static_cast<int32_t>(rank));
}

int32_t Player::salary() const
{
  return rankSalary(mSalaryRank);
}

Player::Rank Player::salaryRank() const
{
  return mSalaryRank;
}

QString Player::salaryString() const
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(52, static_cast<int32_t>(mSalaryRank)+4) + " " + QString::number(rankSalary(mSalaryRank));
}

void Player::setName(const QString & name)
{
  mName = name;
}

void Player::setPersonalSavings(int32_t value)
{
  mPersonalSavings = value;
}

void Player::setRank(Rank rank)
{
  mRank = rank;
}

void Player::setSalaryRank(Rank value)
{
  mSalaryRank = value;
}
