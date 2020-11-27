#ifndef PRIORITYLABEL_H
#define PRIORITYLABEL_H

#include "widget/label.h"

class PriorityLabel
    : public Label
{
public:
  PriorityLabel(QWidget * parentWidget = nullptr);

protected:
  void enterEvent(QEvent * e) override;
  void leaveEvent(QEvent * e) override;
  void paintEvent(QPaintEvent * event) override;

private:
  void drawOutline(Painter & painter);

private:
  bool mHover;
};

#endif // PRIORITYLABEL_H
