#include "borderedbutton.h"

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

#include <QDebug>

BorderedButton::BorderedButton(QWidget * parentWidget)
  : QAbstractButton(parentWidget)
  , mHover(false)
{
}

void BorderedButton::drawBackground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_BORDERED_BUTTON);
  if (mHover)
    baseImageId += 8;

  int32_t w = width();
  int32_t widthBlocks = w / 16;
  if (widthBlocks % 16)
    widthBlocks++;

  int32_t h = height();
  int32_t heightBlocks = h / 16;
  if (heightBlocks % 16)
    heightBlocks++;

  int last_block_offset_x = 16 * widthBlocks - w;
  int last_block_offset_y = 16 * heightBlocks - h;

  for (int32_t yy = 0; yy < heightBlocks; yy++) {
    for (int32_t xx = 0; xx < widthBlocks; xx++) {
      int32_t imageOffset = 0;
      int32_t xOffset = 16*xx;
      int32_t yOffset = 16*yy;

      if (yy == 0) {
        if (xx == 0) {

        }
        else if (xx < widthBlocks-1) {
          imageOffset += 1;
        }
        else {
          imageOffset += 2;
          xOffset -= last_block_offset_x;
        }
      }
      else if (yy < heightBlocks-1) {
        if (xx == 0) {
          imageOffset += 7;
        }
        else if (xx >= widthBlocks-1) {
          imageOffset += 3;
          xOffset -= last_block_offset_x;
        }
        else {
          continue;
        }
      }
      else {
        if (xx == 0) {
          imageOffset += 6;
          yOffset -= last_block_offset_y;
        }
        else if (xx < widthBlocks-1) {
          imageOffset += 5;
          yOffset -= last_block_offset_y;
        }
        else {
          imageOffset += 4;
          xOffset -= last_block_offset_x;
          yOffset -= last_block_offset_y;
        }
      }

      const SgImageRecord * imageRecord = imageData->getImageRecord(baseImageId + imageOffset);
      painter.drawImage(xOffset, yOffset, imageRecord->createImage());
    }
  }
}

void BorderedButton::drawText(Painter &painter)
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

void BorderedButton::enterEvent(QEvent * e)
{
  QAbstractButton::enterEvent(e);
  mHover = true;
  update();
}

void BorderedButton::leaveEvent(QEvent * e)
{
  QAbstractButton::leaveEvent(e);
  mHover = false;
  update();
}

void BorderedButton::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawBackground(painter);
  drawText(painter);
}

