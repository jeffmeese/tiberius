#include "button.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/font.h"

#include "media/sound.h"
#include "media/sounds.h"
#include "media/sounddata.h"

#include <QDir>

Button::Button(QWidget * parentWidget)
  : QAbstractButton(parentWidget)
  , mEnableClickSound(true)
{
  connect(this, SIGNAL(pressed()), SLOT(playClickSound()));
}

void Button::drawBackground(Painter &painter)
{
  if (!isEnabled()) {
    if (!mDisabledImage.isNull()) {
      painter.drawImage(0, 0, mDisabledImage);
    }
    else {
      painter.drawImage(0, 0, mImage);
    }
    return;
  }

  if ((isDown() || isChecked()) && !mPressedImage.isNull())
    painter.drawImage(0, 0, mPressedImage);
  else if (!mHoverImage.isNull() && isHover())
    painter.drawImage(0, 0, mHoverImage);
  else
    painter.drawImage(0, 0, mImage);
}

void Button::drawText(Painter &painter)
{
  if (text().isEmpty())
    return;

  QString textString = text();
  Font f = textFont();
  int32_t w = width();
  int32_t h = height();
  int32_t textWidth = f.calculateTextWidth(textString);
  int32_t textHeight = f.lineHeight();

  int32_t xOffset = (w - textWidth) / 2;
  int32_t yOffset = (h - textHeight) / 2;
  painter.drawText(xOffset, yOffset, textString, f);
  //paintText(xOffset, yOffset, textString, painter);
}

void Button::enterEvent(QEvent * e)
{
  QAbstractButton::enterEvent(e);
  update();
}

bool Button::isHover() const
{
  bool hover = false;
  QPoint pos = mapFromGlobal(QCursor::pos());
  QRect r(this->rect());
  if (r.contains(pos)) {
    hover = true;
  }

  return hover;
}

void Button::leaveEvent(QEvent * e)
{
  QAbstractButton::leaveEvent(e);
  update();
}

void Button::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawBackground(painter);
  drawText(painter);
}

void Button::playClickSound()
{
  if (mEnableClickSound) {
    SoundData * soundData = TiberiusApplication::soundData();
    Sound * sound = soundData->findSound(SOUND_ICON1);
    if (sound != nullptr)
        sound->play();
  }
}
