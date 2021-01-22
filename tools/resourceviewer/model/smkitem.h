#ifndef SMKITEM_H
#define SMKITEM_H

#include "resourceitem.h"

class Video;

class SmkItem
    : public ResourceItem
{
public:
  SmkItem(const QString & pathName);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  std::unique_ptr<Video> mVideo;
};

#endif // SMKITEM_H
