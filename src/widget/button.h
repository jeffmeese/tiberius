#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QImage>

#include "tiberius.h"
#include "tiberiuswidget.h"

#include "graphics/font.h"

class Painter;

class TIBERIUS_LIB_DECL Button
    : public QPushButton
    , public TiberiusWidget
{
  Q_OBJECT

public:
  explicit Button(QWidget * parentWidget = nullptr);

public:
  QImage disabledImage() const;
  bool enableBorder() const;
  bool enableClickSound() const;
  bool enableFocusBorder() const;
  QImage hoverImage() const;
  QImage image() const;
  QImage pressedImage() const;
  void setDisabledImage(const QImage & image);
  void setEnableBorder(bool value);
  void setEnableClickSound(bool value);
  void setEnableFocusBorder(bool value);
  void setHoverImage(const QImage & image);
  void setImage(const QImage & image);
  void setPressedImage(const QImage & image);

protected:
  void enterEvent(QEvent * e) override;
  void leaveEvent(QEvent * e) override;
  void paintEvent(QPaintEvent *e) override;

protected:
  void drawBackground(Painter & painter);
  void drawText(Painter & painter);
  bool isHover() const;

private slots:
  void playClickSound();

private:
  bool mEnableClickSound;
  bool mEnableBorder;
  bool mEnableFocusBorder;
  QImage mDisabledImage;
  QImage mHoverImage;
  QImage mImage;
  QImage mPressedImage;
};

#endif // BUTTON_H
