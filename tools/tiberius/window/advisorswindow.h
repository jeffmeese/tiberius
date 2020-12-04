#ifndef ADVISORSWINDOW_H
#define ADVISORSWINDOW_H

#include <QGroupBox>
#include <QLabel>
#include <QWidget>

#include <memory>

#include "advisor/advisor.h"

class Button;

class City;
class Game;
class ChiefAdvisorWidget;
class EducationAdvisorWidget;
class EntertainmentAdvisorWidget;
class FinanceAdvisorWidget;
class HealthAdvisorWidget;
class ImperialAdvisorWidget;
class LaborAdvisorWidget;
class LegionAdvisorWidget;
class PopulationAdvisorWidget;
class RatingsAdvisorWidget;
class ReligionAdvisorWidget;
class TradeAdvisorWidget;
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
  const Game * game() const;
  Advisor::Type activeAdvisor() const;
  void setActiveAdvisor(Advisor::Type type);
  void setGame(Game * game);

protected:
  void closeEvent(QCloseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  void hideAllAdvisors();
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
  std::unique_ptr<ChiefAdvisorWidget> mChiefAdvisor;
  std::unique_ptr<EducationAdvisorWidget> mEducationAdvisor;
  std::unique_ptr<EntertainmentAdvisorWidget> mEntertainmentAdvisor;
  std::unique_ptr<FinanceAdvisorWidget> mFinanceAdvisor;
  std::unique_ptr<HealthAdvisorWidget> mHealthAdvisor;
  std::unique_ptr<ImperialAdvisorWidget> mImperialAdvisor;
  std::unique_ptr<LaborAdvisorWidget> mLaborAdvisor;
  std::unique_ptr<LegionAdvisorWidget> mLegionAdvisor;
  std::unique_ptr<PopulationAdvisorWidget> mPopulationAdvisor;
  std::unique_ptr<RatingsAdvisorWidget> mRatingsAdvisor;
  std::unique_ptr<ReligionAdvisorWidget> mReligionAdvisor;
  std::unique_ptr<TradeAdvisorWidget> mTradeAdvisor;
  Advisor::Type mActiveAdvisor;
  Game * mGame;
};

#endif // ADVISORSWINDOW_H
