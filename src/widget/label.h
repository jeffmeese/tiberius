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
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit Label(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL bool enableBorder() const;
  TIBERIUS_LIB_DECL bool enableHover() const;
  TIBERIUS_LIB_DECL Font hoverFont() const;
  TIBERIUS_LIB_DECL void setEnableBorder(bool value);
  TIBERIUS_LIB_DECL void setEnableHover(bool enable);
  TIBERIUS_LIB_DECL void setHoverFont(Font font);

protected:
  void enterEvent(QEvent * event) override;
  void leaveEvent(QEvent * event) override;
  void mouseReleaseEvent(QMouseEvent * event) override;
  void paintEvent(QPaintEvent *event) override;

protected:
  void drawMultilineText(Painter & painter);
  void drawText(Painter & painter);

signals:
  void clicked();

private:
  bool mEnableBorder;
  bool mEnableHover;
  Font mHoverFont;
  Font mOldFont;
};

#endif // LABEL_H
