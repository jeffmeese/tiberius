#ifndef ADVISORSWINDOW_H
#define ADVISORSWINDOW_H

#include <QWidget>

#include <memory>

#include "advisor/advisor.h"

namespace Ui {
  class AdvisorsWindow;
}

class AdvisorsWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit AdvisorsWindow(QWidget *parent = nullptr);
  ~AdvisorsWindow();

public:
  Advisor::Type activeAdvisor() const;
  void setActiveAdvisor(Advisor::Type type);

protected:
  void closeEvent(QCloseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  void init();

private slots:
  void showChiefAdvisor();
  void showEducationAdvisor();
  void showEmperorAdvisor();
  void showEntertainmentAdvisor();
  void showGovernmentAdvisor();
  void showHealthAdvisor();
  void showLaborAdvisor();
  void showMilitaryAdvisor();
  void showPopulationAdvisor();
  void showRatingsAdvisor();
  void showReligionAdvisor();
  void showTradeAdvisor();

signals:
  void closed();

private:
  std::unique_ptr<Ui::AdvisorsWindow> mUi;
  Advisor::Type mActiveAdvisor;
};

#endif // ADVISORSWINDOW_H
