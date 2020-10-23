#ifndef FONT_H
#define FONT_H

#include <QImage>
#include <QString>

#include "tiberius.h"

class Font
{
public:
  enum class Type {
    NormalPlain,
    NormalBlack,
    NormalWhite,
    NormalRed,
    NormalGreen,
    LargePlain,
    LargeBlack,
    LargeBrown,
    SmallPlain,
    SmallBlack
  };

public:
  TIBERIUS_LIB_DECL Font();
  TIBERIUS_LIB_DECL Font(Type type);

public:
  TIBERIUS_LIB_DECL int32_t letterSpacing() const;
  TIBERIUS_LIB_DECL int32_t lineHeight() const;
  TIBERIUS_LIB_DECL int32_t imageOffset() const;
  TIBERIUS_LIB_DECL int32_t multibyteImageOffset() const;
  TIBERIUS_LIB_DECL int32_t spaceWidth() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

public:
  TIBERIUS_LIB_DECL int32_t calculateLetterHeight(uint8_t c) const;
  TIBERIUS_LIB_DECL int32_t calculateTextWidth(const std::string & text) const;
  TIBERIUS_LIB_DECL int32_t calculateTextWidth(const QString & text) const;

private:
  int32_t mLetterSpacing;
  int32_t mLineHeight;
  int32_t mImageOffset;
  int32_t mMultibyteImageOffset;
  int32_t mSpaceWidth;
  Type mType;
};

inline int32_t Font::letterSpacing() const
{
  return mLetterSpacing;
}

inline int32_t Font::lineHeight() const
{
  return mLineHeight;
}

inline int32_t Font::imageOffset() const
{
  return mImageOffset;
}

inline int32_t Font::multibyteImageOffset() const
{
  return mMultibyteImageOffset;
}

inline int32_t Font::spaceWidth() const
{
  return mSpaceWidth;
}

inline Font::Type Font::type() const
{
  return mType;
}

#endif // FONT_H
