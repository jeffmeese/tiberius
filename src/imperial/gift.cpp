#include "gift.h"

Gift::Gift()
{
  mType = Type::Modest;
}

Gift::Gift(Type type)
{
  mType = type;
}

int32_t Gift::calculateCost(int32_t savings) const
{
  int32_t cost = 0;
  if (mType == Type::Modest) {
    cost = savings / 8 + 20;
  }
  else if (mType == Type::Generous) {
    cost = savings / 4 + 50;
  }
  else if (mType == Type::Lavish) {
    cost = savings / 2 + 100;
  }

  return cost;
}

Gift::Type Gift::type() const
{
  return mType;
}

void Gift::setType(Type type)
{
  mType = type;
}
