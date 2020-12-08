#include "figure.h"

#include "application/tiberiusapplication.h"

#include "core/streamio.h"

#include <QDebug>

#include "graphics/imagedata.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QDebug>
#include <QPixmap>

Figure::Figure(int32_t id)
{
  mId = id;
  mImageId = 0;
  mCartImageId = 0;
  mType = Figure::Type::None;
}

int32_t Figure::id() const
{
  return mId;
}

int16_t Figure::cartImageId() const
{
  return mCartImageId;
}

QPixmap Figure::getCartImage() const
{
  if (mCartImageId == 0)
    return QPixmap();

  SgImageData * imageData = TiberiusApplication::climateImages();
  return QPixmap::fromImage(imageData->getImageRecord(mCartImageId)->createImage());
}

QPixmap Figure::getImage() const
{
  if (mImageId == 0)
    return QPixmap();

  SgImageData * imageData = TiberiusApplication::climateImages();
  return QPixmap::fromImage(imageData->getImageRecord(mImageId)->createImage());
}

QString Figure::getName() const
{
  return "";
}

int32_t Figure::id() const
{
  return mId;
}

int16_t Figure::imageId() const
{
  return mImageId;
}

void Figure::loadFromDataStream(QDataStream & dataStream)
{
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt8(dataStream));
  mFields.push_back(streamio::readInt16(dataStream));
  mFields.push_back(streamio::readInt16(dataStream));
  mFields.push_back(streamio::readInt16(dataStream));
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
  mFields.push_back(streamio::readInt16(dataStream));
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
  mFields.push_back(streamio::readInt16(dataStream));
  mFields.push_back(streamio::readInt16(dataStream));
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
  mFields.push_back(streamio::readInt16(dataStream));
  mFields.push_back(streamio::readInt16(dataStream));
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
  mFields.push_back(streamio::readInt16(dataStream));
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
}

void Figure::saveToDataStream(QDataStream & dataStream) const
{
}

void Figure::setCartImageId(int16_t value)
{
  mCartImageId = value;
}

void Figure::setImageId(int16_t value)
{
  mImageId = value;
}

void Figure::setType(Type type)
{
  mType = type;
}

Figure::Type Figure::type() const
{
  return mType;
}
