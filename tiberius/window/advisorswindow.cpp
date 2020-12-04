#include "advisorswindow.h"
#include "ui_advisorswindow.h"

#include "application/application.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "widget/button.h"
#include "widget/chiefadvisorwidget.h"
#include "widget/educationadvisorwidget.h"
#include "widget/entertainmentadvisorwidget.h"
#include "widget/financeadvisorwidget.h"
#include "widget/healthadvisorwidget.h"
#include "widget/imperialadvisorwidget.h"
#include "widget/laboradvisorwidget.h"
#include "widget/legionadvisorwidget.h"
#include "widget/populationadvisorwidget.h"
#include "widget/ratingsadvisorwidget.h"
#include "widget/religionadvisorwidget.h"
#include "widget/tradeadvisorwidget.h"

#include <QPainter>

AdvisorsWindow::AdvisorsWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::AdvisorsWindow)
  , mActiveAdvisor(Advisor::Type::Chief)
  , mGame(nullptr)
{
  init();
}

AdvisorsWindow::~AdvisorsWindow()
{
}

Advisor::Type AdvisorsWindow::activeAdvisor() const
{
  return mActiveAdvisor;
}

void AdvisorsWindow::closeEvent(QCloseEvent *)
{
  emit closed();
}

const Game * AdvisorsWindow::game() const
{
  return mGame;
}

void AdvisorsWindow::hideAllAdvisors()
{
  mLaborAdvisor->setVisible(false);
  mLegionAdvisor->setVisible(false);
  mImperialAdvisor->setVisible(false);
  mRatingsAdvisor->setVisible(false);
  mTradeAdvisor->setVisible(false);
  mPopulationAdvisor->setVisible(false);
  mHealthAdvisor->setVisible(false);
  mEducationAdvisor->setVisible(false);
  mEntertainmentAdvisor->setVisible(false);
  mReligionAdvisor->setVisible(false);
  mFinanceAdvisor->setVisible(false);
  mChiefAdvisor->setVisible(false);
}

void AdvisorsWindow::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t backgroundId = imageData->getGroupBaseImageId(GROUP_ADVISOR_BACKGROUND);
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);
  uint32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mUi->setupUi(this);

  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(backgroundId)->createImage()));
  mUi->cButtonBorder->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelId+13)->createImage()));

  mUi->cLaborButton->setImage(imageData->getImageRecord(advisorsId)->createImage());
  mUi->cLaborButton->setPressedImage(imageData->getImageRecord(advisorsId+13)->createImage());
  mUi->cLaborButton->setToolTip(stringData->getString(68, 70));

  mUi->cMilitaryButton->setImage(imageData->getImageRecord(advisorsId+1)->createImage());
  mUi->cMilitaryButton->setPressedImage(imageData->getImageRecord(advisorsId+14)->createImage());
  mUi->cMilitaryButton->setToolTip(stringData->getString(68, 71));

  mUi->cEmperorButton->setImage(imageData->getImageRecord(advisorsId+2)->createImage());
  mUi->cEmperorButton->setPressedImage(imageData->getImageRecord(advisorsId+15)->createImage());
  mUi->cEmperorButton->setToolTip(stringData->getString(68, 72));

  mUi->cRatingsButton->setImage(imageData->getImageRecord(advisorsId+3)->createImage());
  mUi->cRatingsButton->setPressedImage(imageData->getImageRecord(advisorsId+16)->createImage());
  mUi->cRatingsButton->setToolTip(stringData->getString(68, 73));

  mUi->cTradeButton->setImage(imageData->getImageRecord(advisorsId+4)->createImage());
  mUi->cTradeButton->setPressedImage(imageData->getImageRecord(advisorsId+17)->createImage());
  mUi->cTradeButton->setToolTip(stringData->getString(68, 69));

  mUi->cPopulationButton->setImage(imageData->getImageRecord(advisorsId+5)->createImage());
  mUi->cPopulationButton->setPressedImage(imageData->getImageRecord(advisorsId+18)->createImage());
  mUi->cPopulationButton->setToolTip(stringData->getString(68, 75));

  mUi->cHealthButton->setImage(imageData->getImageRecord(advisorsId+6)->createImage());
  mUi->cHealthButton->setPressedImage(imageData->getImageRecord(advisorsId+19)->createImage());
  mUi->cHealthButton->setToolTip(stringData->getString(68, 76));

  mUi->cEducationButton->setImage(imageData->getImageRecord(advisorsId+7)->createImage());
  mUi->cEducationButton->setPressedImage(imageData->getImageRecord(advisorsId+20)->createImage());
  mUi->cEducationButton->setToolTip(stringData->getString(68, 77));

  mUi->cEntertainmentButton->setImage(imageData->getImageRecord(advisorsId+8)->createImage());
  mUi->cEntertainmentButton->setPressedImage(imageData->getImageRecord(advisorsId+21)->createImage());
  mUi->cEntertainmentButton->setToolTip(stringData->getString(68, 78));

  mUi->cReligionButton->setImage(imageData->getImageRecord(advisorsId+9)->createImage());
  mUi->cReligionButton->setPressedImage(imageData->getImageRecord(advisorsId+22)->createImage());
  mUi->cReligionButton->setToolTip(stringData->getString(68, 79));

  mUi->cGovernmentButton->setImage(imageData->getImageRecord(advisorsId+10)->createImage());
  mUi->cGovernmentButton->setPressedImage(imageData->getImageRecord(advisorsId+23)->createImage());
  mUi->cGovernmentButton->setToolTip(stringData->getString(68, 80));

  mUi->cChiefButton->setImage(imageData->getImageRecord(advisorsId+11)->createImage());
  mUi->cChiefButton->setPressedImage(imageData->getImageRecord(advisorsId+24)->createImage());
  mUi->cChiefButton->setToolTip(stringData->getString(68, 81));

  mUi->cReturnButton->setImage(imageData->getImageRecord(advisorsId+12)->createImage());
  mUi->cReturnButton->setToolTip(stringData->getString(68, 82));

  mLaborAdvisor.reset(new LaborAdvisorWidget(this));
  mLaborAdvisor->resize(640, 416);

  mLegionAdvisor.reset(new LegionAdvisorWidget(this));
  mLegionAdvisor->resize(640, 416);

  mImperialAdvisor.reset(new ImperialAdvisorWidget(this));
  mImperialAdvisor->resize(640, 432);

  mRatingsAdvisor.reset(new RatingsAdvisorWidget(this));
  mRatingsAdvisor->resize(640, 432);

  mTradeAdvisor.reset(new TradeAdvisorWidget(this));
  mTradeAdvisor->resize(640, 432);

  mPopulationAdvisor.reset(new PopulationAdvisorWidget(this));
  mPopulationAdvisor->resize(640, 432);

  mHealthAdvisor.reset(new HealthAdvisorWidget(this));
  mHealthAdvisor->resize(640, 288);

  mEducationAdvisor.reset(new EducationAdvisorWidget(this));
  mEducationAdvisor->resize(640, 256);

  mEntertainmentAdvisor.reset(new EntertainmentAdvisorWidget(this));
  mEntertainmentAdvisor->resize(640, 368);

  mReligionAdvisor.reset(new ReligionAdvisorWidget(this));
  mReligionAdvisor->resize(640, 320);

  mFinanceAdvisor.reset(new FinanceAdvisorWidget(this));
  mFinanceAdvisor->resize(640, 416);

  mChiefAdvisor.reset(new ChiefAdvisorWidget(this));
  mChiefAdvisor->resize(640, 368);

  connect(mUi->cChiefButton, SIGNAL(clicked()), SLOT(showChiefAdvisor()));
  connect(mUi->cLaborButton, SIGNAL(clicked()), SLOT(showLaborAdvisor()));
  connect(mUi->cRatingsButton, SIGNAL(clicked()), SLOT(showRatingsAdvisor()));
  connect(mUi->cTradeButton, SIGNAL(clicked()), SLOT(showTradeAdvisor()));
  connect(mUi->cPopulationButton, SIGNAL(clicked()), SLOT(showPopulationAdvisor()));
  connect(mUi->cHealthButton, SIGNAL(clicked()), SLOT(showHealthAdvisor()));
  connect(mUi->cEmperorButton, SIGNAL(clicked()), SLOT(showEmperorAdvisor()));
  connect(mUi->cEntertainmentButton, SIGNAL(clicked()), SLOT(showEntertainmentAdvisor()));
  connect(mUi->cEducationButton, SIGNAL(clicked()), SLOT(showEducationAdvisor()));
  connect(mUi->cGovernmentButton, SIGNAL(clicked()), SLOT(showGovernmentAdvisor()));
  connect(mUi->cMilitaryButton, SIGNAL(clicked()), SLOT(showMilitaryAdvisor()));
  connect(mUi->cReligionButton, SIGNAL(clicked()), SLOT(showReligionAdvisor()));
  connect(mUi->cReturnButton, SIGNAL(clicked()), SLOT(close()));

  connect(mChiefAdvisor.get(), SIGNAL(changed()), SLOT(update()));
  connect(mEntertainmentAdvisor.get(), SIGNAL(changed()), SLOT(update()));
}

void AdvisorsWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void AdvisorsWindow::resizeEvent(QResizeEvent *)
{
  int32_t w = width();
  int32_t h = height();

  int32_t xOffset = (w - mUi->cBackground->width()) / 2;
  int32_t yOffset = (h - mUi->cBackground->height()) / 2;
  mUi->cBackground->move(xOffset, yOffset);

  xOffset = (w - mUi->cButtonBorder->width()) / 2;
  yOffset = (h - mUi->cButtonBorder->height()) / 2 + 216;
  mUi->cButtonBorder->move(xOffset, yOffset);

  xOffset = (w - mUi->groupBox->width()) / 2;
  yOffset = (h - mUi->groupBox->height()) / 2 + 216;
  mUi->groupBox->move(xOffset, yOffset);

  int h2 = (height() - mLaborAdvisor->height()) / 2 - 30;
  mLaborAdvisor->move(xOffset, h2);
  mLegionAdvisor->move(xOffset, h2);
  mImperialAdvisor->move(xOffset, h2);
  mRatingsAdvisor->move(xOffset, h2);
  mTradeAdvisor->move(xOffset, h2);
  mPopulationAdvisor->move(xOffset, h2);
  mHealthAdvisor->move(xOffset, h2);
  mEducationAdvisor->move(xOffset, h2);
  mEntertainmentAdvisor->move(xOffset, h2);
  mReligionAdvisor->move(xOffset, h2);
  mFinanceAdvisor->move(xOffset, h2);
  mChiefAdvisor->move(xOffset, h2);
}

void AdvisorsWindow::setActiveAdvisor(Advisor::Type type)
{
  mActiveAdvisor = type;

  switch (type)
  {
    case Advisor::Type::Chief:
      showChiefAdvisor();
      mUi->cChiefButton->setChecked(true);
      break;
    case Advisor::Type::Labor:
      showLaborAdvisor();
      mUi->cLaborButton->setChecked(true);
      break;
    case Advisor::Type::Ratings:
      showRatingsAdvisor();
      mUi->cRatingsButton->setChecked(true);
      break;
    case Advisor::Type::Population:
      showPopulationAdvisor();
      mUi->cPopulationButton->setChecked(true);
      break;
    case Advisor::Type::Education:
      showEducationAdvisor();
      mUi->cEducationButton->setChecked(true);
      break;
    case Advisor::Type::Emperor:
      showEmperorAdvisor();
      mUi->cEmperorButton->setChecked(true);
      break;
    case Advisor::Type::Entertainment:
      showEntertainmentAdvisor();
      mUi->cEntertainmentButton->setChecked(true);
      break;
    case Advisor::Type::Military:
      showMilitaryAdvisor();
      mUi->cMilitaryButton->setChecked(true);
      break;
    case Advisor::Type::Religion:
      showReligionAdvisor();
      mUi->cReligionButton->setChecked(true);
      break;
    case Advisor::Type::Trade:
      showTradeAdvisor();
      mUi->cTradeButton->setChecked(true);
      break;
    case Advisor::Type::Health:
      showHealthAdvisor();
      mUi->cHealthButton->setChecked(true);
      break;
    case Advisor::Type::Government:
      showGovernmentAdvisor();
      mUi->cGovernmentButton->setChecked(true);
      break;
  }
}

void AdvisorsWindow::setGame(Game *game)
{
  mGame = game;
  mLaborAdvisor->setGame(game);
  mLegionAdvisor->setGame(game);
  mImperialAdvisor->setGame(game);
  mRatingsAdvisor->setGame(game);
  mTradeAdvisor->setGame(game);
  mPopulationAdvisor->setGame(game);
  mHealthAdvisor->setGame(game);
  mEducationAdvisor->setGame(game);
  mEntertainmentAdvisor->setGame(game);
  mReligionAdvisor->setGame(game);
  mFinanceAdvisor->setGame(game);
  mChiefAdvisor->setGame(game);
}

void AdvisorsWindow::showChiefAdvisor()
{
  hideAllAdvisors();
  mChiefAdvisor->update();
  mChiefAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Chief;
}

void AdvisorsWindow::showEducationAdvisor()
{
  hideAllAdvisors();
  mEducationAdvisor->update();
  mEducationAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Education;
}

void AdvisorsWindow::showEmperorAdvisor()
{
  hideAllAdvisors();
  mImperialAdvisor->update();
  mImperialAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Emperor;
}

void AdvisorsWindow::showEntertainmentAdvisor()
{
  hideAllAdvisors();
  mEntertainmentAdvisor->update();
  mEntertainmentAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Entertainment;
}

void AdvisorsWindow::showGovernmentAdvisor()
{
  hideAllAdvisors();
  mFinanceAdvisor->update();
  mFinanceAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Government;
}

void AdvisorsWindow::showHealthAdvisor()
{
  hideAllAdvisors();
  mHealthAdvisor->update();
  mHealthAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Health;
}

void AdvisorsWindow::showLaborAdvisor()
{
  hideAllAdvisors();
  mLaborAdvisor->update();
  mLaborAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Labor;
}

void AdvisorsWindow::showMilitaryAdvisor()
{
  hideAllAdvisors();
  mLegionAdvisor->update();
  mLegionAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Military;
}

void AdvisorsWindow::showPopulationAdvisor()
{
  hideAllAdvisors();
  mPopulationAdvisor->update();
  mPopulationAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Population;
}

void AdvisorsWindow::showRatingsAdvisor()
{
  hideAllAdvisors();
  mRatingsAdvisor->update();
  mRatingsAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Ratings;
}

void AdvisorsWindow::showReligionAdvisor()
{
  hideAllAdvisors();
  mReligionAdvisor->update();
  mReligionAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Religion;
}

void AdvisorsWindow::showTradeAdvisor()
{
  hideAllAdvisors();
  mTradeAdvisor->update();
  mTradeAdvisor->setVisible(true);
  mActiveAdvisor = Advisor::Type::Trade;
}
