#include "city.h"

#include "core/streamio.h"

namespace Empire
{

City::City(int32_t id)
{
  mId = id;
  mInUse = false;
  mTradeRouteCost = 0;
  mNameId = Name::Roma;
  mType = Type::RomanCity;
  for (int32_t i = 0; i < Resource::MAX_RESOURCES+1; i++) {
    mBuyFlags[i] = 0;
    mSellFlags[i] = 0;
  }
}

uint8_t City::buyFlag(int32_t resourceId) const
{
  return mBuyFlags[resourceId];
}

bool City::inUse() const
{
  return mInUse;
}

City::Name City::nameId() const
{
  return mNameId;
}

uint8_t City::sellFlag(int32_t resourceId) const
{
  return mSellFlags[resourceId];
}

uint16_t City::tradeRouteCode() const
{
  return mTradeRouteCost;
}

City::Type City::type() const
{
  return mType;
}

QString City::getName() const
{
  return getName(mNameId);
}

QString City::getName(Name name)
{
  switch (name) {
  case Name::Roma:
    return "Roma";
  case Name::Tarentum:
    return "Tarentum";
  case Name::Capua:
    return "Capua";
  case Name::Brundisium:
    return "Brundisium";
  case Name::Mediolanum:
    return "Mediolanum";
  case Name::CarthagoNova:
    return "Carthago Nova";
  case Name::Carthago:
    return "Carthago";
  case Name::Tarraco:
    return "Tarraco";
  case Name::Athenae:
    return "Athenae";
  case Name::Pergamum:
    return "Pergamum";
  case Name::Syracusae:
    return "Syracusae";
  case Name::Toletum:
    return "Toletum";
  case Name::Tarsus:
    return "Tarsus";
  case Name::LeptisMagna:
    return "Leptis Magna";
  case Name::Tingis:
    return "Tingis";
  case Name::Corinthus:
    return "Corinthus";
  case Name::Valentia:
    return "Valentia";
  case Name::Ephesus:
    return "Ephesus";
  case Name::Miletus:
    return "Miletus";
  case Name::Sinope:
    return "Sinope";
  case Name::Cyrene:
    return "Cyrene";
  case Name::Antiocha:
    return "Antiocha";
  case Name::Heliopolis:
    return "Heliopolis";
  case Name::Damascus:
    return "Damascus";
  case Name::Hierosolyma:
    return "Hierosolyma";
  case Name::Lindum:
    return "Lindum";
  case Name::Calleva:
    return "Calleva";
  case Name::Lutetia:
    return "Lutetia";
  case Name::Massilia:
    return "Massilia";
  case Name::Narbo:
    return "Narbo";
  case Name::Lugdunum:
    return "Lugdunum";
  case Name::Caesarea:
    return "Caesarea";
  case Name::Alexandria:
    return "Alexandria";
  case Name::AugustaTrevorum:
    return "Augusta Trevorum";
  case Name::Argentoratum:
    return "Argentoratum";
  case Name::Volubilis:
    return "Volubilis";
  case Name::Londinium:
    return "Londinium";
  case Name::Thamugadi:
    return "Thamugadi";
  case Name::Sarmizegetusa:
    return "Sarmizegetusa";
  case Name::Byzantium:
    return "Byzantium";
  }

  return "Unknown";
}

QString City::getType() const
{
  return getType(mType);
}

QString City::getType(Type type)
{
  switch (type)
  {
  case Type::RomanCity:
      return "Roman City";
  case Type::OurCity:
    return "Our City";
  case Type::TradeRoute1:
    return "Trade Route 1";
  case Type::TradeRoute2:
    return "Trade Route 2";
  case Type::DistantCity:
    return "Disntant City";
  case Type::RomanCity2:
    return "Roman City 2";
  }

  return "Unknown";
}


void City::loadFromStream(QDataStream &dataStream)
{
  mInUse = streamio::readUInt8(dataStream);
  dataStream.skipRawData(1);
  mType = Type(streamio::readUInt8(dataStream));
  mNameId = Name(streamio::readUInt8(dataStream));
  dataStream.skipRawData(2);

  for (int32_t i = 0; i < Resource::MAX_RESOURCES+1; i++) {
    mBuyFlags[i] = streamio::readUInt8(dataStream);
  }

  for (int32_t i = 0; i < Resource::MAX_RESOURCES+1; i++) {
    mSellFlags[i] = streamio::readUInt8(dataStream);
  }

  mTradeRouteCost = streamio::readUInt16(dataStream);
  dataStream.skipRawData(26);
}

void City::saveToStream(QDataStream &dataStream) const
{

}

}
