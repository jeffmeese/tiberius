#include "graphicsitem.h"
#include "imageitem.h"

#include "graphics/imagedata.h"
#include "graphics/imageindexgroup.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagegroup.h"
#include "graphics/sgimagerecord.h"
#include "graphics/sgpixeldata.h"

#include <QDir>
#include <QFileInfo>

#include <sstream>

struct IndexEntry
{
  std::size_t indexId;
  int32_t imageOffset;

  bool operator<(const IndexEntry & entry)
  {
    return imageOffset < entry.imageOffset;
  }
};

GraphicsItem::GraphicsItem(const QString & imageFileName)
{
  QFileInfo fileInfo(imageFileName);
  QString dirName = fileInfo.path();
  QString fileTitle = fileInfo.baseName();
  QString pixelFileName = dirName + QDir::separator() + fileTitle + ".555";
  if (!QFile(pixelFileName).exists()) {
    pixelFileName = dirName + QDir::separator() + "555" + QDir::separator() + fileTitle + ".555";
  }

  mImageSet.reset(new ImageSet);
  mImageSet->load(imageFileName, pixelFileName);

  QStandardItem * groupsItem = new QStandardItem("Image Groups");
  appendRow(groupsItem);

  QStandardItem * indexItem = new QStandardItem("Index Groups");
  appendRow(indexItem);

  populateImageGroups(groupsItem);
  populateIndexGroups(mImageSet->imageData(), indexItem);
  setText(fileInfo.fileName());
}

void GraphicsItem::createImageItem(const SgImageRecord * imageRecord, QStandardItem *parentItem, int32_t index)
{
  uint32_t imageWidth = imageRecord->imageWidth();
  uint32_t imageHeight = imageRecord->imageHeight();

  std::ostringstream oss;
  oss << index << ". " << imageWidth << "x" << imageHeight;

  QString itemText(QString::fromStdString(oss.str()));
  ImageItem * imageItem = new ImageItem(imageRecord);
  imageItem->setText(itemText);
  imageItem->setData(imageRecord->imageOffset());

  parentItem->appendRow(imageItem);
}

QWidget * GraphicsItem::createView() const
{
  return nullptr;
}

QList<Property> GraphicsItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}

void GraphicsItem::populateImageGroups(QStandardItem * parentItem)
{
  const SgImageData * imageData = mImageSet->imageData();
  for (std::size_t i = 0; i < imageData->totalImageGroups(); i++) {
    const SgImageGroup * imageGroup = imageData->getImageGroup(i);
    std::ostringstream oss;
    oss << imageGroup->fileName().toStdString() << " (" << imageGroup->totalImages() << ")";
    QStandardItem * bitmapItem = new QStandardItem(QString::fromStdString(oss.str()));
    parentItem->appendRow(bitmapItem);

    int32_t indexNum = 0;
    for (int32_t j = imageGroup->firstImageIndex(); j <= imageGroup->lastImageIndex(); j++) {
      const SgImageRecord * imageRecord = imageData->getImageRecord(j);
      createImageItem(imageRecord, bitmapItem, ++indexNum);
    }
  }
}

void GraphicsItem::populateIndexGroups(const SgImageData * imageData, QStandardItem *parentItem)
{
  std::vector<IndexEntry> indexEntries;
  for (std::size_t i = 0; i < imageData->totalIndexEntries(); i++) {
    int32_t imageOffset = imageData->getIndexValue(i);
    if (imageOffset > 0) {
      IndexEntry entry = {i, imageOffset};
      indexEntries.push_back(entry);
    }
  }
  if (indexEntries.size() == 0) {
    return;
  }

  // Sort the index entries by image offset so we
  // can determine which image is in each index group
  std::sort(indexEntries.begin(), indexEntries.end());

  // Determine the images in each IndexGroup
  std::vector<ImageIndexGroup> indexGroups;
  for (std::size_t i = 0; i < indexEntries.size()-1; i++) {

    std::size_t nextIndex = i + 1;
    if (i == indexEntries.size()-1) {
      nextIndex = imageData->totalImageRecords()-1;
    }

    const IndexEntry & entry1 = indexEntries.at(i);
    const IndexEntry & entry2 = indexEntries.at(nextIndex);

    int32_t imageOffset = entry1.imageOffset;
    int32_t nextImageOffset = entry2.imageOffset;

    ImageIndexGroup indexGroup(static_cast<int32_t>(entry1.indexId));
    for (int32_t j = imageOffset; j < nextImageOffset; j++) {
      indexGroup.addImage(j);
    }

    indexGroups.push_back(indexGroup);
  }

  // Sort the index groups by ID
  // so we can put the groups into the model
  // in the same order they show up in the data
  std::sort(indexGroups.begin(), indexGroups.end());

  for (std::size_t i = 0; i < indexGroups.size(); i++) {
    const ImageIndexGroup & group = indexGroups.at(i);
    std::size_t totalImages = group.totalImages();

    std::ostringstream oss;
    oss << group.id() << " (" << group.getImageOffset(0) << ", " << totalImages << ")";
    QStandardItem * groupItem = new QStandardItem(QString::fromStdString(oss.str()));

    int32_t indexNum = 0;
    for (std::size_t j = 0; j < totalImages; j++) {
      uint32_t imageOffset = group.getImageOffset(j);
      const SgImageRecord * imageRecord = imageData->getImageRecord(imageOffset);
      createImageItem(imageRecord, groupItem, ++indexNum);
    }

    parentItem->appendRow(groupItem);
  }
}
