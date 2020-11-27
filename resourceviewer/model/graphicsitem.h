#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include "resourceitem.h"

#include <memory>
#include <QStandardItem>

class ImageSet;
class SgImageData;
class SgImageRecord;

class GraphicsItem
    : public ResourceItem
{
public:
  GraphicsItem(const QString & fileName);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  void createImageItem(const SgImageRecord * imageData, QStandardItem *parentItem, int32_t index);
  void populateImageGroups(QStandardItem * parentItem);
  void populateIndexGroups(const SgImageData * imageData, QStandardItem * parentItem);

private:
  std::unique_ptr<ImageSet> mImageSet;
  //std::unique_ptr<ImageData> mImageData;
};

#endif // GRAPHICGROUP_H
