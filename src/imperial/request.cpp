#include "request.h"

Request::Request()
{
  mAmount = 0;
  mMonthsToComply = 0;
  mResource = Resource::Type::None;
}

int32_t Request::amount() const
{
  return mAmount;
}

int32_t Request::monthsToComply() const
{
  return mMonthsToComply;
}

Resource::Type Request::resource() const
{
  return mResource;
}

void Request::setAmount(int32_t value)
{
  mAmount = value;
}

void Request::setMonthsToComply(int32_t value)
{
  mMonthsToComply = value;
}

void Request::setResourceType(Resource::Type type)
{
  mResource = type;
}
