#include "difficulty.h"

Difficulty::Difficulty()
  : mType(Type::Normal)
{
}

Difficulty::Difficulty(Type type)
  : mType(type)
{

}

int32_t Difficulty::adjustEnemyStrength(int32_t strength) const
{
  switch (mType) {
  case Type::VeryEasy:
    return strength*0.4;
  case Type::Easy:
    return strength*0.6;
  case Type::Normal:
    return strength*0.8;
  case Type::Hard:
    return strength;
  case Type::VeryHard:
    return strength*1.2;
  }

  return strength;
}

int32_t Difficulty::adjustFunds(int32_t funds) const
{
  switch (mType) {
  case Type::VeryEasy:
    return funds*3;
  case Type::Easy:
    return funds*2;
  case Type::Normal:
    return funds*1.5;
  case Type::Hard:
    return funds;
  case Type::VeryHard:
    return funds/2;
  }

  return funds;
}

int32_t Difficulty::adjustWolfAttack(int32_t strength) const
{
  switch (mType) {
  case Type::VeryEasy:
    return strength*2;
  case Type::Easy:
    return strength*4;
  case Type::Normal:
    return strength*6;
  case Type::Hard:
    return strength;
  case Type::VeryHard:
    return strength;
  }

  return strength;
}

int32_t Difficulty::initialFavor() const
{
  switch (mType) {
  case Type::VeryEasy:
    return 80;
  case Type::Easy:
    return 70;
  case Type::Normal:
    return 60;
  case Type::Hard:
    return 60;
  case Type::VeryHard:
    return 50;
  }

  return -1;
}

int32_t Difficulty::initialSentiment() const
{
  switch (mType) {
  case Type::VeryEasy:
    return 70;
  case Type::Easy:
    return 60;
  case Type::Normal:
    return 50;
  case Type::Hard:
    return 50;
  case Type::VeryHard:
    return 40;
  }

  return -1;
}

void Difficulty::setType(Type type)
{
  mType = type;
}

void Difficulty::decrease()
{
  switch (mType) {
    case Type::VeryEasy:
      mType = Type::VeryEasy;
      break;
    case Type::Easy:
      mType = Type::VeryEasy;
      break;
    case Type::Normal:
      mType = Type::Easy;
      break;
    case Type::Hard:
      mType = Type::Normal;
      break;
    case Type::VeryHard:
      mType = Type::Hard;
      break;
  }
}

void Difficulty::increase()
{
  switch (mType) {
    case Type::VeryEasy:
      mType = Type::Easy;
      break;
    case Type::Easy:
      mType = Type::Normal;
      break;
    case Type::Normal:
      mType = Type::Hard;
      break;
    case Type::Hard:
      mType = Type::VeryHard;
      break;
    case Type::VeryHard:
      mType = Type::VeryHard;
      break;
  }
}
