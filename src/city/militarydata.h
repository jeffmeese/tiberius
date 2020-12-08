#ifndef MILITARYDATA_H
#define MILITARYDATA_H

#include "datamodel.h"
#include "datavector.h"

#include "military/legion.h"

#include <memory>
#include <vector>

class Legion;

class MilitaryData
    : public DataModel
    , public DataVector<Legion>
{
public:
  static const int32_t MAX_LEGIONS = 6;
  static const int32_t MAX_FORMATIONS = 50;

public:
  TIBERIUS_LIB_DECL MilitaryData();
  TIBERIUS_LIB_DECL ~MilitaryData();

public:
  TIBERIUS_LIB_DECL int32_t lastLegion() const;
  TIBERIUS_LIB_DECL int32_t lastUsed() const;
  TIBERIUS_LIB_DECL int32_t numActive() const;
  TIBERIUS_LIB_DECL void setLastLegion(int32_t value);
  TIBERIUS_LIB_DECL void setLastUsed(int32_t value);
  TIBERIUS_LIB_DECL void setNumActive(int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream, bool compressed = true) const;

private:
  int32_t mLastUsed;
  int32_t mLastLegion;
  int32_t mNumActive;
};

#endif // MILITARYDATA_H
