#ifndef EDUCATIONADVISORWIDGET_H
#define EDUCATIONADVISORWIDGET_H

#include "advisorwidget.h"

class Label;
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
  void updateCanEducate(Label * label, int32_t working, int32_t amount, int32_t textId);
  void updateCoverage(Label * label, int32_t coverage);
  void updateSubtitle(int32_t totalPopulation, int32_t schoolAged, int32_t academyAged);
  void updateTotal(Label * label, int32_t total, int32_t textId);
  void updateWorking(Label * label, int32_t total);

private:
  Ui::EducationAdvisorWidget *mUi;
};

#endif // EDUCATIONADVISORWIDGET_H
