#include "entertainmentadvisorwidget.h"
#include "ui_entertainmentadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/entertainmentdata.h"
#include "city/populationdata.h"

#include "dialog/festivaldialog.h"

#include "game/game.h"
#include "game/player.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

EntertainmentAdvisorWidget::EntertainmentAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::EntertainmentAdvisorWidget)
{
  init();
}

EntertainmentAdvisorWidget::~EntertainmentAdvisorWidget()
{
  delete mUi;
}

void EntertainmentAdvisorWidget::handleCreateFestival()
{
  FestivalDialog dialog(this);
  dialog.setSelectedGod(mFestivalGod);
  if (dialog.exec() == QDialog::Rejected)
    return;

  Festival::Type type = dialog.festivalType();
  int32_t cost = dialog.festivalCost();
  int32_t wineRequired = dialog.festivalWine();

  Player * player = game()->player();
  EntertainmentData * data = game()->city()->entertainmentData();
  data->setFestivalGod(dialog.selectedGod());

  std::unique_ptr<Festival> festival(new Festival(type));
  festival->setCost(cost);
  festival->setGod(dialog.selectedGod());
  festival->setWineRequired(wineRequired);

  player->decreaseSavings(cost);
  data->setFestival(std::move(festival));
  emit changed();

  doUpdate();
}

void EntertainmentAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);
  uint32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  Font normalBlack(Font::Type::NormalBlack);
  Font largeBlack(Font::Type::LargeBlack);
  Font smallPlain(Font::Type::SmallPlain);
  Font normalWhite(Font::Type::NormalWhite);

  mFestivalGod = God::Type::Ceres;

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+7)->createImage());

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(58, 0));

  mUi->cWorking->setTextFont(smallPlain);
  mUi->cShows->setTextFont(smallPlain);
  mUi->cCanEntertain->setTextFont(smallPlain);
  mUi->cCoverage->setTextFont(smallPlain);

  mUi->cWorking->setText(stringData->getString(58, 1));
  mUi->cShows->setText(stringData->getString(58, 2));
  mUi->cCanEntertain->setText(stringData->getString(58, 3));
  mUi->cCoverage->setText(stringData->getString(58, 4));

  mUi->cWorking->resize(smallPlain.calculateTextWidth(mUi->cWorking->text()), 20);
  mUi->cShows->resize(smallPlain.calculateTextWidth(mUi->cShows->text()), 20);
  mUi->cCanEntertain->resize(smallPlain.calculateTextWidth(mUi->cCanEntertain->text()), 20);
  mUi->cCoverage->resize(smallPlain.calculateTextWidth(mUi->cCoverage->text()), 20);

  mUi->cAmpitheaterCanEntertain->setTextFont(normalWhite);
  mUi->cAmpitheaterCoverage->setTextFont(normalWhite);
  mUi->cAmpitheaterShows->setTextFont(normalWhite);
  mUi->cAmpitheaterTotal->setTextFont(normalWhite);
  mUi->cAmpitheaterWorking->setTextFont(normalWhite);

  mUi->cColosseumCanEntertain->setTextFont(normalWhite);
  mUi->cColosseumCoverage->setTextFont(normalWhite);
  mUi->cColosseumShows->setTextFont(normalWhite);
  mUi->cColosseumTotal->setTextFont(normalWhite);
  mUi->cColosseumWorking->setTextFont(normalWhite);

  mUi->cHippodromeCanEntertain->setTextFont(normalWhite);
  mUi->cHippodromeCoverage->setTextFont(normalWhite);
  mUi->cHippodromeShows->setTextFont(normalWhite);
  mUi->cHippodromeTotal->setTextFont(normalWhite);
  mUi->cHippodromeWorking->setTextFont(normalWhite);

  mUi->cTheaterCanEntertain->setTextFont(normalWhite);
  mUi->cTheaterCoverage->setTextFont(normalWhite);
  mUi->cTheaterShows->setTextFont(normalWhite);
  mUi->cTheatersTotal->setTextFont(normalWhite);
  mUi->cTheatersWorking->setTextFont(normalWhite);

  mUi->cMessage->setTextFont(normalBlack);

  mUi->cFestivals->setTextFont(largeBlack);
  mUi->cMonthsSinceFestival->setTextFont(normalWhite);
  mUi->cCreateFestival->setTextFont(normalWhite);
  mUi->cSentiment->setTextFont(normalWhite);
  mUi->cPreparing->setTextFont(normalWhite);

  mUi->cFestivals->setText(stringData->getString(58, 17));
  mUi->cFestivals->resize(largeBlack.calculateTextWidth(mUi->cFestivals->text()), 32);
  mUi->cFestivalImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(panelId+15)->createImage()));

  mUi->cHippodromeCanEntertain->setText(stringData->getString(56, 2));
  mUi->cCreateFestival->setText(stringData->getString(58, 16));
  mUi->cPreparing->setText(stringData->getString(58, 34));

  mUi->cCreateFestival->setEnableBorder(true);
  mUi->cCreateFestival->setEnableFocusBorder(true);

  connect(mUi->cCreateFestival, SIGNAL(clicked()), SLOT(handleCreateFestival()));
}

void EntertainmentAdvisorWidget::doUpdate()
{
  Font white(Font::Type::NormalWhite);
  const StringData * stringData = Application::language()->stringData();
  EntertainmentData * entertainmentData = game()->city()->entertainmentData();
  PopulationData * populationData = game()->city()->populationData();

  int32_t population = populationData->totalPopulation();
  int32_t totalTheaters = entertainmentData->totalTheaters();
  int32_t totalAmpitheaters = entertainmentData->totalAmpitheaters();
  int32_t totalColossuems = entertainmentData->totalColosseums();
  int32_t totalHippodromes = entertainmentData->totalHippodromes();

  mFestivalGod = entertainmentData->festivalGod();

  mUi->cAmpitheaterTotal->setText(QString::number(totalAmpitheaters) + " " + stringData->getString(8, totalAmpitheaters == 1 ? 36 : 37));
  mUi->cColosseumTotal->setText(QString::number(totalColossuems) + " " + stringData->getString(8, totalColossuems == 1 ? 38 : 39));
  mUi->cHippodromeTotal->setText(QString::number(totalHippodromes) + " " + stringData->getString(8, totalHippodromes == 1 ? 40 : 41));
  mUi->cTheatersTotal->setText(QString::number(totalTheaters) + " " + stringData->getString(8, totalTheaters == 1 ? 34 : 35));

  mUi->cAmpitheaterWorking->setText(QString::number(entertainmentData->workingAmpitheaters()));
  mUi->cColosseumWorking->setText(QString::number(entertainmentData->workingColosseums()));
  mUi->cHippodromeWorking->setText(QString::number(entertainmentData->workingHippodromes()));
  mUi->cTheatersWorking->setText(QString::number(entertainmentData->workingTheaters()));

  mUi->cAmpitheaterShows->setText(QString::number(entertainmentData->ampitheaterShows()));
  mUi->cColosseumShows->setText(QString::number(entertainmentData->colosseumShows()));
  mUi->cHippodromeShows->setText(QString::number(entertainmentData->hippodromeShows()));
  mUi->cTheaterShows->setText(QString::number(entertainmentData->theaterShows()));

  mUi->cAmpitheaterCanEntertain->setText(QString::number(entertainmentData->ampitheaterCapacity()));
  mUi->cColosseumCanEntertain->setText(QString::number(entertainmentData->colosseumCapacity()));
  mUi->cTheaterCanEntertain->setText(QString::number(entertainmentData->theaterCapacity()));

  mUi->cAmpitheaterCoverage->setText(entertainmentData->coverageString(entertainmentData->ampitheaterCoverage(population)));
  mUi->cColosseumCoverage->setText(entertainmentData->coverageString(entertainmentData->colosseumCoverage(population)));
  mUi->cHippodromeCoverage->setText(entertainmentData->coverageString(entertainmentData->hippodromeCoverage(population)));
  mUi->cTheaterCoverage->setText(entertainmentData->coverageString(entertainmentData->theaterCoverage(population)));

  mUi->cAmpitheaterTotal->resize(white.calculateTextWidth(mUi->cAmpitheaterTotal->text()), 20);
  mUi->cColosseumTotal->resize(white.calculateTextWidth(mUi->cAmpitheaterTotal->text()), 20);
  mUi->cHippodromeTotal->resize(white.calculateTextWidth(mUi->cHippodromeTotal->text()), 20);
  mUi->cTheatersTotal->resize(white.calculateTextWidth(mUi->cTheatersTotal->text()), 20);

  QString festivalString = QString::number(entertainmentData->monthsSinceFestival());
  festivalString += " " + stringData->getString(59, 6) + " ";
  festivalString += stringData->getString(58, 15);
  mUi->cMonthsSinceFestival->setText(festivalString);
  mUi->cMonthsSinceFestival->resize(white.calculateTextWidth(festivalString), 20);

  mUi->cMessage->setText(entertainmentData->needsString());

  mUi->cSentiment->setText(stringData->getString(58, 18 + entertainmentData->festivalSentiment()));

  Festival * festival = entertainmentData->festival();
  mUi->cCreateFestival->setVisible(festival == nullptr);
  mUi->cPreparing->setVisible(festival != nullptr);
}
