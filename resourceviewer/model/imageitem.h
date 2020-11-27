#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include "resourceitem.h"

class SgImageRecord;

class ImageItem
    : public ResourceItem
{
public:
  ImageItem(const SgImageRecord * imageRecord);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const SgImageRecord * mImageRecord;
};

#endif // IMAGEITEM_H
