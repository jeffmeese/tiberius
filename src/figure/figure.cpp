#include "figure.h"

#include "core/streamio.h"

Figure::Figure()
{
  mType = Figure::Type::None;
}

void Figure::loadFromDataStream(QDataStream & dataStream)
{
  mAlternativeLocation = streamio::readUInt8(dataStream);
}

void Figure::saveToDataStream(QDataStream & dataStream) const
{
  streamio::writeUInt8(dataStream, mAlternativeLocation);
}

void Figure::setType(Type type)
{
  mType = type;
}

Figure::Type Figure::type() const
{
  return mType;
}
