#include "scrollwidget.h"
#include "scrollbar.h"

ScrollWidget::ScrollWidget(QWidget *parent)
  : QWidget(parent)
{
  mViewport.reset(new QWidget(this));
  //mViewport->setAutoFillBackground(false);

  mScrollBar.reset(new ScrollBar(this));
  //mScrollBar->setAutoFillBackground(false);
}

ScrollWidget::~ScrollWidget()
{

}

void ScrollWidget::resizeEvent(QResizeEvent *event)
{
  mScrollBar->move(width()-39, 0);
  mViewport->resize(width()-39, height());
  mScrollBar->resize(39, height());
}

void ScrollWidget::setViewport(std::unique_ptr<QWidget> widget)
{
  mViewport = std::move(widget);
}

QWidget * ScrollWidget::viewport()
{
  return mViewport.get();
}
