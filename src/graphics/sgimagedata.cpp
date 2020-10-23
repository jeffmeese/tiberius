#include "sgimagedata.h"

#include "sgimagegroup.h"
#include "sgimagerecord.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QPainter>

SgImageData::SgImageData()
{
}

SgImageData::~SgImageData()
{
}

void SgImageData::addImageGroup(std::unique_ptr<SgImageGroup> imageGroup)
{
  mImageGroups.push_back(std::move(imageGroup));
}

void SgImageData::addImageRecord(std::unique_ptr<SgImageRecord> imageRecord)
{
  mImageRecords.push_back(std::move(imageRecord));
}

void SgImageData::clearImageGroups()
{
  mImageGroups.clear();
}

void SgImageData::clearImageRecords()
{
  mImageRecords.clear();
}

SgImageGroup * SgImageData::getImageGroup(std::size_t index)
{
  return mImageGroups.at(index).get();
}

const SgImageGroup * SgImageData::getImageGroup(std::size_t index) const
{
  return mImageGroups.at(index).get();
}

SgImageRecord * SgImageData::getImageRecord(std::size_t index)
{
  return mImageRecords.at(index).get();
}

const SgImageRecord * SgImageData::getImageRecord(std::size_t index) const
{
  return mImageRecords.at(index).get();
}

bool SgImageData::loadFromDataStream(QDataStream &dataStream)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  // Read the header
  SgHeader header;
  header.loadFromDataStream(dataStream);

  // Read the index entries
  for (int16_t i = 0; i < MAX_INDEX_ENTRIES; i++) {
    dataStream >> mIndexData[i];
  }

  // Read the image groups
  for (int32_t i = 0; i < header.mTotalImageGroups; i++) {
    ImageGroupPtr imageGroup(new SgImageGroup);
    imageGroup->loadFromDataStream(dataStream);
    addImageGroup(std::move(imageGroup));
  }

  // Skip the unused image groups
  uint32_t unusedGroups = MAX_IMAGE_GROUPS - header.mTotalImageGroups;
  dataStream.skipRawData(unusedGroups * SgImageGroup::RECORD_SIZE);

  // Read the image records
  for (int32_t i = 0; i < header.mTotalImageRecords; i++) {
    ImageRecordPtr imageRecord(new SgImageRecord(i));
    imageRecord->loadFromDataStream(dataStream);
    addImageRecord(std::move(imageRecord));
  }

  return true;
}

bool SgImageData::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    return false;
  }

  QDataStream dataStream(&file);
  return loadFromDataStream(dataStream);
}

bool SgImageData::saveToDataStream(QDataStream &dataStream) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  // TODO: Fill the header information
  SgHeader header;
  //header.mVersion = SgHeader::VERSION_SG2;
  //header.mTotalImageGroups =  static_cast<uint32_t>(mImageGroups.size());

  // Save the header
  header.saveToDataStream(dataStream);

  // Save the index entries
  for (uint16_t i = 0; i < MAX_INDEX_ENTRIES; i++) {
    dataStream << mIndexData[i];
  }

  // Save the image groups
  for (uint32_t i = 0; i < mImageGroups.size(); i++) {
    const SgImageGroup * imageGroup = mImageGroups.at(i).get();
    imageGroup->saveToDataStream(dataStream);
  }

  return true;
}

bool SgImageData::saveToFile(const QString &fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    return false;
  }

  QDataStream dataStream(&file);
  dataStream.setByteOrder(QDataStream::LittleEndian);
  return saveToDataStream(dataStream);
}

SgImageData::SgHeader::SgHeader()
{

}

bool SgImageData::SgHeader::loadFromDataStream(QDataStream & dataStream)
{
  dataStream >> mFileSize;
  dataStream >> mVersion;
  dataStream.skipRawData(4);
  dataStream >> mTotalImageRecords;
  dataStream >> mTotalImageRecordsUsed;
  dataStream >> mTotalImageGroups;
  dataStream.skipRawData(4);
  dataStream >> mTotalImageFileSize;
  dataStream >> mInternalFileSize;
  dataStream >> mExternalFileSize;
  dataStream.skipRawData(40);

  return true;
}

bool SgImageData::SgHeader::saveToDataStream(QDataStream & dataStream) const
{
  return true;
}
