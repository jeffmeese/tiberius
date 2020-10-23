#ifndef EMPERORCHANGE_H
#define EMPERORCHANGE_H

#include "tiberius.h"
#include "event.h"

#include <QDataStream>

class EmperorChange
    : public Event
{
public:
  TIBERIUS_LIB_DECL EmperorChange();

public:
  TIBERIUS_LIB_DECL int32_t month() const;
  TIBERIUS_LIB_DECL int32_t state() const;
  TIBERIUS_LIB_DECL int32_t year() const;
  TIBERIUS_LIB_DECL void setMonth(int32_t value);
  TIBERIUS_LIB_DECL void setState(int32_t value);
  TIBERIUS_LIB_DECL void setYear(int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mMonth;
  int32_t mYear;
  int32_t mState;
};

inline int32_t EmperorChange::month() const
{
  return mMonth;
}

inline int32_t EmperorChange::state() const
{
  return mState;
}

inline int32_t EmperorChange::year() const
{
  return mYear;
}

inline void EmperorChange::setMonth(int32_t value)
{
  mMonth = value;
}

inline void EmperorChange::setState(int32_t value)
{
  mState = value;
}

inline void EmperorChange::setYear(int32_t value)
{
  mYear = value;
}

#endif // EMPERORCHANGE_H
