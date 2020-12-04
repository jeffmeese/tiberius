#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "application/application.h"

#include "dialog/difficultydialog.h"
#include "dialog/displayoptionsdialog.h"
#include "dialog/filedialog.h"
#include "dialog/messagedialog.h"
#include "dialog/soundoptionsdialog.h"
#include "dialog/speedoptionsdialog.h"

#include "game/game.h"
#include "game/player.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "mission/mission.h"

#include "window/advisorswindow.h"
#include "window/empirewindow.h"
#include "window/gamewindow.h"
#include "window/menuwindow.h"
#include "window/missionwindow.h"
#include "window/titlewindow.h"

#include <QDir>
#include <QKeyEvent>

MainWindow::MainWindow(Application & application, QWidget * parentWidget)
  : QMainWindow(parentWidget)
  , mApplication(application)
  , mUi(new Ui::MainWindow)
  , mAdvisorsWindow(new AdvisorsWindow)
  , mEmpireWindow(new EmpireWindow)
  , mGameWindow(new GameWindow)
  , mMenuWindow(new MenuWindow)
  , mMissionWindow(new MissionWindow)
  , mTitleWindow(new TitleWindow)
{
  init();
}

MainWindow::~MainWindow()
{

}

bool MainWindow::eventFilter(QObject * object, QEvent * event)
{
  if (object == mUi->menuOptions) {
    if (event->type() == QEvent::MouseButtonRelease) {
      QMenu * menu = qobject_cast<QMenu*>(object);
      QAction * action = menu->activeAction();
      if (action == mUi->actionMonthly_Autosave) {
        action->trigger();
        return true;
      }
    }
  }

  if (object == mUi->menuHelp) {
    QMenu * menu = qobject_cast<QMenu*>(object);
    if (event->type() == QEvent::MouseButtonRelease) {
      QAction * action = menu->activeAction();
      if (action == mUi->actionWarnings) {
        qDebug() << "Warnings";
        action->trigger();
        return true;
      }
      if (action == mUi->actionMouse_Help) {
        action->trigger();
        return true;
      }
    }
  }

  return QMainWindow::eventFilter(object, event);
}

void MainWindow::handleAbout()
{

}

void MainWindow::handleAboutToShowHelp()
{
  const StringData * stringData = mApplication.language()->stringData();

  // Update the text for menu items that can change
  bool warnings = Application::settings().warningsEnabled();
  Settings::MouseHelp mouseHelp = Application::settings().mouseHelp();
  int32_t warningsIndex = warnings ? 6 : 5;
  int32_t mouseHelpIndex = 2;
  if (mouseHelp == Settings::Some)
    mouseHelpIndex = 3;
  else if (mouseHelp == Settings::All)
    mouseHelpIndex = 4;

  mUi->actionWarnings->setText(stringData->getString(3, warningsIndex));
  mUi->actionMouse_Help->setText(stringData->getString(3, mouseHelpIndex));
}

void MainWindow::handleAboutToShowOptions()
{
  const StringData * stringData = mApplication.language()->stringData();
  bool autosave = Application::settings().monthlyAutosaveEnabled();
  int32_t autosaveIndex = autosave ? 51 : 52;

  mUi->actionMonthly_Autosave->setText(stringData->getString(19, autosaveIndex));
}

void MainWindow::handleAdvisorWindowClosed()
{
  mUi->menuBar->show();
  mUi->cSidebarWidget->show();
  mGameWindow->show();
  mAdvisorsWindow->hide();
}

void MainWindow::handleAdvisorsRequested()
{
  showAdvisorsWindow(mCurrentAdvisor);
}

void MainWindow::handleChiefAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Chief);
}

void MainWindow::handleDeleteGame()
{
  FileDialog dialog(this);
  dialog.setType(FileDialog::Type::DeleteGame);
  int resp = dialog.exec();
  if (resp == QDialog::Accepted) {
    QString fileName = dialog.fileName();
    QString c3Dir = mApplication.c3Dir();
    QString pathName = c3Dir + QDir::separator() + fileName;
    QFile::remove(pathName);
  }
}

void MainWindow::handleDifficultyOptions()
{
  Settings & settings = mApplication.settings();
  mDifficultyOptionsDialog.reset(new DifficultyDialog(this));
  mDifficultyOptionsDialog->setDifficulty(settings.difficulty().type());
  mDifficultyOptionsDialog->setGodsEffectsOn(settings.godEffectsEnabled());
  connect(mDifficultyOptionsDialog.get(), SIGNAL(changed()), SLOT(handleDifficultyOptionsChanged()));
  mDifficultyOptionsDialog->exec();
}

void MainWindow::handleDifficultyOptionsChanged()
{
  Settings & settings = mApplication.settings();
  settings.setDifficulty(Difficulty(mDifficultyOptionsDialog->difficulty()));
  settings.setGodEffectsEnabled(mDifficultyOptionsDialog->godsEffectsOn());
}

void MainWindow::handleDisplaySettings()
{
  Settings & settings = mApplication.settings();

  mDisplayOptionsDialog.reset(new DisplayOptionsDialog(this));
  mDisplayOptionsDialog->setFullscreen(settings.fullscreen());
  mDisplayOptionsDialog->setScreenResolution(settings.screenResolution());
  connect(mDisplayOptionsDialog.get(), SIGNAL(changed()), SLOT(handleDisplaySettingsChanged()));
  mDisplayOptionsDialog->exec();
}

void MainWindow::handleDisplaySettingsChanged()
{
  Settings & settings = mApplication.settings();

  bool fullScreen = settings.fullscreen();
  if (fullScreen) {
    this->showMaximized();
    this->showFullScreen();
  }
  else {
    this->showNormal();
    ScreenResolution resolution = settings.screenResolution();
    switch (resolution) {
      case Resolution640x480:
        this->resize(640, 480);
        break;
      case Resolution800x600:
        this->resize(800, 600);
        break;
      case Resolution1024x768:
        this->resize(1024, 768);
        break;
    }
  }
}

void MainWindow::handleEducationAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Education);
}

void MainWindow::handleEmperorAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Emperor);
}

void MainWindow::handleEmpire()
{
  mUi->menuBar->hide();
  mGameWindow->hide();
  mEmpireWindow->show();
}

void MainWindow::handleEmpireWindowClosed()
{
  mUi->menuBar->show();
  mUi->cSidebarWidget->show();
  mGameWindow->show();
  mEmpireWindow->hide();
}

void MainWindow::handleEntertainmentAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Entertainment);
}

void MainWindow::handleExitGame()
{
  MessageDialog dialog(MessageDialog::LeaveEmpire, this);
  int32_t resp = dialog.exec();
  if (resp == QDialog::Rejected) {
    return;
  }

  QApplication::exit(0);
}

void MainWindow::handleFullScreen(bool fullScreen)
{
  Application::settings().setFullscreen(fullScreen);
}

void MainWindow::handleGovernmentAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Government);
}

void MainWindow::handleHealthAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Health);
}

void MainWindow::handleHelp()
{

}

void MainWindow::handleLaborAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Labor);
}

void MainWindow::handleLoadGame()
{
  FileDialog dialog(this);
  dialog.setType(FileDialog::LoadMap);
  int nResp = dialog.exec();
  if (nResp == QDialog::Rejected) {
    return;
  }

  QString fileName = dialog.fileName();
  handleLoadGame(fileName);
}

void MainWindow::handleLoadGame(const QString & fileName)
{
  QString c3Dir = mApplication.c3Dir();
  QString filePath = c3Dir + QDir::separator() + fileName;

  std::unique_ptr<Mission> mission(new Mission);
  mission->loadFromFile(filePath);

  mGame.reset(new Game);
  mGame->setMission(std::move(mission));
  mGameWindow->setGame(mGame.get());

  mGame->player()->setName("Player");

  mAdvisorsWindow->setGame(mGame.get());

  mMenuWindow->hide();
  mUi->menuBar->show();
  mGameWindow->show();
  mUi->cSidebarWidget->setVisible(true);
}

void MainWindow::handleMilitaryAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Military);
}

void MainWindow::handleMouseHelp()
{
  const StringData * textData = Application::language()->stringData();

  int32_t textIndex = 2;
  Settings::MouseHelp mouseHelp = Application::settings().mouseHelp();
  if (mouseHelp == Settings::None) {
    Application::settings().setMouseHelp(Settings::Some);
    textIndex = 3;
  }
  else if (mouseHelp == Settings::Some) {
    Application::settings().setMouseHelp(Settings::All);
    textIndex = 4;
  }
  else {
    Application::settings().setMouseHelp(Settings::None);
  }

  mUi->actionMouse_Help->setText(textData->getString(3, textIndex));
}

void MainWindow::handleMonthlyAutosave()
{
  const StringData * textData = mApplication.language()->stringData();
  Application::settings().setMonthlyAutosaveEnabled(!Application::settings().monthlyAutosaveEnabled());
  int32_t textIndex = Application::settings().monthlyAutosaveEnabled() ? 51 : 52;
  mUi->actionMonthly_Autosave->setText(textData->getString(19, textIndex));
}

void MainWindow::handleNewGame()
{
  mUi->menuBar->hide();
  mGameWindow->show();
  mMenuWindow->show();
}

void MainWindow::handlePopulationAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Population);
}

void MainWindow::handleRatingsAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Ratings);
}

void MainWindow::handleReligionAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Religion);
}

void MainWindow::handleReplayMap()
{

}

void MainWindow::handleSaveGame()
{

}

void MainWindow::handleScreenResolution(ScreenResolution resolution)
{
  Application::settings().setScreenResolution(resolution);
}

void MainWindow::handleShowAdvisors()
{
  showAdvisorsWindow(mCurrentAdvisor);
}

void MainWindow::handleSoundSettings()
{
  Settings & settings = mApplication.settings();
  mSoundOptionsDialog.reset(new SoundOptionsDialog(this));
  mSoundOptionsDialog->setCitySoundsOn(settings.citySoundsEnabled());
  mSoundOptionsDialog->setMusicOn(settings.musicEnabled());
  mSoundOptionsDialog->setSoundEffectsOn(settings.soundEffectsEnabled());
  mSoundOptionsDialog->setSpeechOn(settings.speechSoundsEnabled());
  mSoundOptionsDialog->setCitySoundsVolume(settings.citySoundsVolume());
  mSoundOptionsDialog->setMusicVolume(settings.musicVolume());
  mSoundOptionsDialog->setSoundEffectsVolume(settings.speechSoundsVolume());
  mSoundOptionsDialog->setSpeechVolume(settings.speechSoundsVolume());
  connect(mSoundOptionsDialog.get(), SIGNAL(changed()), SLOT(handleSoundSettingsChanged()));
  mSoundOptionsDialog->exec();
}

void MainWindow::handleSoundSettingsChanged()
{
  Settings & settings = mApplication.settings();
  settings.setCitySoundsEnabled(mSoundOptionsDialog->citySoundsOn());
  settings.setCitySoundsVolume(mSoundOptionsDialog->citySoundsVolume());
  settings.setMusicEnabled(mSoundOptionsDialog->musicVolume());
  settings.setMusicVolume(mSoundOptionsDialog->musicVolume());
  settings.setSoundEffectsEnabled(mSoundOptionsDialog->soundEffectsOn());
  settings.setSoundEffectsVolume(mSoundOptionsDialog->soundEffectsVolume());
  settings.setSpeechSoundsEnabled(mSoundOptionsDialog->speechOn());
  settings.setSpeechSoundsVolume(mSoundOptionsDialog->speechVolume());
}

void MainWindow::handleSpeedSettings()
{
  Settings & settings = mApplication.settings();

  mSpeedOptionsDialog.reset(new SpeedOptionsDialog(this));
  mSpeedOptionsDialog->setGameSpeed(settings.gameSpeed());
  mSpeedOptionsDialog->setScrollSpeed(settings.scrollSpeed());
  connect(mSpeedOptionsDialog.get(), SIGNAL(changed()), SLOT(handleSpeedSettingsChanged()));
  mSpeedOptionsDialog->exec();
}

void MainWindow::handleSpeedSettingsChanged()
{
  Settings & settings = mApplication.settings();
  settings.setGameSpeed(mSpeedOptionsDialog->gameSpeed());
  settings.setScrollSpeed(mSpeedOptionsDialog->scrollSpeed());
}

void MainWindow::handleStartMission(int missionNumber)
{
  mMissionWindow->hide();
  mUi->menuBar->show();
  mUi->cSidebarWidget->show();
  mGameWindow->show();
}

void MainWindow::handleStartNewCareer(const QString & playerName)
{
  mUi->menuBar->hide();
  mMenuWindow->hide();
  mMissionWindow->setMissionNumber(1);
  mMissionWindow->show();
}

void MainWindow::handleTitleWindowClosed()
{
  mUi->menuBar->hide();
  mTitleWindow->hide();
  mMenuWindow->show();
}

void MainWindow::handleTradeAdvisor()
{
  showAdvisorsWindow(Advisor::Type::Trade);
}

void MainWindow::handleWarnings()
{
  const StringData * textData = mApplication.language()->stringData();
  Application::settings().setWarningsEnabled(!Application::settings().warningsEnabled());
  int32_t textIndex = Application::settings().warningsEnabled() ? 6 : 5;
  mUi->actionWarnings->setText(textData->getString(3, textIndex));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
  int key = event->key();

  switch (key) {
  case Qt::Key_0:
    handleReligionAdvisor();
    break;
  case Qt::Key_1:
    handleLaborAdvisor();
    break;
  case Qt::Key_2:
    handleMilitaryAdvisor();
    break;
  case Qt::Key_3:
    handleEmperorAdvisor();
    break;
  case Qt::Key_4:
    handleRatingsAdvisor();
    break;
  case Qt::Key_5:
    handleTradeAdvisor();
    break;
  case Qt::Key_6:
    handlePopulationAdvisor();
    break;
  case Qt::Key_7:
    handleHealthAdvisor();
    break;
  case Qt::Key_8:
    handleEducationAdvisor();
    break;
  case Qt::Key_9:
    handleEntertainmentAdvisor();
    break;
  case Qt::Key_Minus:
    handleGovernmentAdvisor();
    break;
  case Qt::Key_Equal:
    handleChiefAdvisor();
    break;
  case Qt::Key_F:
    break;
  case Qt::Key_D:
    break;
  case Qt::Key_C:
    break;
  case Qt::Key_T:
    break;
  case Qt::Key_W:
    break;
  case Qt::Key_P:
    break;
  case Qt::Key_BracketLeft:
    break;
  case Qt::Key_BracketRight:
    break;
  case Qt::Key_Left:
    break;
  case Qt::Key_Right:
    break;
  case Qt::Key_Up:
    break;
  case Qt::Key_Down:
    break;
  case Qt::Key_F1:
    break;
  case Qt::Key_F2:
    break;
  case Qt::Key_F3:
    break;
  case Qt::Key_F4:
    break;
  case Qt::Key_F5:
    break;
  case Qt::Key_F6:
    break;
  case Qt::Key_F7:
    break;
  case Qt::Key_F8:
    break;
  case Qt::Key_F9:
    break;
  case Qt::Key_Space:
    break;
  case Qt::Key_L:
    break;
  }
}

void MainWindow::init()
{
  mUi->setupUi(this);

  mCurrentAdvisor = Advisor::Type::Labor;
  mSidebarWidth = 162;

  mAdvisorsWindow.reset(new AdvisorsWindow(centralWidget()));
  mEmpireWindow.reset(new EmpireWindow(centralWidget()));
  mGameWindow.reset(new GameWindow(centralWidget()));
  mMenuWindow.reset(new MenuWindow(centralWidget()));
  mTitleWindow.reset(new TitleWindow(centralWidget()));
  mGameWindow->lower();

  mAdvisorsWindow->hide();
  mEmpireWindow->hide();
  mGameWindow->hide();
  mMenuWindow->hide();
  mMissionWindow->hide();
  mUi->menuBar->hide();
  mUi->cSidebarWidget->hide();

  mUi->menuOptions->installEventFilter(this);
  mUi->menuHelp->installEventFilter(this);

  connect(mUi->menuHelp, SIGNAL(aboutToShow()), SLOT(handleAboutToShowHelp()));
  connect(mUi->menuOptions, SIGNAL(aboutToShow()), SLOT(handleAboutToShowOptions()));

  connect(mAdvisorsWindow.get(), SIGNAL(closed()), SLOT(handleAdvisorWindowClosed()));
  connect(mEmpireWindow.get(), SIGNAL(closed()), SLOT(handleEmpireWindowClosed()));
  connect(mEmpireWindow.get(), SIGNAL(tradeRequested()), SLOT(handleTradeAdvisor()));

  connect(mTitleWindow.get(), SIGNAL(closed()), SLOT(handleTitleWindowClosed()));
  connect(mMissionWindow.get(), SIGNAL(startMission(int)), SLOT(handleStartMission(int)));
  connect(mMenuWindow.get(), SIGNAL(loadGame(const QString &)), SLOT(handleLoadGame(const QString &)));
  connect(mMenuWindow.get(), SIGNAL(startNewCareer(const QString &)), SLOT(handleStartNewCareer(const QString &)));

  connect(mUi->actionNew_Game, SIGNAL(triggered()), SLOT(handleNewGame()));
  connect(mUi->actionReplay_Map, SIGNAL(triggered()), SLOT(handleReplayMap()));
  connect(mUi->actionLoad_Game, SIGNAL(triggered()), SLOT(handleLoadGame()));
  connect(mUi->actionSave_Game, SIGNAL(triggered()), SLOT(handleSaveGame()));
  connect(mUi->actionDelete_Game, SIGNAL(triggered()), SLOT(handleDeleteGame()));
  connect(mUi->actionExit_Game, SIGNAL(triggered()), SLOT(handleExitGame()));

  connect(mUi->actionDisplay_Settings, SIGNAL(triggered()), SLOT(handleDisplaySettings()));
  connect(mUi->actionSound_Settings, SIGNAL(triggered()), SLOT(handleSoundSettings()));
  connect(mUi->actionSpeed_Settings, SIGNAL(triggered()), SLOT(handleSpeedSettings()));
  connect(mUi->actionDifficulty, SIGNAL(triggered()), SLOT(handleDifficultyOptions()));
  connect(mUi->actionMonthly_Autosave, SIGNAL(triggered()), SLOT(handleMonthlyAutosave()));

  connect(mUi->actionHelp, SIGNAL(triggered()), SLOT(handleHelp()));
  connect(mUi->actionMouse_Help, SIGNAL(triggered()), SLOT(handleMouseHelp()));
  connect(mUi->actionAbout, SIGNAL(triggered()), SLOT(handleAbout()));
  connect(mUi->actionWarnings, SIGNAL(triggered()), SLOT(handleWarnings()));

  connect(mUi->actionChief_Advisor, SIGNAL(triggered()), SLOT(handleChiefAdvisor()));
  connect(mUi->actionLabor, SIGNAL(triggered()), SLOT(handleLaborAdvisor()));
  connect(mUi->actionRatings, SIGNAL(triggered()), SLOT(handleRatingsAdvisor()));
  connect(mUi->actionPopulation, SIGNAL(triggered()), SLOT(handlePopulationAdvisor()));
  connect(mUi->actionEducation, SIGNAL(triggered()), SLOT(handleEducationAdvisor()));
  connect(mUi->actionEmperor, SIGNAL(triggered()), SLOT(handleEmperorAdvisor()));
  connect(mUi->actionEntertainment, SIGNAL(triggered()), SLOT(handleEntertainmentAdvisor()));
  connect(mUi->actionLegion, SIGNAL(triggered()), SLOT(handleMilitaryAdvisor()));
  connect(mUi->actionReligion, SIGNAL(triggered()), SLOT(handleReligionAdvisor()));
  connect(mUi->actionTrade, SIGNAL(triggered()), SLOT(handleTradeAdvisor()));
  connect(mUi->actionHealth, SIGNAL(triggered()), SLOT(handleHealthAdvisor()));
  connect(mUi->actionFinances, SIGNAL(triggered()), SLOT(handleGovernmentAdvisor()));

  connect(mUi->cSidebarWidget, SIGNAL(advisorsRequested()), SLOT(handleAdvisorsRequested()));
  connect(mUi->cSidebarWidget, SIGNAL(empireRequested()), SLOT(handleEmpire()));
  //connect(mUi->cSidebarWidget, SIGNAL(collapsed()), SLOT(update()));
  //connect(mUi->cSidebarWidget, SIGNAL(expanded()), SLOT(update()));
  //connect(mUi->cSidebarWidget, SIGNAL(orientNorth()), mUi->cCity, SLOT(orientNorth()));
  //connect(mUi->cSidebarWidget, SIGNAL(rotateLeft()), mUi->cCity, SLOT(rotateLeft()));
  //connect(mUi->cSidebarWidget, SIGNAL(rotateRight()), mUi->cCity, SLOT(rotateRight()));
  //connect(mUi->cSidebarWidget, SIGNAL(showAdvisors()), SLOT(showAdvisors()));
  //connect(mUi->cSidebarWidget, SIGNAL(showEmpire()), SLOT(showEmpire()));
  //connect(mUi->cSidebarWidget, SIGNAL(showMessages()), SLOT(showMessages()));
  //connect(mUi->cSidebarWidget, SIGNAL(undoLastAction()), SLOT(undoLastAction()));
}

void MainWindow::resizeEvent(QResizeEvent *)
{
  mAdvisorsWindow->resize(width(), height());
  mEmpireWindow->resize(width(), height());
  mGameWindow->resize(width(), height());
  mMenuWindow->resize(width(), height());
  mTitleWindow->resize(width(), height());
  mUi->cSidebarWidget->resize(mSidebarWidth, height());
  mUi->cSidebarWidget->move(rect().right()-mSidebarWidth, 0);
}

void MainWindow::showAdvisorsWindow(Advisor::Type type)
{
  mCurrentAdvisor = type;
  mUi->menuBar->hide();
  mUi->cSidebarWidget->hide();
  mEmpireWindow->hide();
  mGameWindow->hide();
  mAdvisorsWindow->setActiveAdvisor(type);
  mAdvisorsWindow->show();
}

//#include "advisors/advisortypes.h"

//#include "application/application.h"

//#include "dialog/difficultydialog.h"
//#include "dialog/displayoptionsdialog.h"
//#include "dialog/filedialog.h"
//#include "dialog/messagedialog.h"
//#include "dialog/soundoptionsdialog.h"
//#include "dialog/speedoptionsdialog.h"

//#include "game/game.h"

//#include "language/language.h"
//#include "language/textdata.h"

//#include "mission/mission.h"

//#include "widget/menu.h"

//#include "window/advisorswindow.h"
//#include "window/gamewindow.h"
//#include "window/mainmenuwindow.h"
//#include "window/missionwindow.h"
//#include "window/titlewindow.h"

//#include <QDebug>
//#include <QDir>
//#include <QImage>
//#include <QKeyEvent>
//#include <QMenuBar>

//MainWindow::MainWindow(Application & application, QWidget *parent)
//  : QMainWindow(parent)
//  , mUi(new Ui::MainWindow)
//  , mApplication(application)
//  , mGameWindow(nullptr)
//  , mMainMenuWindow(nullptr)
//  , mTitleMenu(nullptr)
//{
//  mUi->setupUi(this);

//  createMenus();
//  connectActions();
//  //showTitleWindow();
//  //showMainMenuWindow();
//  showGameWindow();
//}

//MainWindow::~MainWindow()
//{
//  delete mUi;
//}

//void MainWindow::connectActions()
//{
//  // File menu
//  connect(mNewGameAction.get(), SIGNAL(triggered()), SLOT(handleMainMenu()));
//  connect(mReplayMapAction.get(), SIGNAL(triggered()), SLOT(handleReplayMap()));
//  connect(mLoadGameAction.get(), SIGNAL(triggered()), SLOT(handleLoadGame()));
//  connect(mSaveGameAction.get(), SIGNAL(triggered()), SLOT(handleSaveGame()));
//  connect(mExitGameAction.get(), SIGNAL(triggered()), SLOT(handleExitGame()));
//  if (Application::isPatched())
//    connect(mDeleteGameAction.get(), SIGNAL(triggered()), SLOT(handleDeleteGame()));

//  // Options menu
//  connect(mDisplaySettingsAction.get(), SIGNAL(triggered()), SLOT(handleDisplaySettings()));
//  connect(mSoundSettingsAction.get(), SIGNAL(triggered()), SLOT(handleSoundSettings()));
//  connect(mSpeedSettingsAction.get(), SIGNAL(triggered()), SLOT(handleSpeedSettings()));
//  connect(mAutoSaveAction.get(), SIGNAL(triggered()), SLOT(handleMonthlyAutosave()));
//  if (Application::isPatched())
//    connect(mDifficultyAction.get(), SIGNAL(triggered()), SLOT(handleDifficulty()));

//  // Help menu
//  connect(mHelpAction.get(), SIGNAL(triggered()), SLOT(handleHelp()));
//  connect(mMouseHelpAction.get(), SIGNAL(triggered()), SLOT(handleMouseHelp()));
//  connect(mWarningsAction.get(), SIGNAL(triggered()), SLOT(handleWarnings()));
//  connect(mAboutAction.get(), SIGNAL(triggered()), SLOT(handleAbout()));

//  connect(mLaborAdvisorAction.get(), SIGNAL(triggered()), SLOT(showLaborAdvisor()));
//  connect(mLegionAdvisorAction.get(), SIGNAL(triggered()), SLOT(showLegionAdvisor()));
//  connect(mEmperorAdvisorAction.get(), SIGNAL(triggered()), SLOT(showEmperorAdvisor()));
//  connect(mRatingsAdvisorAction.get(), SIGNAL(triggered()), SLOT(showRatingsAdvisor()));
//  connect(mTradeAdvisorAction.get(), SIGNAL(triggered()), SLOT(showTradeAdvisor()));
//  connect(mPopulationAdvisorAction.get(), SIGNAL(triggered()), SLOT(showPopulationAdvisor()));
//  connect(mHealthAdvisorAction.get(), SIGNAL(triggered()), SLOT(showHealthAdvisor()));
//  connect(mEducationAdvisorAction.get(), SIGNAL(triggered()), SLOT(showEducationAdvisor()));
//  connect(mEntertainmentAdvisorAction.get(), SIGNAL(triggered()), SLOT(showEntertainmentAdvisor()));
//  connect(mReligionAdvisorAction.get(), SIGNAL(triggered()), SLOT(showReligionAdvisor()));
//  connect(mFinancesAdvisorAction.get(), SIGNAL(triggered()), SLOT(showFinanceAdvisor()));
//  connect(mChiefAdvisorAction.get(), SIGNAL(triggered()), SLOT(showChiefAdvisor()));
//}

//void MainWindow::createMenus()
//{
//  const TextData * textData = Application::getLanguage()->textData();
//  bool isPatched = Application::isPatched();
//  Font font(Font::NormalBlack);

//  // File menu
//  mFileMenu.reset(new Menu(textData->getString(1, 0), this));
//  mFileMenu->setImageFont(font);
//  mNewGameAction.reset(new QAction(textData->getString(1, 1), this));
//  mReplayMapAction.reset(new QAction(textData->getString(1, 2),this));
//  mLoadGameAction.reset(new QAction(textData->getString(1, 3),this));
//  mSaveGameAction.reset(new QAction(textData->getString(1, 4),this));
//  mExitGameAction.reset(new QAction(textData->getString(1, 5),this));
//  if (isPatched)
//    mDeleteGameAction.reset(new QAction(textData->getString(1,6), this));

//  mFileMenu->addAction(mNewGameAction.get());
//  mFileMenu->addAction(mReplayMapAction.get());
//  mFileMenu->addAction(mLoadGameAction.get());
//  mFileMenu->addAction(mSaveGameAction.get());
//  if (isPatched)
//    mFileMenu->addAction(mDeleteGameAction.get());

//  mFileMenu->addAction(mExitGameAction.get());
//  menuBar()->addMenu(mFileMenu.get());

//  // Options menu
//  mOptionsMenu.reset(new Menu(textData->getString(2, 0), this));
//  mOptionsMenu->setImageFont(font);
//  mDisplaySettingsAction.reset(new QAction(textData->getString(2, 1), this));
//  mSoundSettingsAction.reset(new QAction(textData->getString(2, 2),this));
//  mSpeedSettingsAction.reset(new QAction(textData->getString(2, 3),this));
//  if (isPatched)
//    mDifficultyAction.reset(new QAction(textData->getString(2, 6),this));

//  mAutoSaveAction.reset(new QAction(textData->getString(19, 51), this));

//  mOptionsMenu->addAction(mDisplaySettingsAction.get());
//  mOptionsMenu->addAction(mSoundSettingsAction.get());
//  mOptionsMenu->addAction(mSpeedSettingsAction.get());
//  if (isPatched)
//    mOptionsMenu->addAction(mDifficultyAction.get());

//  mOptionsMenu->addAction(mAutoSaveAction.get());
//  menuBar()->addMenu(mOptionsMenu.get());

//  // Help menu
//  mHelpMenu.reset(new Menu(textData->getString(3, 0), this));
//  mHelpMenu->setImageFont(font);
//  mHelpAction.reset(new QAction(textData->getString(3, 1), this));
//  mMouseHelpAction.reset(new QAction(textData->getString(3, 4),this));
//  mWarningsAction.reset(new QAction(textData->getString(3,  5),this));
//  mAboutAction.reset(new QAction(textData->getString(3, 7),this));
//  mHelpMenu->addAction(mHelpAction.get());
//  mHelpMenu->addAction(mMouseHelpAction.get());
//  mHelpMenu->addAction(mWarningsAction.get());
//  mHelpMenu->addAction(mAboutAction.get());
//  menuBar()->addMenu(mHelpMenu.get());

//  // Advisors menu
//  mAdvisorsMenu.reset(new Menu(textData->getString(4, 0), this));
//  mAdvisorsMenu->setImageFont(font);
//  mLaborAdvisorAction.reset(new QAction(textData->getString(4, 1), this));
//  mLegionAdvisorAction.reset(new QAction(textData->getString(4, 2),this));
//  mEmperorAdvisorAction.reset(new QAction(textData->getString(4, 3),this));
//  mRatingsAdvisorAction.reset(new QAction(textData->getString(4, 4),this));
//  mTradeAdvisorAction.reset(new QAction(textData->getString(4, 5), this));
//  mPopulationAdvisorAction.reset(new QAction(textData->getString(4, 6),this));
//  mHealthAdvisorAction.reset(new QAction(textData->getString(4, 7), this));
//  mEducationAdvisorAction.reset(new QAction(textData->getString(4, 8),this));
//  mEntertainmentAdvisorAction.reset(new QAction(textData->getString(4, 9), this));
//  mReligionAdvisorAction.reset(new QAction(textData->getString(4, 10),this));
//  mFinancesAdvisorAction.reset(new QAction(textData->getString(4, 11), this));
//  mChiefAdvisorAction.reset(new QAction(textData->getString(4, 12),this));
//  mAdvisorsMenu->addAction(mLaborAdvisorAction.get());
//  mAdvisorsMenu->addAction(mLegionAdvisorAction.get());
//  mAdvisorsMenu->addAction(mEmperorAdvisorAction.get());
//  mAdvisorsMenu->addAction(mRatingsAdvisorAction.get());
//  mAdvisorsMenu->addAction(mTradeAdvisorAction.get());
//  mAdvisorsMenu->addAction(mPopulationAdvisorAction.get());
//  mAdvisorsMenu->addAction(mHealthAdvisorAction.get());
//  mAdvisorsMenu->addAction(mEducationAdvisorAction.get());
//  mAdvisorsMenu->addAction(mEntertainmentAdvisorAction.get());
//  mAdvisorsMenu->addAction(mReligionAdvisorAction.get());
//  mAdvisorsMenu->addAction(mFinancesAdvisorAction.get());
//  mAdvisorsMenu->addAction(mChiefAdvisorAction.get());
//  menuBar()->addMenu(mAdvisorsMenu.get());

//  // Update the text for menu items that can change
//  bool warnings = Application::settings().warningsEnabled();
//  bool autosave = Application::settings().monthlyAutosaveEnabled();
//  Settings::MouseHelp mouseHelp = Application::settings().mouseHelp();
//  int32_t autosaveIndex = autosave ? 51 : 52;
//  int32_t warningsIndex = warnings ? 6 : 5;
//  int32_t mouseHelpIndex = 2;
//  if (mouseHelp == Settings::Some)
//    mouseHelpIndex = 3;
//  else if (mouseHelp == Settings::All)
//    mouseHelpIndex = 4;

//  mAutoSaveAction->setText(textData->getString(19, autosaveIndex));
//  mWarningsAction->setText(textData->getString(3, warningsIndex));
//  mMouseHelpAction->setText(textData->getString(3, mouseHelpIndex));

//  mOptionsMenu->installEventFilter(this);
//  mHelpMenu->installEventFilter(this);
//}

//void MainWindow::decreaseGameSpeed()
//{
//  int gameSpeed = Application::settings().gameSpeed();
//  if (gameSpeed > 10)
//    gameSpeed -= 10;

//  Application::settings().setGameSpeed(gameSpeed);
//}

//bool MainWindow::eventFilter(QObject * object, QEvent * event)
//{
//  if (object == mOptionsMenu.get()) {
//    if (event->type() == QEvent::MouseButtonRelease) {
//      QMenu * menu = qobject_cast<QMenu*>(object);
//      QAction * action = menu->activeAction();
//      if (action == mAutoSaveAction.get()) {
//        action->trigger();
//        return true;
//      }
//    }
//  }

//  if (object == mHelpMenu.get()) {
//    QMenu * menu = qobject_cast<QMenu*>(object);
//    if (event->type() == QEvent::MouseButtonRelease) {
//      QAction * action = menu->activeAction();
//      if (action == mWarningsAction.get()) {
//        action->trigger();
//        return true;
//      }
//      if (action == mMouseHelpAction.get()) {
//        action->trigger();
//        return true;
//      }
//    }
//  }

//  return QMainWindow::eventFilter(object, event);
//}

//void MainWindow::handleAbout()
//{

//}

//void MainWindow::handleAdvisorWindowClosed()
//{
//  menuBar()->setVisible(true);
//}

//void MainWindow::handleDeleteGame()
//{
//  FileDialog dialog(this);
//  dialog.setWindowFlags(Qt::FramelessWindowHint);
//  dialog.setType(FileDialog::Delete);
//  dialog.move( (this->width() - dialog.width()) / 2, (this->height() - dialog.height()) / 2);
//  int32_t resp = dialog.exec();
//  if (resp == QDialog::Rejected) {
//    return;
//  }

//  QString fileName = dialog.fileName();
//}

//void MainWindow::handleDifficulty()
//{
//  mDifficultyDialog.reset(new DifficultyDialog(this));
//  mDifficultyDialog->setDifficulty(Application::settings().difficulty().type());
//  mDifficultyDialog->setGodsEffectsOn(Application::settings().godEffectsEnabled());
//  mDifficultyDialog->move( (this->width() - mDifficultyDialog->width()) / 2, (this->height() - mDifficultyDialog->height()) / 2);
//  connect(mDifficultyDialog.get(), SIGNAL(changed()), SLOT(handleDifficultyChanged()));
//  mDifficultyDialog->exec();
//}

//void MainWindow::handleDifficultyChanged()
//{
//  Application::settings().setDifficulty(Difficulty(mDifficultyDialog->difficulty()));
//  Application::settings().setGodEffectsEnabled(mDifficultyDialog->godsEffectsOn());
//}

//void MainWindow::handleDisplaySettings()
//{
//  mDisplayOptionsDialog.reset(new DisplayOptionsDialog(this));
//  mDisplayOptionsDialog->setFullscreen(Application::settings().fullscreen());
//  mDisplayOptionsDialog->setScreenResolution(Application::settings().screenResolution());
//  mDisplayOptionsDialog->move( (this->width() - mDisplayOptionsDialog->width()) / 2, (this->height() - mDisplayOptionsDialog->height()) / 2);
//  connect(mDisplayOptionsDialog.get(), SIGNAL(changed()), SLOT(handleDisplaySettingsChanged()));
//  mDisplayOptionsDialog->exec();
//}

//void MainWindow::handleDisplaySettingsChanged()
//{
//  bool fullScreen = Application::settings().fullscreen();
//  if (fullScreen) {
//    this->showMaximized();
//    this->showFullScreen();
//  }
//  else {
//    this->showNormal();
//    ScreenResolution resolution = Application::settings().screenResolution();
//    switch (resolution) {
//      case Resolution640x480:
//        this->resize(640, 480);
//        break;
//      case Resolution800x600:
//        this->resize(800, 600);
//        break;
//      case Resolution1024x768:
//        this->resize(1024, 768);
//        break;
//    }
//  }
//}

//void MainWindow::handleExitGame()
//{
//  MessageDialog dialog(MessageDialog::LeaveEmpire, this);
//  dialog.move( (this->width() - dialog.width()) / 2, (this->height() - dialog.height()) / 2);
//  int32_t resp = dialog.exec();
//  if (resp == QDialog::Rejected) {
//    return;
//  }

//  QApplication::exit(0);
//}

//void MainWindow::handleHelp()
//{

//}

//void MainWindow::handleLoadGame()
//{
//  FileDialog dialog(this);
//  dialog.setWindowFlags(Qt::FramelessWindowHint);
//  dialog.move( (this->width() - dialog.width()) / 2, (this->height() - dialog.height()) / 2);
//  int32_t resp = dialog.exec();
//  if (resp == QDialog::Rejected) {
//    return;
//  }

//  QString fileName = dialog.fileName();
//  QString filePath = Application::c3Dir() + QDir::separator() + fileName;
//  handleLoadGame(filePath);
//}

//void MainWindow::handleLoadGame(const QString & fileName)
//{
//  mApplication.loadGame(fileName);
//  showGameWindow();
//}

//void MainWindow::handleMainMenu()
//{
//  showMainMenuWindow();
//}

//void MainWindow::handleMonthlyAutosave()
//{
//  const TextData * textData = Application::getLanguage()->textData();
//  Application::settings().setMonthlyAutosaveEnabled(!Application::settings().monthlyAutosaveEnabled());
//  int32_t textIndex = Application::settings().monthlyAutosaveEnabled() ? 51 : 52;
//  mAutoSaveAction->setText(textData->getString(19, textIndex));
//}

//void MainWindow::handleMouseHelp()
//{
//  const TextData * textData = Application::getLanguage()->textData();

//  int32_t textIndex = 2;
//  Settings::MouseHelp mouseHelp = Application::settings().mouseHelp();
//  if (mouseHelp == Settings::None) {
//    Application::settings().setMouseHelp(Settings::Some);
//    textIndex = 3;
//  }
//  else if (mouseHelp == Settings::Some) {
//    Application::settings().setMouseHelp(Settings::All);
//    textIndex = 4;
//  }
//  else {
//    Application::settings().setMouseHelp(Settings::None);
//  }

//  mMouseHelpAction->setText(textData->getString(3, textIndex));
//}

//void MainWindow::handleReplayMap()
//{

//}

//void MainWindow::handleSaveGame()
//{
//  FileDialog dialog(this);
//  dialog.setWindowFlags(Qt::FramelessWindowHint);
//  dialog.setType(FileDialog::Save);
//  dialog.move( (this->width() - dialog.width()) / 2, (this->height() - dialog.height()) / 2);
//  int32_t resp = dialog.exec();
//  if (resp == QDialog::Rejected) {
//    return;
//  }

//  QString fileName = dialog.fileName();
//  mApplication.game()->saveToFile(fileName);
//}

//void MainWindow::handleSoundSettings()
//{
//  mSoundOptionsDialog.reset(new SoundOptionsDialog(this));
//  mSoundOptionsDialog->setCitySoundsOn(Application::settings().citySoundsEnabled());
//  mSoundOptionsDialog->setMusicOn(Application::settings().musicEnabled());
//  mSoundOptionsDialog->setSoundEffectsOn(Application::settings().soundEffectsEnabled());
//  mSoundOptionsDialog->setSpeechOn(Application::settings().speechSoundsEnabled());
//  mSoundOptionsDialog->setCitySoundsVolume(Application::settings().citySoundsVolume());
//  mSoundOptionsDialog->setMusicVolume(Application::settings().musicVolume());
//  mSoundOptionsDialog->setSoundEffectsVolume(Application::settings().speechSoundsVolume());
//  mSoundOptionsDialog->setSpeechVolume(Application::settings().speechSoundsVolume());
//  connect(mSoundOptionsDialog.get(), SIGNAL(changed()), SLOT(handleSoundSettingsChanged()));
//  mSoundOptionsDialog->move( (this->width() - mSoundOptionsDialog->width()) / 2, (this->height() - mSoundOptionsDialog->height()) / 2);

//  mSoundOptionsDialog->exec();
//}

//void MainWindow::handleSoundSettingsChanged()
//{
//  Application::settings().setCitySoundsEnabled(mSoundOptionsDialog->citySoundsOn());
//  Application::settings().setCitySoundsVolume(mSoundOptionsDialog->citySoundsVolume());
//  Application::settings().setMusicEnabled(mSoundOptionsDialog->musicVolume());
//  Application::settings().setMusicVolume(mSoundOptionsDialog->musicVolume());
//  Application::settings().setSoundEffectsEnabled(mSoundOptionsDialog->soundEffectsOn());
//  Application::settings().setSoundEffectsVolume(mSoundOptionsDialog->soundEffectsVolume());
//  Application::settings().setSpeechSoundsEnabled(mSoundOptionsDialog->speechOn());
//  Application::settings().setSpeechSoundsVolume(mSoundOptionsDialog->speechVolume());
//}

//void MainWindow::handleSpeedSettings()
//{
//  mSpeedOptionsDialog.reset(new SpeedOptionsDialog(this));
//  mSpeedOptionsDialog->setGameSpeed(Application::settings().gameSpeed());
//  mSpeedOptionsDialog->setScrollSpeed(Application::settings().scrollSpeed());
//  mSpeedOptionsDialog->move( (this->width() - mSpeedOptionsDialog->width()) / 2, (this->height() - mSpeedOptionsDialog->height()) / 2);
//  connect(mSpeedOptionsDialog.get(), SIGNAL(changed()), SLOT(handleSpeedSettingsChanged()));
//  mSpeedOptionsDialog->exec();
//}

//void MainWindow::handleSpeedSettingsChanged()
//{
//  Application::settings().setGameSpeed(mSpeedOptionsDialog->gameSpeed());
//  Application::settings().setScrollSpeed(mSpeedOptionsDialog->scrollSpeed());
//}

//void MainWindow::handleStartNewCareer(const QString & playerName)
//{
//  menuBar()->setVisible(false);
//  mApplication.startNewCareer();
//  showMissionWindow();
//}

//void MainWindow::handleWarnings()
//{
//  const TextData * textData = Application::getLanguage()->textData();
//  Application::settings().setWarningsEnabled(!Application::settings().warningsEnabled());
//  int32_t textIndex = Application::settings().warningsEnabled() ? 6 : 5;
//  mWarningsAction->setText(textData->getString(3, textIndex));
//}

//void MainWindow::increaseGameSpeed()
//{
//  int gameSpeed = Application::settings().gameSpeed();
//  if (gameSpeed < 100)
//    gameSpeed += 10;

//  Application::settings().setGameSpeed(gameSpeed);
//}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//  int32_t key = event->key();
//  switch (key)
//  {
//  case Qt::Key_1:
//    showLaborAdvisor();
//    break;
//  case Qt::Key_2:
//    showLegionAdvisor();
//    break;
//  case Qt::Key_3:
//    showEmperorAdvisor();
//    break;
//  case Qt::Key_4:
//    showRatingsAdvisor();
//    break;
//  case Qt::Key_5:
//    showTradeAdvisor();
//    break;
//  case Qt::Key_6:
//    showPopulationAdvisor();
//    break;
//  case Qt::Key_7:
//    showHealthAdvisor();
//    break;
//  case Qt::Key_8:
//    showEducationAdvisor();
//    break;
//  case Qt::Key_9:
//    showEntertainmentAdvisor();
//    break;
//  case Qt::Key_0:
//    showReligionAdvisor();
//    break;
//  case Qt::Key_hyphen:
//    showFinanceAdvisor();
//    break;
//  case Qt::Key_plusminus:
//    showChiefAdvisor();
//    break;
//  case Qt::Key_P:
//    togglePauseGame();
//    break;
//  case Qt::Key_BracketLeft:
//    decreaseGameSpeed();
//    break;
//  case Qt::Key_BracketRight:
//    increaseGameSpeed();
//    break;
//  }
//}

//void MainWindow::resizeEvent(QResizeEvent * event)
//{
//}

//void MainWindow::showAdvisorsWindow(AdvisorType advisorType)
//{
//  if (mGameWindow != nullptr) {
//    //mGameWindow->showAdvisors();
//  }
//}

//void MainWindow::showChiefAdvisor()
//{
//  showAdvisorsWindow(ChiefAdvisor);
//}

//void MainWindow::showEducationAdvisor()
//{
//  showAdvisorsWindow(EducationAdvisor);
//}

//void MainWindow::showEmperorAdvisor()
//{
//  showAdvisorsWindow(EmperorAdvisor);
//}

//void MainWindow::showEmpire()
//{

//}

//void MainWindow::showEntertainmentAdvisor()
//{
//  showAdvisorsWindow(EntertainmentAdvisor);
//}

//void MainWindow::showFinanceAdvisor()
//{
//  showAdvisorsWindow(GovernmentAdvisor);
//}

//void MainWindow::showGameWindow()
//{
//  menuBar()->setVisible(true);
//  mGameWindow = new GameWindow;
//  mGameWindow->setGame(mApplication.game());
//  setCentralWidget(mGameWindow);
//}

//void MainWindow::showHealthAdvisor()
//{
//  showAdvisorsWindow(HealthAdvisor);
//}

//void MainWindow::showLaborAdvisor()
//{
//  showAdvisorsWindow(LaborAdvisor);
//}

//void MainWindow::showLegionAdvisor()
//{
//  showAdvisorsWindow(MilitaryAdvisor);
//}

//void MainWindow::showMainMenuWindow()
//{
//  menuBar()->setVisible(false);

//  mMainMenuWindow = new MainMenuWindow;
//  connect(mMainMenuWindow, SIGNAL(startCareer(const QString &)), SLOT(handleStartNewCareer(const QString &)));
//  connect(mMainMenuWindow, SIGNAL(loadGame(const QString &)), SLOT(handleLoadGame(const QString&)));
//  setCentralWidget(mMainMenuWindow);
//}

//void MainWindow::showMessages()
//{

//}

//void MainWindow::showMission()
//{

//}

//void MainWindow::showMissionWindow()
//{
//  MissionWindow * missionWindow = new MissionWindow;
//  setCentralWidget(missionWindow);
//}

//void MainWindow::showPopulationAdvisor()
//{
//  showAdvisorsWindow(PopulationAdvisor);
//}

//void MainWindow::showRatingsAdvisor()
//{
//  showAdvisorsWindow(RatingsAdvisor);
//}

//void MainWindow::showReligionAdvisor()
//{
//  showAdvisorsWindow(ReligionAdvisor);
//}

//void MainWindow::showTradeAdvisor()
//{
//  showAdvisorsWindow(TradeAdvisor);
//}

//void MainWindow::showTitleWindow()
//{
//  menuBar()->setVisible(false);

//  mTitleMenu = new TitleWindow;
//  connect(mTitleMenu, SIGNAL(closed()), this, SLOT(handleMainMenu()));
//  setCentralWidget(mTitleMenu);
//}

//void MainWindow::togglePauseGame()
//{

//}
