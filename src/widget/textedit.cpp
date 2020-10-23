#include "textedit.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include <QDebug>
#include <QImage>
#include <QKeyEvent>
#include <QPainter>

TextEdit::TextEdit(QWidget * parentWidget)
  : ScrollWidget(parentWidget)
{
  std::unique_ptr<Viewport> viewport(new Viewport(this));
  mViewport = viewport.get();
  setViewport(std::move(viewport));
}

void TextEdit::insertImage(const QImage &image)
{
  mViewport->mImages.push_back(image);
  mViewport->mText.push_back(QChar::ObjectReplacementCharacter);
}

void TextEdit::insertText(const QString &text)
{
  for (int i = 0; i < text.size(); i++) {
    mViewport->mText.push_back(text.at(i));
  }
}

TextEdit::Viewport::Viewport(QWidget * parent)
  : QWidget(parent)
{
  setTextFont(Font::Type::NormalWhite);
}

void TextEdit::Viewport::paintEvent(QPaintEvent *)
{
  Painter painter(this);

  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_SUNKEN_TEXTBOX_BACKGROUND);

  int32_t w = width();
  int32_t h = height();
  StitchedImage image(16, 16, 7, 7, baseImageId);
  painter.drawImage(0, 0, image.constructImage(w, h));

  Font f = textFont();
  int xOffset = 0;
  int yOffset = 10;
  for (std::size_t i = 0; i < mText.size(); i++) {
    QChar c = mText.at(i);
    painter.drawText(xOffset, yOffset, c, f);
    xOffset += f.calculateTextWidth(c);
  }
}

