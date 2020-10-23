#include "label.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QPainter>

Label::Label(QWidget * parentWidget)
  : QLabel(parentWidget)
{
}

void Label::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawText(painter);
}

void Label::drawText(Painter & painter)
{
  QString textString = text();

  const Font & f = textFont();
  int32_t textWidth = f.calculateTextWidth(textString);
  int32_t textHeight = f.lineHeight();

  int32_t w = width();
  int32_t h = height();
  int32_t xOffset = 0;
  int32_t yOffset = 0;

  Qt::Alignment alignment = this->alignment();
  if (alignment.testFlag(Qt::AlignHCenter)) {
    xOffset = (w - textWidth) / 2;
  }
  if (alignment.testFlag(Qt::AlignVCenter)) {
    yOffset = (h - textHeight) / 2;
  }
  if (alignment.testFlag(Qt::AlignRight)) {
    xOffset = w - textWidth;
  }
  if (alignment.testFlag(Qt::AlignBottom)) {
    yOffset = h - textHeight;
  }
  if (alignment.testFlag(Qt::AlignCenter)) {
    xOffset = (w - textWidth) / 2;
    yOffset = (h - textHeight) / 2;
  }

  painter.drawText(xOffset, yOffset, textString, f);
}
