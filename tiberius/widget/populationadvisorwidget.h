#ifndef POPULATIONADVISORWIDGET_H
#define POPULATIONADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class PopulationAdvisorWidget;
}

class PopulationAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit PopulationAdvisorWidget(QWidget *parent = nullptr);
  ~PopulationAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::PopulationAdvisorWidget *mUi;
};

#endif // POPULATIONADVISORWIDGET_H
