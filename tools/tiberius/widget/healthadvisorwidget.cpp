#include "healthadvisorwidget.h"
#include "ui_healthadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/healthdata.h"
#include "city/populationdata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

HealthAdvisorWidget::HealthAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::HealthAdvisorWidget)
{
  init();
}

HealthAdvisorWidget::~HealthAdvisorWidget()
{
  delete mUi;
}

void HealthAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);
  Font smallPlain(Font::Type::SmallPlain);
  Font normalGreen(Font::Type::NormalGreen);

  int32_t textWidth = 0;
  QString textString;

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+6)->createImage());

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(56, 0));

  mUi->cSubtitle->setTextFont(normalBlack);

  textString = stringData->getString(56, 3);
  textWidth = smallPlain.calculateTextWidth(textString);
  mUi->cWorking->setTextFont(smallPlain);
  mUi->cWorking->setText(textString);
  mUi->cWorking->resize(textWidth, 20);

  textString = stringData->getString(56, 4);
  textWidth = smallPlain.calculateTextWidth(textString);
  mUi->cCareFor->setTextFont(smallPlain);
  mUi->cCareFor->setText(textString);
  mUi->cCareFor->resize(textWidth, 20);

  textString = stringData->getString(56, 5);
  textWidth = smallPlain.calculateTextWidth(textString);
  mUi->cCoverage->setTextFont(smallPlain);
  mUi->cCoverage->setText(textString);
  mUi->cCoverage->resize(textWidth, 20);

  mUi->cBathTotal->setTextFont(normalGreen);
  mUi->cBathWorking->setTextFont(normalGreen);
  mUi->cBathCareFor->setTextFont(normalGreen);
  mUi->cBathCoverage->setTextFont(normalGreen);

  mUi->cBarberTotal->setTextFont(normalGreen);
  mUi->cBarberWorking->setTextFont(normalGreen);
  mUi->cBarberCareFor->setTextFont(normalGreen);
  mUi->cBarberCoverage->setTextFont(normalGreen);

  mUi->cDoctorTotal->setTextFont(normalGreen);
  mUi->cDoctorWorking->setTextFont(normalGreen);
  mUi->cDoctorCareFor->setTextFont(normalGreen);
  mUi->cDoctorCoverage->setTextFont(normalGreen);

  mUi->cHospitalTotal->setTextFont(normalGreen);
  mUi->cHospitalWorking->setTextFont(normalGreen);
  mUi->cHospitalCareFor->setTextFont(normalGreen);
  mUi->cHospitalCoverage->setTextFont(normalGreen);

  mUi->cMessage->setTextFont(normalBlack);
}

void HealthAdvisorWidget::doUpdate()
{
  const StringData * stringData = Application::language()->stringData();

  HealthData * healthData = game()->city()->healthData();
  PopulationData * populationData = game()->city()->populationData();

  int32_t totalBarbers = healthData->totalBarbers();
  int32_t totalBaths = healthData->totalBathHouses();
  int32_t totalClinics = healthData->totalClinics();
  int32_t totalHospitals = healthData->totalHospitals();
  int32_t workingBarbers = healthData->workingBarbers();
  int32_t workingBaths = healthData->workingBathHouses();
  int32_t workingClinics = healthData->workingClinics();
  int32_t workingHospitals = healthData->workingHospitals();

  Font font(Font::Type::NormalGreen);

  int32_t population = populationData->totalPopulation();
  if (population < 200) {
    mUi->cSubtitle->setText(stringData->getString(56, 15));
  }
  else {
    int32_t cityHealthScore = healthData->healthScore();
    int32_t textId = cityHealthScore / 10 + 16;
    mUi->cSubtitle->setText(stringData->getString(56, textId));
  }

  QString bathString = QString::number(totalBaths) + " ";
  bathString += stringData->getString(8, totalBaths == 1 ? 24 : 25);
  mUi->cBathTotal->setText(bathString);
  mUi->cBathTotal->resize(font.calculateTextWidth(mUi->cBathTotal->text()), 20);
  mUi->cBathWorking->setText(QString::number(workingBaths));

  QString barberString = QString::number(totalBarbers) + " ";
  barberString += stringData->getString(8, totalBarbers == 1 ? 26 : 27);
  mUi->cBarberTotal->setText(barberString);
  mUi->cBarberTotal->resize(font.calculateTextWidth(mUi->cBarberTotal->text()), 20);
  mUi->cBarberWorking->setText(QString::number(workingBarbers));

  QString clinicString = QString::number(totalClinics) + " ";
  clinicString += stringData->getString(8, totalClinics == 1 ? 28 : 29);
  mUi->cDoctorTotal->setText(clinicString);
  mUi->cDoctorTotal->resize(font.calculateTextWidth(mUi->cDoctorTotal->text()), 20);
  mUi->cDoctorWorking->setText(QString::number(workingClinics));

  QString hospitalString = QString::number(totalHospitals) + " ";
  hospitalString += stringData->getString(8, totalHospitals == 1 ? 30 : 31);
  mUi->cHospitalTotal->setText(hospitalString);
  mUi->cHospitalTotal->resize(font.calculateTextWidth(mUi->cHospitalTotal->text()), 20);
  mUi->cHospitalWorking->setText(QString::number(workingHospitals));

  int32_t coverage = workingHospitals * HealthData::COVERARGE_PER_HOSPITAL;
  mUi->cBarberCareFor->setText(stringData->getString(56, 2));
  mUi->cBathCareFor->setText(stringData->getString(56, 2));
  mUi->cDoctorCareFor->setText(stringData->getString(56, 2));
  mUi->cHospitalCareFor->setText(QString::number(coverage));

  mUi->cBarberCoverage->setText(stringData->getString(56, 2));
  mUi->cBathCoverage->setText(stringData->getString(56, 2));
  mUi->cDoctorCoverage->setText(stringData->getString(56, 2));

  int32_t percentCoverage = healthData->hosptialCoverage(population);
  if (percentCoverage == 0) {
    mUi->cHospitalCoverage->setText(stringData->getString(57, 10));
  }
  else if (percentCoverage < 100) {
    int32_t stringId = percentCoverage / 10 + 11;
    mUi->cHospitalCoverage->setText(stringData->getString(57, stringId));
  }
  else {
    mUi->cHospitalCoverage->setText(stringData->getString(57, 21));
  }

  int32_t healthAdvice = healthData->healthAdvice();
  mUi->cMessage->setText(stringData->getString(56, 7+healthAdvice));
}
