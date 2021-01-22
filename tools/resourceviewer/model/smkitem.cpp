#include "smkitem.h"

#include "media/video.h"

#include "widgets/smkwidget.h"

#include <QFileInfo>

SmkItem::SmkItem(const QString & pathName)
{
  QFileInfo fileInfo(pathName);
  setText(fileInfo.fileName());

  mVideo.reset(new Video(1, pathName));
}

QWidget * SmkItem::createView() const
{
  SmkWidget * widget = new SmkWidget(mVideo.get());
  return widget;
}

QList<Property> SmkItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Width", QString::number(mVideo->width())));
  propertyList.append(Property("Height", QString::number(mVideo->height())));
  propertyList.append(Property("Scale Mode", mVideo->scaleMode()));
  propertyList.append(Property("Frame", QString::number(mVideo->frame())));
  propertyList.append(Property("Frame Count", QString::number(mVideo->frameCount())));
  propertyList.append(Property("Microseconds Per Frame", QString::number(mVideo->usf())));
  propertyList.append(Property("Frames Per Second", QString::number(mVideo->framesPerSecond())));
  return propertyList;
}
