#include "font.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"

#include <QDebug>
#include <QPainter>

Font::Font()
{
  setType(Font::Type::NormalPlain);
}

Font::Font(Type type)
{
  setType(type);
}

int32_t Font::calculateLetterHeight(uint8_t c) const
{
  const Language * language = TiberiusApplication::language();
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t startImageId = imageData->getGroupBaseImageId(GROUP_FONT) + mImageOffset;
  uint32_t letterOffset = language->mapCharToId(c);
  const SgImageRecord * record = imageData->getImageRecord(startImageId+letterOffset);

  int32_t offset = record->imageHeight() + mLineHeight;
  if (offset < 0) {
    offset = 0;
  }
  if (c < 128 || c == 0xE7) {
      offset = 0;
  }
  return offset;
}

int32_t Font::calculateTextWidth(const std::string &text) const
{
  const Language * language = TiberiusApplication::language();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  int32_t totalWidth = 0;
  uint32_t startImageId = imageData->getGroupBaseImageId(GROUP_FONT) + mImageOffset;
  for (std::size_t i = 0; i < text.size(); i++) {
    char c = text.at(i);
    if (c == ' ' ) {
      totalWidth += mSpaceWidth;
    }
    else {
      uint32_t letterOffset = language->mapCharToId(c);
      const SgImageRecord * record = imageData->getImageRecord(startImageId+letterOffset-1);
      totalWidth += record->imageWidth() + letterSpacing();
    }
  }
  return totalWidth;
}

int32_t Font::calculateTextWidth(const QString &text) const
{
  return calculateTextWidth(text.toStdString());
}

void Font::setType(Type type)
{
  mType = type;
  switch (type)
  {
    case Font::Type::NormalPlain:
      mImageOffset = 0;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 1;
      mLineHeight = 11;
      break;
    case Font::Type::NormalBlack:
      mImageOffset = 134;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 0;
      mLineHeight = 11;
      break;
    case Font::Type::NormalWhite:
      mImageOffset = 268;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 0;
      mLineHeight = 11;
      break;
    case Font::Type::NormalRed:
      mImageOffset = 402;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 0;
      mLineHeight = 11;
      break;
    case Font::Type::NormalGreen:
      mImageOffset = 1072;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 0;
      mLineHeight = 11;
      break;
    case Font::Type::LargePlain:
      mImageOffset = 536;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 10;
      mLetterSpacing = 1;
      mLineHeight = 23;
      break;
    case Font::Type::LargeBlack:
      mImageOffset = 670;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 10;
      mLetterSpacing = 1;
      mLineHeight = 23;
      break;
    case Font::Type::LargeBrown:
      mImageOffset = 804;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 10;
      mLetterSpacing = 1;
      mLineHeight = 24;
      break;
    case Font::Type::SmallPlain:
      mImageOffset = 938;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 4;
      mLetterSpacing = 1;
      mLineHeight = 9;
      break;
    case Font::Type::SmallBlack:
      mImageOffset = 1206;
      mMultibyteImageOffset = 0;
      mSpaceWidth = 6;
      mLetterSpacing = 0;
      mLineHeight = 11;
      break;
  }
}
