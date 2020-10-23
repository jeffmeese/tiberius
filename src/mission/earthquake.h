#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include "tiberius.h"
#include "event.h"

#include <QDataStream>

class Earthquake
    : public Event
{
public:
  enum Severity
  {
    Minor = 0,
    Average = 1,
    Major = 2
  };

public:
  TIBERIUS_LIB_DECL Earthquake();

public:
  TIBERIUS_LIB_DECL Severity severity() const;
  TIBERIUS_LIB_DECL int16_t x() const;
  TIBERIUS_LIB_DECL int16_t y() const;
  TIBERIUS_LIB_DECL void setSeverity(Severity value);
  TIBERIUS_LIB_DECL void setX(int16_t value);
  TIBERIUS_LIB_DECL void setY(int16_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mDelay;
  int32_t mDuration;
  int32_t mMaxDelay;
  int32_t mMaxDuration;
  int32_t mState;
  int32_t mExpandX[4];
  int32_t mExpandY[4];
  int16_t mX;
  int16_t mY;
  Severity mSeverity;
};

inline Earthquake::Severity Earthquake::severity() const
{
  return mSeverity;
}

inline int16_t Earthquake::x() const
{
  return mX;
}

inline int16_t Earthquake::y() const
{
  return mY;
}

inline void Earthquake::setSeverity(Severity value)
{
  mSeverity = value;
}

inline void Earthquake::setX(int16_t value)
{
  mX = value;
}

inline void Earthquake::setY(int16_t value)
{
  mY = value;
}

#endif // EARTHQUAKE_H
