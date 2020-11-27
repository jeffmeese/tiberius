#ifndef GIFT_H
#define GIFT_H

#include "tiberius.h"

#include <QString>

#include <cstdint>

class Gift
{
public:
  enum class Type
  {
    Modest = 1,
    Generous = 2,
    Lavish = 3
  };

public:
  TIBERIUS_LIB_DECL Gift();
  TIBERIUS_LIB_DECL Gift(Type type);

public:
  TIBERIUS_LIB_DECL int32_t calculateCost(int32_t savings) const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

private:
  Type mType;
};

#endif // GIFT_H
