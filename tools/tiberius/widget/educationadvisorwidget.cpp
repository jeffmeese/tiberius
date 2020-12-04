#include "educationadvisorwidget.h"
#include "ui_educationadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/educationdata.h"
#include "city/populationdata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

EducationAdvisorWidget::EducationAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::EducationAdvisorWidget)
{
  init();
}

EducationAdvisorWidget::~EducationAdvisorWidget()
{
  delete mUi;
}

void EducationAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);
  Font smallPlain(Font::Type::SmallPlain);
  Font normalWhite(Font::Type::NormalWhite);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+8)->createImage());

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(57, 0));

  mUi->cSubtitle->setTextFont(normalBlack);
  mUi->cCanEducate->setTextFont(smallPlain);
  mUi->cWorking->setTextFont(smallPlain);
  mUi->cCoverage->setTextFont(smallPlain);
  mUi->cAcademyCanEducate->setTextFont(normalWhite);
  mUi->cAcademyNumber->setTextFont(normalWhite);
  mUi->cAcademyWorking->setTextFont(normalWhite);
  mUi->cAcademyCoverage->setTextFont(normalWhite);
  mUi->cLibraryCanEducate->setTextFont(normalWhite);
  mUi->cLibraryCoverage->setTextFont(normalWhite);
  mUi->cLibraryNumber->setTextFont(normalWhite);
  mUi->cLibraryWorking->setTextFont(normalWhite);
  mUi->cSchoolCanEducate->setTextFont(normalWhite);
  mUi->cSchoolCoverage->setTextFont(normalWhite);
  mUi->cSchoolNumber->setTextFont(normalWhite);
  mUi->cSchoolWorking->setTextFont(normalWhite);
  mUi->cMessage->setTextFont(normalBlack);

  // Fill in values that don't change
  mUi->cWorking->setText(stringData->getString(57, 4));
  mUi->cCanEducate->setText(stringData->getString(57, 5));
  mUi->cCoverage->setText(stringData->getString(57, 6));
  mUi->cWorking->resize(smallPlain.calculateTextWidth(mUi->cWorking->text()), 20);
  mUi->cCanEducate->resize(smallPlain.calculateTextWidth(mUi->cCanEducate->text()), 20);
  mUi->cCoverage->resize(smallPlain.calculateTextWidth(mUi->cCoverage->text()), 20);
}

void EducationAdvisorWidget::doUpdate()
{
  const EducationData * educationData = game()->city()->educationData();
  const PopulationData * populationData = game()->city()->populationData();
  const StringData * stringData = Application::language()->stringData();

  int32_t totalPopulation = populationData->totalPopulation();
  int32_t academyAged = populationData->academyAgedPopulation();
  int32_t schoolAged = populationData->schoolAgedPopulation();
  int32_t schoolCoverage = educationData->schoolCoverage(schoolAged);
  int32_t academyCoverage = educationData->academyCoverage(academyAged);
  int32_t libraryCoverage = educationData->libraryCoverage(totalPopulation);
  int32_t totalAcademies = educationData->totalAcademies();
  int32_t totalLibraries = educationData->totalLibraries();
  int32_t totalSchools = educationData->totalSchools();
  int32_t workingAcademies = educationData->workingAcademies();
  int32_t workingLibraries = educationData->workingLibraries();
  int32_t workingSchools = educationData->workingSchools();

  // Subtitle
  updateSubtitle(totalPopulation, schoolAged, academyAged);

  // Schools
  updateTotal(mUi->cSchoolNumber, totalSchools, 18);
  updateWorking(mUi->cSchoolWorking, workingSchools);
  updateCanEducate(mUi->cSchoolCanEducate, workingSchools, EducationData::COVERAGE_PER_SCHOOL, 7);
  updateCoverage(mUi->cSchoolCoverage, schoolCoverage);

  // Academies
  updateTotal(mUi->cAcademyNumber, totalAcademies, 20);
  updateWorking(mUi->cAcademyWorking, workingAcademies);
  updateCanEducate(mUi->cAcademyCanEducate, workingAcademies, EducationData::COVERAGE_PER_ACADEMY, 8);
  updateCoverage(mUi->cAcademyCoverage, academyCoverage);

  // Libraries
  updateTotal(mUi->cLibraryNumber, totalLibraries, 22);
  updateWorking(mUi->cLibraryWorking, workingLibraries);
  updateCanEducate(mUi->cLibraryCanEducate, workingLibraries, EducationData::COVERAGE_PER_LIBRARY, 7);
  updateCoverage(mUi->cLibraryCoverage, libraryCoverage);

  int32_t textId = educationData->educationNeeds();
  mUi->cMessage->setText(stringData->getString(57, 22+textId));
}

void EducationAdvisorWidget::updateCanEducate(Label * label, int32_t working, int32_t amount, int32_t textId)
{
  Font font(Font::Type::NormalWhite);
  const StringData * stringData = Application::language()->stringData();

  QString text = QString::number(working * amount) + " ";
  text += stringData->getString(57, textId);
  label->setText(text);
  label->resize(font.calculateTextWidth(text), 20);
}

void EducationAdvisorWidget::updateCoverage(Label * label, int32_t coverage)
{
  const StringData * stringData = Application::language()->stringData();
  if (coverage == 0) {
    label->setText(stringData->getString(57, 10));
  }
  else if (coverage < 100) {
    int32_t textId = coverage / 10 + 11;
    label->setText(stringData->getString(57, textId));
  }
  else {
    label->setText(stringData->getString(57, 21));
  }
}

void EducationAdvisorWidget::updateSubtitle(int32_t population, int32_t schoolAged, int32_t academyAged)
{
  Font font(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();

  QString subtitleString;
  subtitleString += QString::number(population) + " ";
  subtitleString += stringData->getString(57, 1) + " ";
  subtitleString += QString::number(schoolAged) + " ";
  subtitleString += stringData->getString(57, 2) + " ";
  subtitleString += QString::number(academyAged) + " ";
  subtitleString += stringData->getString(57, 3);
  mUi->cSubtitle->setText(subtitleString);
  mUi->cSubtitle->resize(font.calculateTextWidth(mUi->cSubtitle->text()), 20);
}

void EducationAdvisorWidget::updateWorking(Label * label, int32_t total)
{
  QString text = QString::number(total);
  label->setText(text);
}

void EducationAdvisorWidget::updateTotal(Label * label, int32_t total, int32_t textId)
{
  Font font(Font::Type::NormalWhite);

  const StringData * stringData = Application::language()->stringData();
  QString text = QString::number(total) + " ";
  text += stringData->getString(8, total == 1 ? textId : textId+1);
  label->setText(text);
  label->resize(font.calculateTextWidth(text), 20);
}
