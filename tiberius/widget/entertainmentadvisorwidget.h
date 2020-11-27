#ifndef ENTERTAINMENTADVISORWIDGET_H
#define ENTERTAINMENTADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class EntertainmentAdvisorWidget;
}

class EntertainmentAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit EntertainmentAdvisorWidget(QWidget *parent = nullptr);
  ~EntertainmentAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::EntertainmentAdvisorWidget *mUi;
};

#endif // ENTERTAINMENTADVISORWIDGET_H
