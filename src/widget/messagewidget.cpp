#include "messagewidget.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "language/language.h"
#include "language/message.h"

#include "widget/scrollbar.h"

#include <QDebug>
#include <QPainter>
#include <QScrollBar>

MessageWidget::MessageWidget(QWidget * parent)
  : QWidget(parent)
  , mMessage(nullptr)
  , mLineHeight(20)
  , mMarginLeft(10)
  , mMarginRight(40)
  , mMarginTop(10)
{
}

void MessageWidget::drawBackground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_SUNKEN_TEXTBOX_BACKGROUND);

  int32_t w = width();
  int32_t h = height();
  StitchedImage image(16, 16, 7, 7, baseImageId);
  painter.drawImage(0, 0, image.constructImage(w, h));
}

void MessageWidget::drawForeground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_MESSAGE_IMAGES) - 1;
  if (mMessage == nullptr) {
    return;
  }

  Font f = this->textFont();
  int w = width();
  int h = height();

  int x = mMarginLeft;
  int y = mMarginTop;
  QString content = mMessage->content();
  content = content.replace(".", ". ");
  QStringList wordList = content.split(' ');
  for (int i = 0; i < wordList.size(); i++) {
    QString word = wordList.at(i);
    //if (word.trimmed().isEmpty())
    //  continue;

    int graphicIndex = word.indexOf('G');
    int newlineIndex = word.indexOf('\n');
    if (newlineIndex >= 0) {
      for (int j = 0; j < word.size(); j++) {
        QChar c = word.at(j);
        if (c == '\n') {
          x = mMarginLeft;
          y += mLineHeight;
        }
      }
    }
    else if (graphicIndex >= 0 && word.at(graphicIndex+1).isNumber()) {
      x = mMarginLeft;
      y += mLineHeight;

      QString numString = word.mid(1);
      int imageOffset = numString.toInt();
      int imageId = imageOffset + baseImageId;
      const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
      int imageWidth = imageRecord->imageWidth();
      int xOffset = (width()-imageWidth) / 2;
      painter.drawImage(xOffset, y, imageRecord->createImage());
      y += imageRecord->imageHeight() + mLineHeight;
    }
    else {
      int textWidth = f.calculateTextWidth(word) + f.spaceWidth();
      if (textWidth + x > (w - mMarginRight) ) {
        x = mMarginLeft;
        y += mLineHeight;
      }
      painter.drawText(x, y, word, textFont());
      x += textWidth;
    }
  }
}

void MessageWidget::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawBackground(painter);
  drawForeground(painter);
}

void MessageWidget::resizeEvent(QResizeEvent *event)
{

}

void MessageWidget::setMessage(const Message *message)
{
  mMessage = message;
}
