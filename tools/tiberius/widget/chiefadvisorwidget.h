#ifndef CHIEFADVISORWIDGET_H
#define CHIEFADVISORWIDGET_H

#include "advisorwidget.h"

class City;
namespace Ui {
  class ChiefAdvisorWidget;
}

class ChiefAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit ChiefAdvisorWidget(QWidget *parent = nullptr);
  ~ChiefAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();
  void updateCityHealthData();
  void updateConsumptionData();
  void updateCrimeData();
  void updateEducationData();
  void updateEmploymentData();
  void updateEntertainmentData();
  void updateFinanceData();
  void updateFoodData();
  void updateHealthData();
  void updateMigrationData();
  void updateMilitaryData();
  void updateSentimentData();

private:
  Ui::ChiefAdvisorWidget *mUi;
};

#endif // CHIEFADVISORWIDGET_H
