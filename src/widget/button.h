#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QImage>

#include "tiberius.h"
#include "tiberiuswidget.h"

#include "graphics/font.h"

class Painter;

class Button
    : public QPushButton
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit Button(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL QImage disabledImage() const;
  TIBERIUS_LIB_DECL bool enableBorder() const;
  TIBERIUS_LIB_DECL bool enableClickSound() const;
  TIBERIUS_LIB_DECL bool enableFocusBorder() const;
  TIBERIUS_LIB_DECL QImage hoverImage() const;
  TIBERIUS_LIB_DECL QImage image() const;
  TIBERIUS_LIB_DECL QImage pressedImage() const;
  TIBERIUS_LIB_DECL void setDisabledImage(const QImage & image);
  TIBERIUS_LIB_DECL void setEnableBorder(bool value);
  TIBERIUS_LIB_DECL void setEnableClickSound(bool value);
  TIBERIUS_LIB_DECL void setEnableFocusBorder(bool value);
  TIBERIUS_LIB_DECL void setHoverImage(const QImage & image);
  TIBERIUS_LIB_DECL void setImage(const QImage & image);
  TIBERIUS_LIB_DECL void setPressedImage(const QImage & image);

protected:
  void enterEvent(QEvent * e) override;
  void leaveEvent(QEvent * e) override;
  void paintEvent(QPaintEvent *e) override;

private slots:
  void playClickSound();

protected:
  void drawBackground(Painter & painter);
  void drawText(Painter & painter);
  bool isHover() const;

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
