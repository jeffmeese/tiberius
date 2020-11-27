#ifndef LEGION_H
#define LEGION_H

#include "tiberius.h"

#include <QString>

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

public:
  TIBERIUS_LIB_DECL Legion(Type type);
  TIBERIUS_LIB_DECL ~Legion();

public:
  TIBERIUS_LIB_DECL bool academyTrained() const;
  TIBERIUS_LIB_DECL bool empireService() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL int32_t totalSoldiers() const;
  TIBERIUS_LIB_DECL Type type();
  TIBERIUS_LIB_DECL void setAcademyTrained(bool value);
  TIBERIUS_LIB_DECL void setEmpireService(bool value);
  TIBERIUS_LIB_DECL void setName(const QString & name);

public:
  TIBERIUS_LIB_DECL void addSolider(std::unique_ptr<Soldier> soldier);
  TIBERIUS_LIB_DECL void removeSolider(const QString & name);

private:
  typedef std::unique_ptr<Soldier> SoldierPtr;
  typedef std::vector<SoldierPtr> SoldierVector;

private:
  bool mAcademyTrained;
  bool mEmpireService;
  QString mName;
  SoldierVector mSoldiers;
  Type mType;
};

#endif // LEGION_H
