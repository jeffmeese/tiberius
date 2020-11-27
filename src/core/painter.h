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
  TIBERIUS_LIB_DECL int32_t drawText(int32_t x, int32_t y, const QString & text, const Font & font);
};

#endif // PAINTER_H
