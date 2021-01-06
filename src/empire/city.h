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
  enum class Type
  {
    RomanCity = 0,
    OurCity = 1,
    TradeRoute1 = 2,
    TradeRoute2 = 3,
    DistantCity = 4,
    RomanCity2 = 5
  };

  enum class Name
  {
    Roma = 0x00,
    Tarentum = 0x01,
    Capua = 0x02,
    Brundisium = 0x03,
    Mediolanum = 0x04,
    CarthagoNova = 0x05,
    Carthago = 0x06,
    Tarraco = 0x07,
    Athenae = 0x08,
    Pergamum = 0x09,
    Syracusae = 0x0A,
    Toletum = 0x0B,
    Tarsus = 0x0C,
    LeptisMagna = 0x0D,
    Tingis = 0x0E,
    Corinthus = 0x0F,
    Valentia = 0x10,
    Ephesus = 0x11,
    Miletus = 0x12,
    Sinope = 0x13,
    Cyrene = 0x14,
    Antiocha = 0x15,
    Heliopolis = 0x16,
    Damascus = 0x17,
    Hierosolyma = 0x18,
    Lindum = 0x19,
    Calleva = 0x1A,
    Lutetia = 0x1B,
    Massilia = 0x1C,
    Narbo = 0x1D,
    Lugdunum = 0x1E,
    Caesarea = 0x1F,
    Alexandria = 0x20,
    AugustaTrevorum = 0x21,
    Argentoratum = 0x22,
    Volubilis = 0x23,
    Londinium = 0x24,
    Thamugadi = 0x25,
    Sarmizegetusa = 0x26,
    Byzantium = 0x27,
  };

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
