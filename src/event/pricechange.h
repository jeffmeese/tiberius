#ifndef PRICECHANGE_H
#define PRICECHANGE_H

#include "tiberius.h"
#include "event.h"

#include <QDataStream>

class PriceChange
    : public Event
{
public:
  TIBERIUS_LIB_DECL PriceChange();

public:
  TIBERIUS_LIB_DECL int8_t amount() const;
  TIBERIUS_LIB_DECL int8_t resourceId() const;
  TIBERIUS_LIB_DECL bool rise() const;
  TIBERIUS_LIB_DECL void setAmount(int8_t value);
  TIBERIUS_LIB_DECL void setResourceId(int8_t value);
  TIBERIUS_LIB_DECL void setRise(bool value);

private:
  bool mRise;
  int8_t mAmount;
  int8_t mResourceId;
};

inline int8_t PriceChange::amount() const
{
  return mAmount;
}

inline int8_t PriceChange::resourceId() const
{
  return mResourceId;
}

inline bool PriceChange::rise() const
{
  return mRise;
}

inline void PriceChange::setRise(bool value)
{
  mRise = value;
}

inline void PriceChange::setAmount(int8_t value)
{
  mAmount = value;
}

inline void PriceChange::setResourceId(int8_t value)
{
  mResourceId = value;
}

#endif // PRICECHANGE_H
