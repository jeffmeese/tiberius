#ifndef SIDEBARWIDGET_H
#define SIDEBARWIDGET_H

#include <QWidget>

class Button;
class BuildMenu;
class BuildMenuItem;
namespace Ui
{
  class SidebarWidget;
};

class SidebarWidget
    : public QWidget
{
  Q_OBJECT

public:
  explicit SidebarWidget(QWidget *parent = nullptr);
  ~SidebarWidget();

public slots:
  void cancelMenu();

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

private:
  using BuildMenuPtr = std::unique_ptr<BuildMenu>;
  using BuildMenuItemPtr = std::unique_ptr<BuildMenuItem>;

private:
  void connectActions();
  void createMenus();
  void createMenuItem(BuildMenu * menu, const QString & label, int32_t price = -1);
  void init();
  void initButton(Button * button, uint32_t groupId, uint32_t offset, bool canDisable);
  void showBuildMenu(BuildMenu * menu, Button * button);
  void startBuild();

private slots:
  void handleAdvisorsButton();
  void handleBuildAcademy();
  void handleBuildActorColony();
  void handleBuildAmpitheater();
  void handleBuildAqueduct();
  void handleBuildBarber();
  void handleBuildBarracks();
  void handleBuildBaths();
  void handleBuildCalvary();
  void handleBuildChariotMaker();
  void handleBuildColosseum();
  void handleBuildDock();
  void handleBuildDoctor();
  void handleBuildEngineerPost();
  void handleBuildFarmFruit();
  void handleBuildFarmMeat();
  void handleBuildFarmOlives();
  void handleBuildFarmVegetables();
  void handleBuildFarmVines();
  void handleBuildFarmWheat();
  void handleBuildForum();
  void handleBuildFountain();
  void handleBuildGardens();
  void handleBuildGatehouse();
  void handleBuildGladiatorSchool();
  void handleBuildGovernorsHouse();
  void handleBuildGovernorsPalace();
  void handleBuildGovernorsVilla();
  void handleBuildGranary();
  void handleBuildHippodrome();
  void handleBuildHospital();
  void handleBuildHouse();
  void handleBuildJavelin();
  void handleBuildLargeCeresTemple();
  void handleBuildLargeMarsTemple();
  void handleBuildLargeMercuryTemple();
  void handleBuildLargeNeptuneTemple();
  void handleBuildLargeVenusTemple();
  void handleBuildLargeStatue();
  void handleBuildLegionnaries();
  void handleBuildLibrary();
  void handleBuildLionHouse();
  void handleBuildLowBridge();
  void handleBuildMarket();
  void handleBuildMediumStatue();
  void handleBuildOracle();
  void handleBuildPlaza();
  void handleBuildPrefecture();
  void handleBuildRawMaterialsClay();
  void handleBuildRawMaterialsIron();
  void handleBuildRawMaterialsMarble();
  void handleBuildRawMaterialsTimber();
  void handleBuildReservoir();
  void handleBuildRoad();
  void handleBuildSchool();
  void handleBuildShipBridge();
  void handleBuildShipyard();
  void handleBuildSmallCeresTemple();
  void handleBuildSmallMarsTemple();
  void handleBuildSmallMercuryTemple();
  void handleBuildSmallNeptuneTemple();
  void handleBuildSmallVenusTemple();
  void handleBuildSmallStatue();
  void handleBuildSenate();
  void handleBuildTemple();
  void handleBuildTheater();
  void handleBuildTower();
  void handleBuildWall();
  void handleBuildWarehouse();
  void handleBuildWell();
  void handleBuildWharf();
  void handleBuildWorkshopFurniture();
  void handleBuildWorkshopOil();
  void handleBuildWorkshopPottery();
  void handleBuildWorkshopWeapons();
  void handleBuildWorkshopWine();
  void handleClear();
  void handleCollapseButton();
  void handleCycleButton();
  void handleEducationButton();
  void handleEmpireButton();
  void handleEngineeringButton();
  void handleEntertainmentButton();
  void handleExpandButton();
  void handleFarmMenu();
  void handleFortMenu();
  void handleGovernmentButton();
  void handleHealthButton();
  void handleIndustryButton();
  void handleLargeTempleMenu();
  void handleMessagesButton();
  void handleMissionButton();
  void handleOrientNorthButton();
  void handleOverlaysButton();
  void handleRawMaterialsMenu();
  void handleReligionButton();
  void handleRotateLeftButton();
  void handleRotateRightButton();
  void handleSecurityButton();
  void handleSmallTempleMenu();
  void handleWaterButton();
  void handleWorkshopMenu();
  void handleUndoButton();

signals:
  void advisorsRequested();
  void empireRequested();

private:
  std::unique_ptr<Ui::SidebarWidget> mUi;
  BuildMenuPtr mEducationMenu;
  BuildMenuPtr mEngineeringMenu;
  BuildMenuPtr mEntertainmentMenu;
  BuildMenuPtr mFarmMenu;
  BuildMenuPtr mFortMenu;
  BuildMenuPtr mGovernmentMenu;
  BuildMenuPtr mHealthMenu;
  BuildMenuPtr mIndustryMenu;
  BuildMenuPtr mLargeTempleMenu;
  BuildMenuPtr mRawMaterialsMenu;
  BuildMenuPtr mReligionMenu;
  BuildMenuPtr mSecurityMenu;
  BuildMenuPtr mSmallTempleMenu;
  BuildMenuPtr mWaterMenu;
  BuildMenuPtr mWorkshopMenu;
};

#endif // SIDEBARWIDGET_H


//#include <QWidget>
//#include <QSoundEffect>

//class Button;
//class BuildMenu;
//class BuildMenuItem;

//namespace Ui
//{
//  class Sidebar;
//};

//class Sidebar
//    : public QWidget
//{
//  Q_OBJECT

//public:
//  explicit Sidebar(QWidget *parent = nullptr);
//  ~Sidebar();

//public slots:
//  void cancelMenu();
//  void collapse();
//  void expand();

//protected:
//  void mousePressEvent(QMouseEvent *event) override;

//private:
//  typedef std::unique_ptr<Button> ButtonPtr;
//  typedef std::unique_ptr<BuildMenu> BuildMenuPtr;
//  typedef std::unique_ptr<BuildMenuItem> BuildMenuItemPtr;

//private:
//  void connectActions();
//  void createMenus();
//  void createMenuItem(BuildMenu * menu, const QString & label, int32_t price = -1);
//  void initUi();
//  void initButton(Button * button, uint32_t baseId, uint32_t offset, bool canDisable);
//  void playClickSound();
//  void startBuild();
//  void showBuildMenu(BuildMenu * menu, Button * button);

//private slots:
//  void handleAdvisorsButton();
//  void handleClearButton();
//  void handleCollapseButton();
//  void handleCycleButton();
//  void handleEducationButton();
//  void handleEmpireButton();
//  void handleEngineeringButton();
//  void handleEntertainmentButton();
//  void handleExpandButton();
//  void handleGovernmentButton();
//  void handleHealthButton();
//  void handleHouseButton();
//  void handleIndustryButton();
//  void handleMessagesButton();
//  void handleMissionButton();
//  void handleOrientNorthButton();
//  void handleOverlaysButton();
//  void handleReligionButton();
//  void handleRoadButton();
//  void handleRotateLeftButton();
//  void handleRotateRightButton();
//  void handleSecurityButton();
//  void handleWaterButton();
//  void handleUndoButton();

//signals:
//  void collapsed();
//  void expanded();
//  void orientNorth();
//  void rotateLeft();
//  void rotateRight();
//  void showAdvisors();
//  void showEmpire();
//  void showMessages();
//  void showMission();
//  void undoLastAction();

//private:
//  Ui::Sidebar * mUi;
//  bool mCollapsed;

//  BuildMenuPtr mEducationMenu;
//  BuildMenuPtr mEngineeringMenu;
//  BuildMenuPtr mEntertainmentMenu;
//  BuildMenuPtr mFarmMenu;
//  BuildMenuPtr mFortMenu;
//  BuildMenuPtr mGovernmentMenu;
//  BuildMenuPtr mHealthMenu;
//  BuildMenuPtr mIndustryMenu;
//  BuildMenuPtr mLargeTempleMenu;
//  BuildMenuPtr mRawMaterialsMenu;
//  BuildMenuPtr mReligionMenu;
//  BuildMenuPtr mSecurityMenu;
//  BuildMenuPtr mSmallTempleMenu;
//  BuildMenuPtr mWaterMenu;
//  BuildMenuPtr mWorkshopMenu;
//  QSoundEffect mClickSound;

////  ButtonPtr mAqueductButton;
////  ButtonPtr mFountainButton;
////  ButtonPtr mReservoirButton;
////  ButtonPtr mWellButton;
////  ButtonPtr mDoctorButton;
////  ButtonPtr mBarberButton;
////  ButtonPtr mBathsButton;
////  ButtonPtr mHospitalButton;
////  ButtonPtr mSmallTempleButton;
////  ButtonPtr mSmallCeresTempleButton;
////  ButtonPtr mSmallNeptuneTempleButton;
////  ButtonPtr mSmallMercuryTempleButton;
////  ButtonPtr mSmallMarsTempleButton;
////  ButtonPtr mSmallVenusTempleButton;
////  ButtonPtr mLargeTempleButton;
////  ButtonPtr mLargeCeresTempleButton;
////  ButtonPtr mLargeNeptuneTempleButton;
////  ButtonPtr mLargeMercuryTempleButton;
////  ButtonPtr mLargeMarsTempleButton;
////  ButtonPtr mLargeVenusTempleButton;
////  ButtonPtr mOracleButton;
////  ButtonPtr mLibraryButton;
////  ButtonPtr mSchoolButton;
////  ButtonPtr mAcademyButton;
////  ButtonPtr mTheaterButton;
////  ButtonPtr mAmpitheaterButton;
////  ButtonPtr mColosseumButton;
////  ButtonPtr mGladiatorSchoolButton;
////  ButtonPtr mLionHouseButton;
////  ButtonPtr mActorColonyButton;
////  ButtonPtr mChariotMakerButton;
////  ButtonPtr mHippodromeButton;
////  ButtonPtr mForumButton;
////  ButtonPtr mSenateButton;
////  ButtonPtr mGovernorsHouseButton;
////  ButtonPtr mGovernorsVillaButton;
////  ButtonPtr mGovernorsPalaceButton;
////  ButtonPtr mSmallStatueButton;
////  ButtonPtr mMediumStatueButton;
////  ButtonPtr mLargeStatueButton;
////  ButtonPtr mGardensButton;
////  ButtonPtr mPlazaButton;
////  ButtonPtr mEngineerButton;
////  ButtonPtr mLowBridgeButton;
////  ButtonPtr mShipBridgeButton;
////  ButtonPtr mShipyardButton;
////  ButtonPtr mWharfButton;
////  ButtonPtr mDockButton;
////  ButtonPtr mPrefectButton;
////  ButtonPtr mFortButton;
////  ButtonPtr mWallButton;
////  ButtonPtr mTowerButton;
////  ButtonPtr mGatehouseButton;
////  ButtonPtr mFarmButton;
////  ButtonPtr mWheatFarmButton;
////  ButtonPtr mFruitFarmButton;
////  ButtonPtr mVegetableFarmButton;
////  ButtonPtr mPigFarmButton;
////  ButtonPtr mRawMaterialsButton;
////  ButtonPtr mClayButton;
////  ButtonPtr mTimerButton;
////  ButtonPtr mIronMineButton;
////  ButtonPtr mMarbleButton;
////  ButtonPtr mWorkshopButton;
////  ButtonPtr mPotteryWorkshopButton;
////  ButtonPtr mFurnitureWorkshopButton;
////  ButtonPtr mOilWorkshopButton;
////  ButtonPtr mWineWorkshopButton;
////  ButtonPtr mMarketButton;
////  ButtonPtr mGranaryButton;
////  ButtonPtr mWarehouseButton;
//};

//#endif // SIDEBAR_H
