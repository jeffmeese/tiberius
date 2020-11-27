#ifndef MILITARYDATA_H
#define MILITARYDATA_H

#include "tiberius.h"

#include <cstdint>
#include <memory>
#include <vector>

class Legion;

class MilitaryData
{
public:
  static const int32_t MAX_LEGIONS = 6;
  static const int32_t MAX_FORMATIONS = 50;

public:
  TIBERIUS_LIB_DECL MilitaryData();
  TIBERIUS_LIB_DECL ~MilitaryData();

public:
  TIBERIUS_LIB_DECL int32_t totalLegions() const;

private:
  typedef std::unique_ptr<Legion> LegionPtr;
  typedef std::vector<LegionPtr> LegionVector;

private:
  LegionVector mLegions;
};

#endif // MILITARYDATA_H
