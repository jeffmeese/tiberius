#ifndef TIBERIUSWIDGET_H
#define TIBERIUSWIDGET_H

#include "tiberius.h"

#include "graphics/font.h"

class TiberiusWidget
{
public:
  TIBERIUS_LIB_DECL TiberiusWidget();

public:
  TIBERIUS_LIB_DECL const Font & textFont() const;
  TIBERIUS_LIB_DECL void setTextFont(const Font & font);

private:
  Font mFont;
};

inline const Font & TiberiusWidget::textFont() const
{
  return mFont;
}

inline void TiberiusWidget::setTextFont(const Font &font)
{
  mFont = font;
}

#endif // TIBERIUSWIDGET_H
