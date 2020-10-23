#include "sidebarwidget.h"
#include "ui_sidebarwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QPainter>

static const int BUTTON_WIDTH = 240;
static const int BUTTON_HEIGHT = 20;

SidebarWidget::SidebarWidget(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::SidebarWidget)
{
  init();
}

SidebarWidget::~SidebarWidget()
{
}

void SidebarWidget::init()
{
  mUi->setupUi(this);

  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t buildImageId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);
  uint32_t panelImageId = imageData->getGroupBaseImageId(GROUP_SIDE_PANEL);

  mUi->cOutline->setAutoFillBackground(false);
  mUi->cOutline->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+1)->createImage()));
  mUi->cPanelImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+4)->createImage()));
  mUi->cPanelImage2->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+4)->createImage()));
  mUi->cBuildImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(buildImageId+12)->createImage()));

  mUi->cOverlay->setText(stringData->getString(6, 4));
  initButton(mUi->cOverlay, 93, 0, false);
  //initButton(mUi->cCollapse, 90, 0, true);
  initButton(mUi->cExpand, 90, 4, true);

  initButton(mUi->cAdvisors, GROUP_SIDEBAR_ADVISORS_EMPIRE, 0, false);
  initButton(mUi->cEmpire,   GROUP_SIDEBAR_ADVISORS_EMPIRE, 3, false);

  initButton(mUi->cMission,     GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 0, false);
  initButton(mUi->cRotateNorth, GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 3, false);
  initButton(mUi->cRotateRight, GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 6, false);
  initButton(mUi->cRotateLeft,  GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 9, false);

  initButton(mUi->cHouse,          GROUP_SIDEBAR_BUTTONS, 0, true);
  initButton(mUi->cClear,          GROUP_SIDEBAR_BUTTONS, 8, true);
  initButton(mUi->cRoad,           GROUP_SIDEBAR_BUTTONS, 12, true);
  initButton(mUi->cWater,          GROUP_SIDEBAR_BUTTONS, 4, true);
  initButton(mUi->cHealth,         GROUP_SIDEBAR_BUTTONS, 40, true);
  initButton(mUi->cReligion,       GROUP_SIDEBAR_BUTTONS, 28, true);
  initButton(mUi->cEducation,      GROUP_SIDEBAR_BUTTONS, 24, true);
  initButton(mUi->cEntertainment,  GROUP_SIDEBAR_BUTTONS, 20, true);
  initButton(mUi->cGovernment,     GROUP_SIDEBAR_BUTTONS, 16, true);
  initButton(mUi->cEngineering,    GROUP_SIDEBAR_BUTTONS, 44, true);
  initButton(mUi->cSecurity,       GROUP_SIDEBAR_BUTTONS, 36, true);
  initButton(mUi->cIndustry,       GROUP_SIDEBAR_BUTTONS, 32, true);
  initButton(mUi->cUndo,           GROUP_SIDEBAR_BUTTONS, 48, true);
  initButton(mUi->cMessages,       GROUP_MESSAGE_ICON, 18, true);
  initButton(mUi->cCycle,          GROUP_MESSAGE_ICON, 22, true);

  connect(mUi->cAdvisors, SIGNAL(clicked()), SIGNAL(advisorsRequested()));
}

void SidebarWidget::initButton(Button *button, uint32_t groupId, uint32_t offset, bool canDisable)
{
  const SgImageData * imageData = Application::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(groupId);

  button->setImage(imageData->getImageRecord(baseId+offset)->createImage());
  button->setHoverImage(imageData->getImageRecord(baseId+offset+1)->createImage());
  button->setPressedImage(imageData->getImageRecord(baseId+offset+2)->createImage());
  if (canDisable)
    button->setDisabledImage(imageData->getImageRecord(baseId+offset+3)->createImage());
}

void SidebarWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::lightGray));
}

//#include "sidebar.h"
//#include "ui_sidebar.h"

//#include "application/application.h"

//#include "graphics/imagedata.h"
//#include "graphics/imagegroups.h"
//#include "graphics/imageset.h"
//#include "graphics/sgimagedata.h"
//#include "graphics/sgimagerecord.h"

//#include "language/language.h"
//#include "language/textdata.h"

//#include "widget/buildmenu.h"
//#include "widget/buildmenuitem.h"
//#include "widget/button.h"
//#include "widget/minimap.h"

//#include <QDebug>
//#include <QDir>
//#include <QImage>
//#include <QMouseEvent>
//#include <QPainter>
//#include <QSound>
//#include <QSoundEffect>

//static const int32_t BUTTON_WIDTH = 240;
//static const int32_t BUTTON_HEIGHT = 20;

//Sidebar::Sidebar(QWidget *parent)
//  : QWidget(parent)
//  , mUi(new Ui::Sidebar)
//  , mCollapsed(false)
//{
//  initUi();
//  createMenus();
//  connectActions();
//}

//Sidebar::~Sidebar()
//{
//  delete mUi;
//}

//void Sidebar::cancelMenu()
//{
//  mUi->cWater->setDown(false);
//  mUi->cHealth->setDown(false);
//  mUi->cReligion->setDown(false);
//  mUi->cEducation->setDown(false);
//  mUi->cEntertainment->setDown(false);
//  mUi->cGovernment->setDown(false);
//  mUi->cEngineering->setDown(false);
//  mUi->cSecurity->setDown(false);
//  mUi->cIndustry->setDown(false);

//  mEducationMenu->setVisible(false);
//  mEngineeringMenu->setVisible(false);
//  mEntertainmentMenu->setVisible(false);
//  mFarmMenu->setVisible(false);
//  mFortMenu->setVisible(false);
//  mGovernmentMenu->setVisible(false);
//  mHealthMenu->setVisible(false);
//  mIndustryMenu->setVisible(false);
//  mLargeTempleMenu->setVisible(false);
//  mRawMaterialsMenu->setVisible(false);
//  mReligionMenu->setVisible(false);
//  mSecurityMenu->setVisible(false);
//  mSmallTempleMenu->setVisible(false);
//  mWaterMenu->setVisible(false);
//  mWorkshopMenu->setVisible(false);

//  mUi->cAdvisors->setEnabled(true);
//  mUi->cEmpire->setEnabled(true);
//  mUi->cRotateNorth->setEnabled(true);
//  mUi->cRotateLeft->setEnabled(true);
//  mUi->cRotateRight->setEnabled(true);
//  mUi->cMission->setEnabled(true);
//}

//void Sidebar::collapse()
//{
//}

//void Sidebar::connectActions()
//{
//  connect(mUi->cAdvisors, SIGNAL(clicked()), SLOT(handleAdvisorsButton()));
//  connect(mUi->cEmpire, SIGNAL(clicked()), SLOT(handleEmpireButton()));
//  connect(mUi->cMission, SIGNAL(clicked()), SLOT(handleMissionButton()));
//  connect(mUi->cRotateNorth, SIGNAL(clicked()), SLOT(handleOrientNorthButton()));
//  connect(mUi->cRotateLeft, SIGNAL(clicked()), SLOT(handleRotateLeftButton()));
//  connect(mUi->cRotateRight, SIGNAL(clicked()), SLOT(handleRotateRightButton()));
//  connect(mUi->cHouse, SIGNAL(clicked()), SLOT(handleHouseButton()));
//  connect(mUi->cClear, SIGNAL(clicked()), SLOT(handleClearButton()));
//  connect(mUi->cRoad, SIGNAL(clicked()), SLOT(handleRoadButton()));
//  connect(mUi->cWater, SIGNAL(clicked()), SLOT(handleWaterButton()));
//  connect(mUi->cHealth, SIGNAL(clicked()), SLOT(handleHealthButton()));
//  connect(mUi->cReligion, SIGNAL(clicked()), SLOT(handleReligionButton()));
//  connect(mUi->cEducation, SIGNAL(clicked()), SLOT(handleEducationButton()));
//  connect(mUi->cEntertainment, SIGNAL(clicked()), SLOT(handleEntertainmentButton()));
//  connect(mUi->cGovernment, SIGNAL(clicked()), SLOT(handleGovernmentButton()));
//  connect(mUi->cEngineering, SIGNAL(clicked()), SLOT(handleEngineeringButton()));
//  connect(mUi->cSecurity, SIGNAL(clicked()), SLOT(handleSecurityButton()));
//  connect(mUi->cIndustry, SIGNAL(clicked()), SLOT(handleIndustryButton()));
//  connect(mUi->cUndo, SIGNAL(clicked()), SLOT(handleUndoButton()));
//  connect(mUi->cMessages, SIGNAL(clicked()), SLOT(handleMessagesButton()));
//  connect(mUi->cCycle, SIGNAL(clicked()), SLOT(handleCycleButton()));
//  connect(mUi->cCollapse, SIGNAL(clicked()), SLOT(handleCollapseButton()));
//  connect(mUi->cExpand, SIGNAL(clicked()), SLOT(handleExpandButton()));
//  connect(mUi->cOverlay, SIGNAL(clicked()), SLOT(handleOverlaysButton()));
//}

//void Sidebar::createMenus()
//{
//  // TODO: Need to read prices from model data

//  const TextData * textData = Application::getLanguage()->textData();

//  int32_t menuWidth = 240;
//  int32_t menuHeight = 240;

//  mWaterMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mWaterMenu.get(), textData->getString(28, 90), 80);      // Reservoir
//  createMenuItem(mWaterMenu.get(), textData->getString(28, 8), 8);        // Aqueduct
//  createMenuItem(mWaterMenu.get(), textData->getString(28, 91), 15);      // Fountain
//  createMenuItem(mWaterMenu.get(), textData->getString(28, 92), 5);       // Well
//  mWaterMenu->setVisible(false);
//  mWaterMenu->resize(menuWidth, menuHeight);

//  mHealthMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mHealthMenu.get(), textData->getString(28, 49), 25);     // Barber
//  createMenuItem(mHealthMenu.get(), textData->getString(28, 48), 50);     // Baths
//  createMenuItem(mHealthMenu.get(), textData->getString(28, 46), 30);     // Doctor
//  createMenuItem(mHealthMenu.get(), textData->getString(28, 47), 300);    // Hospital
//  mHealthMenu->setVisible(false);
//  mHealthMenu->resize(menuWidth, menuHeight);

//  mReligionMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mReligionMenu.get(), textData->getString(28, 96), -1);   // Small temple
//  createMenuItem(mReligionMenu.get(), textData->getString(28, 97), -1);   // Large temple
//  createMenuItem(mReligionMenu.get(), textData->getString(28, 98), 200);  // Oracle
//  mReligionMenu->setVisible(false);
//  mReligionMenu->resize(menuWidth, menuHeight);

//  mEducationMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mEducationMenu.get(), textData->getString(28, 51), 50);   // School
//  createMenuItem(mEducationMenu.get(), textData->getString(28, 52), 100);  // Academy
//  createMenuItem(mEducationMenu.get(), textData->getString(28, 53), 75);   // Library
//  mEducationMenu->setVisible(false);
//  mEducationMenu->resize(menuWidth, menuHeight);

//  mEntertainmentMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 31), 50);   // Theater
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 30), 100);  // Ampitheater
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 33), 500);  // Colosseum
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 34), 75);   // Gladiator School
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 35), 75);   // Lion House
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 36), 50);   // Actor Colony
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 32), 75);   // Chariot Maker
//  createMenuItem(mEntertainmentMenu.get(), textData->getString(28, 37), 2500); // Hippodrome
//  mEntertainmentMenu->setVisible(false);
//  mEntertainmentMenu->resize(menuWidth, menuHeight);

//  mGovernmentMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 86), 75);   // Forum
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 85), 400);  // Senate
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 77), 150);  // Gov house
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 78), 400);  // Gov villa
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 79), 700);  // Gov palace
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 41), 12);   // Small statue
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 42), 60);   // Medium statue
//  createMenuItem(mGovernmentMenu.get(), textData->getString(28, 43), 150);  // Large statue
//  mGovernmentMenu->setVisible(false);
//  mGovernmentMenu->resize(menuWidth, menuHeight);

//  mEngineeringMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 39), 12);   // Gardens
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 38), 15);   // Plaza
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 81), 30);   // Engineer Post
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 82), 40);   // Low bridge
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 83), 100);  // Ship Bridge
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 75), 100);  // Dock
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 74), 100);  // Shipyard
//  createMenuItem(mEngineeringMenu.get(), textData->getString(28, 76), 60);   // Wharf
//  mEngineeringMenu->setVisible(false);
//  mEngineeringMenu->resize(menuWidth, menuHeight);

//  mSecurityMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mSecurityMenu.get(), textData->getString(28, 55), 30);      // Prefect
//  createMenuItem(mSecurityMenu.get(), textData->getString(28, 6), 12);       // Wall
//  createMenuItem(mSecurityMenu.get(), textData->getString(28, 59), 150);     // Tower
//  createMenuItem(mSecurityMenu.get(), textData->getString(28, 58), 100);     // Gatehouse
//  createMenuItem(mSecurityMenu.get(), textData->getString(28, 57), -1);      // Fort
//  mSecurityMenu->setVisible(false);
//  mSecurityMenu->resize(menuWidth, menuHeight);

//  mIndustryMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 2), -1);      // Farm
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 3), -1);      // Raw Materials
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 4), -1);      // Workshop
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 70), 40);     // Market
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 71), 100);    // Granary
//  createMenuItem(mIndustryMenu.get(), textData->getString(28, 72), 70);     // Warehouse
//  mIndustryMenu->setVisible(false);
//  mIndustryMenu->resize(menuWidth, menuHeight);

//  mSmallTempleMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mSmallTempleMenu.get(), textData->getString(28, 60), 50);     // Ceres
//  createMenuItem(mSmallTempleMenu.get(), textData->getString(28, 61), 50);     // Neptune
//  createMenuItem(mSmallTempleMenu.get(), textData->getString(28, 62), 50);     // Mercury
//  createMenuItem(mSmallTempleMenu.get(), textData->getString(28, 63), 50);     // Mars
//  createMenuItem(mSmallTempleMenu.get(), textData->getString(28, 64), 50);     // Venus
//  mSmallTempleMenu->setVisible(false);
//  mSmallTempleMenu->resize(menuWidth, menuHeight);

//  mLargeTempleMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mLargeTempleMenu.get(), textData->getString(28, 60), 150);     // Ceres
//  createMenuItem(mLargeTempleMenu.get(), textData->getString(28, 61), 150);     // Neptune
//  createMenuItem(mLargeTempleMenu.get(), textData->getString(28, 62), 150);     // Mercury
//  createMenuItem(mLargeTempleMenu.get(), textData->getString(28, 63), 150);     // Mars
//  createMenuItem(mLargeTempleMenu.get(), textData->getString(28, 64), 150);     // Venus
//  mLargeTempleMenu->setVisible(false);
//  mLargeTempleMenu->resize(menuWidth, menuHeight);

//  mFortMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mFortMenu.get(), textData->getString(28, 40), 1000);     // Legionaries
//  createMenuItem(mFortMenu.get(), textData->getString(28, 44), 1000);     // Javelin
//  createMenuItem(mFortMenu.get(), textData->getString(28, 45), 1000);     // Cavalry
//  mFortMenu->setVisible(false);
//  mFortMenu->resize(menuWidth, menuHeight);

//  mRawMaterialsMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mRawMaterialsMenu.get(), textData->getString(28, 109), 40);     // Clay
//  createMenuItem(mRawMaterialsMenu.get(), textData->getString(28, 108), 40);     // Timber
//  createMenuItem(mRawMaterialsMenu.get(), textData->getString(28, 107), 50);     // Iron
//  createMenuItem(mRawMaterialsMenu.get(), textData->getString(28, 106), 50);     // Marble
//  mRawMaterialsMenu->setVisible(false);
//  mRawMaterialsMenu->resize(menuWidth, menuHeight);

//  mWorkshopMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mWorkshopMenu.get(), textData->getString(28, 114), 40);     // Pottery
//  createMenuItem(mWorkshopMenu.get(), textData->getString(28, 113), 40);     // Furniture
//  createMenuItem(mWorkshopMenu.get(), textData->getString(28, 112), 50);     // Weapons
//  createMenuItem(mWorkshopMenu.get(), textData->getString(28, 111), 50);     // Oil
//  createMenuItem(mWorkshopMenu.get(), textData->getString(28, 110), 45);     // Wine
//  mWorkshopMenu->setVisible(false);
//  mWorkshopMenu->resize(menuWidth, menuHeight);

//  mFarmMenu.reset(new BuildMenu(parentWidget()));
//  createMenuItem(mFarmMenu.get(), textData->getString(28, 100), 40);     // Wheat
//  createMenuItem(mFarmMenu.get(), textData->getString(28, 102), 40);     // Fruit
//  createMenuItem(mFarmMenu.get(), textData->getString(28, 103), 40);     // Vegetables
//  createMenuItem(mFarmMenu.get(), textData->getString(28, 105), 40);     // Pigs
//  createMenuItem(mFarmMenu.get(), textData->getString(28, 104), 40);     // Vines
//  mFarmMenu->setVisible(false);
//  mFarmMenu->resize(menuWidth, menuHeight);
//}

//void Sidebar::createMenuItem(BuildMenu * menu, const QString & label, int32_t price)
//{
//  BuildMenuItemPtr menuItem(new BuildMenuItem(menu));

//  const TextData * textData = Application::getLanguage()->textData();
//  const SgImageData * imageData = Application::getImageData()->getImageSet(Application::getClimateImageFile())->imageData();
//  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);
//  QString dnText = textData->getString(6, 0);

//  menuItem->setText(label);
//  menuItem->setPrice(price);
//  menuItem->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
//  menuItem->setImageFont(Font::NormalGreen);

//  QImage normalImage(BUTTON_WIDTH, BUTTON_HEIGHT, QImage::Format_ARGB32);
//  QImage focusedImage(BUTTON_WIDTH, BUTTON_HEIGHT, QImage::Format_ARGB32);
//  QPainter normalPainter(&normalImage);
//  QPainter focusPainter(&focusedImage);

//  int32_t blocks = BUTTON_WIDTH / 16;
//  for (int32_t i = 0; i < blocks; i++) {
//    uint32_t normalImageId = baseImageId + 47;
//    uint32_t focusImageId = baseImageId + 44;
//    if (i == 0) {
//      normalImageId = baseImageId + 46;
//      focusImageId = baseImageId + 43;
//    }
//    if (i == blocks-1) {
//      normalImageId = baseImageId + 48;
//      focusImageId = baseImageId + 45;
//    }

//    normalPainter.drawImage(i*16, 0, imageData->getImageRecord(normalImageId)->createImage());
//    focusPainter.drawImage(i*16, 0, imageData->getImageRecord(focusImageId)->createImage());
//  }

//  menuItem->setStandardImage(normalImage);
//  menuItem->setFocusedImage(focusedImage);

//  menu->addItem(std::move(menuItem));
//}

//void Sidebar::expand()
//{

//}

//void Sidebar::handleAdvisorsButton()
//{
//  cancelMenu();
//  playClickSound();
//}

//void Sidebar::handleClearButton()
//{
//  cancelMenu();
//  playClickSound();
//}

//void Sidebar::handleCollapseButton()
//{
//  cancelMenu();
//  playClickSound();
//}

//void Sidebar::handleCycleButton()
//{
//  cancelMenu();
//  playClickSound();
//}

//void Sidebar::handleEducationButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mEducationMenu.get(), mUi->cEducation);
//}

//void Sidebar::handleEmpireButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleEngineeringButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mEngineeringMenu.get(), mUi->cEngineering);
//}

//void Sidebar::handleEntertainmentButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mEntertainmentMenu.get(), mUi->cEntertainment);
//}

//void Sidebar::handleExpandButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleGovernmentButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mGovernmentMenu.get(), mUi->cGovernment);
//}

//void Sidebar::handleHealthButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mHealthMenu.get(), mUi->cHealth);
//}

//void Sidebar::handleHouseButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleIndustryButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mIndustryMenu.get(), mUi->cIndustry);
//}

//void Sidebar::handleMessagesButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleMissionButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleOrientNorthButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleOverlaysButton()
//{
//  playClickSound();
//  cancelMenu();
//  mUi->cOverlay->setDown(true);
//}

//void Sidebar::handleReligionButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mReligionMenu.get(), mUi->cReligion);
//}

//void Sidebar::handleRoadButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleRotateLeftButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleRotateRightButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::handleSecurityButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mSecurityMenu.get(), mUi->cSecurity);
//}

//void Sidebar::showBuildMenu(BuildMenu *menu, Button * button)
//{
//  QRect rect(this->rect());
//  QPoint pt = this->mapToParent(rect.topLeft());
//  int32_t xOffset = pt.x() - BUTTON_WIDTH - 10;
//  int32_t yOffset = height()/2;
//  menu->move(xOffset, yOffset);
//  menu->setVisible(true);
//  button->setDown(true);
//}

//void Sidebar::handleWaterButton()
//{
//  playClickSound();
//  cancelMenu();
//  startBuild();
//  showBuildMenu(mWaterMenu.get(), mUi->cWater);
//}

//void Sidebar::handleUndoButton()
//{
//  playClickSound();
//  cancelMenu();
//}

//void Sidebar::initUi()
//{
//  const TextData * textData = Application::getLanguage()->textData();
//  const SgImageData * imageData = Application::getImageData()->getImageSet(Application::getClimateImageFile())->imageData();
//  uint32_t buildImageId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);
//  uint32_t panelImageId = imageData->getGroupBaseImageId(GROUP_SIDE_PANEL);

//  mUi->setupUi(this);

//  mUi->cOutline->setAutoFillBackground(false);
//  mUi->cOutline->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+1)->createImage()));
//  mUi->cPanelImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+4)->createImage()));
//  mUi->cPanelImage2->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelImageId+4)->createImage()));
//  mUi->cBuildImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(buildImageId+12)->createImage()));

//  mUi->cOverlay->setText(textData->getString(6, 4));
//  initButton(mUi->cOverlay, 93, 0, false);
//  initButton(mUi->cCollapse, 90, 0, true);
//  initButton(mUi->cExpand, 90, 4, true);

//  initButton(mUi->cAdvisors, GROUP_SIDEBAR_ADVISORS_EMPIRE, 0, false);
//  initButton(mUi->cEmpire,   GROUP_SIDEBAR_ADVISORS_EMPIRE, 3, false);

//  initButton(mUi->cMission,     GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 0, false);
//  initButton(mUi->cRotateNorth, GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 3, false);
//  initButton(mUi->cRotateRight, GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 6, false);
//  initButton(mUi->cRotateLeft,  GROUP_SIDEBAR_BRIEFING_ROTATE_BUTTONS, 9, false);

//  initButton(mUi->cHouse,          GROUP_SIDEBAR_BUTTONS, 0, true);
//  initButton(mUi->cClear,          GROUP_SIDEBAR_BUTTONS, 8, true);
//  initButton(mUi->cRoad,           GROUP_SIDEBAR_BUTTONS, 12, true);
//  initButton(mUi->cWater,          GROUP_SIDEBAR_BUTTONS, 4, true);
//  initButton(mUi->cHealth,         GROUP_SIDEBAR_BUTTONS, 40, true);
//  initButton(mUi->cReligion,       GROUP_SIDEBAR_BUTTONS, 28, true);
//  initButton(mUi->cEducation,      GROUP_SIDEBAR_BUTTONS, 24, true);
//  initButton(mUi->cEntertainment,  GROUP_SIDEBAR_BUTTONS, 20, true);
//  initButton(mUi->cGovernment,     GROUP_SIDEBAR_BUTTONS, 16, true);
//  initButton(mUi->cEngineering,    GROUP_SIDEBAR_BUTTONS, 44, true);
//  initButton(mUi->cSecurity,       GROUP_SIDEBAR_BUTTONS, 36, true);
//  initButton(mUi->cIndustry,       GROUP_SIDEBAR_BUTTONS, 32, true);
//  initButton(mUi->cUndo,           GROUP_SIDEBAR_BUTTONS, 48, true);
//  initButton(mUi->cMessages,       GROUP_MESSAGE_ICON, 18, true);
//  initButton(mUi->cCycle,          GROUP_MESSAGE_ICON, 22, true);

//  mUi->cUndo->setEnabled(false);
//  mUi->cMessages->setEnabled(false);
//  mUi->cCycle->setEnabled(false);
//  mUi->cExpand->setVisible(false);

//  QString c3Dir = Application::c3Dir();
//  QString wavDir = c3Dir + QDir::separator() + "wavs";
//  QString fileName = wavDir + QDir::separator() + "ICON1.WAV";

//  mClickSound.setSource(QUrl::fromLocalFile(fileName));
//  mClickSound.setLoopCount(1);
//}

//void Sidebar::initButton(Button * button, uint32_t groupId, uint32_t offset, bool canDisable)
//{
//  const SgImageData * imageData = Application::getImageData()->getImageSet(Application::getClimateImageFile())->imageData();
//  uint32_t baseId = imageData->getGroupBaseImageId(groupId);

//  button->setStandardImage(imageData->getImageRecord(baseId+offset)->createImage());
//  button->setFocusedImage(imageData->getImageRecord(baseId+offset+1)->createImage());
//  button->setPressedImage(imageData->getImageRecord(baseId+offset+2)->createImage());
//  if (canDisable)
//    button->setDisabledImage(imageData->getImageRecord(baseId+offset+3)->createImage());
//}

//void Sidebar::mousePressEvent(QMouseEvent *event)
//{
//  if (event->button() == Qt::RightButton) {
//    cancelMenu();
//  }
//}

//void Sidebar::playClickSound()
//{
//  float soundVolume = Application::settings().soundEffectsVolume();
//  mClickSound.setVolume(soundVolume/100);
//  mClickSound.play();
//}

//void Sidebar::startBuild()
//{
//  mUi->cAdvisors->setEnabled(false);
//  mUi->cEmpire->setEnabled(false);
//  mUi->cRotateNorth->setEnabled(false);
//  mUi->cRotateLeft->setEnabled(false);
//  mUi->cRotateRight->setEnabled(false);
//  mUi->cMission->setEnabled(false);
//}

