#include "sidebarwidget.h"
#include "ui_sidebarwidget.h"

#include "application/application.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "widget/buildmenu.h"
#include "widget/buildmenuitem.h"

#include <QDebug>
#include <QMouseEvent>
#include <QPainter>

static const int BUTTON_WIDTH = 270;
static const int BUTTON_HEIGHT = 20;

SidebarWidget::SidebarWidget(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::SidebarWidget)
{
  init();
  createMenus();
  connectActions();
}

SidebarWidget::~SidebarWidget()
{
}

void SidebarWidget::cancelMenu()
{
  mUi->cWater->setDown(false);
  mUi->cHealth->setDown(false);
  mUi->cReligion->setDown(false);
  mUi->cEducation->setDown(false);
  mUi->cEntertainment->setDown(false);
  mUi->cGovernment->setDown(false);
  mUi->cEngineering->setDown(false);
  mUi->cSecurity->setDown(false);
  mUi->cIndustry->setDown(false);

  mEducationMenu->setVisible(false);
  mEngineeringMenu->setVisible(false);
  mEntertainmentMenu->setVisible(false);
  mFarmMenu->setVisible(false);
  mFortMenu->setVisible(false);
  mGovernmentMenu->setVisible(false);
  mHealthMenu->setVisible(false);
  mIndustryMenu->setVisible(false);
  mLargeTempleMenu->setVisible(false);
  mRawMaterialsMenu->setVisible(false);
  mReligionMenu->setVisible(false);
  mSecurityMenu->setVisible(false);
  mSmallTempleMenu->setVisible(false);
  mWaterMenu->setVisible(false);
  mWorkshopMenu->setVisible(false);

  mUi->cAdvisors->setEnabled(true);
  mUi->cEmpire->setEnabled(true);
  mUi->cRotateNorth->setEnabled(true);
  mUi->cRotateLeft->setEnabled(true);
  mUi->cRotateRight->setEnabled(true);
  mUi->cMission->setEnabled(true);
}

void SidebarWidget::connectActions()
{
  connect(mUi->cAdvisors, SIGNAL(clicked()), SLOT(handleAdvisorsButton()));
  connect(mUi->cEmpire, SIGNAL(clicked()), SLOT(handleEmpireButton()));
  connect(mUi->cMission, SIGNAL(clicked()), SLOT(handleMissionButton()));
  connect(mUi->cRotateNorth, SIGNAL(clicked()), SLOT(handleOrientNorthButton()));
  connect(mUi->cRotateLeft, SIGNAL(clicked()), SLOT(handleRotateLeftButton()));
  connect(mUi->cRotateRight, SIGNAL(clicked()), SLOT(handleRotateRightButton()));
  connect(mUi->cWater, SIGNAL(clicked()), SLOT(handleWaterButton()));
  connect(mUi->cHealth, SIGNAL(clicked()), SLOT(handleHealthButton()));
  connect(mUi->cReligion, SIGNAL(clicked()), SLOT(handleReligionButton()));
  connect(mUi->cEducation, SIGNAL(clicked()), SLOT(handleEducationButton()));
  connect(mUi->cEntertainment, SIGNAL(clicked()), SLOT(handleEntertainmentButton()));
  connect(mUi->cGovernment, SIGNAL(clicked()), SLOT(handleGovernmentButton()));
  connect(mUi->cEngineering, SIGNAL(clicked()), SLOT(handleEngineeringButton()));
  connect(mUi->cSecurity, SIGNAL(clicked()), SLOT(handleSecurityButton()));
  connect(mUi->cIndustry, SIGNAL(clicked()), SLOT(handleIndustryButton()));
  connect(mUi->cUndo, SIGNAL(clicked()), SLOT(handleUndoButton()));
  connect(mUi->cMessages, SIGNAL(clicked()), SLOT(handleMessagesButton()));
  connect(mUi->cCycle, SIGNAL(clicked()), SLOT(handleCycleButton()));
  connect(mUi->cCollapse, SIGNAL(clicked()), SLOT(handleCollapseButton()));
  connect(mUi->cExpand, SIGNAL(clicked()), SLOT(handleExpandButton()));
  connect(mUi->cOverlay, SIGNAL(clicked()), SLOT(handleOverlaysButton()));

  connect(mReligionMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleSmallTempleMenu()));
  connect(mReligionMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleLargeTempleMenu()));
  connect(mIndustryMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleFarmMenu()));
  connect(mIndustryMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleRawMaterialsMenu()));
  connect(mIndustryMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleWorkshopMenu()));
  connect(mSecurityMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleFortMenu()));

  connect(mUi->cHouse, SIGNAL(clicked()), SLOT(handleBuildHouse()));
  connect(mUi->cClear, SIGNAL(clicked()), SLOT(handleClear()));
  connect(mUi->cRoad, SIGNAL(clicked()), SLOT(handleBuildRoad()));

  // Water menu
  connect(mWaterMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildReservoir()));
  connect(mWaterMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildAqueduct()));
  connect(mWaterMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildFountain()));
  connect(mWaterMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildWell()));

  // Health menu
  connect(mHealthMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildBarber()));
  connect(mHealthMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildBaths()));
  connect(mHealthMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildDoctor()));
  connect(mHealthMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildHospital()));

  // Religion Menu
  connect(mSmallTempleMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildSmallCeresTemple()));
  connect(mSmallTempleMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildSmallNeptuneTemple()));
  connect(mSmallTempleMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildSmallMercuryTemple()));
  connect(mSmallTempleMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildSmallMarsTemple()));
  connect(mSmallTempleMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildSmallVenusTemple()));
  connect(mLargeTempleMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildLargeCeresTemple()));
  connect(mLargeTempleMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildLargeNeptuneTemple()));
  connect(mLargeTempleMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildLargeMercuryTemple()));
  connect(mLargeTempleMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildLargeMarsTemple()));
  connect(mLargeTempleMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildLargeVenusTemple()));
  connect(mReligionMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildOracle()));

  // Education menu
  connect(mEducationMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildSchool()));
  connect(mEducationMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildLibrary()));
  connect(mEducationMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildAcademy()));

  // Entertainment Menu
  connect(mEntertainmentMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildTheater()));
  connect(mEntertainmentMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildAmpitheater()));
  connect(mEntertainmentMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildColosseum()));
  connect(mEntertainmentMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildGladiatorSchool()));
  connect(mEntertainmentMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildLionHouse()));
  connect(mEntertainmentMenu->itemAt(5), SIGNAL(clicked()), SLOT(handleBuildChariotMaker()));
  connect(mEntertainmentMenu->itemAt(6), SIGNAL(clicked()), SLOT(handleBuildHippodrome()));

  // Government menu
  connect(mGovernmentMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildForum())); // Forum
  connect(mGovernmentMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildSenate())); // Senate
  connect(mGovernmentMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildGovernorsHouse())); // Gov house
  connect(mGovernmentMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildGovernorsVilla())); // Gov villa
  connect(mGovernmentMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildGovernorsPalace())); // Gov palace
  connect(mGovernmentMenu->itemAt(5), SIGNAL(clicked()), SLOT(handleBuildSmallStatue())); // Small statue
  connect(mGovernmentMenu->itemAt(6), SIGNAL(clicked()), SLOT(handleBuildMediumStatue())); // Medium statue
  connect(mGovernmentMenu->itemAt(7), SIGNAL(clicked()), SLOT(handleBuildLargeStatue())); // Large statue

  // Engineering menu
  connect(mEngineeringMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildGardens()));
  connect(mEngineeringMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildPlaza()));
  connect(mEngineeringMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildEngineerPost()));
  connect(mEngineeringMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildLowBridge()));
  connect(mEngineeringMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildShipBridge()));
  connect(mEngineeringMenu->itemAt(5), SIGNAL(clicked()), SLOT(handleBuildDock()));
  connect(mEngineeringMenu->itemAt(6), SIGNAL(clicked()), SLOT(handleBuildShipyard()));
  connect(mEngineeringMenu->itemAt(7), SIGNAL(clicked()), SLOT(handleBuildWharf()));

  // Security Menu
  connect(mSecurityMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildPrefecture()));
  connect(mSecurityMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildWall()));
  connect(mSecurityMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildTower()));
  connect(mSecurityMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildGatehouse()));
  connect(mFortMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildLegionnaries()));
  connect(mFortMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildJavelin()));
  connect(mFortMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildCalvary()));

  // Farm menu
  connect(mFarmMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildFarmWheat()));
  connect(mFarmMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildFarmVegetables()));
  connect(mFarmMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildFarmFruit()));
  connect(mFarmMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildFarmOlives()));
  connect(mFarmMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildFarmVines()));
  connect(mFarmMenu->itemAt(5), SIGNAL(clicked()), SLOT(handleBuildFarmMeat()));

  // Raw materials menu
  connect(mRawMaterialsMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildRawMaterialsClay()));
  connect(mRawMaterialsMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildRawMaterialsTimber()));
  connect(mRawMaterialsMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildRawMaterialsIron()));
  connect(mRawMaterialsMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildRawMaterialsMarble()));

  // Workshop menu
  connect(mWorkshopMenu->itemAt(0), SIGNAL(clicked()), SLOT(handleBuildWorkshopPottery()));
  connect(mWorkshopMenu->itemAt(1), SIGNAL(clicked()), SLOT(handleBuildWorkshopFurniture()));
  connect(mWorkshopMenu->itemAt(2), SIGNAL(clicked()), SLOT(handleBuildWorkshopWeapons()));
  connect(mWorkshopMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildWorkshopOil()));
  connect(mWorkshopMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildWorkshopWine()));

  // Industry menu
  connect(mIndustryMenu->itemAt(3), SIGNAL(clicked()), SLOT(handleBuildMarket()));
  connect(mIndustryMenu->itemAt(4), SIGNAL(clicked()), SLOT(handleBuildGranary()));
  connect(mIndustryMenu->itemAt(5), SIGNAL(clicked()), SLOT(handleBuildWarehouse()));
}

void SidebarWidget::createMenus()
{
  // TODO: Need to read prices from model data

  const StringData * stringData = Application::language()->stringData();

  int32_t menuWidth = 240;
  int32_t menuHeight = 240;

  mWaterMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mWaterMenu.get(), stringData->getString(28, 90), 80);      // Reservoir
  createMenuItem(mWaterMenu.get(), stringData->getString(28, 8), 8);        // Aqueduct
  createMenuItem(mWaterMenu.get(), stringData->getString(28, 91), 15);      // Fountain
  createMenuItem(mWaterMenu.get(), stringData->getString(28, 92), 5);       // Well
  mWaterMenu->setVisible(false);
  mWaterMenu->resize(menuWidth, menuHeight);

  mHealthMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mHealthMenu.get(), stringData->getString(28, 49), 25);     // Barber
  createMenuItem(mHealthMenu.get(), stringData->getString(28, 48), 50);     // Baths
  createMenuItem(mHealthMenu.get(), stringData->getString(28, 46), 30);     // Doctor
  createMenuItem(mHealthMenu.get(), stringData->getString(28, 47), 300);    // Hospital
  mHealthMenu->setVisible(false);
  mHealthMenu->resize(menuWidth, menuHeight);

  mReligionMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mReligionMenu.get(), stringData->getString(28, 96), -1);   // Small temple
  createMenuItem(mReligionMenu.get(), stringData->getString(28, 97), -1);   // Large temple
  createMenuItem(mReligionMenu.get(), stringData->getString(28, 98), 200);  // Oracle
  mReligionMenu->setVisible(false);
  mReligionMenu->resize(menuWidth, menuHeight);

  mEducationMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mEducationMenu.get(), stringData->getString(28, 51), 50);   // School
  createMenuItem(mEducationMenu.get(), stringData->getString(28, 52), 100);  // Academy
  createMenuItem(mEducationMenu.get(), stringData->getString(28, 53), 75);   // Library
  mEducationMenu->setVisible(false);
  mEducationMenu->resize(menuWidth, menuHeight);

  mEntertainmentMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 31), 50);   // Theater
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 30), 100);  // Ampitheater
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 33), 500);  // Colosseum
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 34), 75);   // Gladiator School
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 35), 75);   // Lion House
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 36), 50);   // Actor Colony
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 32), 75);   // Chariot Maker
  createMenuItem(mEntertainmentMenu.get(), stringData->getString(28, 37), 2500); // Hippodrome
  mEntertainmentMenu->setVisible(false);
  mEntertainmentMenu->resize(menuWidth, menuHeight);

  mGovernmentMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 86), 75);   // Forum
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 85), 400);  // Senate
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 77), 150);  // Gov house
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 78), 400);  // Gov villa
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 79), 700);  // Gov palace
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 41), 12);   // Small statue
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 42), 60);   // Medium statue
  createMenuItem(mGovernmentMenu.get(), stringData->getString(28, 43), 150);  // Large statue
  mGovernmentMenu->setVisible(false);
  mGovernmentMenu->resize(menuWidth, menuHeight);

  mEngineeringMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 39), 12);   // Gardens
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 38), 15);   // Plaza
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 81), 30);   // Engineer Post
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 82), 40);   // Low bridge
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 83), 100);  // Ship Bridge
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 75), 100);  // Dock
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 74), 100);  // Shipyard
  createMenuItem(mEngineeringMenu.get(), stringData->getString(28, 76), 60);   // Wharf
  mEngineeringMenu->setVisible(false);
  mEngineeringMenu->resize(menuWidth, menuHeight);

  mSecurityMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mSecurityMenu.get(), stringData->getString(28, 55), 30);      // Prefect
  createMenuItem(mSecurityMenu.get(), stringData->getString(28, 6), 12);       // Wall
  createMenuItem(mSecurityMenu.get(), stringData->getString(28, 59), 150);     // Tower
  createMenuItem(mSecurityMenu.get(), stringData->getString(28, 58), 100);     // Gatehouse
  createMenuItem(mSecurityMenu.get(), stringData->getString(28, 57), -1);      // Fort
  //mSecurityMenu->itemAt(1)->setAvailable(false);
  //mSecurityMenu->itemAt(2)->setAvailable(false);
  //mSecurityMenu->itemAt(3)->setAvailable(false);
  //mSecurityMenu->itemAt(4)->setAvailable(false);
  mSecurityMenu->setVisible(false);
  mSecurityMenu->resize(menuWidth, menuHeight);

  mIndustryMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 2), -1);      // Farm
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 3), -1);      // Raw Materials
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 4), -1);      // Workshop
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 70), 40);     // Market
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 71), 100);    // Granary
  createMenuItem(mIndustryMenu.get(), stringData->getString(28, 72), 70);     // Warehouse
  mIndustryMenu->setVisible(false);
  mIndustryMenu->resize(menuWidth, menuHeight);

  mSmallTempleMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mSmallTempleMenu.get(), stringData->getString(28, 60), 50);     // Ceres
  createMenuItem(mSmallTempleMenu.get(), stringData->getString(28, 61), 50);     // Neptune
  createMenuItem(mSmallTempleMenu.get(), stringData->getString(28, 62), 50);     // Mercury
  createMenuItem(mSmallTempleMenu.get(), stringData->getString(28, 63), 50);     // Mars
  createMenuItem(mSmallTempleMenu.get(), stringData->getString(28, 64), 50);     // Venus
  mSmallTempleMenu->setVisible(false);
  mSmallTempleMenu->resize(menuWidth, menuHeight);

  mLargeTempleMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mLargeTempleMenu.get(), stringData->getString(28, 60), 150);     // Ceres
  createMenuItem(mLargeTempleMenu.get(), stringData->getString(28, 61), 150);     // Neptune
  createMenuItem(mLargeTempleMenu.get(), stringData->getString(28, 62), 150);     // Mercury
  createMenuItem(mLargeTempleMenu.get(), stringData->getString(28, 63), 150);     // Mars
  createMenuItem(mLargeTempleMenu.get(), stringData->getString(28, 64), 150);     // Venus
  mLargeTempleMenu->setVisible(false);
  mLargeTempleMenu->resize(menuWidth, menuHeight);

  mFortMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mFortMenu.get(), stringData->getString(28, 40), 1000);     // Legionaries
  createMenuItem(mFortMenu.get(), stringData->getString(28, 44), 1000);     // Javelin
  createMenuItem(mFortMenu.get(), stringData->getString(28, 45), 1000);     // Cavalry
  mFortMenu->setVisible(false);
  mFortMenu->resize(menuWidth, menuHeight);

  mRawMaterialsMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mRawMaterialsMenu.get(), stringData->getString(28, 109), 40);     // Clay
  createMenuItem(mRawMaterialsMenu.get(), stringData->getString(28, 108), 40);     // Timber
  createMenuItem(mRawMaterialsMenu.get(), stringData->getString(28, 107), 50);     // Iron
  createMenuItem(mRawMaterialsMenu.get(), stringData->getString(28, 106), 50);     // Marble
  mRawMaterialsMenu->setVisible(false);
  mRawMaterialsMenu->resize(menuWidth, menuHeight);

  mWorkshopMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mWorkshopMenu.get(), stringData->getString(28, 114), 40);     // Pottery
  createMenuItem(mWorkshopMenu.get(), stringData->getString(28, 113), 40);     // Furniture
  createMenuItem(mWorkshopMenu.get(), stringData->getString(28, 112), 50);     // Weapons
  createMenuItem(mWorkshopMenu.get(), stringData->getString(28, 111), 50);     // Oil
  createMenuItem(mWorkshopMenu.get(), stringData->getString(28, 110), 45);     // Wine
  mWorkshopMenu->setVisible(false);
  mWorkshopMenu->resize(menuWidth, menuHeight);

  mFarmMenu.reset(new BuildMenu(parentWidget()));
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 100), 40);     // Wheat
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 101), 40);     // Vegetables
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 102), 40);     // Fruit
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 103), 40);     // Olives
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 104), 40);     // Vines
  createMenuItem(mFarmMenu.get(), stringData->getString(28, 105), 40);     // Pigs

  mFarmMenu->setVisible(false);
  mFarmMenu->resize(menuWidth, menuHeight);
}

void SidebarWidget::createMenuItem(BuildMenu * menu, const QString & label, int32_t price)
{
  BuildMenuItemPtr menuItem(new BuildMenuItem(menu));

  const StringData * textData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);
  QString dnText = textData->getString(6, 0);

  menuItem->setText(label);
  menuItem->setPrice(price);
  menuItem->resize(BUTTON_WIDTH, BUTTON_HEIGHT);
  menuItem->setTextFont(Font::Type::NormalGreen);

  QImage normalImage(BUTTON_WIDTH, BUTTON_HEIGHT, QImage::Format_ARGB32);
  QImage hoverImage(BUTTON_WIDTH, BUTTON_HEIGHT, QImage::Format_ARGB32);
  QPainter normalPainter(&normalImage);
  QPainter hoverPainter(&hoverImage);

  int32_t blocks = BUTTON_WIDTH / 16;
  for (int32_t i = 0; i < blocks; i++) {
    uint32_t normalImageId = baseImageId + 47;
    uint32_t focusImageId = baseImageId + 44;
    if (i == 0) {
      normalImageId = baseImageId + 46;
      focusImageId = baseImageId + 43;
    }
    if (i == blocks-1) {
      normalImageId = baseImageId + 48;
      focusImageId = baseImageId + 45;
    }

    normalPainter.drawImage(i*16, 0, imageData->getImageRecord(normalImageId)->createImage());
    hoverPainter.drawImage(i*16, 0, imageData->getImageRecord(focusImageId)->createImage());
  }

  menuItem->setImage(normalImage);
  menuItem->setHoverImage(hoverImage);

  menu->addItem(std::move(menuItem));
}

void SidebarWidget::handleAdvisorsButton()
{
  cancelMenu();
}

void SidebarWidget::handleBuildAcademy()
{
  cancelMenu();
}

void SidebarWidget::handleBuildActorColony()
{
  cancelMenu();
}

void SidebarWidget::handleBuildAmpitheater()
{
  cancelMenu();
}

void SidebarWidget::handleBuildAqueduct()
{
  cancelMenu();
}

void SidebarWidget::handleBuildBarber()
{
  cancelMenu();
}

void SidebarWidget::handleBuildBarracks()
{
  ;
  cancelMenu();
}

void SidebarWidget::handleBuildBaths()
{
  ;
  cancelMenu();
}

void SidebarWidget::handleBuildCalvary()
{
  cancelMenu();
}

void SidebarWidget::handleBuildChariotMaker()
{
  cancelMenu();
}

void SidebarWidget::handleBuildColosseum()
{
  cancelMenu();
}

void SidebarWidget::handleBuildDock()
{
  ;
  cancelMenu();
}

void SidebarWidget::handleBuildDoctor()
{
  cancelMenu();
}

void SidebarWidget::handleBuildEngineerPost()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmFruit()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmMeat()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmOlives()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmVegetables()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmVines()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFarmWheat()
{
  cancelMenu();
}

void SidebarWidget::handleBuildForum()
{
  cancelMenu();
}

void SidebarWidget::handleBuildFountain()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGardens()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGatehouse()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGladiatorSchool()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGovernorsHouse()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGovernorsPalace()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGovernorsVilla()
{
  cancelMenu();
}

void SidebarWidget::handleBuildGranary()
{
  cancelMenu();
}

void SidebarWidget::handleBuildHippodrome()
{
  cancelMenu();
}

void SidebarWidget::handleBuildHospital()
{
  cancelMenu();
}

void SidebarWidget::handleBuildHouse()
{
  cancelMenu();
}

void SidebarWidget::handleBuildJavelin()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeCeresTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeMarsTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeMercuryTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeNeptuneTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeVenusTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLargeStatue()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLegionnaries()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLibrary()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLionHouse()
{
  cancelMenu();
}

void SidebarWidget::handleBuildLowBridge()
{
  cancelMenu();
}

void SidebarWidget::handleBuildMarket()
{
  cancelMenu();
}

void SidebarWidget::handleBuildMediumStatue()
{
  cancelMenu();
}

void SidebarWidget::handleBuildOracle()
{
  cancelMenu();
}

void SidebarWidget::handleBuildPlaza()
{
  cancelMenu();
}

void SidebarWidget::handleBuildPrefecture()
{
  cancelMenu();
}

void SidebarWidget::handleBuildRawMaterialsClay()
{
  cancelMenu();
}

void SidebarWidget::handleBuildRawMaterialsIron()
{
  cancelMenu();
}

void SidebarWidget::handleBuildRawMaterialsMarble()
{
  cancelMenu();
}

void SidebarWidget::handleBuildRawMaterialsTimber()
{
  cancelMenu();
}

void SidebarWidget::handleBuildReservoir()
{
  cancelMenu();
}

void SidebarWidget::handleBuildRoad()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSchool()
{
  cancelMenu();
}

void SidebarWidget::handleBuildShipBridge()
{
  cancelMenu();
}

void SidebarWidget::handleBuildShipyard()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallCeresTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallMarsTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallMercuryTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallNeptuneTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallVenusTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSmallStatue()
{
  cancelMenu();
}

void SidebarWidget::handleBuildSenate()
{
  cancelMenu();
}

void SidebarWidget::handleBuildTemple()
{
  cancelMenu();
}

void SidebarWidget::handleBuildTheater()
{
  cancelMenu();
}

void SidebarWidget::handleBuildTower()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWall()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWarehouse()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWell()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWharf()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWorkshopFurniture()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWorkshopOil()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWorkshopPottery()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWorkshopWeapons()
{
  cancelMenu();
}

void SidebarWidget::handleBuildWorkshopWine()
{
  cancelMenu();
}

void SidebarWidget::handleClear()
{
  cancelMenu();
  ;
}

void SidebarWidget::handleCollapseButton()
{
  cancelMenu();
}

void SidebarWidget::handleCycleButton()
{
  cancelMenu();
}

void SidebarWidget::handleEducationButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mEducationMenu.get(), mUi->cEducation);
}

void SidebarWidget::handleEmpireButton()
{
  cancelMenu();
}

void SidebarWidget::handleEngineeringButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mEngineeringMenu.get(), mUi->cEngineering);
}

void SidebarWidget::handleEntertainmentButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mEntertainmentMenu.get(), mUi->cEntertainment);
}

void SidebarWidget::handleExpandButton()
{
  cancelMenu();
}

void SidebarWidget::handleFarmMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mFarmMenu.get(), nullptr);
}

void SidebarWidget::handleFortMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mFortMenu.get(), nullptr);
}

void SidebarWidget::handleGovernmentButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mGovernmentMenu.get(), mUi->cGovernment);
}

void SidebarWidget::handleHealthButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mHealthMenu.get(), mUi->cHealth);
}

void SidebarWidget::handleIndustryButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mIndustryMenu.get(), mUi->cIndustry);
}

void SidebarWidget::handleLargeTempleMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mLargeTempleMenu.get(), nullptr);
}

void SidebarWidget::handleMessagesButton()
{
  cancelMenu();
}

void SidebarWidget::handleMissionButton()
{
  cancelMenu();
}

void SidebarWidget::handleOrientNorthButton()
{
  cancelMenu();
}

void SidebarWidget::handleOverlaysButton()
{
  cancelMenu();
  mUi->cOverlay->setDown(true);
}

void SidebarWidget::handleRawMaterialsMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mRawMaterialsMenu.get(), nullptr);
}

void SidebarWidget::handleReligionButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mReligionMenu.get(), mUi->cReligion);
}

void SidebarWidget::handleRotateLeftButton()
{
  cancelMenu();
}

void SidebarWidget::handleRotateRightButton()
{
  cancelMenu();
}

void SidebarWidget::handleSecurityButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mSecurityMenu.get(), mUi->cSecurity);
}

void SidebarWidget::handleSmallTempleMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mSmallTempleMenu.get(), nullptr);
}

void SidebarWidget::handleWaterButton()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mWaterMenu.get(), mUi->cWater);
}

void SidebarWidget::handleWorkshopMenu()
{
  cancelMenu();
  startBuild();
  showBuildMenu(mWorkshopMenu.get(), nullptr);
}

void SidebarWidget::handleUndoButton()
{
  cancelMenu();
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
  connect(mUi->cEmpire, SIGNAL(clicked()), SIGNAL(empireRequested()));
  connect(mUi->cWater, SIGNAL(clicked()), SLOT(handleWaterButton()));
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

void SidebarWidget::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::RightButton) {
    cancelMenu();
  }
}

void SidebarWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::lightGray));
}

void SidebarWidget::showBuildMenu(BuildMenu *menu, Button * button)
{
  std::size_t totalItems = menu->totalItemsAvailable();
  bool isOdd = totalItems % 2;
  int yOffset = 415 + BUTTON_HEIGHT / 2 - totalItems*(BUTTON_HEIGHT+5) + 5;
  if (!isOdd)
    yOffset += BUTTON_HEIGHT/2;

  QRect rect(this->rect());
  QPoint pt = this->mapToParent(rect.topLeft());
  int32_t xOffset = pt.x() - BUTTON_WIDTH - 10;
  menu->move(xOffset, yOffset);
  menu->setVisible(true);
  if (button != nullptr)
    button->setDown(true);
}

void SidebarWidget::startBuild()
{
  mUi->cAdvisors->setEnabled(false);
  mUi->cEmpire->setEnabled(false);
  mUi->cRotateNorth->setEnabled(false);
  mUi->cRotateLeft->setEnabled(false);
  mUi->cRotateRight->setEnabled(false);
  mUi->cMission->setEnabled(false);
}
