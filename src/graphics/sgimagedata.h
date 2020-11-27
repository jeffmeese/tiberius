#ifndef SGIMAGEDATA_H
#define SGIMAGEDATA_H

#include <memory>
#include <vector>

#include <QDataStream>
#include <QString>

#include "tiberius.h"

class SgImageGroup;
class SgImageRecord;

class SgImageData
{
public:
  TIBERIUS_LIB_DECL SgImageData();
  TIBERIUS_LIB_DECL ~SgImageData();

public:
  TIBERIUS_LIB_DECL void addImageGroup(std::unique_ptr<SgImageGroup> imageGroup);
  TIBERIUS_LIB_DECL void addImageRecord(std::unique_ptr<SgImageRecord> imageRecord);
  TIBERIUS_LIB_DECL void clearImageGroups();
  TIBERIUS_LIB_DECL void clearImageRecords();
  TIBERIUS_LIB_DECL int32_t getGroupBaseImageId(int16_t index) const;
  TIBERIUS_LIB_DECL int32_t getIndexValue(std::size_t index) const;
  TIBERIUS_LIB_DECL SgImageGroup * getImageGroup(std::size_t index);
  TIBERIUS_LIB_DECL const SgImageGroup * getImageGroup(std::size_t index) const;
  TIBERIUS_LIB_DECL SgImageRecord * getImageRecord(std::size_t imageId);
  TIBERIUS_LIB_DECL const SgImageRecord * getImageRecord(std::size_t imageId) const;
  TIBERIUS_LIB_DECL bool loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL bool loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL bool saveToDataStream(QDataStream & dataStream) const;
  TIBERIUS_LIB_DECL bool saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL std::size_t totalImageGroups() const;
  TIBERIUS_LIB_DECL std::size_t totalImageRecords() const;
  TIBERIUS_LIB_DECL std::size_t totalIndexEntries() const;

private:
  class SgHeader
  {
    friend class SgImageData;

    // Constants
  public:
    static const uint32_t VERSION_SG2      = 211;
    static const uint32_t VERSION_SG3      = 213;
    static const uint32_t VERSION_SG3Alpha = 214;

    // Construction / Destruction
  public:
    SgHeader();

    // Methods
  public:
    bool loadFromDataStream(QDataStream & dataStream);
    bool saveToDataStream(QDataStream & dataStream) const;

    // Members
  private:
    int32_t mExternalFileSize;
    int32_t mFileSize;
    int32_t mInternalFileSize;
    int32_t mTotalImageGroups;
    int32_t mTotalImageFileSize;
    int32_t mTotalImageRecords;
    int32_t mTotalImageRecordsUsed;
    int32_t mVersion;
  };

private:
  static const int16_t MAX_INDEX_ENTRIES = 300;
  static const int16_t MAX_IMAGE_GROUPS = 100;

private:
  typedef std::unique_ptr<SgImageGroup> ImageGroupPtr;
  typedef std::unique_ptr<SgImageRecord> ImageRecordPtr;
  typedef std::vector<ImageGroupPtr> ImageGroupVector;
  typedef std::vector<ImageRecordPtr> ImageRecordVector;

private:
  ImageGroupVector mImageGroups;
  ImageRecordVector mImageRecords;
  int16_t mIndexData[MAX_INDEX_ENTRIES];
};

inline int32_t SgImageData::getGroupBaseImageId(int16_t index) const
{
  return mIndexData[index];
}

inline int32_t SgImageData::getIndexValue(std::size_t index) const
{
  return mIndexData[index];
}

inline std::size_t SgImageData::totalImageGroups() const
{
  return mImageGroups.size();
}

inline std::size_t SgImageData::totalImageRecords() const
{
  return mImageRecords.size();
}

inline std::size_t SgImageData::totalIndexEntries() const
{
  return MAX_INDEX_ENTRIES;
}

#endif // SGIMAGEDATA_H
