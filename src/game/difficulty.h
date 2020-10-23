#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QString>

#include "tiberius.h"

class Difficulty
{
public:
  enum class Type
  {
    VeryEasy = 1,
    Easy = 2,
    Normal = 3,
    Hard = 4,
    VeryHard = 5
  };

public:
  TIBERIUS_LIB_DECL Difficulty();
  TIBERIUS_LIB_DECL Difficulty(Type type);

public:
  TIBERIUS_LIB_DECL int32_t initialFavor() const;
  TIBERIUS_LIB_DECL int32_t initialSentiment() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL int32_t adjustEnemyStrength(int32_t strength) const;
  TIBERIUS_LIB_DECL int32_t adjustFunds(int32_t funds) const;
  TIBERIUS_LIB_DECL int32_t adjustWolfAttack(int32_t strength) const;

public:
  TIBERIUS_LIB_DECL void decrease();
  TIBERIUS_LIB_DECL void increase();

private:
  int32_t mInitialFavor;
  int32_t mInitialSentiment;
  Type mType;
};

inline Difficulty::Type Difficulty::type() const
{
  return mType;
}

#endif // DIFFICULTY_H
