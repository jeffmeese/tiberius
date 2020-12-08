#ifndef FIGURE_H
#define FIGURE_H

#include "tiberius.h"

#include "game/direction.h"
#include "map/location.h"

#include <QDataStream>

#include <fstream>

class Figure
{
public:
  enum class Type
  {
    None = 0,
    Immigrant = 1,
    Emigrant = 2,
    Homeless = 3,
    CartPusher = 4,
    Recruiter = 5,
    Fire = 6,
    TaxCollector = 7,
    Engineer = 8,
    WarehouseWorker = 9,
    Prefect = 10,
    JavelinThrower = 11,
    Cavalry = 12,
    Legionnaire = 13,
    LegionPost = 14,
    Actor = 15,
    Gladiator = 16,
    LionTamer = 17,
    Charioteer = 18,
    TraderDonkeyLeader = 19,
    TradeShip = 20,
    TraderDonkeyFollower = 21,
    Protestor = 22,
    Criminal = 23,
    Rioter = 24,
    FishingBoat = 25,
    MarketTrader = 26,
    Priest = 27,
    SchoolChild = 28,
    Teacher = 29,
    Librarian = 30,
    Barber = 31,
    BathWorker = 32,
    Doctor = 33,
    Surgeon = 34,
    Worker = 35,
    Flag = 36,
    Flotsam = 37,
    Docker = 38,
    MarketBuyer = 39,
    Patrician = 40,
    Native = 41,
    Sentry = 42,
    EnemyNative1 = 43,
    EnemySword1 = 44,
    EnemySword2 = 45,
    EnemyCamel = 46,
    EnemyElephant = 47,
    EnemyChariot = 48,
    EnemySword3 = 49,
    EnemySword4 = 50,
    EnemyNative2 = 51,
    EnemyArcher = 52,
    EnemyAxe = 53,
    EnemyGladiator = 54,
    EnemyCasearJaveling = 55,
    EnemyCasearCavalry = 56,
    EnemyCasearLegionnarie = 57,
    NativeTrader = 58,
    Arrow = 59,
    Javelin = 60,
    Bolt = 61,
    Crossbow = 62,

    Missionary = 64,
    Seagulls = 65,
    DeliveryBoy = 66,
    Shipwreck = 67,
    Sheep = 68,
    Wolves = 69,
    Zebras = 70,
    Spear = 71,
    HippodromeHorses = 72
  };

public:
  TIBERIUS_LIB_DECL Figure(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL int16_t cartImageId() const;
  TIBERIUS_LIB_DECL int16_t imageId() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setCartImageId(int16_t value);
  TIBERIUS_LIB_DECL void setImageId(int16_t value);
  TIBERIUS_LIB_DECL void setType(Type type);

  TIBERIUS_LIB_DECL int32_t getField(int32_t index) const { return mFields[index]; }
  TIBERIUS_LIB_DECL int32_t totalFields() const { return static_cast<int32_t>(mFields.size()); }

public:
  TIBERIUS_LIB_DECL QPixmap getCartImage() const;
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getName() const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int16_t mCartImageId;
  int32_t mId;
  int16_t mImageId;
  Type mType;
  Location mLocation;
  Location mPreviousLocation;
  std::vector<int32_t> mFields;
//  int32_t mAlternativeLocation;
//  int32_t mImageOffset;
//  bool mIsEnemyImage;
//  bool mFlotsamVisible;
//  int32_t mImageId;
//  int32_t mCartImageId;
//  int32_t mNextFigureOnTile;
//  Type mType;
//  int32_t mResourceId;
//  bool mUseCrossCountry;
//  bool mIsFriendly;
//  int32_t mState;
//  int32_t mFactionId;
//  int32_t mActionStatePriorToAttack;
//  Direction mDirection;
//  Direction mPreviousDirection;
//  Direction mAttackDirection;
//  Location mPos;
//  Location mPrevPos;
//  int32_t mMissleDamage;
//  int32_t mDamage;
//  int32_t mGridOffset;
//  Location mDestination;
//  int32_t mDestinationGridOffset;
//  Location mSource;
//  Location mFormationPosition;
//  int32_t mWaitTicks;
//  int32_t mActionState;
//  int32_t mProgress;
//  int32_t mRoutingPathId;
//  int32_t mRoutingCurrentTile;
//  int32_t mRoutingPathLength;
//  int32_t mInBuildingTicks;
//  bool mOnRoad;
//  int32_t mMaxRoamLength;
//  int32_t mRoamLength;
//  bool mRoamChooseDirection;
//  bool mRoamRandomCounter;
//  bool mRoamTurnDirection;
//  int32_t mRoamTicksUntilTurn;
//  Location mCrossCountry;
//  Location mCrossCountryDelta;
//  int32_t mDeltaXY;
//  Direction mCrossCountryDirection;
//  int32_t mSpeed;
//  int32_t mBuildingId;
//  int32_t mImmigrantBuildingId;
//  int32_t mDestinationBuildingId;
//  int32_t mFormationId;
//  int32_t mIndexInFormation;
//  int32_t mFormationAtRest;
//  int32_t mNumImmigrants;
//  bool mIsGhost;
//  int32_t mMinMaxSeen;
//  int32_t mLeadingFigureId;
//  int32_t mAttackImageOffset;
//  int32_t mWaitTicksMissle;
//  Location mOffsetCart;
//  int32_t mEmpireCityId;
//  int32_t mTradeAmountBought;
//  int32_t mName;
//  int32_t mTerrainUsage;
//  int32_t mLoads;
//  bool mIsBoat;
//  int32_t mHeightAdjustedTicks;
//  int32_t mCurrentHeight;
//  int32_t mTargetHeight;
//  int32_t mCollectItemId;
//  int32_t mFailedDockAttempts;
//  int32_t mPhraseSequence;
//  int32_t mPhraseId;
//  int32_t mPhraseCity;
//  int32_t mTraderId;
//  int32_t mWaitTicksNextTarget;
//  int32_t mTargetFigureId;
//  int32_t mTargetedByFigureId;
//  int32_t mCreatedSequence;
//  int32_t mTargetFigureCreatedSequence;
//  int32_t mFiguresOnTile;
//  int32_t mNumAttackers;
//  int32_t mAttackerId1;
//  int32_t mAttackerId2;
//  int32_t mOpponentId;
};

#endif // FIGURE_H
