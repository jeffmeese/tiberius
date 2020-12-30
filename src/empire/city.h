#ifndef EMPIRE_CITY_H
#define EMPIRE_CITY_H

#include "tiberius.h"

#include "resource/resource.h"

#include <cstdint>

#include <QDataStream>

namespace Empire
{

class City
{
public:
  TIBERIUS_LIB_DECL City();

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  bool mInUse;
  uint8_t mType;
  uint8_t mNameId;
  uint8_t mBuyFlags[Resource::MAX_RESOURCES];
  uint8_t mSellFlags[Resource::MAX_RESOURCES];
  uint16_t mTradeRouteCost;
};

}

#endif // EMPIRE_CITY_H
