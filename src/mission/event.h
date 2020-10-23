#ifndef EVENT_H
#define EVENT_H

#include <cstdint>

#include "tiberius.h"

class Event
{
public:
  TIBERIUS_LIB_DECL bool enabled() const;
  TIBERIUS_LIB_DECL uint16_t month() const;
  TIBERIUS_LIB_DECL uint16_t year() const;
  TIBERIUS_LIB_DECL void setEnabled(bool value);
  TIBERIUS_LIB_DECL void setMonth(uint16_t value);
  TIBERIUS_LIB_DECL void setYear(uint16_t value);

protected:
  TIBERIUS_LIB_DECL Event();

private:
  bool mEnabled;
  uint16_t mMonth;
  uint16_t mYear;
};

inline bool Event::enabled() const
{
  return mEnabled;
}

inline uint16_t Event::month() const
{
  return mMonth;
}

inline uint16_t Event::year() const
{
  return mYear;
}

inline void Event::setEnabled(bool value)
{
  mEnabled = value;
}

inline void Event::setMonth(uint16_t value)
{
  mMonth = value;
}

inline void Event::setYear(uint16_t value)
{
  mYear = value;
}

#endif // EVENT_H
