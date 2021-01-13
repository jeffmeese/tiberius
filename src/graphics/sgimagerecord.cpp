#include "sgimagerecord.h"

#include "sgimagegroup.h"
#include "sgpixeldata.h"

#include <sstream>

#include <QDebug>

enum {
  ISOMETRIC_TILE_WIDTH = 58,
  ISOMETRIC_TILE_HEIGHT = 30,
  ISOMETRIC_TILE_BYTES = 1800,
  ISOMETRIC_LARGE_TILE_WIDTH = 78,
  ISOMETRIC_LARGE_TILE_HEIGHT = 40,
  ISOMETRIC_LARGE_TILE_BYTES = 3200
};

SgImageRecord::SgImageRecord(int32_t imageIndex)
  : mImageIndex(imageIndex)
  , mPixelData(nullptr)
{
  mExternal = mReversible = mFullyCompressed = mPartlyCompressed = 0;
  mImageType = mImageWidth = mImageHeight = mImageLength = mImageOffset = 0;
  mUncompressedLength = mAnimationSpeed = mAnimationSprites = 0;
  mBitmapId = mXOffset = mYOffset = mTileSize = mMirrorOffset = 0;
}

SgImageRecord::~SgImageRecord()
{
}

QImage SgImageRecord::createImage() const
{
  if (mPixelData == nullptr) {
    qDebug() << "No pixel data specified for image record";
    return QImage();
  }

  // Calculate the offset of this image
  // External images have an offset of 1
  int32_t offset = mImageOffset;
  if (mExternal)
    offset--;

  // Get a pointer to the section of the pixel data for this image
  const quint8 * buffer = reinterpret_cast<const quint8*>(&(mPixelData->data()[offset]));

  // Create an image and set it's background to black
  QImage image(mImageWidth, mImageHeight, QImage::Format_ARGB32_Premultiplied);
  image.fill(0);

  switch (mImageType) {
  case 0: case 1: case 10: case 12: case 13:
    loadStandardImage(&image, buffer);
    break;
  case 30:
    loadIsometricImage(&image, buffer);
    break;
  case 256: case 257: case 276:
    loadSpriteImage(&image, buffer);
    break;
  }

  for (int i = 0; i < mImageHeight; i++) {
    for (int j = 0; j < mImageWidth; j++) {

    }
  }
  return image;
}

bool SgImageRecord::loadFromDataStream(QDataStream & dataStream)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  dataStream >> mImageOffset;
  dataStream >> mImageLength;
  dataStream >> mUncompressedLength;
  dataStream.skipRawData(4);
  dataStream >> mMirrorOffset;
  dataStream >> mImageWidth;
  dataStream >> mImageHeight;
  dataStream.skipRawData(6);
  dataStream >> mAnimationSprites;
  dataStream.skipRawData(2);
  dataStream >> mXOffset;
  dataStream >> mYOffset;
  dataStream.skipRawData(10);
  dataStream >> mReversible;
  dataStream.skipRawData(1);
  dataStream >> mImageType;
  dataStream >> mExternal;
  dataStream >> mFullyCompressed;
  dataStream >> mPartlyCompressed;
  dataStream >> mTileSize;
  dataStream >> mBitmapId;
  dataStream.skipRawData(1);
  dataStream >> mAnimationSpeed;
  dataStream.skipRawData(5);

  return true;
}

void SgImageRecord::loadIsometricBase(QImage *image, const quint8 * buffer) const
{
  int32_t size = mTileSize;
  int32_t width = mImageWidth;
  int32_t height = (width + 2) / 2;
  int32_t heightOffset = mImageHeight - height;
  int32_t yOffset = heightOffset;

  if (size == 0) {
    if (height % ISOMETRIC_TILE_HEIGHT == 0) {
      size = height / ISOMETRIC_TILE_HEIGHT;
    } else if (height % ISOMETRIC_LARGE_TILE_HEIGHT == 0) {
      size = height / ISOMETRIC_LARGE_TILE_HEIGHT;
    }
  }

  int32_t tileBytes = ISOMETRIC_TILE_BYTES;
  int32_t tileHeight = ISOMETRIC_TILE_HEIGHT;
  int32_t tileWidth = ISOMETRIC_TILE_WIDTH;
  if (ISOMETRIC_LARGE_TILE_HEIGHT * size == height) {
    tileBytes = ISOMETRIC_LARGE_TILE_BYTES;
    tileHeight = ISOMETRIC_LARGE_TILE_HEIGHT;
    tileWidth = ISOMETRIC_LARGE_TILE_WIDTH;
  }

  int32_t i = 0;
  int32_t yEnd = size + (size - 1);
  for (int32_t y = 0; y < yEnd; y++) {
    int32_t xOffset = (y-size+1) * tileHeight;
    int32_t xEnd = 2*size-y-1;
    if (y < size) {
      xOffset = (size-y-1) * tileHeight;
      xEnd = y + 1;
    }
    for (int32_t x = 0; x < xEnd; x++, i++) {
      loadIsometricTile(image, &buffer[i*tileBytes], xOffset, yOffset, tileWidth, tileHeight);
      xOffset += tileWidth + 2;
    }
    yOffset += tileHeight / 2;
  }
}

void SgImageRecord::loadIsometricImage(QImage *image, const quint8 * buffer) const
{
  loadIsometricBase(image, buffer);
  loadTransparentImage(image, &buffer[mUncompressedLength], mImageLength - mUncompressedLength);
}

void SgImageRecord::loadIsometricTile(QImage * image, const quint8 * buffer, int xOffset, int yOffset, int tileWidth, int tileHeight) const
{
  int i = 0;
  int halfHeight = tileHeight / 2;
  for (int y = 0; y < halfHeight; y++) {
    int start = tileHeight - 2*(y+1);
    int end = tileWidth - start;
    for (int x = start; x < end; x++, i += 2) {
      uint8_t b0 = buffer[i];
      uint8_t b1 = buffer[i+1];
      uint16_t color = b0 | (b1 << 8);
      setImagePixel(image, xOffset + x, yOffset + y, color);
    }
  }

  for (int y = halfHeight; y < tileHeight; y++) {
    int start = 2*y - tileHeight;
    int end = tileWidth - start;
    for (int x = start; x < end; x++, i += 2) {
      uint8_t b0 = buffer[i];
      uint8_t b1 = buffer[i+1];
      uint16_t color = b0 | (b1 << 8);
      setImagePixel(image, xOffset + x, yOffset + y, color);
    }
  }
}

void SgImageRecord::loadSpriteImage(QImage *image, const quint8 * buffer) const
{
  loadTransparentImage(image, buffer, mImageLength);
}

void SgImageRecord::loadStandardImage(QImage *image, const quint8 * buffer) const
{
  int32_t i = 0;
  for (int32_t y = 0; y < mImageHeight; y++) {
    for (int32_t x = 0; x < mImageWidth; x++, i += 2) {
      uint8_t b0 = buffer[i];
      uint8_t b1 = buffer[i+1];
      uint16_t color = b0 | (b1 << 8);
      setImagePixel(image, x, y, color);
    }
  }
}

void SgImageRecord::loadTransparentImage(QImage * image, const quint8 * buffer, int length) const
{
  int32_t x = 0, y = 0;
  int32_t i = 0;
  while (i < length) {
    quint8 value = buffer[i++];
    if (value == 255) {
      x += buffer[i++];
      while (x >= image->width()) {
        y++;
        x -= image->width();
      }
    }
    else {
      for (int32_t j = 0; j < value; j++, i += 2) {
        uint8_t b0 = buffer[i];
        uint8_t b1 = buffer[i+1];

        setImagePixel(image, x, y, (uint16_t)(b0 | (b1 << 8)));
        x++;
        if (x >= image->width()) {
          y++;
          x = 0;
        }
      }
    }
  }
}

bool SgImageRecord::saveToDataStream(QDataStream & dataStream) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  int32_t dummyValue = 0;
  int16_t dummyShort = 0;
  int8_t dummyByte = 0;

  dataStream << mImageOffset;
  dataStream << mImageLength;
  dataStream << mUncompressedLength;
  dataStream << dummyValue;
  dataStream << mMirrorOffset;
  dataStream << mImageWidth;
  dataStream << mImageHeight;
  dataStream << dummyShort;
  dataStream << dummyShort;
  dataStream << dummyShort;
  dataStream << mAnimationSprites;
  dataStream << dummyShort;
  dataStream << mXOffset;
  dataStream << mYOffset;
  dataStream << dummyValue;
  dataStream << dummyValue;
  dataStream << dummyShort;
  dataStream << mReversible;
  dataStream << dummyByte;
  dataStream << mImageType;
  dataStream << mExternal;
  dataStream << mFullyCompressed;
  dataStream << mPartlyCompressed;
  dataStream << mTileSize;
  dataStream << dummyByte;
  dataStream << mBitmapId;
  dataStream << dummyByte;
  dataStream << mAnimationSpeed;
  dataStream << dummyByte;
  dataStream << dummyValue;

  return true;
}

void SgImageRecord::setImagePixel(QImage * image, int x, int y, uint16_t color) const
{
  if (color == 0xf81f) {
    return;
  }

  quint32 rgb = 0xff000000;
  rgb |= ((color & 0x7c00) << 9) | ((color & 0x7000) << 4); // Red: bits 11-15, should go to bits 17-24
  rgb |= ((color & 0x3e0) << 6) | ((color & 0x300));        // Green: bits 6-10, should go to bits 9-16
  rgb |= ((color & 0x1f) << 3) | ((color & 0x1c) >> 2);     // Blue: bits 1-5, should go to bits 1-8
  image->setPixel(x, y, rgb);
}

void SgImageRecord::setPixelData(const SgPixelData *pixelData)
{
  mPixelData = pixelData;
}
