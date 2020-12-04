#ifndef ENTERTAINMENTADVISORWIDGET_H
#define ENTERTAINMENTADVISORWIDGET_H

#include "advisorwidget.h"

#include "religion/god.h"

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

private slots:
  void handleCreateFestival();

private:
  Ui::EntertainmentAdvisorWidget *mUi;
  God::Type mFestivalGod;
};

#endif // ENTERTAINMENTADVISORWIDGET_H
