#ifndef SCRIBEMESSAGE_H
#define SCRIBEMESSAGE_H

#include "tiberius.h"

#include <cstdint>

#include <QDataStream>

class ScribeMessage
{
public:
  enum class Type
  {
    None = 0x00,
    Population500 = 0x02,
    Population1000 = 0x03,
    Population2000 = 0x04,
    Population3000 = 0x05,
    Population5000 = 0x06,
    Population10000 = 0x07,
    Population15000 = 0x08,
    Population20000 = 0x09,
    Population25000 = 0x0a,
    Riots = 0x0b,
    Fire = 0x0c,
    CollapsedBuilding = 0x0d,
    DestroyedBuilding = 0x0e,
    CityInDebt = 0x10,
    CityInDebtAgain = 0x11,
    CityStillInDebt = 0x12,
    LocalUprising = 0x16,
    BarbariansAttack = 0x17,
    DistantBattle = 0x19,
    EnemiesClosing = 0x1a,
    EnemiesAtTheDoor = 0x1b,
    EmperorRequestGoods = 0x1c,
    EmperorRequestArmy = 0x1e,
    ImperialReminder = 0x1f,
    EmperorGratitude = 0x20,
    EmperorAngerGoods = 0x21,
    EmperorAngleRequest = 0x22,
    EmperorGratitudeLate = 0x23,
    EmployeesNeeded = 0x24,
    Smallfestival = 0x26,
    Largefestival = 0x27,
    Grandfestival = 0x28,
    CeresWrath = 0x29,
    NeptuneWrath = 0x2a,
    Marsrath = 0x2c,
    VenusWrath = 0x2d,
    PeopleDisgruntled = 0x2e,
    PeopleAngry = 0x30,
    Theft = 0x34,
    GodsUnhappy = 0x37,
    Earthquake = 0x3e,
    GladiatorRevolt = 0x3f,
    NewEmperor = 0x40,
    Sandstorms = 0x41,
    StormySeas = 0x42,
    Landslides = 0x43,
    WageRise = 0x44,
    WageFall = 0x45,
    ContaminatedWater = 0x46,
    IronMineCave = 0x47,
    ClayPitFlood = 0x48,
    RevoltFinished = 0x49,
    IncreasedTrading = 0x4a,
    DecreasedTrading = 0x4b,
    EmpireChange = 0x4d,
    PriceRise = 0x4e,
    PriceFall = 0x4f,
    CitySaved = 0x57,
    Triumph = 0x59,
    CeresUpset = 0x5b,
    NeptuneUpset = 0x5c,
    MercuryUpset = 0x5d,
    MarsUpset = 0x5e,
    VenusUpset = 0x5f,
    CeresBlessing = 0x60,
    NeptuneBlessing = 0x61,
    MercuryBlessing = 0x62,
    MarsBlessing = 0x63,
    VenusBlessing = 0x64,
    GodsWrathful = 0x65,
    Disease = 0x67,
    Pestilence = 0x68,
    SpriritOfMars = 0x69,
    WorkingHippodrome = 0x6d,
    WorkingColosseum = 0x6e,
    Emigration = 0x6f,
    EnemyAttacks = 0x72,
    DispatchReady = 0x73,
    NoDock = 0x75,
    BoatsTrapped = 0x76,
    LocalUprisingByMars = 0x79
  };

public:
  TIBERIUS_LIB_DECL ScribeMessage();

public:
  TIBERIUS_LIB_DECL uint8_t data1() const;
  TIBERIUS_LIB_DECL uint8_t data2() const;
  TIBERIUS_LIB_DECL uint8_t month() const;
  TIBERIUS_LIB_DECL uint8_t read() const;
  TIBERIUS_LIB_DECL int16_t entryNumber() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL int16_t year() const;
  TIBERIUS_LIB_DECL void setData1(uint8_t value);
  TIBERIUS_LIB_DECL void setData2(uint8_t value);
  TIBERIUS_LIB_DECL void setMonth(uint8_t value);
  TIBERIUS_LIB_DECL void setRead(uint8_t value);
  TIBERIUS_LIB_DECL void setEntryNumber(int16_t value);
  TIBERIUS_LIB_DECL void setYear(int16_t value);
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  uint8_t mData1;
  uint8_t mData2;
  uint8_t mMonth;
  uint8_t mRead;
  int16_t mEntryNumber;
  int16_t mYear;
  Type mType;
};

#endif // SCRIBEMESSAGE_H
