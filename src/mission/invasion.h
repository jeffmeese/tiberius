#ifndef INVASION_H
#define INVASION_H

#include "tiberius.h"
#include "event.h"

#include <QDataStream>

class Invasion
    : public Event
{
public:
  TIBERIUS_LIB_DECL Invasion();

public:
  TIBERIUS_LIB_DECL int32_t amount() const;
  TIBERIUS_LIB_DECL int32_t attackPoint() const;
  TIBERIUS_LIB_DECL int32_t attackType() const;
  TIBERIUS_LIB_DECL int32_t enemyId() const;
  TIBERIUS_LIB_DECL int32_t type() const;
  TIBERIUS_LIB_DECL void setAmount(int32_t value);
  TIBERIUS_LIB_DECL void setAttackPoint(int32_t value);
  TIBERIUS_LIB_DECL void setAttackType(int32_t value);
  TIBERIUS_LIB_DECL void setEnemyId(int32_t value);
  TIBERIUS_LIB_DECL void setType(int32_t value);

private:
  int32_t mAmount;
  int32_t mAttackPoint;
  int32_t mAttackType;
  int32_t mEnemyId;
  int32_t mType;
};

inline int32_t Invasion::amount() const
{
  return mAmount;
}

inline int32_t Invasion::attackPoint() const
{
  return mAttackPoint;
}

inline int32_t Invasion::attackType() const
{
  return mAttackType;
}

inline int32_t Invasion::enemyId() const
{
  return mEnemyId;
}

inline int32_t Invasion::type() const
{
  return mType;
}

inline void Invasion::setAttackPoint(int32_t value)
{
  mAttackPoint = value;
}

inline void Invasion::setAttackType(int32_t value)
{
  mAttackType = value;
}

inline void Invasion::setAmount(int32_t value)
{
  mAmount = value;
}

inline void Invasion::setEnemyId(int32_t value)
{
  mEnemyId = value;
}

inline void Invasion::setType(int32_t value)
{
  mType = value;
}

#endif // INVASION_H
