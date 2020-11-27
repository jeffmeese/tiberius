#ifndef SGIMAGERECORD_H
#define SGIMAGERECORD_H

#include <QDataStream>
#include <QImage>
#include <QString>

#include "tiberius.h"

class SgImageGroup;
class SgPixelData;

class SgImageRecord
{
// Construction / Destruction
public:
  TIBERIUS_LIB_DECL SgImageRecord(int32_t imageIndex);
  TIBERIUS_LIB_DECL ~SgImageRecord();

  // Properties
public:
  TIBERIUS_LIB_DECL bool external() const;
  TIBERIUS_LIB_DECL bool fullyCompressed() const;
  TIBERIUS_LIB_DECL bool partlyCompressed() const;
  TIBERIUS_LIB_DECL bool reversible() const;
  TIBERIUS_LIB_DECL int8_t animationSpeed() const;
  TIBERIUS_LIB_DECL int8_t bitmapId() const;
  TIBERIUS_LIB_DECL int8_t tileSize() const;
  TIBERIUS_LIB_DECL int16_t imageType() const;
  TIBERIUS_LIB_DECL int16_t animationSprites() const;
  TIBERIUS_LIB_DECL int16_t imageHeight() const;
  TIBERIUS_LIB_DECL int16_t imageWidth() const;
  TIBERIUS_LIB_DECL int16_t xOffset() const;
  TIBERIUS_LIB_DECL int16_t yOffset() const;
  TIBERIUS_LIB_DECL int32_t index() const;
  TIBERIUS_LIB_DECL int32_t imageOffset() const;
  TIBERIUS_LIB_DECL int32_t imageLength() const;
  TIBERIUS_LIB_DECL int32_t mirrorOffset() const;
  TIBERIUS_LIB_DECL int32_t uncompressedLength() const;
  TIBERIUS_LIB_DECL const SgPixelData * getPixelData() const;
  TIBERIUS_LIB_DECL void setExternal(bool value);
  TIBERIUS_LIB_DECL void setFullyCompressed(bool value);
  TIBERIUS_LIB_DECL void setPartlyCompressed(bool value);
  TIBERIUS_LIB_DECL void setReversible(bool value);
  TIBERIUS_LIB_DECL void setAnimationSpeed(int8_t value);
  TIBERIUS_LIB_DECL void setBitmapId(int8_t value);
  TIBERIUS_LIB_DECL void setImageType(int16_t value);
  TIBERIUS_LIB_DECL void setAnimationSprites(int16_t value);
  TIBERIUS_LIB_DECL void setImageHeight(int16_t value);
  TIBERIUS_LIB_DECL void setImageWidth(int16_t value);
  TIBERIUS_LIB_DECL void setParentGroup(SgImageGroup * imageGroup);
  TIBERIUS_LIB_DECL void setXOffset(int16_t value);
  TIBERIUS_LIB_DECL void setYOffset(int16_t value);
  TIBERIUS_LIB_DECL void setImageOffset(int32_t value);
  TIBERIUS_LIB_DECL void setImageLength(int32_t value);
  TIBERIUS_LIB_DECL void setUncompressedLength(int32_t value);
  TIBERIUS_LIB_DECL void setPixelData(const SgPixelData * pixelData);

  // Methods
public:
  TIBERIUS_LIB_DECL QImage createImage() const;
  TIBERIUS_LIB_DECL bool loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL bool saveToDataStream(QDataStream & dataStream) const;

private:
  void loadIsometricBase(QImage * image, const quint8 * buffer) const;
  void loadIsometricImage(QImage * image, const quint8 * buffer) const;
  void loadIsometricTile(QImage * image, const quint8 * buffer, int xOffset, int yOffset, int tileWidth, int tileHeight) const;
  void loadSpriteImage(QImage * image, const quint8 * buffer) const;
  void loadStandardImage(QImage * image, const quint8 * buffer) const;
  void loadTransparentImage(QImage * image, const quint8 * buffer, int32_t length) const;
  void setImagePixel(QImage * image, int x, int y, uint16_t color) const;

  // Members
private:
  int8_t mExternal;
  int8_t mFullyCompressed;
  int8_t mPartlyCompressed;
  int8_t mTileSize;
  int8_t mReversible;
  int8_t mAnimationSpeed;
  int8_t mBitmapId;
  int16_t mImageType;
  int16_t mAnimationSprites;
  int16_t mImageHeight;
  int16_t mImageWidth;
  int16_t mXOffset;
  int16_t mYOffset;
  int32_t mImageOffset;
  int32_t mImageLength;
  int32_t mMirrorOffset;
  int32_t mUncompressedLength;
  int32_t mImageIndex;
  const SgPixelData * mPixelData;
};

inline bool SgImageRecord::external() const
{
  return (mExternal == 1);
}

inline bool SgImageRecord::fullyCompressed() const
{
  return (mFullyCompressed == 1);
}

inline bool SgImageRecord::partlyCompressed() const
{
  return (mPartlyCompressed == 1);
}

inline bool SgImageRecord::reversible() const
{
  return (mReversible == 1);
}

inline int8_t SgImageRecord::animationSpeed() const
{
  return mAnimationSpeed;
}

inline int8_t SgImageRecord::bitmapId() const
{
  return mBitmapId;
}

inline int8_t SgImageRecord::tileSize() const
{
  return mTileSize;
}

inline int16_t SgImageRecord::imageType() const
{
  return mImageType;
}

inline int16_t SgImageRecord::animationSprites() const
{
  return mAnimationSprites;
}

inline int16_t SgImageRecord::imageHeight() const
{
  return mImageHeight;
}

inline int16_t SgImageRecord::imageWidth() const
{
  return mImageWidth;
}

inline int16_t SgImageRecord::xOffset() const
{
  return mXOffset;
}

inline int16_t SgImageRecord::yOffset() const
{
  return mYOffset;
}

inline int32_t SgImageRecord::index() const
{
  return mImageIndex;
}

inline int32_t SgImageRecord::imageOffset() const
{
  return mImageOffset;
}

inline int32_t SgImageRecord::imageLength() const
{
  return mImageLength;
}

inline int32_t SgImageRecord::mirrorOffset() const
{
  return mMirrorOffset;
}

inline int32_t SgImageRecord::uncompressedLength() const
{
  return mUncompressedLength;
}

inline const SgPixelData * SgImageRecord::getPixelData() const
{
  return mPixelData;
}

inline void SgImageRecord::setExternal(bool value)
{
  mExternal = value;
}

inline void SgImageRecord::setFullyCompressed(bool value)
{
  mFullyCompressed = value;
}

inline void SgImageRecord::setPartlyCompressed(bool value)
{
  mPartlyCompressed = value;
}

inline void SgImageRecord::setReversible(bool value)
{
  mReversible = value;
}

inline void SgImageRecord::setAnimationSpeed(int8_t value)
{
  mAnimationSpeed = value;
}

inline void SgImageRecord::setBitmapId(int8_t value)
{
  mBitmapId = value;
}

inline void SgImageRecord::setImageType(int16_t value)
{
  mImageType = value;
}

inline void SgImageRecord::setAnimationSprites(int16_t value)
{
  mAnimationSprites = value;
}

inline void SgImageRecord::setImageHeight(int16_t value)
{
  mImageHeight = value;
}

inline void SgImageRecord::setImageWidth(int16_t value)
{
  mImageWidth = value;
}

inline void SgImageRecord::setXOffset(int16_t value)
{
  mXOffset = value;
}

inline void SgImageRecord::setYOffset(int16_t value)
{
  mYOffset = value;
}

inline void SgImageRecord::setImageOffset(int32_t value)
{
  mImageOffset = value;
}

inline void SgImageRecord::setImageLength(int32_t value)
{
  mImageLength = value;
}

inline void SgImageRecord::setUncompressedLength(int32_t value)
{
  mUncompressedLength = value;
}

#endif // SGIMAGERECORD_H
