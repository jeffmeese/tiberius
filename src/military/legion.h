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
  static const int32_t MAX_SOLDIERS = 16;

public:
  enum class Type
  {
    Legionnaires = 0,
    Javelin = 1,
    Cavalry = 2
  };

  enum class Morale
  {
    TotallyDistraugt = 0,
    Terrified = 1,
    ExtremelyScared = 2,
    VeryFrightened = 3,
    Frightened = 4,
    BadlyShaken = 5,
    Shaken = 6,
    Poor = 7,
    QuitePoor = 8,
    BelowAverage = 9,
    Average = 10,
    AboveAverage = 11,
    Encouraged = 12,
    QuiteDaring = 13,
    Daring = 14,
    Bold = 15,
    VeryBold = 16,
    Strong = 17,
    ExtremelyStrong = 18,
    Excellent = 19,
    Perfect = 20
  };

public:
  TIBERIUS_LIB_DECL Legion(Type type, int32_t id);
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

public:
  TIBERIUS_LIB_DECL void addSolider(std::unique_ptr<Soldier> soldier);
  TIBERIUS_LIB_DECL QString moraleString() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL void removeSolider(const QString & name);
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
  int32_t mId;
  Morale mMorale;
  Type mType;
  SoldierVector mSoldiers;
};

#endif // LEGION_H
