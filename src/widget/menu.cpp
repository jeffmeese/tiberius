#include "menu.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagedata.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QDebug>
#include <QImage>
#include <QMouseEvent>
#include <QPainter>

#include <cmath>

static const int32_t MARGIN_TOP = 8;
static const int32_t MARGIN_LEFT = 6;
static const int32_t TEXT_HEIGHT = 16;

Menu::Menu(QWidget * parentWidget)
  : QMenu(parentWidget)
{
  init();
}

Menu::Menu(const QString & title, QWidget * parentWidget)
  : QMenu(parentWidget)
{
  init(title);
}

// Adjusts the dimensions of the menu since we are
// using a different font than Qt is using for the menu items
void Menu::computeAdjustedDimensions()
{
  QList<QAction*> actionList = actions();
  int32_t maxWidth = -1;
  for (int32_t i = 0; i < actionList.size(); i++) {
    QAction * action = actionList.at(i);
    QString text = action->text();
    int32_t textWidth = textFont().calculateTextWidth(text);
    if (textWidth > maxWidth) {
      maxWidth = textWidth;
    }
  }

  int32_t w = maxWidth + MARGIN_LEFT;
  int32_t h = MARGIN_TOP + actionList.size()*(TEXT_HEIGHT + MARGIN_TOP/2);

  int32_t xBlocks = w / 16;
  int32_t yBlocks = h / 16;
  if (w % 16 != 0) {
    xBlocks++;
  }
  if (h % 16 != 0) {
    yBlocks++;
  }

  mAdjustedWidth = xBlocks * 16;
  mAdjustedHeight = yBlocks * 16;

  resize(mAdjustedWidth, mAdjustedHeight);
}

void Menu::drawBackground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();

  int32_t xBlocks = mAdjustedWidth / 16;
  int32_t yBlocks = mAdjustedHeight / 16;

  int32_t imageId = 1218;
  for (int32_t y = 0; y < yBlocks; y++) {
    for (int32_t x = 0; x < xBlocks; x++) {
      const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
      painter.drawImage(x*16, y*16, imageRecord->createImage());
    }
  }
}

void Menu::drawMenuItems(Painter & painter)
{
  int32_t xOffset = rect().left() + MARGIN_LEFT;
  int32_t yOffset = MARGIN_TOP;
  QList<QAction*> actionList = actions();
  for (int32_t i = 0; i < actionList.size(); i++) {
    QAction * action = actionList.at(i);
    QString text = action->text();
    if (i == mFocusedItem) {
      QBrush brush(Qt::white);
      painter.fillRect(0, yOffset-MARGIN_TOP/2, mAdjustedWidth, TEXT_HEIGHT, brush);
      painter.drawText(xOffset, yOffset, text, textFont());
    }
    else {
      painter.drawText(xOffset, yOffset, text, textFont());
    }
    yOffset += TEXT_HEIGHT + MARGIN_TOP/2;
  }
}

void Menu::init(const QString &title)
{
  mAdjustedWidth = mAdjustedHeight = -1;
  setTitle(title);
}

void Menu::mouseMoveEvent(QMouseEvent *event)
{
  QPoint pos = event->pos();

  int32_t xMin = rect().left();
  int32_t xMax = rect().right();

  mFocusedItem = -1;
  int32_t yMin = 0;
  QList<QAction*> actionList = actions();
  for (int32_t i = 0; i < actionList.size(); i++) {
    int32_t yMax = yMin + TEXT_HEIGHT + MARGIN_TOP/2;
    if (pos.y() >= yMin && pos.y() <= yMax && pos.x() >= xMin && pos.x() <= xMax) {
      mFocusedItem = i;
      break;
    }
    yMin = yMax;
  }
  update();
}

void Menu::mouseReleaseEvent(QMouseEvent *event)
{
  QPoint pos = event->pos();

  mFocusedItem = -1;
  int32_t yMin = 0;
  QAction * selectedAction = nullptr;
  QList<QAction*> actionList = actions();
  for (int32_t i = 0; i < actionList.size(); i++) {
    QAction * action = actionList.at(i);
    int32_t yMax = yMin + TEXT_HEIGHT + MARGIN_TOP/2;
    if (pos.y() >= yMin && pos.y() <= yMax) {
      selectedAction = action;
      break;
    }
    yMin = yMax;
  }

  update();
  if (selectedAction != nullptr) {
    mFocusedItem = -1;
    hide();
    selectedAction->trigger();
  }
}

void Menu::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  computeAdjustedDimensions();
  drawBackground(painter);
  drawMenuItems(painter);
}
