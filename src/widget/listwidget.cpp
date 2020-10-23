#include "listwidget.h"
#include "scrollbar.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QDebug>
#include <QImage>
#include <QMouseEvent>
#include <QPainter>
#include <QScrollBar>

static const int32_t MARGIN_LEFT = 15;
static const int32_t MARGIN_TOP = 6;
static const int32_t MARGIN_BOTTOM = 6;
static const int32_t ITEM_MARGIN_TOP = 2;
static const int32_t ITEM_MARGIN_BOTTOM = 2;
static const int32_t TEXT_HEIGHT = 11;
static const int32_t ITEM_HEIGHT = ITEM_MARGIN_TOP + TEXT_HEIGHT + ITEM_MARGIN_BOTTOM;

ListWidget::ListWidget(QWidget * parentWidget)
  : QListWidget(parentWidget)
  , mActiveItem(nullptr)
  , mFirstVisibleItem(0)
{
  setAutoFillBackground(false);

  Font standardFont(Font::Type::NormalGreen);
  setTextFont(standardFont);

  verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
}

void ListWidget::drawBackground(Painter & painter)
{
  int32_t xBlocks = width() / 16;
  int32_t yBlocks = height() / 16;
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_SUNKEN_TEXTBOX_BACKGROUND);

  int32_t yImgIncr = 0;
  int32_t yImgAdd = 0;
  uint32_t imageIdOffset;
  for (int32_t y = 0; y < yBlocks; y++) {
    int32_t xImgIncr = 0;
    for (int32_t x = 0; x < xBlocks; x++) {
      if (y == 0) {
        if (x == 0) {
          imageIdOffset = 0;
        }
        else if (x == xBlocks-1) {
          imageIdOffset = 6;
        }
        else {
          imageIdOffset = 1 + xImgIncr++;
        }
        yImgAdd = 0;
      }
      else if (y == yBlocks-1) {
        if (x == 0) {
          imageIdOffset = 42;
        }
        else if (x == xBlocks-1) {
          imageIdOffset = 48;
        }
        else {
          imageIdOffset = 43 + xImgIncr++;
        }
        yImgAdd = 0;
      }
      else {
        if (x == 0) {
          imageIdOffset = 7 + yImgIncr;
        }
        else if (x == xBlocks-1) {
          imageIdOffset = 13 + yImgIncr;
        }
        else {
          imageIdOffset = 8 + yImgIncr + xImgIncr++;
        }
        yImgAdd = 7;
      }

      // draw
      const SgImageRecord * imageRecord = imageData->getImageRecord(baseImageId + imageIdOffset);
      painter.drawImage(16*x, 16*y, imageRecord->createImage());

      if (xImgIncr >= 5) {
        xImgIncr = 0;
      }
    }
    yImgIncr += yImgAdd;
    if (yImgIncr >= 35) {
      yImgIncr = 0;
    }
  }
}

void ListWidget::drawText(Painter &painter)
{
  Font standardFont(Font::Type::NormalGreen);
  Font focusFont(Font::Type::NormalWhite);

  int32_t itemsVisible = (height() - MARGIN_TOP - MARGIN_BOTTOM) / ITEM_HEIGHT;
  int32_t lastItem = mFirstVisibleItem + itemsVisible;
  if  (lastItem >= count())
    lastItem = count();

  int32_t yOffset = MARGIN_TOP;
  for (int32_t i = mFirstVisibleItem; i < lastItem; i++) {
    QListWidgetItem * listItem = item(i);
    QString itemText = listItem->text();
    setTextFont(standardFont);
    if (listItem == mActiveItem)
      setTextFont(focusFont);

    painter.drawText(MARGIN_LEFT, yOffset, itemText, textFont());
    yOffset += ITEM_HEIGHT;
  }
}

int ListWidget::firstVisibleItem() const
{
  return mFirstVisibleItem;
}

QListWidgetItem * ListWidget::itemAt(const QPoint &pt)
{
  int32_t itemsVisible = (height() - MARGIN_TOP - MARGIN_BOTTOM) / ITEM_HEIGHT;
  int32_t lastItem = mFirstVisibleItem + itemsVisible;
  if  (lastItem >= count())
    lastItem = count();

  QListWidgetItem * item = nullptr;
  int32_t yOffset = MARGIN_TOP;
  for (int32_t i = mFirstVisibleItem; i < lastItem; i++) {
    QListWidgetItem * listItem = this->item(i);
    QRect rect(0, yOffset, width(), ITEM_HEIGHT);
    if (rect.contains(pt)) {
      item = listItem;
    }
    yOffset += ITEM_HEIGHT;
  }
  return item;
}

void ListWidget::mousePressEvent(QMouseEvent * event)
{
  QPoint pos(event->pos());
  QListWidgetItem * item = itemAt(pos);
  if (item != nullptr) {
    emit currentItemChanged(item, nullptr);
  }
}

void ListWidget::mouseMoveEvent(QMouseEvent * event)
{
  QPoint pos = event->pos();
  if (mActiveItem != nullptr) {

  }
  mActiveItem = itemAt(pos);
  viewport()->update();
}

void ListWidget::paintEvent(QPaintEvent * )
{
  Painter painter(this->viewport());
  drawBackground(painter);
  drawText(painter);
}

void ListWidget::setFirstVisibleItem(int item)
{
  mFirstVisibleItem = item;
}

int ListWidget::totalVisibleItems() const
{
  return (height() - MARGIN_TOP - MARGIN_BOTTOM) / ITEM_HEIGHT;
}
