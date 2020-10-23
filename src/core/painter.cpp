#include "painter.h"

#include "application/tiberiusapplication.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

Painter::Painter(QPaintDevice * device)
  : QPainter(device)
{

}

void Painter::drawText(int x, int y, const QString & text, const Font & font)
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
}
