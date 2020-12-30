#ifndef BUILDING_H
#define BUILDING_H

#include "tiberius.h"

#include <QPixmap>
#include <QString>

class Building
{
public:
  enum class Type : uint8_t
  {
    None = 0,
    SmallTent = 10,
    LargeTent = 11,
    SmallShack = 12,
    LargeShack = 13,
    SmallHovel = 14,
    LargeHovel = 15,
    SmallCasa = 16,
    LargeCasa = 17,
    SmallInsulae = 18,
    MediumInsulae = 19,
    LargeInsulae = 20,
    GrandInsulae = 21,
    SmallVilla = 22,
    MediumVilla = 23,
    LargeVilla = 24,
    GrandVilla = 25,
    SmallPalace = 26,
    MediumPalace = 27,
    LargePalace = 28,
    LuxuryPalace = 29,
    Ampitheater = 30,
    Theater = 31,
    Hippodrome = 32,
    Colosseum = 33,
    GladiatorSchool = 34,
    LionHouse = 35,
    ActorColony = 36,
    Charioteer = 37,
    Plaza = 38,
    Gardens = 39,
    //Unknown = 40,
    SmallStatue = 41,
    MediumStatue = 42,
    LargeStatue = 43,
    //Unknown = 44,
    //Unknown = 45,
    Doctor = 46,
    Hospital = 47,
    Baths = 48,
    Barber = 49,
    //Unknown = 50,
    School = 51,
    Academy = 52,
    Library = 53,
    FortSoldierArea = 54,
    Prefecture = 55,
    TriumphalArch = 56,
    Fort = 57,
    Gatehouse = 58,
    Tower = 59,
    CeresTempleSmall = 60,
    NeptuneTempleSmall = 61,
    MercuryTempleSmall = 62,
    MarsTempleSmall = 63,
    VenusTempleSmall = 64,
    CeresTempleLarge = 65,
    NeptuneTempleLarge = 66,
    MercuryTempleLarge = 67,
    MarsTempleLarge = 68,
    VenusTempleLarge = 69,
    Market = 70,
    Granary = 71,
    Warehouse = 72,
    WarehouseEmptySpace = 73,
    Shipyard = 74,
    Dock = 75,
    Wharf = 76,
    GovernorsHouse = 77,
    GovernorsVilla = 78,
    GovernorsMansion = 79,
    MissionPost = 80,
    EngineerPost = 81,
    LowBridge = 82,
    ShipBridge = 83,
    Senate = 84,
    SenateUpgraded = 85,
    Forum = 86,
    ForumUpgraded = 87,
    NativeHut = 88,
    NativeMeeting = 89,
    Reservoir = 90,
    Fountain = 91,
    Well = 92,
    NativeField = 93,
    MilitaryAcademy = 94,
    Barracks = 95,
    //Unknown = 96,
    //Unknown = 97,
    Oracle = 98,
    Burning = 99,
    WheatFarm = 100,
    VegetableFarm = 101,
    FruitFarm = 102,
    OliveFarm = 103,
    VineFarm = 104,
    PigFarm = 105,
    MarbleQuarry = 106,
    IronMine = 107,
    TimberYard = 108,
    ClayPit = 109,
    WineWorkshop = 110,
    OilWorkshop = 111,
    WeaponsWorkshop = 112,
    FurnitureWorkshop = 113,
    PotteryWorkshop = 114
  };

public:
  TIBERIUS_LIB_DECL Building(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

  TIBERIUS_LIB_DECL int32_t getField(int32_t index) const { return mFields[index]; }
  TIBERIUS_LIB_DECL int32_t totalFields() const { return static_cast<int32_t>(mFields.size()); }

public:
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getName() const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  uint8_t mTileSize;
  uint8_t mXPos;
  uint8_t mYPos;
  uint16_t mId;
  Type mType;
  std::vector<int32_t> mFields;
};

#endif // BUILDING_H
