#include "dialog.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"

Dialog::Dialog(QWidget * parentWidget)
  : QDialog(parentWidget)
{
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

void Dialog::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  painter.drawPanel(0, 0, width(), height(), 16, 12, GROUP_DIALOG_BACKGROUND);
}

