#include "chiefadvisorwidget.h"
#include "ui_chiefadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/educationdata.h"
#include "city/entertainmentdata.h"
#include "city/financedata.h"
#include "city/healthdata.h"
#include "city/labordata.h"
#include "city/militarydata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

ChiefAdvisorWidget::ChiefAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::ChiefAdvisorWidget)
{
  init();
}

ChiefAdvisorWidget::~ChiefAdvisorWidget()
{
  delete mUi;
}

void ChiefAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+11)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(61, 0));

  int32_t imageId = imageData->getGroupBaseImageId(GROUP_BULLET);
  mUi->cButton1->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton2->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton3->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton4->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton5->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton6->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton7->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton8->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton9->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton10->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton11->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
  mUi->cButton12->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));

  mUi->cEmploymentLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cFinanceLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cMigrationLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cFoodLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cConsumptionLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cMilitaryLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cCrimeLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cHealthLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cEducationLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cCityHealthLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cEntertainmentLabel->setTextFont(Font::Type::NormalWhite);
  mUi->cSentimentLabel->setTextFont(Font::Type::NormalWhite);

  mUi->cEmploymentLabel->setText(stringData->getString(61, 1));
  mUi->cFinanceLabel->setText(stringData->getString(61, 2));
  mUi->cMigrationLabel->setText(stringData->getString(61, 3));
  mUi->cFoodLabel->setText(stringData->getString(61, 4));
  mUi->cConsumptionLabel->setText(stringData->getString(61, 62));
  mUi->cMilitaryLabel->setText(stringData->getString(61, 5));
  mUi->cCrimeLabel->setText(stringData->getString(61, 6));
  mUi->cHealthLabel->setText(stringData->getString(61, 7));
  mUi->cEducationLabel->setText(stringData->getString(61, 8));
  mUi->cCityHealthLabel->setText(stringData->getString(61, 9));
  mUi->cEntertainmentLabel->setText(stringData->getString(61, 10));
  mUi->cSentimentLabel->setText(stringData->getString(61, 11));

  mUi->cEmploymentData->setTextFont(Font::Type::NormalGreen);
  mUi->cFinanceData->setTextFont(Font::Type::NormalGreen);
  mUi->cMigrationData->setTextFont(Font::Type::NormalGreen);
  mUi->cFoodData->setTextFont(Font::Type::NormalGreen);
  mUi->cConsumptionData->setTextFont(Font::Type::NormalGreen);
  mUi->cMilitaryData->setTextFont(Font::Type::NormalGreen);
  mUi->cCrimeData->setTextFont(Font::Type::NormalGreen);
  mUi->cHealthData->setTextFont(Font::Type::NormalGreen);
  mUi->cEducationData->setTextFont(Font::Type::NormalGreen);
  mUi->cCityHealthData->setTextFont(Font::Type::NormalGreen);
  mUi->cEntertainmentData->setTextFont(Font::Type::NormalGreen);
  mUi->cSentimentData->setTextFont(Font::Type::NormalGreen);

  mUi->cEmploymentData->setText("");
  mUi->cFinanceData->setText("");
  mUi->cMigrationData->setText("");
  mUi->cFoodData->setText("");
  mUi->cConsumptionData->setText("");
  mUi->cMilitaryData->setText("");
  mUi->cCrimeData->setText("");
  mUi->cHealthData->setText("");
  mUi->cEducationData->setText("");
  mUi->cCityHealthData->setText("");
  mUi->cEntertainmentData->setText("");
  mUi->cSentimentData->setText("");
}

void ChiefAdvisorWidget::doUpdate()
{
  mUi->cEmploymentData->setText("");
  mUi->cFinanceData->setText("");
  mUi->cMigrationData->setText("");
  mUi->cFoodData->setText("");
  mUi->cConsumptionData->setText("");
  mUi->cMilitaryData->setText("");
  mUi->cCrimeData->setText("");
  mUi->cHealthData->setText("");
  mUi->cEducationData->setText("");
  mUi->cCityHealthData->setText("");
  mUi->cEntertainmentData->setText("");
  mUi->cSentimentData->setText("");

  updateEmploymentData();
  updateFinanceData();
  updateMigrationData();
  updateFoodData();
  updateConsumptionData();
  updateMilitaryData();
  updateCrimeData();
  updateHealthData();
  updateEducationData();
  updateCityHealthData();
  updateEntertainmentData();
  updateSentimentData();
}

void ChiefAdvisorWidget::updateCityHealthData()
{

}

void ChiefAdvisorWidget::updateConsumptionData()
{

}

void ChiefAdvisorWidget::updateCrimeData()
{

}

void ChiefAdvisorWidget::updateEducationData()
{

}

void ChiefAdvisorWidget::updateEmploymentData()
{
  const StringData * stringData = Application::language()->stringData();

  int32_t unemploymentPercentage = game()->city()->laborData()->unemploymentPercentage();
  int32_t workersNeeded = game()->city()->laborData()->workersNeeded();
  QString textString;
  if (unemploymentPercentage == 0) {
    if (workersNeeded == 0) {
      mUi->cEmploymentData->setTextFont(Font::Type::NormalGreen);
      textString = stringData->getString(61, 14);
    }
    else {
      mUi->cEmploymentData->setTextFont(Font::Type::NormalRed);
      textString = stringData->getString(61, 13) + " " + QString::number(workersNeeded);
      if (workersNeeded == 1)
        textString += " " + stringData->getString(8, 12);
      else {
        textString += " " + stringData->getString(8, 13);
      }
    }
  }
  else {
    mUi->cEmploymentData->setTextFont(Font::Type::NormalRed);
    textString = stringData->getString(61, 12) + " " + QString::number(unemploymentPercentage) + "%";
  }
  mUi->cEmploymentData->setText(textString);
}


void ChiefAdvisorWidget::updateEntertainmentData()
{

}

void ChiefAdvisorWidget::updateFinanceData()
{
  const StringData * stringData = Application::language()->stringData();

  QString textString;

  int32_t previousYearBalance = game()->city()->financeData()->previousYearBalance();
  int32_t totalDenarii = game()->city()->financeData()->totalDenarii();
  if (totalDenarii < previousYearBalance) {
    mUi->cFinanceData->setTextFont(Font::Type::NormalRed);
    textString = stringData->getString(61, 16);
    textString += QStringLiteral("%1").arg((previousYearBalance-totalDenarii), 7);
    textString += " " + stringData->getString(6, 0);
  }
  else if (totalDenarii > previousYearBalance) {
    mUi->cFinanceData->setTextFont(Font::Type::NormalGreen);
    textString = stringData->getString(61, 15);
    textString += QStringLiteral("%1").arg((totalDenarii-previousYearBalance), 7);
    textString += " " + stringData->getString(6, 0);
  }
  else {
    mUi->cFinanceData->setTextFont(Font::Type::NormalGreen);
    textString = stringData->getString(61, 17);
  }

  mUi->cFinanceData->setText(textString);
}

void ChiefAdvisorWidget::updateFoodData()
{

}

void ChiefAdvisorWidget::updateHealthData()
{

}

void ChiefAdvisorWidget::updateMigrationData()
{

}

void ChiefAdvisorWidget::updateMilitaryData()
{

}

void ChiefAdvisorWidget::updateSentimentData()
{

}

