#ifndef LEGION_H
#define LEGION_H

#include "tiberius.h"

#include <QString>
#include <QPixmap>

#include <cstdint>
#include <memory>
#include <vector>

class Soldier;

class Legion
{
public:
  static const int32_t MAX_FIGURES = 16;

public:
  enum class Type
  {
    Javelin = 11,
    Cavalry = 12,
    Legionnaires = 13
  };

  enum class Morale
  {
    TotallyDistraugt = 0,
    Terrified = 5,
    ExtremelyScared = 10,
    VeryFrightened = 15,
    Frightened = 20,
    BadlyShaken = 25,
    Shaken = 30,
    Poor = 35,
    QuitePoor = 40,
    BelowAverage = 45,
    Average = 50,
    AboveAverage = 55,
    Encouraged = 60,
    QuiteDaring = 65,
    Daring = 70,
    Bold = 75,
    VeryBold = 80,
    Strong = 85,
    ExtremelyStrong = 90,
    Excellent = 95,
    Perfect = 100
  };

public:
  TIBERIUS_LIB_DECL Legion(int32_t id);
  TIBERIUS_LIB_DECL ~Legion();

public:
  TIBERIUS_LIB_DECL bool academyTrained() const;
  TIBERIUS_LIB_DECL bool empireService() const;
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL QPixmap image() const;
  TIBERIUS_LIB_DECL Morale morale() const;
  TIBERIUS_LIB_DECL int32_t totalSoldiers() const;
  TIBERIUS_LIB_DECL Type type();
  TIBERIUS_LIB_DECL void setAcademyTrained(bool value);
  TIBERIUS_LIB_DECL void setEmpireService(bool value);
  TIBERIUS_LIB_DECL void setMorale(Morale value);

  TIBERIUS_LIB_DECL int32_t getField(int32_t index) const { return mFields[index]; }
  TIBERIUS_LIB_DECL int32_t totalFields() const { return static_cast<int32_t>(mFields.size()); }

public:
  TIBERIUS_LIB_DECL void addSolider(std::unique_ptr<Soldier> soldier);
  TIBERIUS_LIB_DECL QString moraleString() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void removeSolider(const QString & name);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
  TIBERIUS_LIB_DECL QString typeString() const;

public:
  TIBERIUS_LIB_DECL static QString moraleString(Morale morale);
  TIBERIUS_LIB_DECL static QString typeString(Type type);

private:
  typedef std::unique_ptr<Soldier> SoldierPtr;
  typedef std::vector<SoldierPtr> SoldierVector;

private:
  bool mAcademyTrained;
  bool mEmpireService;
  bool mFriendly;
  bool mAtFort;
  bool mIsLegion;
  bool mIsHerd;
  bool mIsHalted;
  bool mMissleFired;
  bool mMarsCurse;
  bool mAtDistantBattle;
  bool mUnknownFired;
  uint8_t mFactionId;
  uint8_t mLegionId;
  uint8_t mState;
  uint8_t mNumSoliders;
  uint8_t mMaxSoliders;
  uint8_t mXFort;
  uint8_t mYFort;
  uint8_t mXStandard;
  uint8_t mYStandard;
  uint8_t mX;
  uint8_t mY;
  uint8_t mDestX;
  uint8_t mDestY;
  uint8_t mMonthsOfLowMorale;
  uint8_t mEnemyType;
  uint8_t mDirection;
  uint8_t mPrevXHome;
  uint8_t mPrevYHome;
  uint8_t mOrientation;
  uint8_t mMonthsAway;
  uint8_t mMonthsOfVeryLowMorale;
  uint8_t mInvasionId;
  uint8_t mWolfDelay;
  uint8_t mHerdDirection;
  int16_t mInvasionSequence;
  int16_t mAttack;
  int16_t mRecruitType;
  int16_t mDamage;
  int16_t mMaxDamage;
  int16_t mTicks;
  int16_t mRecentBattle;
  int16_t mEnemyAdvance;
  int16_t mEnemyFallback;
  int16_t mEnemyHalt;
  int16_t mMissleTimeout;
  int16_t mMissionAttack;
  int16_t mPreviosDefense;
  int16_t mBuildingId;
  int16_t mDestBuildingId;
  int16_t mFigureId;
  int16_t mFigures[MAX_FIGURES];
  int16_t mDefense;
  int32_t mId;
  Morale mMorale;
  Type mType;
  SoldierVector mSoldiers;
  std::vector<int32_t> mFields;
};

#endif // LEGION_H
