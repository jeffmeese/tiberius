#ifndef HEALTHADVISORWIDGET_H
#define HEALTHADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class HealthAdvisorWidget;
}

class HealthAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit HealthAdvisorWidget(QWidget *parent = nullptr);
  ~HealthAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::HealthAdvisorWidget * mUi;
};

#endif // HEALTHADVISORWIDGET_H
