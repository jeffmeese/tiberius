#include "imagedata.h"

#include "application/tiberiusapplication.h"

#include "imageset.h"
#include "sgimagedata.h"
#include "sgimagegroup.h"
#include "sgpixeldata.h"
#include "sgimagerecord.h"

#include <QDir>
#include <QFileInfo>

#include <sstream>
#include <stdexcept>

ImageData::ImageData()
{
}

ImageData::~ImageData()
{
}

void ImageData::addImageSet(const QString &key, std::unique_ptr<ImageSet> imageSet)
{
  mImageMap[key] = std::move(imageSet);
}

void ImageData::clearImageSets()
{
  mImageMap.clear();
}

ImageSet * ImageData::getImageSet(const QString & key)
{
  ImageSetMap::iterator itr = mImageMap.find(key);
  if (itr == mImageMap.end()) {
    return nullptr;
  }

  return itr->second.get();
}

const ImageSet * ImageData::getImageSet(const QString & key) const
{
  ImageSetMap::const_iterator itr = mImageMap.find(key);
  if (itr == mImageMap.end()) {
    return nullptr;
  }

  return itr->second.get();
}

void ImageData::loadFromDir(const QString &dirName)
{
  QStringList nameFilters;
  nameFilters << "*.sg2";

  QDir inputDir(dirName);
  QStringList fileList = inputDir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString pathName = dirName + QDir::separator() + fileList.at(i);
    QFileInfo fileInfo(pathName);
    QString fileTitle = fileInfo.baseName();
    QString fileName = fileInfo.fileName();
    QString key = fileTitle.toLower();

    QString dirName(fileInfo.path());
    QString pixelFileName = TiberiusApplication::getPixelFileName(pathName, dirName);
    if (pixelFileName.isEmpty()) {
      dirName = dirName + QDir::separator() + "555";
      pixelFileName = TiberiusApplication::getPixelFileName(pathName, dirName);
    }

    if (pixelFileName.isEmpty()) {
      std::ostringstream oss;
      oss << "Could not locate pixel file name for image file " << pathName.toStdString();
      throw std::invalid_argument(oss.str());
    }

    std::unique_ptr<ImageSet> imageSet(new ImageSet);
    imageSet->load(pathName, pixelFileName);
    addImageSet(key, std::move(imageSet));
  }
}
