#ifndef LABORADVISORWIDGET_H
#define LABORADVISORWIDGET_H

#include "advisorwidget.h"

#include "city/labordata.h"

class City;
class LaborAdvisorButton;
namespace Ui {
  class LaborAdvisorWidget;
}

class LaborAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit LaborAdvisorWidget(QWidget *parent = nullptr);
  ~LaborAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();
  int showPriorityDialog();
  void updateEmployment();
  void updateLabor();
  void updateLaborCategory(LaborAdvisorButton * button, LaborData::Type type);
  void updateWages();

private slots:
  void changeIndustry();
  void changeFood();
  void changeEngineering();
  void changeWater();
  void changePrefectures();
  void changeMilitary();
  void changeEntertainment();
  void changeHealth();
  void changeGovernance();
  void decreaseWages();
  void increaseWages();

private:
  Ui::LaborAdvisorWidget * mUi;
};

#endif // LABORADVISORWIDGET_H
