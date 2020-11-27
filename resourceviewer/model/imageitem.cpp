#include "imageitem.h"

//#include "graphics/imagedata.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QLabel>
#include <QImage>

#include <sstream>

ImageItem::ImageItem(const SgImageRecord * imageRecord)
  : mImageRecord(imageRecord)
{
}

QWidget * ImageItem::createView() const
{
  QImage image = mImageRecord->createImage();

  QLabel * label = new QLabel;
  label->setAlignment(Qt::AlignCenter);
  label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  label->setPixmap(QPixmap::fromImage(image));
  return label;
}

QList<Property> ImageItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.push_back(Property("Index", QString::number(mImageRecord->index())));
  propertyList.push_back(Property("Offset", QString::number(mImageRecord->imageOffset())));
  propertyList.push_back(Property("Length", QString::number(mImageRecord->imageLength())));
  propertyList.push_back(Property("Uncompressed Length", QString::number(mImageRecord->uncompressedLength())));
  propertyList.push_back(Property("Width", QString::number(mImageRecord->imageWidth())));
  propertyList.push_back(Property("Height", QString::number(mImageRecord->imageHeight())));
  propertyList.push_back(Property("External", QString::number(mImageRecord->external())));
  propertyList.push_back(Property("Fully Compressed", QString::number(mImageRecord->fullyCompressed())));
  propertyList.push_back(Property("Partly Compressed", QString::number(mImageRecord->partlyCompressed())));
  propertyList.push_back(Property("Bitmap ID", QString::number(mImageRecord->bitmapId())));

  return propertyList;
}
