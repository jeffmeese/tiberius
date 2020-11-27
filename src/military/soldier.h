#ifndef SOLDIER_H
#define SOLDIER_H

#include "tiberius.h"

#include <QString>

class Soldier
{
public:
  TIBERIUS_LIB_DECL Soldier();

public:
  TIBERIUS_LIB_DECL bool academyTrained() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL void setAcademyTrained(bool value);
  TIBERIUS_LIB_DECL void setName(const QString & name);

private:
  bool mAcademyTrained;
  QString mName;
};

#endif // SOLDIER_H
