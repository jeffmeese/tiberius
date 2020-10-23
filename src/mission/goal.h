#ifndef GOAL_H
#define GOAL_H

#include <cstdint>

#include "tiberius.h"

class Goal
{
public:
  TIBERIUS_LIB_DECL Goal();

public:
  TIBERIUS_LIB_DECL bool enabled() const;
  TIBERIUS_LIB_DECL int32_t target() const;
  TIBERIUS_LIB_DECL void setEnabled(bool value);
  TIBERIUS_LIB_DECL void setTarget(int32_t value);

private:
  bool mEnabled;
  int32_t mTarget;
};

inline bool Goal::enabled() const
{
  return mEnabled;
}

inline int32_t Goal::target() const
{
  return mTarget;
}

inline void Goal::setEnabled(bool value)
{
  mEnabled = value;
}

inline void Goal::setTarget(int32_t value)
{
  mTarget = value;
}

#endif // GOAL_H
