#include "populationadvisorwidget.h"
#include "ui_populationadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

PopulationAdvisorWidget::PopulationAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::PopulationAdvisorWidget)
  , mBottomGraphType(GraphType::Society)
  , mMainGraphType(GraphType::History)
  , mTopGraphType(GraphType::Census)
{
  init();
}

PopulationAdvisorWidget::~PopulationAdvisorWidget()
{
  delete mUi;
}

void PopulationAdvisorWidget::doUpdate()
{
  const StringData * stringData = Application::language()->stringData();

  setTitle(mUi->cTitle, mMainGraphType);
  setGraphLabel(mUi->cMainLabel, mMainGraphType, false);
  setGraphLabel(mUi->cTopLabel, mTopGraphType, true);
  setGraphLabel(mUi->cBottomLabel, mBottomGraphType, true);

  int32_t numGranaries = 1;
  int32_t monthSupply = 1;

  QString granaryText = QString::number(numGranaries) + " ";
  granaryText += stringData->getString(8, (numGranaries == 1) ? 6 : 7) + " ";
  granaryText += stringData->getString(55, 12) + " ";
  granaryText += QString::number(monthSupply) + " ";
  granaryText += stringData->getString(8, monthSupply == 1 ? 4 : 5);
  mUi->cGranaryStorage->setText(granaryText);

  int32_t numFoods = 2;
  QString foodText = stringData->getString(55, 16) + " ";
  foodText += QString::number(numFoods);
  mUi->cFoodVariety->setText(foodText);

  QString statusString = stringData->getString(55, 24);
  mUi->cImmigrationStatus->setText(statusString);

  updateImmigrantString();
}

void PopulationAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);
  uint32_t bulletId = imageData->getGroupBaseImageId(GROUP_BULLET);
  uint32_t backgroundId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  Font normalBlack(Font::Type::NormalBlack);
  Font normalWhite(Font::Type::NormalWhite);
  Font largeBlack(Font::Type::LargeBlack);
  Font smallPlain(Font::Type::SmallPlain);

  mUi->setupUi(this);

  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(backgroundId+14)->createImage()));

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+5)->createImage());

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(55, 0));

  mUi->cBullet1->setPixmap(QPixmap::fromImage(imageData->getImageRecord(bulletId)->createImage()));
  mUi->cBullet2->setPixmap(QPixmap::fromImage(imageData->getImageRecord(bulletId)->createImage()));
  mUi->cBullet3->setPixmap(QPixmap::fromImage(imageData->getImageRecord(bulletId)->createImage()));
  mUi->cBullet4->setPixmap(QPixmap::fromImage(imageData->getImageRecord(bulletId)->createImage()));

  mUi->cBottomLabel->setTextFont(normalBlack);
  mUi->cTopLabel->setTextFont(normalBlack);
  mUi->cMainLabel->setTextFont(normalBlack);
  mUi->cGranaryStorage->setTextFont(normalWhite);
  mUi->cFoodVariety->setTextFont(normalWhite);
  mUi->cImmigrationStatus->setTextFont(normalWhite);
  mUi->cImmigrants->setTextFont(normalWhite);
  mUi->cMinY->setTextFont(smallPlain);
  mUi->cMaxY->setTextFont(smallPlain);
  mUi->cMidY->setTextFont(smallPlain);
}

void PopulationAdvisorWidget::setGraphLabel(Label * label, GraphType graphType, bool small)
{
  const StringData * stringData = Application::language()->stringData();
  if (graphType == GraphType::History) {
    label->setText(stringData->getString(55, (small) ? 3 : 6));
  }
  else if (graphType == GraphType::Census) {
    label->setText(stringData->getString(55, (small) ? 4 : 7));
  }
  else {
    label->setText(stringData->getString(55, (small) ? 5 : 8));
  }
}

void PopulationAdvisorWidget::setTitle(Label * label, GraphType graphType)
{
  const StringData * stringData = Application::language()->stringData();
  if (graphType == GraphType::History) {
    label->setText(stringData->getString(55, 0));
  }
  else if (graphType == GraphType::Census) {
    label->setText(stringData->getString(55, 1));
  }
  else {
    label->setText(stringData->getString(55, 2));
  }
}

void PopulationAdvisorWidget::updateImmigrantString()
{
  const StringData * stringData = Application::language()->stringData();

  int32_t totalImmigrants = 3;
  QString immigrantsString = QString::number(totalImmigrants) + " ";
  immigrantsString += stringData->getString(55, (totalImmigrants==1) ? 18 : 17);
  mUi->cImmigrants->setText(immigrantsString);
}
