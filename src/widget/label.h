#ifndef LABEL_H
#define LABEL_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include "core/painter.h"

#include "graphics/font.h"

#include <QLabel>

class Label
    : public QLabel
    , public TiberiusWidget
{
public:
  TIBERIUS_LIB_DECL explicit Label(QWidget * parentWidget = nullptr);

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  void drawText(Painter & painter);
};

#endif // LABEL_H
