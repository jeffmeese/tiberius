#ifndef REQUEST_H
#define REQUEST_H

#include "tiberius.h"

#include "resource/resource.h"

#include <QString>

#include <cstdint>

class Request
{
public:
  TIBERIUS_LIB_DECL Request();

public:
  TIBERIUS_LIB_DECL int32_t amount() const;
  TIBERIUS_LIB_DECL int32_t monthsToComply() const;
  TIBERIUS_LIB_DECL Resource::Type resource() const;
  TIBERIUS_LIB_DECL void setAmount(int32_t value);
  TIBERIUS_LIB_DECL void setMonthsToComply(int32_t value);
  TIBERIUS_LIB_DECL void setResourceType(Resource::Type type);

private:
  int32_t mAmount;
  int32_t mMonthsToComply;
  Resource::Type mResource;
};

#endif // REQUEST_H
