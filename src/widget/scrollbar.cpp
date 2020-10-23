#include "scrollbar.h"
#include "button.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

static const int SLIDER_MARGIN = 2;
static const int SLIDER_LEFT_MARGIN = 7;

ScrollBar::ScrollBar(QWidget * parentWidget)
  : QWidget(parentWidget)
{
  mValue = 0;
  mMinumum = 0;
  mMaximum = 100;
  mStepSize = 5;
  mSliderHeight = 25;
  mButtonWidth = 39;
  mButtonHeight = 26;
  mSliderPressed = false;

  setMouseTracking(true);
  setAutoFillBackground(false);
  mScrollUpButton.reset(new Button(this));
  mScrollDownButton.reset(new Button(this));

  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_OK_CANCEL_SCROLL_BUTTONS);

  mScrollUpButton->setImage(imageData->getImageRecord(baseImageId+8)->createImage());
  mScrollUpButton->setPressedImage(imageData->getImageRecord(baseImageId+10)->createImage());
  mScrollUpButton->setHoverImage(imageData->getImageRecord(baseImageId+9)->createImage());
  mScrollDownButton->setImage(imageData->getImageRecord(baseImageId+12)->createImage());
  mScrollDownButton->setPressedImage(imageData->getImageRecord(baseImageId+14)->createImage());
  mScrollDownButton->setHoverImage(imageData->getImageRecord(baseImageId+13)->createImage());

  mScrollUpButton->resize(mButtonWidth, mButtonHeight);
  mScrollDownButton->resize(mButtonWidth, mButtonHeight);

  connect(mScrollUpButton.get(), SIGNAL(clicked()), SLOT(scrollUp()));
  connect(mScrollDownButton.get(), SIGNAL(clicked()), SLOT(scrollDown()));

  updateSliderPosition();
}

int ScrollBar::calculateValueFromPosition(const QPoint &pos)
{
  QRect rect(this->rect());
  int scrollHeight = rect.height() - (2*mButtonHeight + mSliderHeight + 2*SLIDER_MARGIN);
  int numSteps = (mMaximum - mMinumum) / mStepSize;
  float pixelsPerValue = static_cast<float>(scrollHeight) / numSteps;
  int yPos = rect.top() + mButtonHeight;
  int value = mMinumum + static_cast<int>((pos.y()-yPos) / pixelsPerValue);
  if (value < mMinumum) {
    value = mMinumum;
  }
  if (value > mMaximum) {
    value = mMaximum;
  }

  return value;
}

void ScrollBar::mouseMoveEvent(QMouseEvent *event)
{
  QPoint pos = event->pos();
  if (mSliderPressed) {
    int value = calculateValueFromPosition(pos);
    if (value != mValue) {
      setValue(value);
      emit valueChanged(value);
    }
  }
  QWidget::mousePressEvent(event);
}

void ScrollBar::mousePressEvent(QMouseEvent *event)
{
  QPoint pos = event->pos();

  if (mSliderRect.contains(pos)) {
    mSliderPressed = true;
    emit sliderPressed();
    return;
  }
  else {
    int value = calculateValueFromPosition(pos);
    setValue(value);
    emit valueChanged(value);
  }
  QWidget::mousePressEvent(event);
}

void ScrollBar::mouseReleaseEvent(QMouseEvent * event)
{
  if (mSliderPressed) {
    mSliderPressed = false;
    emit sliderReleased();
  }

  QWidget::mouseReleaseEvent(event);
}

void ScrollBar::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  const SgImageData * imageData = TiberiusApplication::climateImages();
  int baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);
  int xPos = mSliderRect.left() + SLIDER_LEFT_MARGIN;
  int yPos = mSliderRect.top();
  painter.drawImage(xPos, yPos, imageData->getImageRecord(baseImageId+39)->createImage());
}

void ScrollBar::resizeEvent(QResizeEvent *)
{
  QRect rect(this->rect());

  mScrollUpButton->move(rect.left(), rect.top());
  mScrollDownButton->move(rect.left(), rect.bottom()-mButtonHeight);
}

void ScrollBar::scrollDown()
{
  if (mValue < mMaximum) {
    mValue += mStepSize;
    updateSliderPosition();
    emit valueChanged(mValue);
    update();
  }
}

void ScrollBar::scrollUp()
{
  if (mValue > mMinumum) {
    mValue -= mStepSize;
    updateSliderPosition();
    emit valueChanged(mValue);
    update();
  }
}

void ScrollBar::setMaximum(int value)
{
  mMaximum = value;
  update();
}

void ScrollBar::setMinimum(int value)
{
  mMinumum = value;
  update();
}

void ScrollBar::setRange(int minValue, int maxValue)
{
  mMinumum = minValue;
  mMaximum = maxValue;
  update();
}

void ScrollBar::setStepSize(int value)
{
  mStepSize = value;
  update();
}

void ScrollBar::setValue(int value)
{
  mValue = value;
  updateSliderPosition();
  update();
}

void ScrollBar::updateSliderPosition()
{
  QRect rect(this->rect());
  int scrollHeight = rect.height() - (2*mButtonHeight + mSliderHeight + 2*SLIDER_MARGIN);
  float pixelsPerScroll = static_cast<float>(scrollHeight) / (mMaximum - mMinumum);
  int pixelOffset = static_cast<int>(mValue * pixelsPerScroll);
  int yPos = rect.top() + mScrollUpButton->height() + pixelOffset + SLIDER_MARGIN;
  int xPos = rect.left();
  mSliderRect.setRect(xPos, yPos, mSliderHeight + 2*SLIDER_LEFT_MARGIN, mSliderHeight);
}
