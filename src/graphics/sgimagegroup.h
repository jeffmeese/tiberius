#ifndef SGIMAGEGROUP_H
#define SGIMAGEGROUP_H

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>
#include <QString>

#include "tiberius.h"

class SgImageRecord;

class SgImageGroup
{
public:
  enum {
    RECORD_SIZE = 200
  };

public:
  TIBERIUS_LIB_DECL SgImageGroup();

public:
  TIBERIUS_LIB_DECL QString description() const;
  TIBERIUS_LIB_DECL QString fileName() const;
  TIBERIUS_LIB_DECL int32_t firstImageIndex() const;
  TIBERIUS_LIB_DECL int32_t height() const;
  TIBERIUS_LIB_DECL int32_t lastImageIndex() const;
  TIBERIUS_LIB_DECL int32_t width() const;
  TIBERIUS_LIB_DECL int32_t totalImages() const;
  TIBERIUS_LIB_DECL void setDescription(const QString & value);
  TIBERIUS_LIB_DECL void setFileName(const QString & value);
  TIBERIUS_LIB_DECL void setFirstImageIndex(int32_t value);
  TIBERIUS_LIB_DECL void setHeight(int32_t value);
  TIBERIUS_LIB_DECL void setLastImageIndex(int32_t value);
  TIBERIUS_LIB_DECL void setWidth(int32_t value);
  TIBERIUS_LIB_DECL void setTotalImages(int32_t value);

public:
  TIBERIUS_LIB_DECL bool loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL bool saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mFirstImageIndex;
  int32_t mHeight;
  int32_t mLastImageIndex;
  int32_t mTotalImages;
  int32_t mWidth;
  QString mFileName;
  QString mDescription;
};

inline QString SgImageGroup::description() const
{
  return mDescription;
}

inline QString SgImageGroup::fileName() const
{
  return mFileName;
}

inline int32_t SgImageGroup::firstImageIndex() const
{
  return mFirstImageIndex;
}

inline int32_t SgImageGroup::height() const
{
  return mHeight;
}

inline int32_t SgImageGroup::lastImageIndex() const
{
  return mLastImageIndex;
}

inline int32_t SgImageGroup::totalImages() const
{
  return mTotalImages;
}

inline int32_t SgImageGroup::width() const
{
  return mWidth;
}

inline void SgImageGroup::setDescription(const QString & value)
{
  mDescription = value;
}

inline void SgImageGroup::setFileName(const QString & value)
{
  mFileName = value;
}

inline void SgImageGroup::setFirstImageIndex(int32_t value)
{
  mFirstImageIndex = value;
}

inline void SgImageGroup::setHeight(int32_t value)
{
  mHeight = value;
}

inline void SgImageGroup::setLastImageIndex(int32_t value)
{
  mLastImageIndex = value;
}

inline void SgImageGroup::setWidth(int32_t value)
{
  mWidth = value;
}

inline void SgImageGroup::setTotalImages(int32_t value)
{
  mTotalImages = value;
}

#endif // SGIMAGEGROUP_H
