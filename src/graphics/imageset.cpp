#include "imageset.h"

#include "application/tiberiusapplication.h"

#include "sgimagedata.h"
#include "sgimagegroup.h"
#include "sgimagerecord.h"
#include "sgpixeldata.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>

ImageSet::ImageSet()
  : mImageData(new SgImageData)
  , mPixelData(new SgPixelData)
{
}

void ImageSet::associatePixelData()
{
  mExternalPixelData.clear();

  for (std::size_t j = 0; j < mImageData->totalImageGroups(); j++) {
    SgImageGroup * imageGroup = mImageData->getImageGroup(j);
    QString groupFileName = imageGroup->fileName();
    for (int32_t k = imageGroup->firstImageIndex(); k <= imageGroup->lastImageIndex(); k++) {
      SgImageRecord * imageRecord = mImageData->getImageRecord(k);
      if (imageRecord->external()) {
        imageRecord->setPixelData(nullptr);

        QString c3Dir = TiberiusApplication::c3Dir();
        QFileInfo fileInfo(groupFileName);
        QString fileTitle = fileInfo.baseName();
        QString pixelFileName = c3Dir + QDir::separator() + fileTitle + ".555";
        if (!QFile::exists(pixelFileName)) {
          pixelFileName = c3Dir + QDir::separator() + "555" + QDir::separator() + fileTitle + ".555";
        }

        PixelDataPtr pixelData(new SgPixelData);
        pixelData->loadFromFile(pixelFileName);
        imageRecord->setPixelData(pixelData.get());
        mExternalPixelData.push_back(std::move(pixelData));
      }
      else {
        imageRecord->setPixelData(mPixelData.get());
      }
    }
  }
}

void ImageSet::load(const QString &imageFileName, const QString &pixelFileName)
{
  mImageData.reset(new SgImageData);
  mPixelData.reset(new SgPixelData);

  mImageData->loadFromFile(imageFileName);
  mPixelData->loadFromFile(pixelFileName);
  associatePixelData();
}

void ImageSet::setImageData(std::unique_ptr<SgImageData> imageData)
{
  mImageData = std::move(imageData);
  associatePixelData();
}

void ImageSet::setPixelData(std::unique_ptr<SgPixelData> pixelData)
{
  mPixelData = std::move(pixelData);
  associatePixelData();
}
