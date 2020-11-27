#include "menubar.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QDebug>
#include <QMouseEvent>
#include <QPainter>

static const int32_t MARGIN_LEFT = 6;
static const int32_t MARGIN_TOP = 6;
static const int32_t ITEM_PADDING_LEFT = 5;

MenuBar::MenuBar(QWidget * parentWidget)
  : QMenuBar(parentWidget)
  , mActiveMenu(nullptr)
{
  setMouseTracking(true);
}

void MenuBar::handleAboutToHide()
{
  QPoint cursorPos = QCursor::pos();
  QPoint pos = mapFromGlobal(cursorPos);
  if (!rect().contains(pos))
    mActiveMenu = nullptr;
}

void MenuBar::drawBackground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageOffset = imageData->getGroupBaseImageId(GROUP_TOP_MENU_SIDEBAR);

  // Determine the number of standard blocks we need to draw (excluding the last block)
  int32_t w = width();
  int32_t xBlocks = w / 24;
  int32_t widthCovered = xBlocks * 24;
  int32_t diff = w - widthCovered;
  while (diff > 16) {
    xBlocks--;
    widthCovered = xBlocks * 24;
    diff -= 24;
    if (diff <= 0) {
      diff = 0;
      break;
    }
  }

  // Calculate the image ID for the last block based on the width remaining
  diff = w - widthCovered;
  uint32_t lastImageId = baseImageOffset + 11;
  if (diff > 16 && diff <= 32) {
    lastImageId = baseImageOffset + 10;
  }
  else if (diff > 32) {
    lastImageId = baseImageOffset + 11;
  }

  // Draw all blocks except the final one
  int32_t imgOffset = 0;
  for (int32_t x = 0; x < xBlocks; x++) {
    uint32_t imageId = baseImageOffset + imgOffset++;
    const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
    painter.drawImage(24*x, 0, imageRecord->createImage());
    if (imgOffset >= 9) {
      imgOffset = 0;
    }
  }

  // Draw the last block
  const SgImageRecord * imageRecord = imageData->getImageRecord(lastImageId);
  painter.drawImage(24*xBlocks, 0, imageRecord->createImage());
}

void MenuBar::drawMenus(Painter & painter)
{
  Font f(Font::Type::NormalBlack);

  int32_t xOffset = MARGIN_LEFT;
  int32_t yOffset = MARGIN_TOP;
  for (int32_t i = 0; i < actions().size(); i++) {
    QAction * action = actions().at(i);
    QString text = action->text();
    int32_t textWidth = f.calculateTextWidth(text);
    painter.drawText(xOffset+ITEM_PADDING_LEFT, yOffset, text, f);
    xOffset += textWidth + 2*MARGIN_LEFT;
  }
}

bool MenuBar::eventFilter(QObject *, QEvent *event)
{
  if (event->type() == QEvent::MouseMove) {
    QPoint mousePos = mapFromGlobal(QCursor::pos());
    QRect menuRect;
    QMenu * menu = menuAt(mousePos, menuRect);
    if (menu != nullptr && menu != mActiveMenu) {
      if (mActiveMenu != nullptr) {
        disconnect(mActiveMenu, 0, 0, 0);
        mActiveMenu->removeEventFilter(this);
        mActiveMenu->close();
        mActiveMenu = nullptr;
      }

      connect(menu, SIGNAL(aboutToHide()), SLOT(handleAboutToHide()));
      menu->installEventFilter(this);
      menu->popup(mapToGlobal(menuRect.bottomLeft()));
      mActiveMenu = menu;
    }
  }
  return false;
}

QMenu * MenuBar::menuAt(const QPoint &pos, QRect & menuRect)
{
  QRect rect(this->rect());
  Font f(Font::Type::NormalBlack);
  int32_t xMin = MARGIN_LEFT;
  for (int32_t i = 0; i < actions().size(); i++) {
    QAction * action = actions().at(i);
    QString text = action->text();
    int32_t textWidth = f.calculateTextWidth(text);
    int32_t xMax = xMin + textWidth;
    QRect itemRect(xMin, rect.top(), xMax-xMin, rect.height());
    if (itemRect.contains(pos)) {
      menuRect = itemRect;
      return action->menu();
    }
    xMin += textWidth + 2*MARGIN_LEFT;
  }

  return nullptr;
}

void MenuBar::mousePressEvent(QMouseEvent * event)
{
  QPoint mousePos = event->pos();
  QRect menuRect;
  QMenu * menu = menuAt(mousePos, menuRect);
  if (mActiveMenu != nullptr) {
    disconnect(mActiveMenu, 0, 0, 0);
    mActiveMenu->removeEventFilter(this);
    bool sameMenu = (menu == mActiveMenu);
    mActiveMenu = nullptr;
    if (sameMenu)
      return;
  }

  if (menu != nullptr) {
    connect(menu, SIGNAL(aboutToHide()), SLOT(handleAboutToHide()));
    menu->installEventFilter(this);
    menu->popup(mapToGlobal(menuRect.bottomLeft()));
    mActiveMenu = menu;
  }
}

void MenuBar::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawBackground(painter);
  drawMenus(painter);
}

