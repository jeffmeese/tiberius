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
  TIBERIUS_LIB_DECL Figure();

public:
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mAlternativeLocation;
  int32_t mImageOffset;
  bool mIsEnemyImage;
  bool mFlotsamVisible;
  int32_t mImageId;
  int32_t mCartImageId;
  int32_t mNextFigureOnTile;
  Type mType;
  int32_t mResourceId;
  bool mUseCrossCountry;
  bool mIsFriendly;
  int32_t mState;
  int32_t mFactionId;
  int32_t mActionStatePriorToAttack;
  Direction mDirection;
  Direction mPreviousDirection;
  Direction mAttackDirection;
  Location mPos;
  Location mPrevPos;
  int32_t mMissleDamage;
  int32_t mDamage;
  int32_t mGridOffset;
  Location mDestination;
  int32_t mDestinationGridOffset;
  Location mSource;
  Location mFormationPosition;
  int32_t mWaitTicks;
  int32_t mActionState;
  int32_t mProgress;
  int32_t mRoutingPathId;
  int32_t mRoutingCurrentTile;
  int32_t mRoutingPathLength;
  int32_t mInBuildingTicks;
  bool mOnRoad;
  int32_t mMaxRoamLength;
  int32_t mRoamLength;
  bool mRoamChooseDirection;
  bool mRoamRandomCounter;
  bool mRoamTurnDirection;
  int32_t mRoamTicksUntilTurn;
  Location mCrossCountry;
  Location mCrossCountryDelta;
  int32_t mDeltaXY;
  Direction mCrossCountryDirection;
  int32_t mSpeed;
  int32_t mBuildingId;
  int32_t mImmigrantBuildingId;
  int32_t mDestinationBuildingId;
  int32_t mFormationId;
  int32_t mIndexInFormation;
  int32_t mFormationAtRest;
  int32_t mNumImmigrants;
  bool mIsGhost;
  int32_t mMinMaxSeen;
  int32_t mLeadingFigureId;
  int32_t mAttackImageOffset;
  int32_t mWaitTicksMissle;
  Location mOffsetCart;
  int32_t mEmpireCityId;
  int32_t mTradeAmountBought;
  int32_t mName;
  int32_t mTerrainUsage;
  int32_t mLoads;
  bool mIsBoat;
  int32_t mHeightAdjustedTicks;
  int32_t mCurrentHeight;
  int32_t mTargetHeight;
  int32_t mCollectItemId;
  int32_t mFailedDockAttempts;
  int32_t mPhraseSequence;
  int32_t mPhraseId;
  int32_t mPhraseCity;
  int32_t mTraderId;
  int32_t mWaitTicksNextTarget;
  int32_t mTargetFigureId;
  int32_t mTargetedByFigureId;
  int32_t mCreatedSequence;
  int32_t mTargetFigureCreatedSequence;
  int32_t mFiguresOnTile;
  int32_t mNumAttackers;
  int32_t mAttackerId1;
  int32_t mAttackerId2;
  int32_t mOpponentId;
};

#endif // FIGURE_H
