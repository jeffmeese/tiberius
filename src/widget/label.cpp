#include "label.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

Label::Label(QWidget * parentWidget)
  : QLabel(parentWidget)
  , mEnableHover(false)
  , mHoverFont(Font::Type::NormalRed)
{
}

void Label::drawMultilineText(Painter & painter)
{
  qDebug() << QObject::tr(__FUNCTION__);

  Font f = textFont();
  QString text = this->text();
  int32_t lineHeight = f.lineHeight();

  int32_t xOffset = 0;
  int32_t yOffset = 0;
  int32_t w = width();
  int32_t currentWidth = 0;
  int32_t totalHeight = lineHeight + 5;
  QStringList stringList = text.split(' ');
  for (int i = 0; i < stringList.size(); i++) {
    QString word = stringList.at(i);
    int wordWidth = f.calculateTextWidth(word);
    if (currentWidth + wordWidth < w) {
      painter.drawText(xOffset, yOffset, word, f);
      xOffset += wordWidth + f.spaceWidth();
      currentWidth += wordWidth + f.spaceWidth();
    }
    else {
      yOffset += lineHeight + 5;
      totalHeight += lineHeight + 5;
      currentWidth = 0;
      xOffset = 0;
      painter.drawText(xOffset, yOffset, word, f);
      xOffset += wordWidth + f.spaceWidth();
      currentWidth += wordWidth + f.spaceWidth();
    }
  }

  resize(w, totalHeight);
}

void Label::drawText(Painter & painter)
{
  QString textString = text();

  int32_t w = width();
  int32_t h = height();

  const Font & f = textFont();
  int32_t textWidth = f.calculateTextWidth(textString);
  int32_t textHeight = f.lineHeight();

  if (textWidth > w) {
    drawMultilineText(painter);
    return;
  }

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

bool Label::enableHover() const
{
  return mEnableHover;
}

Font Label::hoverFont() const
{
  return mHoverFont;
}

void Label::enterEvent(QEvent * event)
{
  if (mEnableHover) {
    mOldFont = textFont();
    setTextFont(mHoverFont);
  }

  QWidget::enterEvent(event);
}

void Label::leaveEvent(QEvent * event)
{
  if (mEnableHover)
    setTextFont(mOldFont);

  QWidget::leaveEvent(event);
}

void Label::mouseReleaseEvent(QMouseEvent * event)
{
  if (event->button() == Qt::LeftButton) {
    emit clicked();
  }
  QLabel::mouseReleaseEvent(event);
}

void Label::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawText(painter);
}

void Label::setEnableHover(bool enable)
{
  mEnableHover = enable;
  this->setAttribute(Qt::WA_Hover, enable);
}

void Label::setHoverFont(Font font)
{
  mHoverFont = font;
}
