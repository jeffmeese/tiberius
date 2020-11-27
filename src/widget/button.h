#ifndef BUTTON_H
#define BUTTON_H

#include <QAbstractButton>
#include <QImage>

#include "tiberius.h"
#include "tiberiuswidget.h"

#include "graphics/font.h"

class Painter;

class Button
    : public QAbstractButton
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit Button(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL QImage disabledImage() const;
  TIBERIUS_LIB_DECL bool enableClickSound() const;
  TIBERIUS_LIB_DECL QImage hoverImage() const;
  TIBERIUS_LIB_DECL QImage image() const;
  TIBERIUS_LIB_DECL QImage pressedImage() const;
  TIBERIUS_LIB_DECL void setDisabledImage(const QImage & image);
  TIBERIUS_LIB_DECL void setEnableClickSound(bool value);
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
  QImage mDisabledImage;
  QImage mHoverImage;
  QImage mImage;
  QImage mPressedImage;
};

inline QImage Button::disabledImage() const
{
  return mDisabledImage;
}

inline bool Button::enableClickSound() const
{
  return mEnableClickSound;
}

inline QImage Button::hoverImage() const
{
  return mHoverImage;
}

inline QImage Button::image() const
{
  return mImage;
}

inline QImage Button::pressedImage() const
{
  return mPressedImage;
}

inline void Button::setDisabledImage(const QImage & image)
{
  mDisabledImage = image;
}

inline void Button::setEnableClickSound(bool value)
{
  mEnableClickSound = value;
}

inline void Button::setHoverImage(const QImage & image)
{
  mHoverImage = image;
}

inline void Button::setImage(const QImage & image)
{
  mImage = image;
}

inline void Button::setPressedImage(const QImage & image)
{
  mPressedImage = image;
}

#endif // BUTTON_H
