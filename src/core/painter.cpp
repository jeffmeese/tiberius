#include "painter.h"

#include "application/tiberiusapplication.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "language/language.h"
#include "language/stringdata.h"

Painter::Painter(QPaintDevice * device)
  : QPainter(device)
{
}

void Painter::drawBorder(int32_t x, int32_t y, int32_t width, int32_t height, bool focused)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_BORDERED_BUTTON);
  if (focused)
    baseImageId += 8;

  int32_t w = width;
  int32_t widthBlocks = w / 16;
  if (widthBlocks % 16)
    widthBlocks++;

  int32_t h = height;
  int32_t heightBlocks = h / 16;
  if (heightBlocks % 16)
    heightBlocks++;

  int last_block_offset_x = 16 * widthBlocks - w;
  int last_block_offset_y = 16 * heightBlocks - h;

  for (int32_t yy = 0; yy < heightBlocks; yy++) {
    for (int32_t xx = 0; xx < widthBlocks; xx++) {
      int32_t imageOffset = 0;
      int32_t xOffset = x + 16*xx;
      int32_t yOffset = y + 16*yy;

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
      drawImage(xOffset, yOffset, imageRecord->createImage());
    }
  }
}

void Painter::drawPanel(int32_t x, int32_t y, int32_t w, int32_t h, int32_t nX, int32_t nY, int32_t baseId)
{
  SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageIndex = imageData->getGroupBaseImageId(baseId);

  StitchedImage stitchedImage(nX, nX, nY, nY, baseImageIndex);
  drawImage(x, y, stitchedImage.constructImage(w, h));
}

int32_t Painter::drawText(int32_t x, int32_t y, const QString & text, const Font & font)
{
  const Language * language = TiberiusApplication::language();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  std::string s = text.toStdString();
  int32_t xOffset = x;
  uint32_t startImageId = imageData->getGroupBaseImageId(GROUP_FONT) + font.imageOffset();
  for (int32_t i = 0; i < text.size(); i++) {
    char c = s.at(i);
    if (c == ' ' ) {
      xOffset += font.spaceWidth();
    }
    else {
      uint32_t letterOffset = language->mapCharToId(c);
      const SgImageRecord * record = imageData->getImageRecord(startImageId+letterOffset-1);
      drawImage(xOffset, y, record->createImage());
      xOffset += record->imageWidth() + font.letterSpacing();
    }
  }
  return xOffset;
}
