#ifndef PAINTER_H
#define PAINTER_H

#include "tiberius.h"

#include <QPainter>

class Font;

class Painter
    : public QPainter
{
public:
  TIBERIUS_LIB_DECL Painter(QPaintDevice * device);

public:
  TIBERIUS_LIB_DECL void drawText(int x, int y, const QString & text, const Font & font);
};

#endif // PAINTER_H
