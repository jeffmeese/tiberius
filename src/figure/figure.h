#ifndef FIGURE_H
#define FIGURE_H

#include "tiberius.h"

#include "map/location.h"

#include <QDataStream>

class Figure
{
public:
  enum class Type
  {
    None = 0,
  };

  enum class Direction
  {
    North = 0,
    South = 1,
    East = 2,
    West = 3
  };

public:
  TIBERIUS_LIB_DECL Figure(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mId;
  uint8_t mAlternativeLocation;
  uint8_t mImageOffset;
  bool mIsEnemyImage;
  bool mFlotsamVisible;
  int16_t mImageId;
  int16_t mCartImageId;
  int16_t mNextFigureOnTile;
  Type mType;
  uint8_t mResourceId;
  bool mUseCrossCountry;
  bool mIsFriendly;
  uint8_t mState;
  uint8_t mFactionId;
  uint8_t mActionStatePriorToAttack;
  Direction mDirection;
  Direction mPreviousDirection;
  Direction mAttackDirection;
  Location mPos;
  Location mPrevPos;
  uint8_t mMissleDamage;
  uint8_t mDamage;
  int16_t mGridOffset;
  Location mDestination;
  int16_t mDestinationGridOffset;
  Location mSource;
  Location mFormationPosition;
  int16_t mWaitTicks;
  uint8_t mActionState;
  uint8_t mProgress;
  int16_t mRoutingPathId;
  int16_t mRoutingCurrentTile;
  int16_t mRoutingPathLength;
  uint8_t mInBuildingTicks;
  bool mOnRoad;
  int16_t mMaxRoamLength;
  int16_t mRoamLength;
  bool mRoamChooseDirection;
  bool mRoamRandomCounter;
  bool mRoamTurnDirection;
  int8_t mRoamTicksUntilTurn;
  Location mCrossCountry;
  Location mCrossCountryDelta;
  int16_t mDeltaXY;
  Direction mCrossCountryDirection;
  uint8_t mSpeed;
  int16_t mBuildingId;
  int16_t mImmigrantBuildingId;
  int16_t mDestinationBuildingId;
  int16_t mFormationId;
  uint8_t mIndexInFormation;
  uint8_t mFormationAtRest;
  uint8_t mNumImmigrants;
  bool mIsGhost;
  uint8_t mMinMaxSeen;
  int16_t mLeadingFigureId;
  uint8_t mAttackImageOffset;
  uint8_t mWaitTicksMissle;
  Location mOffsetCart;
  uint8_t mEmpireCityId;
  uint8_t mTradeAmountBought;
  int16_t mName;
  uint8_t mTerrainUsage;
  uint8_t mLoads;
  bool mIsBoat;
  uint8_t mHeightAdjustedTicks;
  uint8_t mCurrentHeight;
  uint8_t mTargetHeight;
  uint8_t mCollectItemId;
  uint8_t mFailedDockAttempts;
  uint8_t mPhraseSequence;
  uint8_t mPhraseId;
  uint8_t mPhraseCity;
  uint8_t mTraderId;
  uint8_t mWaitTicksNextTarget;
  int16_t mTargetFigureId;
  int16_t mTargetedByFigureId;
  int16_t mCreatedSequence;
  int16_t mTargetFigureCreatedSequence;
  uint8_t mFiguresOnTile;
  uint8_t mNumAttackers;
  int16_t mAttackerId1;
  int16_t mAttackerId2;
  int16_t mOpponentId;
};

#endif // FIGURE_H
