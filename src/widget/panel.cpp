#include "panel.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"

Panel::Panel(QWidget *parent)
  : QWidget(parent)
{

}

void Panel::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  painter.drawPanel(0, 0, width(), height(), 16, 12, GROUP_DIALOG_BACKGROUND);
}
