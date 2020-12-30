#include "building.h"

#include "core/streamio.h"

Building::Building(int32_t id)
{
  mId = id;
  mType = Type::None;
}

QPixmap Building::getImage() const
{
  return QPixmap();
}

QString Building::getName() const
{
  return "";
}

int32_t Building::id() const
{
  return mId;
}

void Building::loadFromDataStream(QDataStream & dataStream)
{
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mTileSize = streamio::readUInt8(dataStream); mFields.push_back(mTileSize);
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mXPos = streamio::readUInt8(dataStream); mFields.push_back(mXPos);
  mYPos = streamio::readUInt8(dataStream); mFields.push_back(mYPos);
  mFields.push_back(streamio::readUInt8(dataStream));
  mFields.push_back(streamio::readUInt8(dataStream));
  mType = Type(streamio::readInt8(dataStream)); mFields.push_back(static_cast<uint8_t>(mType));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mId = streamio::readUInt16(dataStream); mFields.push_back(mId);
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));


  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));
  //mFields.push_back(streamio::readUInt8(dataStream));

  //dataStream.skipRawData(124);

  //mFields.push_back(streamio::readUInt16(dataStream));
  //mFields.push_back(streamio::readUInt16(dataStream));
  //mFields.push_back(streamio::readUInt16(dataStream));
  //mFields.push_back(streamio::readUInt16(dataStream));
  //dataStream.skipRawData(120);

//  mFields.push_back(streamio::readUInt16(dataStream));
//  mFields.push_back(streamio::readUInt16(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
//  mFields.push_back(streamio::readInt8(dataStream));
}

void Building::saveToDataStream(QDataStream & dataStream) const
{
}

void Building::setType(Type value)
{
  mType = value;
}

Building::Type Building::type() const
{
  return mType;
}
