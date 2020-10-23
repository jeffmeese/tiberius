#include "advisorswindow.h"
#include "ui_advisorswindow.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include <QPainter>

AdvisorsWindow::AdvisorsWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::AdvisorsWindow)
  , mActiveAdvisor(Advisor::Type::Chief)
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

void AdvisorsWindow::init()
{
  mUi->setupUi(this);

  const SgImageData * imageData = Application::climateImages();
  uint32_t backgroundId = imageData->getGroupBaseImageId(GROUP_ADVISOR_BACKGROUND);
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(backgroundId)->createImage()));

  mUi->cLabor->setImage(imageData->getImageRecord(advisorsId)->createImage());
  mUi->cLabor->setPressedImage(imageData->getImageRecord(advisorsId+13)->createImage());

  mUi->cMilitary->setImage(imageData->getImageRecord(advisorsId+1)->createImage());
  mUi->cMilitary->setPressedImage(imageData->getImageRecord(advisorsId+14)->createImage());

  mUi->cEmperor->setImage(imageData->getImageRecord(advisorsId+2)->createImage());
  mUi->cEmperor->setPressedImage(imageData->getImageRecord(advisorsId+15)->createImage());

  mUi->cRatings->setImage(imageData->getImageRecord(advisorsId+3)->createImage());
  mUi->cRatings->setPressedImage(imageData->getImageRecord(advisorsId+16)->createImage());

  mUi->cTrade->setImage(imageData->getImageRecord(advisorsId+4)->createImage());
  mUi->cTrade->setPressedImage(imageData->getImageRecord(advisorsId+17)->createImage());

  mUi->cPopulation->setImage(imageData->getImageRecord(advisorsId+5)->createImage());
  mUi->cPopulation->setPressedImage(imageData->getImageRecord(advisorsId+18)->createImage());

  mUi->cHealth->setImage(imageData->getImageRecord(advisorsId+6)->createImage());
  mUi->cHealth->setPressedImage(imageData->getImageRecord(advisorsId+19)->createImage());

  mUi->cEducation->setImage(imageData->getImageRecord(advisorsId+7)->createImage());
  mUi->cEducation->setPressedImage(imageData->getImageRecord(advisorsId+20)->createImage());

  mUi->cEntertainment->setImage(imageData->getImageRecord(advisorsId+8)->createImage());
  mUi->cEntertainment->setPressedImage(imageData->getImageRecord(advisorsId+21)->createImage());

  mUi->cReligion->setImage(imageData->getImageRecord(advisorsId+9)->createImage());
  mUi->cReligion->setPressedImage(imageData->getImageRecord(advisorsId+22)->createImage());

  mUi->cGovernment->setImage(imageData->getImageRecord(advisorsId+10)->createImage());
  mUi->cGovernment->setPressedImage(imageData->getImageRecord(advisorsId+23)->createImage());

  mUi->cChief->setImage(imageData->getImageRecord(advisorsId+11)->createImage());
  mUi->cChief->setPressedImage(imageData->getImageRecord(advisorsId+24)->createImage());

  mUi->cReturn->setImage(imageData->getImageRecord(advisorsId+12)->createImage());

  connect(mUi->cChief, SIGNAL(clicked()), SLOT(showChiefAdvisor()));
  connect(mUi->cLabor, SIGNAL(clicked()), SLOT(showLaborAdvisor()));
  connect(mUi->cRatings, SIGNAL(clicked()), SLOT(showRatingsAdvisor()));
  connect(mUi->cTrade, SIGNAL(clicked()), SLOT(showTradeAdvisor()));
  connect(mUi->cPopulation, SIGNAL(clicked()), SLOT(showPopulationAdvisor()));
  connect(mUi->cHealth, SIGNAL(clicked()), SLOT(showHealthAdvisor()));
  connect(mUi->cEmperor, SIGNAL(clicked()), SLOT(showEmperorAdvisor()));
  connect(mUi->cEntertainment, SIGNAL(clicked()), SLOT(showEntertainmentAdvisor()));
  connect(mUi->cEducation, SIGNAL(clicked()), SLOT(showEducationAdvisor()));
  connect(mUi->cGovernment, SIGNAL(clicked()), SLOT(showGovernmentAdvisor()));
  connect(mUi->cMilitary, SIGNAL(clicked()), SLOT(showMilitaryAdvisor()));
  connect(mUi->cReligion, SIGNAL(clicked()), SLOT(showReligionAdvisor()));
  connect(mUi->cReturn, SIGNAL(clicked()), SLOT(close()));
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

  xOffset = (w - mUi->groupBox->width()) / 2;
  yOffset = (h - mUi->groupBox->height()) / 2 + 216;
  mUi->groupBox->move(xOffset, yOffset);
}

void AdvisorsWindow::setActiveAdvisor(Advisor::Type type)
{
  mActiveAdvisor = type;

  switch (type)
  {
    case Advisor::Type::Chief:
      showChiefAdvisor();
      mUi->cChief->setChecked(true);
      break;
    case Advisor::Type::Labor:
      showLaborAdvisor();
      mUi->cLabor->setChecked(true);
      break;
    case Advisor::Type::Ratings:
      showRatingsAdvisor();
      mUi->cRatings->setChecked(true);
      break;
    case Advisor::Type::Population:
      showPopulationAdvisor();
      mUi->cPopulation->setChecked(true);
      break;
    case Advisor::Type::Education:
      showEducationAdvisor();
      mUi->cEducation->setChecked(true);
      break;
    case Advisor::Type::Emperor:
      showEmperorAdvisor();
      mUi->cEmperor->setChecked(true);
      break;
    case Advisor::Type::Entertainment:
      showEntertainmentAdvisor();
      mUi->cEntertainment->setChecked(true);
      break;
    case Advisor::Type::Military:
      showMilitaryAdvisor();
      mUi->cMilitary->setChecked(true);
      break;
    case Advisor::Type::Religion:
      showReligionAdvisor();
      mUi->cReligion->setChecked(true);
      break;
    case Advisor::Type::Trade:
      showTradeAdvisor();
      mUi->cTrade->setChecked(true);
      break;
    case Advisor::Type::Health:
      showHealthAdvisor();
      mUi->cHealth->setChecked(true);
      break;
    case Advisor::Type::Government:
      showGovernmentAdvisor();
      mUi->cGovernment->setChecked(true);
      break;
  }
}

void AdvisorsWindow::showChiefAdvisor()
{
  mActiveAdvisor = Advisor::Type::Chief;
}

void AdvisorsWindow::showEducationAdvisor()
{
  mActiveAdvisor = Advisor::Type::Education;
}

void AdvisorsWindow::showEmperorAdvisor()
{
  mActiveAdvisor = Advisor::Type::Emperor;
}

void AdvisorsWindow::showEntertainmentAdvisor()
{
  mActiveAdvisor = Advisor::Type::Entertainment;
}

void AdvisorsWindow::showGovernmentAdvisor()
{
  mActiveAdvisor = Advisor::Type::Government;
}

void AdvisorsWindow::showHealthAdvisor()
{
  mActiveAdvisor = Advisor::Type::Health;
}

void AdvisorsWindow::showLaborAdvisor()
{
  mActiveAdvisor = Advisor::Type::Labor;
}

void AdvisorsWindow::showMilitaryAdvisor()
{
  mActiveAdvisor = Advisor::Type::Military;
}

void AdvisorsWindow::showPopulationAdvisor()
{
  mActiveAdvisor = Advisor::Type::Population;
}

void AdvisorsWindow::showRatingsAdvisor()
{
  mActiveAdvisor = Advisor::Type::Ratings;
}

void AdvisorsWindow::showReligionAdvisor()
{
  mActiveAdvisor = Advisor::Type::Religion;
}

void AdvisorsWindow::showTradeAdvisor()
{
  mActiveAdvisor = Advisor::Type::Trade;
}
