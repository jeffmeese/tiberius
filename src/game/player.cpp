#include "player.h"

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

int32_t Player::salary() const
{
  return salaryForRank(mSalaryRank);
}

Player::Rank Player::salaryRank() const
{
  return mSalaryRank;
}

int32_t Player::salaryForRank(Rank rank)
{
  switch (rank)
  {
  case Rank::Citizen:
    return 0;
  case Rank::Clerk:
    return 2;
  case Rank::Engineer:
    return 5;
  case Rank::Architect:
    return 8;
  case Rank::Quaestor:
    return 12;
  case Rank::Procurator:
    return 20;
  case Rank::Aedile:
    return 30;
  case Rank::Praetor:
    return 40;
  case Rank::Consul:
    return 60;
  case Rank::Proconsul:
    return 80;
  case Rank::Caesar:
    return 100;
  }

  return 0;
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
