#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <cstdint>
#include <map>
#include <memory>
#include <vector>

#include <QString>

#include "tiberius.h"

class ImageSet;

class ImageData
{
public:
  TIBERIUS_LIB_DECL ImageData();
  TIBERIUS_LIB_DECL ~ImageData();

public:
  TIBERIUS_LIB_DECL void addImageSet(const QString & key, std::unique_ptr<ImageSet> imageSet);
  TIBERIUS_LIB_DECL void clearImageSets();
  TIBERIUS_LIB_DECL ImageSet * getImageSet(const QString & key);
  TIBERIUS_LIB_DECL const ImageSet * getImageSet(const QString & key) const;
  TIBERIUS_LIB_DECL void loadFromDir(const QString & dirName);
  TIBERIUS_LIB_DECL std::size_t totalImageSets() const;

private:
  using ImageSetPtr = std::unique_ptr<ImageSet>;
  using ImageSetMap = std::map<QString, ImageSetPtr>;

private:
  ImageSetMap mImageMap;
};

#endif // IMAGEDATA_H
