#ifndef BORDEREDBUTTON_H
#define BORDEREDBUTTON_H

#include "tiberiuswidget.h"

#include <QAbstractButton>

class Painter;

class BorderedButton
    : public QAbstractButton
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit BorderedButton(QWidget * parentWidget = nullptr);

protected:
  void enterEvent(QEvent * e) override;
  void leaveEvent(QEvent * e) override;
  void paintEvent(QPaintEvent *e) override;

private:
  void drawBackground(Painter & painter);
  void drawText(Painter & painter);

private:
  bool mHover;
};

#endif // BORDEREDBUTTON_H
