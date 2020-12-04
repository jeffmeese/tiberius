#ifndef RELIGIONDATA_H
#define RELIGIONDATA_H

#include "datamodel.h"

#include "religion/god.h"

#include <map>
#include <memory>

class Festival;

class ReligionData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL ReligionData();

public:
  TIBERIUS_LIB_DECL God * getGod(God::Type type);
  TIBERIUS_LIB_DECL const God * getGod(God::Type type) const;
  TIBERIUS_LIB_DECL int32_t oracles() const;
  TIBERIUS_LIB_DECL int32_t relgionNeeds() const;
  TIBERIUS_LIB_DECL void setOracles(int32_t value);

public:
  TIBERIUS_LIB_DECL QString needString() const;
  TIBERIUS_LIB_DECL void throwFestival(Festival * festival);

private:
  using GodPtr = std::unique_ptr<God>;

private:
  int32_t mOracles;
  int32_t mReligionNeeds;
  GodPtr mGods[5];
  std::map<God::Type, int> mGodToIndex;
};

#endif // RELIGIONDATA_H
