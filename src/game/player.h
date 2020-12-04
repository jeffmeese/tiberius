#ifndef PLAYER_H
#define PLAYER_H

#include "tiberius.h"

#include <QString>

#include <cstdint>

class Player
{
public:
  enum class Rank
  {
    Citizen = 0,
    Clerk = 1,
    Engineer = 2,
    Architect = 3,
    Quaestor = 4,
    Procurator = 5,
    Aedile = 6,
    Praetor = 7,
    Consul = 8,
    Proconsul = 9,
    Caesar = 10
  };

public:
  TIBERIUS_LIB_DECL Player();

public:
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL int32_t personalSavings() const;
  TIBERIUS_LIB_DECL Rank rank() const;
  TIBERIUS_LIB_DECL int32_t salary() const;
  TIBERIUS_LIB_DECL Rank salaryRank() const;
  TIBERIUS_LIB_DECL QString salaryString() const;
  TIBERIUS_LIB_DECL void setName(const QString & name);
  TIBERIUS_LIB_DECL void setPersonalSavings(int32_t value);
  TIBERIUS_LIB_DECL void setRank(Rank rank);
  TIBERIUS_LIB_DECL void setSalaryRank(Rank rank);

public:
  TIBERIUS_LIB_DECL void decreaseSavings(int32_t value);
  TIBERIUS_LIB_DECL void increaseSavings(int32_t value);
  TIBERIUS_LIB_DECL QString rankString() const;

public:
  TIBERIUS_LIB_DECL static QString rankString(Rank rank);
  TIBERIUS_LIB_DECL static int32_t rankSalary(Rank rank);

private:
  QString mName;
  int32_t mPersonalSavings;
  Rank mRank;
  Rank mSalaryRank;
  int32_t mSalary;
};

#endif // PLAYER_H
