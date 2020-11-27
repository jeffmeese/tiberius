#ifndef STITCHEDIMAGE_H
#define STITCHEDIMAGE_H

#include <cstdint>

#include <QImage>

#include "tiberius.h"

class StitchedImage
{
public:
  TIBERIUS_LIB_DECL StitchedImage(int32_t mBlockWidth, int32_t mBlockHeight, int32_t numX, int32_t numY, int32_t imageOffset);

public:
  TIBERIUS_LIB_DECL QImage constructImage(int32_t w, int32_t h);
  TIBERIUS_LIB_DECL static QImage create(int32_t w, int32_t h, int32_t blockWidth, int32_t blockHeight, int32_t numX, int32_t numY, int32_t imageOffset);

private:
  int32_t mBlockWidth;
  int32_t mBlockHeight;
  int32_t mNumX;
  int32_t mNumY;
  int32_t mImageOffset;
};

#endif // STITCHEDIMAGE_H
