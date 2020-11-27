#ifndef EDUCATIONADVISORWIDGET_H
#define EDUCATIONADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class EducationAdvisorWidget;
}

class EducationAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit EducationAdvisorWidget(QWidget *parent = nullptr);
  ~EducationAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::EducationAdvisorWidget *mUi;
};

#endif // EDUCATIONADVISORWIDGET_H
