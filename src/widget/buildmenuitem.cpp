#include "buildmenuitem.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "language/language.h"
#include "language/stringdata.h"

BuildMenuItem::BuildMenuItem(QWidget * parentWidget)
  : Button(parentWidget)
  , mPrice(-1)
{
}

void BuildMenuItem::paintEvent(QPaintEvent *)
{
  static const int32_t RIGHT_MARGIN = 10;

  const StringData * stringData = TiberiusApplication::language()->stringData();
  Font f = textFont();
  QString textLabel(text());

  Painter painter(this);
  drawBackground(painter);

  QString dnText = stringData->getString(6, 0);
  QString placeHolderText = QString::number(1000) + " " + dnText;
  int32_t priceTextWidth = f.calculateTextWidth(placeHolderText) + RIGHT_MARGIN;
  int32_t labelWidth = width() - priceTextWidth;
  int32_t xOffset = (labelWidth - f.calculateTextWidth(textLabel)) / 2;
  painter.drawText(xOffset, 4, textLabel, f);

  if (mPrice > 0) {
    QString priceText = QString::number(mPrice) + " " + dnText;
    painter.drawText(labelWidth, 4, priceText, f);
  }
}
