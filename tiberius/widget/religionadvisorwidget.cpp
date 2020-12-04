#include "religionadvisorwidget.h"
#include "ui_religionadvisorwidget.h"

#include "application/application.h"
#include "application/settings.h"

#include "city/city.h"
#include "city/religiondata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "religion/god.h"

ReligionAdvisorWidget::ReligionAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::ReligionAdvisorWidget)
{
  init();
}

ReligionAdvisorWidget::~ReligionAdvisorWidget()
{
  delete mUi;
}

void ReligionAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalWhite(Font::Type::NormalWhite);
  Font smallPlain(Font::Type::SmallPlain);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+9)->createImage());
  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(59, 0));

  mUi->cSmall->setTextFont(smallPlain);
  mUi->cSmall->setText(stringData->getString(59, 1));
  mUi->cSmall->resize(smallPlain.calculateTextWidth(mUi->cSmall->text()), 20);

  mUi->cLarge->setTextFont(smallPlain);
  mUi->cLarge->setText(stringData->getString(59, 2));
  mUi->cLarge->resize(smallPlain.calculateTextWidth(mUi->cLarge->text()), 20);

  mUi->cMonths->setTextFont(smallPlain);
  mUi->cMonths->setText(stringData->getString(59, 6));
  mUi->cMonths->resize(smallPlain.calculateTextWidth(mUi->cMonths->text()), 20);

  mUi->cTemples->setTextFont(smallPlain);
  mUi->cTemples->setText(stringData->getString(59, 5));
  mUi->cTemples->resize(smallPlain.calculateTextWidth(mUi->cTemples->text()), 20);

  mUi->cSince->setTextFont(smallPlain);
  mUi->cSince->setText(stringData->getString(59, 9));
  mUi->cSince->resize(smallPlain.calculateTextWidth(mUi->cSince->text()), 20);

  mUi->cFestival->setTextFont(smallPlain);
  mUi->cFestival->setText(stringData->getString(59, 7));
  mUi->cFestival->resize(smallPlain.calculateTextWidth(mUi->cFestival->text()), 20);

  mUi->cGodsAre->setTextFont(smallPlain);
  mUi->cGodsAre->setText(stringData->getString(59, 3));
  mUi->cGodsAre->resize(smallPlain.calculateTextWidth(mUi->cGodsAre->text()), 20);

  mUi->cOracles->setTextFont(normalWhite);
  mUi->cOracles->setText(stringData->getString(59, 8));
  mUi->cOracles->resize(normalWhite.calculateTextWidth(mUi->cOracles->text()), 20);

  mUi->cCeresName->setTextFont(normalWhite);
  mUi->cCeresDescription->setTextFont(smallPlain);
  mUi->cCeresSmall->setTextFont(normalWhite);
  mUi->cCeresLarge->setTextFont(normalWhite);
  mUi->cCeresMonths->setTextFont(normalWhite);
  mUi->cCeresSentiment->setTextFont(normalWhite);

  mUi->cNeptuneName->setTextFont(normalWhite);
  mUi->cNeptuneDescription->setTextFont(smallPlain);
  mUi->cNeptuneSmall->setTextFont(normalWhite);
  mUi->cNeptuneLarge->setTextFont(normalWhite);
  mUi->cNeptuneMonths->setTextFont(normalWhite);
  mUi->cNeptuneSentiment->setTextFont(normalWhite);

  mUi->cMercuryName->setTextFont(normalWhite);
  mUi->cMercuryDescription->setTextFont(smallPlain);
  mUi->cMercurySmall->setTextFont(normalWhite);
  mUi->cMercuryLarge->setTextFont(normalWhite);
  mUi->cMercuryMonths->setTextFont(normalWhite);
  mUi->cMercurySentiment->setTextFont(normalWhite);

  mUi->cMarsName->setTextFont(normalWhite);
  mUi->cMarsDescription->setTextFont(smallPlain);
  mUi->cMarsSmall->setTextFont(normalWhite);
  mUi->cMarsLarge->setTextFont(normalWhite);
  mUi->cMarsMonths->setTextFont(normalWhite);
  mUi->cMarsSentiment->setTextFont(normalWhite);

  mUi->cVenusName->setTextFont(normalWhite);
  mUi->cVenusDescription->setTextFont(smallPlain);
  mUi->cVenusSmall->setTextFont(normalWhite);
  mUi->cVenusLarge->setTextFont(normalWhite);
  mUi->cVenusMonths->setTextFont(normalWhite);
  mUi->cVenusSentiment->setTextFont(normalWhite);

  mUi->cNumOracles->setTextFont(normalWhite);

  mUi->cGodsOff->setText(stringData->getString(59, 43));
}

void ReligionAdvisorWidget::doUpdate()
{
  Font normalWhite(Font::Type::NormalWhite);
  Font smallPlain(Font::Type::SmallPlain);

  ReligionData * religionData = game()->city()->religionData();
  God * ceres = religionData->getGod(God::Type::Ceres);
  God * neptune = religionData->getGod(God::Type::Neptune);
  God * mercury = religionData->getGod(God::Type::Mercury);
  God * mars = religionData->getGod(God::Type::Mars);
  God * venus = religionData->getGod(God::Type::Venus);

  Settings & settings = Application::settings();
  this->resize(640, settings.godEffectsEnabled() ? 272 : 320);
  mUi->cGodsOff->setVisible(!settings.godEffectsEnabled());

  mUi->cCeresName->setText(ceres->name());
  mUi->cCeresDescription->setText(ceres->description());
  mUi->cCeresName->resize(normalWhite.calculateTextWidth(mUi->cCeresName->text()), 20);
  mUi->cCeresDescription->resize(smallPlain.calculateTextWidth(mUi->cCeresDescription->text()), 20);
  mUi->cCeresSmall->setText(QString::number(ceres->smallTemples()));
  mUi->cCeresLarge->setText(QString::number(ceres->largeTemples()));
  mUi->cCeresMonths->setText(QString::number(ceres->monthsSinceFestival()));
  mUi->cCeresSentiment->setText(ceres->sentimentString());
  mUi->cCeresSentiment->resize(normalWhite.calculateTextWidth(ceres->sentimentString()), 20);

  mUi->cNeptuneName->setText(neptune->name());
  mUi->cNeptuneDescription->setText(neptune->description());
  mUi->cNeptuneName->resize(normalWhite.calculateTextWidth(mUi->cNeptuneName->text()), 20);
  mUi->cNeptuneDescription->resize(smallPlain.calculateTextWidth(mUi->cNeptuneDescription->text()), 20);
  mUi->cNeptuneSmall->setText(QString::number(neptune->smallTemples()));
  mUi->cNeptuneLarge->setText(QString::number(neptune->largeTemples()));
  mUi->cNeptuneMonths->setText(QString::number(neptune->monthsSinceFestival()));
  mUi->cNeptuneSentiment->setText(neptune->sentimentString());
  mUi->cNeptuneSentiment->resize(normalWhite.calculateTextWidth(neptune->sentimentString()), 20);

  mUi->cMercuryName->setText(mercury->name());
  mUi->cMercuryDescription->setText(mercury->description());
  mUi->cMercuryName->resize(normalWhite.calculateTextWidth(mUi->cMercuryName->text()), 20);
  mUi->cMercuryDescription->resize(smallPlain.calculateTextWidth(mUi->cMercuryDescription->text()), 20);
  mUi->cMercurySmall->setText(QString::number(mercury->smallTemples()));
  mUi->cMercuryLarge->setText(QString::number(mercury->largeTemples()));
  mUi->cMercuryMonths->setText(QString::number(mercury->monthsSinceFestival()));
  mUi->cMercurySentiment->setText(mercury->sentimentString());
  mUi->cMercurySentiment->resize(normalWhite.calculateTextWidth(mercury->sentimentString()), 20);

  mUi->cMarsName->setText(mars->name());
  mUi->cMarsDescription->setText(mars->description());
  mUi->cMarsName->resize(normalWhite.calculateTextWidth(mUi->cMarsName->text()), 20);
  mUi->cMarsDescription->resize(smallPlain.calculateTextWidth(mUi->cMarsDescription->text()), 20);
  mUi->cMarsSmall->setText(QString::number(mars->smallTemples()));
  mUi->cMarsLarge->setText(QString::number(mars->largeTemples()));
  mUi->cMarsMonths->setText(QString::number(mars->monthsSinceFestival()));
  mUi->cMarsSentiment->setText(mars->sentimentString());
  mUi->cMarsSentiment->resize(normalWhite.calculateTextWidth(mars->sentimentString()), 20);

  mUi->cVenusName->setText(venus->name());
  mUi->cVenusDescription->setText(venus->description());
  mUi->cVenusName->resize(normalWhite.calculateTextWidth(mUi->cVenusName->text()), 20);
  mUi->cVenusDescription->resize(smallPlain.calculateTextWidth(mUi->cVenusDescription->text()), 20);
  mUi->cVenusSmall->setText(QString::number(venus->smallTemples()));
  mUi->cVenusLarge->setText(QString::number(venus->largeTemples()));
  mUi->cVenusMonths->setText(QString::number(venus->monthsSinceFestival()));
  mUi->cVenusSentiment->setText(venus->sentimentString());
  mUi->cVenusSentiment->resize(normalWhite.calculateTextWidth(venus->sentimentString()), 20);

  mUi->cNumOracles->setText(QString::number(religionData->oracles()));

  mUi->cMessage->setText(religionData->needString());
}
