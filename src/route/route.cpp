#include "route.h"

Route::Route(int32_t id)
{
  mId = id;
}

int32_t Route::id() const
{
  return mId;
}

void Route::loadFromDataStream(QDataStream & dataStream)
{

}

void Route::saveToDataStream(QDataStream & dataStream) const
{

}
