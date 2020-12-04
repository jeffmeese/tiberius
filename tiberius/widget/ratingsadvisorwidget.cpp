#include "ratingsadvisorwidget.h"
#include "ui_ratingsadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/populationdata.h"
#include "city/ratingsdata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

RatingsAdvisorWidget::RatingsAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::RatingsAdvisorWidget)
{
  init();
}

RatingsAdvisorWidget::~RatingsAdvisorWidget()
{
  delete mUi;
}

void RatingsAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);
  uint32_t backgoundId = imageData->getGroupBaseImageId(GROUP_RATINGS_BACKGROUND);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);
  Font normalWhite(Font::Type::NormalWhite);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+3)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(53, 0));

  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(backgoundId)->createImage()));

  mUi->cTargetPopulation->setTextFont(normalBlack);

  mUi->cCultureButton->setTitle(stringData->getString(53, 1));
  mUi->cCultureButton->setEnableBorder(true);
  mUi->cCultureButton->setEnableFocusBorder(true);

  mUi->cProsperityButton->setTitle(stringData->getString(53, 2));
  mUi->cProsperityButton->setEnableBorder(true);
  mUi->cProsperityButton->setEnableFocusBorder(true);

  mUi->cPeaceButton->setTitle(stringData->getString(53, 3));
  mUi->cPeaceButton->setEnableBorder(true);
  mUi->cPeaceButton->setEnableFocusBorder(true);

  mUi->cFavorButton->setTitle(stringData->getString(53, 4));
  mUi->cFavorButton->setEnableBorder(true);
  mUi->cFavorButton->setEnableFocusBorder(true);

  mUi->cMessageTitle->setTextFont(normalWhite);
  mUi->cMessage->setTextFont(normalWhite);

  connect(mUi->cCultureButton, SIGNAL(clicked()), SLOT(handleClickCulture()));
  connect(mUi->cPeaceButton, SIGNAL(clicked()), SLOT(handleClickPeace()));
  connect(mUi->cProsperityButton, SIGNAL(clicked()), SLOT(handleClickProsperity()));
  connect(mUi->cFavorButton, SIGNAL(clicked()), SLOT(handleClickFavor()));

  mUi->cMessage->setVisible(false);
  mUi->cMessageTitle->setVisible(false);
}

void RatingsAdvisorWidget::doUpdate()
{
  const StringData * stringData = Application::language()->stringData();
  RatingsData * ratingsData = game()->city()->ratingsData();

  Font font(Font::Type::NormalBlack);

  int32_t culture = ratingsData->culture();
  int32_t peace = ratingsData->peace();
  int32_t prosperity = ratingsData->prosperity();
  int32_t favor = ratingsData->favor();
  int32_t targetCulture = ratingsData->targetCulture();
  int32_t targetPeace = ratingsData->targetPeace();
  int32_t targetProsperity = ratingsData->targetProsperity();
  int32_t targetFavor = ratingsData->targetFavor();
  int32_t targetPopulation = ratingsData->targetPopulation();

  QString textString = stringData->getString(53, 6);
  textString += " " + QString::number(targetPopulation) + ")";
  mUi->cTargetPopulation->setText(textString);
  mUi->cTargetPopulation->resize(font.calculateTextWidth(textString), 20);

  mUi->cCultureButton->setTarget(targetCulture);
  mUi->cCultureButton->setValue(culture);

  mUi->cProsperityButton->setTarget(targetProsperity);
  mUi->cProsperityButton->setValue(prosperity);

  mUi->cPeaceButton->setTarget(targetPeace);
  mUi->cPeaceButton->setValue(peace);

  mUi->cFavorButton->setTarget(targetFavor);
  mUi->cFavorButton->setValue(favor);
}

void RatingsAdvisorWidget::handleClickCulture()
{
  const StringData * stringData = Application::language()->stringData();
  RatingsData * ratingsData = game()->city()->ratingsData();
  Font font(Font::Type::NormalWhite);

  mUi->cMessage->setVisible(true);
  mUi->cMessageTitle->setVisible(true);

  mUi->cMessageTitle->setText(stringData->getString(53, 1));
  mUi->cMessageTitle->resize(font.calculateTextWidth(stringData->getString(53, 1)), 20);

  int32_t culture = ratingsData->culture();
  if (culture > 90) {
    mUi->cMessage->setText(stringData->getString(53, 50));
  }
  else {

  }
}

void RatingsAdvisorWidget::handleClickFavor()
{
  const StringData * stringData = Application::language()->stringData();
  RatingsData * ratingsData = game()->city()->ratingsData();
  Font font(Font::Type::NormalWhite);

  mUi->cMessage->setVisible(true);
  mUi->cMessageTitle->setVisible(true);

  mUi->cMessageTitle->setText(stringData->getString(53, 4));
  mUi->cMessageTitle->resize(font.calculateTextWidth(stringData->getString(53, 4)), 20);

  int32_t favor = ratingsData->favor();
  if (favor > 90) {
    mUi->cMessage->setText(stringData->getString(53, 53));
  }
  else {

  }
}

void RatingsAdvisorWidget::handleClickPeace()
{
  const StringData * stringData = Application::language()->stringData();
  RatingsData * ratingsData = game()->city()->ratingsData();
  Font font(Font::Type::NormalWhite);

  mUi->cMessage->setVisible(true);
  mUi->cMessageTitle->setVisible(true);

  mUi->cMessageTitle->setText(stringData->getString(53, 3));
  mUi->cMessageTitle->resize(font.calculateTextWidth(stringData->getString(53, 3)), 20);

  int32_t peace = ratingsData->peace();
  if (peace > 90) {
    mUi->cMessage->setText(stringData->getString(53, 52));
  }
  else {

  }
}

void RatingsAdvisorWidget::handleClickProsperity()
{
  const StringData * stringData = Application::language()->stringData();
  RatingsData * ratingsData = game()->city()->ratingsData();
  Font font(Font::Type::NormalWhite);

  mUi->cMessage->setVisible(true);
  mUi->cMessageTitle->setVisible(true);

  mUi->cMessageTitle->setText(stringData->getString(53, 2));
  mUi->cMessageTitle->resize(font.calculateTextWidth(stringData->getString(53, 2)), 20);

  int32_t prosperity = ratingsData->prosperity();
  if (prosperity > 90) {
    mUi->cMessage->setText(stringData->getString(53, 17));
  }
  else {

  }
}

RatingsButton::RatingsButton(QWidget * parentWidget)
  : Button(parentWidget)
{
  init();
}

void RatingsButton::init()
{
  setEnableBorder(true);

  mTitle.reset(new Label(this));
  mTitle->setGeometry(0, 8, width(), 20);
  mTitle->setTextFont(Font::Type::NormalBlack);
  mTitle->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

  mValue.reset(new Label(this));
  mValue->setGeometry(0, 23, width(), 32);
  mValue->setTextFont(Font::Type::LargeBlack);
  mValue->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

  mTarget.reset(new Label(this));
  mTarget->setGeometry(0, 48, width(), 20);
  mTarget->setTextFont(Font::Type::NormalBlack);
  mTarget->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
}

void RatingsButton::setTarget(int32_t target)
{
  const StringData * stringData = Application::language()->stringData();
  QString textNeeded = stringData->getString(53, 5);
  mTarget->setText(QString::number(target) + " " + textNeeded);
}

void RatingsButton::setTitle(const QString & title)
{
  mTitle->setText(title);
}

void RatingsButton::setValue(int32_t value)
{
  mValue->setText(QString::number(value));
}
