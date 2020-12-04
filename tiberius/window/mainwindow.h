#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

#include <memory>

#include "advisor/advisor.h"

#include "graphics/resolution.h"

class Application;
class DifficultyDialog;
class DisplayOptionsDialog;
class SoundOptionsDialog;
class SpeedOptionsDialog;
class AdvisorsWindow;
class EmpireWindow;
class Game;
class GameWindow;
class MenuWindow;
class MissionWindow;
class TitleWindow;

namespace Ui
{
  class MainWindow;
}

class MainWindow
    : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(Application & application, QWidget *parent = nullptr);
  ~MainWindow();

protected:
  bool eventFilter(QObject * object, QEvent * event) override;
  void keyPressEvent(QKeyEvent * event) override;
  void resizeEvent(QResizeEvent * event) override;

private slots:
  void handleAbout();
  void handleAboutToShowHelp();
  void handleAboutToShowOptions();
  void handleAdvisorsRequested();
  void handleAdvisorWindowClosed();
  void handleChiefAdvisor();
  void handleDeleteGame();
  void handleDifficultyOptions();
  void handleDifficultyOptionsChanged();
  void handleDisplaySettings();
  void handleDisplaySettingsChanged();
  void handleEducationAdvisor();
  void handleEmperorAdvisor();
  void handleEmpire();
  void handleEmpireWindowClosed();
  void handleEntertainmentAdvisor();
  void handleExitGame();
  void handleFullScreen(bool fullScreen);
  void handleGovernmentAdvisor();
  void handleHealthAdvisor();
  void handleHelp();
  void handleLaborAdvisor();
  void handleLoadGame();
  void handleLoadGame(const QString & fileName);
  void handleMilitaryAdvisor();
  void handleMonthlyAutosave();
  void handleMouseHelp();
  void handleNewGame();
  void handlePopulationAdvisor();
  void handleRatingsAdvisor();
  void handleReligionAdvisor();
  void handleReplayMap();
  void handleSaveGame();
  void handleShowAdvisors();
  void handleScreenResolution(ScreenResolution resolution);
  void handleSoundSettings();
  void handleSoundSettingsChanged();
  void handleSpeedSettings();
  void handleSpeedSettingsChanged();
  void handleStartMission(int missionNumber);
  void handleStartNewCareer(const QString & playerName);
  void handleTitleWindowClosed();
  void handleTradeAdvisor();
  void handleWarnings();

private:
  void init();
  void showAdvisorsWindow(Advisor::Type type);

private:
  Application & mApplication;
  Advisor::Type mCurrentAdvisor;
  int32_t mSidebarWidth;
  std::unique_ptr<Ui::MainWindow> mUi;
  std::unique_ptr<AdvisorsWindow> mAdvisorsWindow;
  std::unique_ptr<EmpireWindow> mEmpireWindow;
  std::unique_ptr<GameWindow> mGameWindow;
  std::unique_ptr<MenuWindow> mMenuWindow;
  std::unique_ptr<MissionWindow> mMissionWindow;
  std::unique_ptr<TitleWindow> mTitleWindow;
  std::unique_ptr<QWidget> mFinanceWidget;
  std::unique_ptr<QWidget> mPopulationWidget;
  std::unique_ptr<QWidget> mDateWidget;
  std::unique_ptr<Game> mGame;
  std::unique_ptr<DisplayOptionsDialog> mDisplayOptionsDialog;
  std::unique_ptr<DifficultyDialog> mDifficultyOptionsDialog;
  std::unique_ptr<SoundOptionsDialog> mSoundOptionsDialog;
  std::unique_ptr<SpeedOptionsDialog> mSpeedOptionsDialog;

//public:
//  bool eventFilter(QObject * object, QEvent * event) override;
//  void keyPressEvent(QKeyEvent *event) override;
//  void resizeEvent(QResizeEvent * event) override;

//private slots:
//  void decreaseGameSpeed();
//  void handleAbout();
//  void handleAdvisorWindowClosed();
//  void handleDeleteGame();
//  void handleDifficulty();
//  void handleDifficultyChanged();
//  void handleDisplaySettings();
//  void handleDisplaySettingsChanged();
//  void handleExitGame();
//  void handleHelp();
//  void handleLoadGame();
//  void handleLoadGame(const QString & fileName);
//  void handleMainMenu();
//  void handleMonthlyAutosave();
//  void handleMouseHelp();
//  void handleReplayMap();
//  void handleSaveGame();
//  void handleSoundSettings();
//  void handleSoundSettingsChanged();
//  void handleSpeedSettings();
//  void handleSpeedSettingsChanged();
//  void handleStartNewCareer(const QString & playerName);
//  void handleWarnings();
//  void increaseGameSpeed();
//  void showChiefAdvisor();
//  void showEducationAdvisor();
//  void showEmperorAdvisor();
//  void showEmpire();
//  void showEntertainmentAdvisor();
//  void showFinanceAdvisor();
//  void showHealthAdvisor();
//  void showLaborAdvisor();
//  void showLegionAdvisor();
//  void showMessages();
//  void showMission();
//  void showPopulationAdvisor();
//  void showRatingsAdvisor();
//  void showReligionAdvisor();
//  void showTradeAdvisor();
//  void togglePauseGame();
//  void showGameWindow();

//private:
//  void connectActions();
//  void createMenus();
//  void showAdvisorsWindow(AdvisorType advisor);
//  void showMainMenuWindow();
//  void showMissionWindow();
//  void showTitleWindow();

//private:
//  typedef std::unique_ptr<Menu> MenuPtr;
//  typedef std::unique_ptr<QAction> ActionPtr;

//private:
//  Ui::MainWindow * mUi;
//  Application & mApplication;
//  GameWindow * mGameWindow;
//  MainMenuWindow * mMainMenuWindow;
//  TitleWindow * mTitleMenu;
//  MenuPtr mFileMenu;
//  MenuPtr mOptionsMenu;
//  MenuPtr mHelpMenu;
//  MenuPtr mAdvisorsMenu;
//  ActionPtr mNewGameAction;
//  ActionPtr mReplayMapAction;
//  ActionPtr mLoadGameAction;
//  ActionPtr mSaveGameAction;
//  ActionPtr mDeleteGameAction;
//  ActionPtr mExitGameAction;
//  ActionPtr mDisplaySettingsAction;
//  ActionPtr mSoundSettingsAction;
//  ActionPtr mSpeedSettingsAction;
//  ActionPtr mDifficultyAction;
//  ActionPtr mAutoSaveAction;
//  ActionPtr mHelpAction;
//  ActionPtr mMouseHelpAction;
//  ActionPtr mWarningsAction;
//  ActionPtr mAboutAction;
//  ActionPtr mLaborAdvisorAction;
//  ActionPtr mLegionAdvisorAction;
//  ActionPtr mEmperorAdvisorAction;
//  ActionPtr mRatingsAdvisorAction;
//  ActionPtr mTradeAdvisorAction;
//  ActionPtr mPopulationAdvisorAction;
//  ActionPtr mHealthAdvisorAction;
//  ActionPtr mEducationAdvisorAction;
//  ActionPtr mEntertainmentAdvisorAction;
//  ActionPtr mReligionAdvisorAction;
//  ActionPtr mFinancesAdvisorAction;
//  ActionPtr mChiefAdvisorAction;
//  std::unique_ptr<DifficultyDialog> mDifficultyDialog;
//  std::unique_ptr<DisplayOptionsDialog> mDisplayOptionsDialog;
//  std::unique_ptr<SpeedOptionsDialog> mSpeedOptionsDialog;
//  std::unique_ptr<SoundOptionsDialog> mSoundOptionsDialog;
};

#endif // MAINWINDOW_H
