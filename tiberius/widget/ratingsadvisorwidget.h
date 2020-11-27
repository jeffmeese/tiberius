#ifndef RATINGSADVISORWIDGET_H
#define RATINGSADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class RatingsAdvisorWidget;
}

class RatingsAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit RatingsAdvisorWidget(QWidget *parent = nullptr);
  ~RatingsAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::RatingsAdvisorWidget *mUi;
};

#endif // RATINGSADVISORWIDGET_H
