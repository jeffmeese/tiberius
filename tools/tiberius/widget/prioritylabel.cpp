#include "prioritylabel.h"

#include "application/application.h"

#include "core/painter.h"

#include "graphics/imagedata.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

PriorityLabel::PriorityLabel(QWidget * parentWidget)
  : Label(parentWidget)
  , mHover(false)
{
}

void PriorityLabel::drawOutline(Painter & painter)
{
  int w = width();
  int h = height();

  if (isEnabled()) {
    QPen pen(Qt::black);
    if (mHover)
      pen.setColor(Qt::red);

    painter.setPen(pen);
    painter.drawRect(1, 0, w-2, h-1);
  }
  else {
    QColor color(100, 100, 100);
    QBrush brush(color);
    painter.fillRect(1, 0, w-2, h-1, brush);

    QPen pen(Qt::black);
    painter.setPen(pen);
    painter.drawRect(1, 0, w-2, h-1);
  }
}

void PriorityLabel::enterEvent(QEvent * e)
{
  Label::enterEvent(e);
  mHover = true;
  update();
}

void PriorityLabel::leaveEvent(QEvent * e)
{
  Label::leaveEvent(e);
  mHover = false;
  update();
}

void PriorityLabel::paintEvent(QPaintEvent * e)
{
  Painter painter(this);
  drawOutline(painter);
  drawText(painter);
}

