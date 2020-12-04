#ifndef LABEL_H
#define LABEL_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include "core/painter.h"

#include "graphics/font.h"

#include <QLabel>

class TIBERIUS_LIB_DECL Label
    : public QLabel
    , public TiberiusWidget
{
  Q_OBJECT

public:
  explicit Label(QWidget * parentWidget = nullptr);

public:
  bool enableBorder() const;
  bool enableHover() const;
  Font hoverFont() const;
  void setEnableBorder(bool value);
  void setEnableHover(bool enable);
  void setHoverFont(Font font);

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
