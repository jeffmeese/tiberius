#ifndef GLADIATORREVOLT_H
#define GLADIATORREVOLT_H

#include "tiberius.h"
#include "event.h"

#include <QDataStream>

class GladiatorRevolt
    : public Event
{
public:
  TIBERIUS_LIB_DECL GladiatorRevolt();

public:
  TIBERIUS_LIB_DECL int32_t endMonth() const;
  TIBERIUS_LIB_DECL int32_t state() const;
  TIBERIUS_LIB_DECL void setEndMonth(int32_t value);
  TIBERIUS_LIB_DECL void setState(int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mEndMonth;
  int32_t mState;
};

inline int32_t GladiatorRevolt::endMonth() const
{
  return mEndMonth;
}

inline int32_t GladiatorRevolt::state() const
{
  return mState;
}

inline void GladiatorRevolt::setEndMonth(int32_t value)
{
  mEndMonth = value;
}

inline void GladiatorRevolt::setState(int32_t value)
{
  mState = value;
}

#endif // GLADIATORREVOLT_H
