#include "figure.h"

#include "core/streamio.h"

#include <QDebug>


Figure::Figure(int32_t id)
{
  mId = id;
  mType = Figure::Type::None;

  mIsEnemyImage = false;
  mFlotsamVisible = false;
  mUseCrossCountry = false;
  mIsFriendly = false;
  mOnRoad = false;
  mRoamChooseDirection = false;
  mRoamRandomCounter = false;
  mRoamTurnDirection = false;
  mIsGhost = false;
  mIsBoat = false;

  mAlternativeLocation = 0;
  mImageOffset = 0;
  mImageId = 0;
  mCartImageId = 0;
  mNextFigureOnTile = 0;
  mResourceId = 0;
  mState = 0;
  mFactionId = 0;
  mActionStatePriorToAttack = 0;
  mMissleDamage = 0;
  mDamage = 0;
  mGridOffset = 0;
  mDestinationGridOffset = 0;
  mWaitTicks = 0;
  mActionState = 0;
  mProgress = 0;
  mRoutingPathId = 0;
  mRoutingCurrentTile = 0;
  mRoutingPathLength = 0;
  mInBuildingTicks = 0;
  mMaxRoamLength = 0;
  mRoamLength = 0;
  mRoamTicksUntilTurn = 0;
  mDeltaXY = 0;
  mSpeed = 0;
  mBuildingId = 0;
  mImmigrantBuildingId = 0;
  mDestinationBuildingId = 0;
  mFormationId = 0;
  mIndexInFormation = 0;
  mFormationAtRest = 0;
  mNumImmigrants = 0;
  mMinMaxSeen = 0;
  mLeadingFigureId = 0;
  mAttackImageOffset = 0;
  mWaitTicksMissle = 0;
  mEmpireCityId = 0;
  mTradeAmountBought = 0;
  mName = 0;
  mTerrainUsage = 0;
  mLoads = 0;
  mHeightAdjustedTicks = 0;
  mCurrentHeight = 0;
  mTargetHeight = 0;
  mCollectItemId = 0;
  mFailedDockAttempts = 0;
  mPhraseSequence = 0;
  mPhraseId = 0;
  mPhraseCity = 0;
  mTraderId = 0;
  mWaitTicksNextTarget = 0;
  mTargetFigureId = 0;
  mTargetedByFigureId = 0;
  mCreatedSequence = 0;
  mTargetFigureCreatedSequence = 0;
  mFiguresOnTile = 0;
  mNumAttackers = 0;
  mAttackerId1 = 0;
  mAttackerId2 = 0;
  mOpponentId = 0;

  mDirection = Direction::North;
  mPreviousDirection = Direction::North;
  mAttackDirection = Direction::North;
  mCrossCountryDirection = Direction::North;
}

int32_t Figure::id() const
{
  return mId;
}

void Figure::loadFromDataStream(QDataStream & dataStream)
{
  char c;
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Type?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream); // Short?
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);
  c = streamio::readInt8(dataStream);

//  mAlternativeLocation = streamio::readUInt8(dataStream);
//  mImageOffset = streamio::readUInt8(dataStream);
//  mIsEnemyImage = streamio::readUInt8(dataStream);
//  mFlotsamVisible = streamio::readUInt8(dataStream);
//  mImageId = streamio::readInt16(dataStream);
//  mCartImageId = streamio::readInt16(dataStream);
  qDebug() << mImageId ;
}

void Figure::saveToDataStream(QDataStream & dataStream) const
{
  streamio::writeUInt8(dataStream, mAlternativeLocation);
}

void Figure::setType(Type type)
{
  mType = type;
}

Figure::Type Figure::type() const
{
  return mType;
}
