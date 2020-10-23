#ifndef DEMANDCHANGE_H
#define DEMANDCHANGE_H

#include "tiberius.h"
#include "event.h"

//#include "resources/resourcetypes.h"

#include <QDataStream>

class DemandChange
    : public Event
{
public:
  TIBERIUS_LIB_DECL DemandChange();

public:
  TIBERIUS_LIB_DECL int8_t resourceId() const;
  TIBERIUS_LIB_DECL bool rise() const;
  TIBERIUS_LIB_DECL int8_t routeId() const;
  TIBERIUS_LIB_DECL void setResourceId(int8_t value);
  TIBERIUS_LIB_DECL void setRise(bool value);
  TIBERIUS_LIB_DECL void setRouteId(int8_t value);

private:
  bool mRise;
  int8_t mResourceId;
  int8_t mRouteId;
};

inline int8_t DemandChange::resourceId() const
{
  return mResourceId;
}

inline bool DemandChange::rise() const
{
  return mRise;
}

inline int8_t DemandChange::routeId() const
{
  return mRouteId;
}

inline void DemandChange::setResourceId(int8_t value)
{
  mResourceId = value;
}

inline void DemandChange::setRise(bool value)
{
  mRise = value;
}

inline void DemandChange::setRouteId(int8_t value)
{
  mRouteId = value;
}

#endif // DEMANDCHANGE_H
