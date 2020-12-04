#include "button.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/font.h"
#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "media/sound.h"
#include "media/sounds.h"
#include "media/sounddata.h"

#include <QDir>

Button::Button(QWidget * parentWidget)
  : QPushButton(parentWidget)
  , mEnableClickSound(true)
  , mEnableBorder(false)
  , mEnableFocusBorder(false)
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
}

void Button::enterEvent(QEvent * e)
{
  QPushButton::enterEvent(e);
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
  QPushButton::leaveEvent(e);
  update();
}

void Button::paintEvent(QPaintEvent * event)
{
  if (!icon().isNull()) {
    QPushButton::paintEvent(event);
  }

  Painter painter(this);
  drawBackground(painter);

  if (mEnableBorder) {
    bool hover = isHover() && mEnableFocusBorder;
    painter.drawBorder(0, 0, width(), height(), hover);
  }

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

QImage Button::disabledImage() const
{
  return mDisabledImage;
}

bool Button::enableBorder() const
{
  return mEnableBorder;
}

bool Button::enableClickSound() const
{
  return mEnableClickSound;
}

bool Button::enableFocusBorder() const
{
  return mEnableFocusBorder;
}

QImage Button::hoverImage() const
{
  return mHoverImage;
}

QImage Button::image() const
{
  return mImage;
}

QImage Button::pressedImage() const
{
  return mPressedImage;
}

void Button::setDisabledImage(const QImage & image)
{
  mDisabledImage = image;
}

void Button::setEnableBorder(bool value)
{
  mEnableBorder = value;
}

void Button::setEnableClickSound(bool value)
{
  mEnableClickSound = value;
}

void Button::setEnableFocusBorder(bool value)
{
  mEnableFocusBorder = value;
}

void Button::setHoverImage(const QImage & image)
{
  mHoverImage = image;
}

void Button::setImage(const QImage & image)
{
  mImage = image;
}

void Button::setPressedImage(const QImage & image)
{
  mPressedImage = image;
}
