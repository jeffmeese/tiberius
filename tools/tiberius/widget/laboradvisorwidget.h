#ifndef LABORADVISORWIDGET_H
#define LABORADVISORWIDGET_H

#include "advisorwidget.h"

#include "city/labordata.h"

#include "widget/button.h"

#include <QLabel>

class City;
class LaborAdvisorButton;
namespace Ui {
  class LaborAdvisorWidget;
}

class Label;

class LaborAdvisorButton
    : public Button
{
  Q_OBJECT

public:
  LaborAdvisorButton(QWidget * parentWidget = nullptr);

public:
  void setHave(int value);
  void setNeed(int value);
  void setPriority(int level);
  void setSector(const QString & text);

private:
  void init();

private:
  std::unique_ptr<QLabel> mLock;
  std::unique_ptr<Label> mPriority;
  std::unique_ptr<Label> mSector;
  std::unique_ptr<Label> mHave;
  std::unique_ptr<Label> mNeed;
};

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
  void initLaborButton(LaborAdvisorButton * button, const QString & text);
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
