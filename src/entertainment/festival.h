#ifndef FESTIVAL_H
#define FESTIVAL_H

#include "tiberius.h"

#include "religion/god.h"

#include <cstdint>

class Festival
{
public:
  enum class Type
  {
    Small = 0,
    Large = 1,
    Grand = 2,
  };

public:
  TIBERIUS_LIB_DECL Festival(Type type);

public:
  TIBERIUS_LIB_DECL int32_t cost() const;
  TIBERIUS_LIB_DECL God::Type god() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL int32_t wineRequired() const;
  TIBERIUS_LIB_DECL void setCost(int32_t value);
  TIBERIUS_LIB_DECL void setGod(God::Type value);
  TIBERIUS_LIB_DECL void setWineRequired(int32_t value);

private:
  int32_t mCost;
  int32_t mWineRequired;
  Type mType;
  God::Type mGodType;
};

#endif // FESTIVAL_H
