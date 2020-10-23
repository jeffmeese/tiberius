#include "dialog.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/stitchedimage.h"

#include <QPainter>

Dialog::Dialog(QWidget * parentWidget)
  : QDialog(parentWidget)
{
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

void Dialog::drawBorder(QPainter & painter)
{
  SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageIndex = imageData->getGroupBaseImageId(GROUP_DIALOG_BACKGROUND);

  int w = width();
  int h = height();
  StitchedImage stitchedImage(16, 16, 12, 12, baseImageIndex);
  painter.drawImage(0, 0, stitchedImage.constructImage(w, h));
}

void Dialog::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  drawBorder(painter);
}

