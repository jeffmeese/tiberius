#ifndef IMAGESET_H
#define IMAGESET_H

#include <memory>
#include <vector>

#include <QString>

#include "tiberius.h"

class SgImageData;
class SgPixelData;

class ImageSet
{
public:
  TIBERIUS_LIB_DECL ImageSet();

public:
  TIBERIUS_LIB_DECL SgImageData * imageData();
  TIBERIUS_LIB_DECL const SgImageData * imageData() const;
  TIBERIUS_LIB_DECL SgPixelData * pixelData();
  TIBERIUS_LIB_DECL const SgPixelData * pixelData() const;
  TIBERIUS_LIB_DECL void setImageData(std::unique_ptr<SgImageData> imageData);
  TIBERIUS_LIB_DECL void setPixelData(std::unique_ptr<SgPixelData> pixelData);

public:
  TIBERIUS_LIB_DECL void load(const QString & imageFileName, const QString & pixelFileName);

private:
  void associatePixelData();

private:
  using ImageDataPtr = std::unique_ptr<SgImageData>;
  using PixelDataPtr = std::unique_ptr<SgPixelData>;

private:
  ImageDataPtr mImageData;
  PixelDataPtr mPixelData;
  std::vector<PixelDataPtr> mExternalPixelData;
};

inline SgImageData * ImageSet::imageData()
{
  return mImageData.get();
}

inline const SgImageData * ImageSet::imageData() const
{
  return mImageData.get();
}

inline SgPixelData * ImageSet::pixelData()
{
  return mPixelData.get();
}

inline const SgPixelData * ImageSet::pixelData() const
{
  return mPixelData.get();
}

#endif // IMAGESET_H
