#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QWidget>

class Painter;
class Message;
class ScrollBar;

class MessageWidget
    : public QWidget
    , public TiberiusWidget
{
public:
  TIBERIUS_LIB_DECL explicit MessageWidget(QWidget * parent = nullptr);

public:
  TIBERIUS_LIB_DECL void setMessage(const Message * message);

protected:
  void paintEvent(QPaintEvent *e) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  void drawBackground(Painter & painter);
  void drawForeground(Painter & painter);

private:
  const Message * mMessage;
  int mLineHeight;
  int mMarginLeft;
  int mMarginRight;
  int mMarginTop;
};

#endif // MESSAGEWIDGET_H
