#ifndef SCROLLWIDGET_H
#define SCROLLWIDGET_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QWidget>

class ScrollBar;

class ScrollWidget
    : public QWidget
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit ScrollWidget(QWidget *parent = nullptr);
  TIBERIUS_LIB_DECL ~ScrollWidget();

public:
  TIBERIUS_LIB_DECL QWidget * viewport();
  TIBERIUS_LIB_DECL void setViewport(std::unique_ptr<QWidget> widget);

protected:
  void resizeEvent(QResizeEvent *event) override;

signals:

private:
  std::unique_ptr<QWidget> mViewport;
  std::unique_ptr<ScrollBar> mScrollBar;
};

#endif // SCROLLWIDGET_H
