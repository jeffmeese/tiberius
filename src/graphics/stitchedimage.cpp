#include "stitchedimage.h"

#include "application/tiberiusapplication.h"

#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QDebug>
#include <QPainter>

StitchedImage::StitchedImage(int32_t blockWidth, int32_t blockHeight, int32_t numX, int32_t numY, int32_t imageOffset)
  : mBlockWidth(blockWidth)
  , mBlockHeight(blockHeight)
  , mNumX(numX)
  , mNumY(numY)
  , mImageOffset(imageOffset)
{
}

QImage StitchedImage::constructImage(int32_t w, int32_t h)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();

  int32_t cols = w / mBlockWidth;
  int32_t rows = h / mBlockHeight;

  QImage image(w, h, QImage::Format_ARGB32);
  QPainter painter(&image);

  int32_t imageRow = 0;
  for (int32_t y = 0; y < rows; y++) {
    int32_t imageCol = 0;
    for (int32_t x = 0; x < cols; x++) {

      uint32_t imageOffset = 0;
      if (y == 0) {

        // Top-Left
        if (x == 0) {
          imageOffset = 0;
        }

        // Top-Middle
        else if (x < cols-1) {
          imageOffset = imageCol;
        }

        // Top-Right
        else if (x == cols-1) {
          imageOffset = mNumX-1;
        }
      }
      else if (y < rows-1) {

        // Middle-Left
        if (x == 0) {
          imageOffset = imageRow*mNumX;
        }

        // Middle-Center
        else if (x < cols-1) {
          imageOffset = imageRow*mNumX + imageCol;
        }

        // Middle-Right
        else if (x == cols-1) {
          imageOffset = imageRow*mNumX + mNumX - 1;
        }
      }

      if (y == rows-1) {

        // Bottom-Left
        if (x == 0) {
          imageOffset = (mNumY-1)*mNumX;
        }

        // Bottom-Middle
        else if (x < cols-1) {
          imageOffset = (mNumY-1)*mNumX + imageCol;
        }

        // Bottom-Right
        else if (x == cols-1) {
          imageOffset = mNumX*mNumY-1;
        }
      }

      const SgImageRecord * imageRecord = imageData->getImageRecord(mImageOffset + imageOffset);
      painter.drawImage(x*mBlockWidth, y*mBlockHeight, imageRecord->createImage());

      imageCol++;
      if (imageCol == mNumX-1) {
        imageCol = 1;
      }
    }

    imageRow++;
    if (imageRow == mNumY-1) {
      imageRow = 1;
    }
  }

  return image;
}

QImage StitchedImage::create(int32_t w, int32_t h, int32_t blockWidth, int32_t blockHeight, int32_t numX, int32_t numY, int32_t imageOffset)
{
  StitchedImage image(blockWidth, blockHeight, numX, numY, imageOffset);
  return image.constructImage(w, h);
}
