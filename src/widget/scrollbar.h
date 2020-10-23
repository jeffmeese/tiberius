#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QWidget>

class Button;

class ScrollBar
    : public QWidget
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit ScrollBar(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL int maxmimum() const;
  TIBERIUS_LIB_DECL int minimum() const;
  TIBERIUS_LIB_DECL int stepSize() const;
  TIBERIUS_LIB_DECL int value() const;
  TIBERIUS_LIB_DECL void setMaximum(int value);
  TIBERIUS_LIB_DECL void setMinimum(int value);
  TIBERIUS_LIB_DECL void setRange(int minValue, int maxValue);
  TIBERIUS_LIB_DECL void setStepSize(int value);

public slots:
  TIBERIUS_LIB_DECL void scrollDown();
  TIBERIUS_LIB_DECL void scrollUp();
  TIBERIUS_LIB_DECL void setValue(int value);

protected:
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *) override;

private:
  int calculateScrollAreaHeight() const;
  int calculateValueFromPosition(const QPoint & pos);
  void updateSliderPosition();

signals:
  void sliderMoved(int value);
  void sliderPressed();
  void sliderReleased();
  void valueChanged(int value);

private:
  bool mSliderPressed;
  int mMaximum;
  int mMinumum;
  int mStepSize;
  int mValue;
  int mSliderHeight;
  int mButtonWidth;
  int mButtonHeight;
  QRect mSliderRect;
  std::unique_ptr<Button> mScrollDownButton;
  std::unique_ptr<Button> mScrollUpButton;
};

inline int ScrollBar::maxmimum() const
{
  return mMaximum;
}

inline int ScrollBar::minimum() const
{
  return mMinumum;
}

inline int ScrollBar::stepSize() const
{
  return mStepSize;
}

inline int ScrollBar::value() const
{
  return mValue;
}

#endif // SCROLLBAR_H
