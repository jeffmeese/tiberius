#include "laboradvisorwidget.h"
#include "ui_laboradvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/labordata.h"

#include "dialog/prioritydialog.h"

#include "game/game.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "language/language.h"
#include "language/stringdata.h"
#include "language/stringdatagroup.h"

#include <QPainter>

LaborAdvisorWidget::LaborAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::LaborAdvisorWidget)
{
  init();
}

LaborAdvisorWidget::~LaborAdvisorWidget()
{
  delete mUi;
}

void LaborAdvisorWidget::changeEngineering()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Engineering, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeEntertainment()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Entertainment, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeFood()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Food, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeGovernance()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Governance, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeHealth()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Health, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeIndustry()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Industry, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changeMilitary()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Military, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::changePrefectures()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    const LaborData::Category & c = game()->city()->laborData()->category(LaborData::Type::Prefectures);
    if (c.priority != priority) {
      game()->city()->laborData()->updatePriority(LaborData::Type::Prefectures, priority);
      updateLabor();
    }
  }
}

void LaborAdvisorWidget::changeWater()
{
  int priority = showPriorityDialog();
  if (priority != -1 && game() != nullptr) {
    game()->city()->laborData()->updatePriority(LaborData::Type::Water, priority);
    updateLabor();
  }
}

void LaborAdvisorWidget::decreaseWages()
{
  if (game() != nullptr)
    game()->city()->laborData()->decreaseWage();

  updateWages();
}

void LaborAdvisorWidget::doUpdate()
{
  updateWages();
  updateLabor();
  updateEmployment();
}

void LaborAdvisorWidget::increaseWages()
{
  if (game() != nullptr)
    game()->city()->laborData()->increaseWage();

  updateWages();
}

void LaborAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);
  int32_t baseImageId = imageData->getGroupBaseImageId(GROUP_LABOR_PRIORITY_LOCK);

  mUi->setupUi(this);

  Font largeBlack(Font::Type::LargeBlack);
  Font smallPlain(Font::Type::SmallPlain);
  Font normalBlack(Font::Type::NormalBlack);
  Font normalWhite(Font::Type::NormalWhite);

  mUi->cIconButton->move(10, 10);
  mUi->cIconButton->resize(40, 40);
  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId)->createImage());
  mUi->cIconButton->setPressedImage(imageData->getImageRecord(advisorsId+13)->createImage());

  mUi->cTitle->setGeometry(60, 12, 545, 35);
  mUi->cTitle->setTextFont(largeBlack);

  mUi->cPriority->setGeometry(60, 52, 63, 20);
  mUi->cPriority->setTextFont(smallPlain);
  mUi->cPriority->setText(stringData->getString(50, 21));
  mUi->cPriority->resize(smallPlain.calculateTextWidth(mUi->cPriority->text()), 20);

  mUi->cSector->setGeometry(170, 52, 63, 20);
  mUi->cSector->setTextFont(smallPlain);
  mUi->cSector->setText(stringData->getString(50, 22));
  mUi->cSector->resize(smallPlain.calculateTextWidth(mUi->cSector->text()), 20);

  mUi->cNeed->setGeometry(400, 52, 63, 20);
  mUi->cNeed->setTextFont(smallPlain);
  mUi->cNeed->setText(stringData->getString(50, 23));
  mUi->cNeed->resize(smallPlain.calculateTextWidth(mUi->cNeed->text()), 20);

  mUi->cHave->setGeometry(500, 52, 63, 20);
  mUi->cHave->setTextFont(smallPlain);
  mUi->cHave->setText(stringData->getString(50, 24));
  mUi->cHave->resize(smallPlain.calculateTextWidth(mUi->cHave->text()), 20);

  mUi->cNumEmployed->move(32, 320);
  mUi->cNumEmployed->setTextFont(normalBlack);

  mUi->cEmployed->setTextFont(normalBlack);
  mUi->cEmployed->setText(stringData->getString(50, 12));
  mUi->cEmployed->resize(normalBlack.calculateTextWidth(mUi->cEmployed->text()), 20);

  mUi->cNumUnemployed->setTextFont(normalBlack);

  mUi->cUnemployed->setTextFont(normalBlack);
  mUi->cUnemployed->setText(stringData->getString(50, 13));
  mUi->cUnemployed->resize(normalBlack.calculateTextWidth(mUi->cUnemployed->text()), 20);

  mUi->cPercentUnemployed->setTextFont(normalBlack);

  mUi->cWages->setTextFont(normalWhite);
  mUi->cWages->setText(stringData->getString(50, 14));
  mUi->cWages->resize(normalWhite.calculateTextWidth(mUi->cWages->text()), 20);

  mUi->cCityWages->setTextFont(normalWhite);

  mUi->cWagesDenarii->setTextFont(normalWhite);
  mUi->cWagesDenarii->setText(stringData->getString(50, 15));
  mUi->cWagesDenarii->resize(normalWhite.calculateTextWidth(mUi->cWagesDenarii->text()), 20);

  mUi->cRomePays->setTextFont(normalWhite);
  mUi->cRomePays->setText(stringData->getString(50, 18));
  mUi->cRomePays->resize(normalWhite.calculateTextWidth(mUi->cRomePays->text()), 20);

  mUi->cRomeWages->setTextFont(normalWhite);

  mUi->cBill->setTextFont(normalBlack);
  mUi->cBill->setText(stringData->getString(50, 19));

  mUi->cBillAmount->setTextFont(normalBlack);

  mUi->cDenarii->setTextFont(normalBlack);
  mUi->cDenarii->setText(stringData->getString(6, 0));

  mUi->cWagesDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cWagesDown->setPressedImage(imageData->getImageRecord(18)->createImage());
  mUi->cWagesUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cWagesUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  initLaborButton(mUi->cIndustryButton, stringData->getString(50, 1));
  initLaborButton(mUi->cFoodButton, stringData->getString(50, 2));
  initLaborButton(mUi->cEngineeringButton, stringData->getString(50, 3));
  initLaborButton(mUi->cWaterButton, stringData->getString(50, 4));
  initLaborButton(mUi->cPrefectureButton, stringData->getString(50, 5));
  initLaborButton(mUi->cMilitaryButton, stringData->getString(50, 6));
  initLaborButton(mUi->cEntertainmentButton, stringData->getString(50, 7));
  initLaborButton(mUi->cHealthButton, stringData->getString(50, 8));
  initLaborButton(mUi->cGovernanceButton, stringData->getString(50, 9));

  connect(mUi->cIndustryButton, SIGNAL(clicked()), SLOT(changeIndustry()));
  connect(mUi->cFoodButton, SIGNAL(clicked()), SLOT(changeFood()));
  connect(mUi->cEngineeringButton, SIGNAL(clicked()), SLOT(changeEngineering()));
  connect(mUi->cWaterButton, SIGNAL(clicked()), SLOT(changeWater()));
  connect(mUi->cPrefectureButton, SIGNAL(clicked()), SLOT(changePrefectures()));
  connect(mUi->cMilitaryButton, SIGNAL(clicked()), SLOT(changeMilitary()));
  connect(mUi->cEntertainmentButton, SIGNAL(clicked()), SLOT(changeEntertainment()));
  connect(mUi->cHealthButton, SIGNAL(clicked()), SLOT(changeHealth()));
  connect(mUi->cGovernanceButton, SIGNAL(clicked()), SLOT(changeGovernance()));
  connect(mUi->cWagesDown, SIGNAL(clicked()), SLOT(decreaseWages()));
  connect(mUi->cWagesUp, SIGNAL(clicked()), SLOT(increaseWages()));
}

void LaborAdvisorWidget::initLaborButton(LaborAdvisorButton * button, const QString & text)
{
  button->setHave(0);
  button->setNeed(0);
  button->setSector(text);
  button->setPriority(0);
}

int LaborAdvisorWidget::showPriorityDialog()
{
  int32_t maxPriority = LaborData::MAX_LABOR_CATEGORIES;
  if (game() != nullptr) {
    maxPriority = game()->city()->laborData()->minPriorityAvaiable();
  }

  PriorityDialog dialog(this);
  dialog.setMaxPriority(maxPriority);
  int response = dialog.exec();
  if (response == QDialog::Rejected) {
    return -1;
  }

  return dialog.selectedPriority();
}

void LaborAdvisorWidget::updateEmployment()
{
  int32_t employed = 0;
  int32_t unemployed = 0;
  int32_t percent = 0;
  if (game() != nullptr) {
    employed = game()->city()->laborData()->totalEmployed();
    unemployed = game()->city()->laborData()->totalUnemployed();
    percent = game()->city()->laborData()->unemploymentPercentage();
  }

  QString sEmployed = QString::number(employed) + " ";
  QString sUnemployed = QString::number(unemployed) + " ";
  QString sPercent = QStringLiteral("%1%)").arg(percent, 3);

  Font f = mUi->cNumEmployed->textFont();
  int32_t width = 0;
  width += f.calculateTextWidth(sEmployed);
  mUi->cNumEmployed->resize(width, 20);
  mUi->cNumEmployed->setText(sEmployed);
  mUi->cEmployed->move(32 + width, 320);
  width += f.calculateTextWidth(mUi->cEmployed->text());

  mUi->cNumUnemployed->move(50+width, 320);
  width += f.calculateTextWidth(sUnemployed);
  mUi->cNumUnemployed->resize(f.calculateTextWidth(sUnemployed), 20);
  mUi->cNumUnemployed->setText(sUnemployed);
  mUi->cUnemployed->move(50+width, 320);
  width += f.calculateTextWidth(mUi->cUnemployed->text());

  mUi->cPercentUnemployed->move(50 + width, 320);
  mUi->cPercentUnemployed->resize(f.calculateTextWidth(sPercent), 20);
  mUi->cPercentUnemployed->setText(sPercent);
}

void LaborAdvisorWidget::updateLabor()
{
  updateLaborCategory(mUi->cIndustryButton, LaborData::Type::Industry);
  updateLaborCategory(mUi->cFoodButton, LaborData::Type::Food);
  updateLaborCategory(mUi->cEngineeringButton, LaborData::Type::Engineering);
  updateLaborCategory(mUi->cWaterButton, LaborData::Type::Water);
  updateLaborCategory(mUi->cPrefectureButton, LaborData::Type::Prefectures);
  updateLaborCategory(mUi->cMilitaryButton, LaborData::Type::Military);
  updateLaborCategory(mUi->cEntertainmentButton, LaborData::Type::Entertainment);
  updateLaborCategory(mUi->cHealthButton, LaborData::Type::Health);
  updateLaborCategory(mUi->cGovernanceButton, LaborData::Type::Governance);
}

void LaborAdvisorWidget::updateLaborCategory(LaborAdvisorButton * button, LaborData::Type type)
{
  if (game() != nullptr) {
    const LaborData::Category & c = game()->city()->laborData()->category(type);
    button->setHave(c.workersAvaialble);
    button->setNeed(c.workersNeeded);
    button->setPriority(c.priority);
  }
}

void LaborAdvisorWidget::updateWages()
{
  Font f = mUi->cRomePays->textFont();

  int32_t annualBill = 0;
  int32_t cityWages = 0;
  int32_t romeWages = 0;
  if (game() != nullptr) {
    cityWages = game()->city()->laborData()->wage();
    annualBill = game()->city()->laborData()->estimateAnnualBill();
    romeWages = game()->city()->laborData()->romeWage();
  }

  QString sWages = QString::number(cityWages) + " ";
  QString sBill = QString::number(annualBill) + " ";
  QString sRome = QString::number(romeWages) + " )";

  int32_t textWidth = f.calculateTextWidth(sWages);
  int32_t xOffset = textWidth;
  mUi->cCityWages->setText(sWages);

  textWidth = f.calculateTextWidth(mUi->cWagesDenarii->text() + " ");
  mUi->cWagesDenarii->setGeometry(230+xOffset, 359, textWidth, 20);
  xOffset += textWidth;

  textWidth = f.calculateTextWidth(mUi->cRomePays->text() + " ");
  mUi->cRomePays->setGeometry(230+xOffset, 359, textWidth, 20);
  xOffset += textWidth;

  textWidth = f.calculateTextWidth(sRome);
  mUi->cRomeWages->setGeometry(230+xOffset, 359, textWidth, 20);
  mUi->cRomeWages->setText(sRome);

  xOffset = 64 + f.calculateTextWidth(mUi->cBill->text() + " ");
  textWidth = f.calculateTextWidth(sBill + " ");
  mUi->cBillAmount->setGeometry(xOffset, 390, textWidth, 20);
  mUi->cBillAmount->setText(sBill);
  xOffset += textWidth;

  textWidth = f.calculateTextWidth(mUi->cDenarii->text());
  mUi->cDenarii->setGeometry(xOffset, 390, textWidth, 20);

  textWidth = f.calculateTextWidth(mUi->cBill->text() + " ");
  mUi->cBill->setGeometry(64, 390, textWidth, 20);
}

LaborAdvisorButton::LaborAdvisorButton(QWidget * widget)
  : Button(widget)
{
  init();
}

void LaborAdvisorButton::init()
{
  const SgImageData * imageData = Application::climateImages();

  setEnableBorder(true);
  setEnableFocusBorder(true);

  mLock.reset(new QLabel(this));
  mPriority.reset(new Label(this));
  mSector.reset(new Label(this));
  mHave.reset(new Label(this));
  mNeed.reset(new Label(this));

  mPriority->setTextFont(Font::Type::NormalWhite);
  mSector->setTextFont(Font::Type::NormalWhite);
  mHave->setTextFont(Font::Type::NormalWhite);
  mNeed->setTextFont(Font::Type::NormalWhite);

  mLock->move(24, 4);
  mPriority->move(52, 2);
  mSector->move(130, 5);
  mHave->move(360, 2);
  mNeed->move(452, 2);

  mPriority->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  mSector->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mHave->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  mNeed->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

  mSector->resize(210, 22);
  mLock->resize(11, 17);
  mPriority->resize(24, 20);
  mHave->resize(48, 20);
  mNeed->resize(48, 20);

  int32_t baseImageId = imageData->getGroupBaseImageId(GROUP_LABOR_PRIORITY_LOCK);
  QPixmap p = QPixmap::fromImage(imageData->getImageRecord(baseImageId)->createImage());
  mLock->setPixmap(p);
}

void LaborAdvisorButton::setPriority(int level)
{
  if (level == 0) {
    mLock->setVisible(false);
    mPriority->setVisible(false);
    update();
    return;
  }

  mLock->setVisible(true);
  mPriority->setVisible(true);
  QString s = QString::number(level);
  mPriority->setText(s);
  update();
}

void LaborAdvisorButton::setSector(const QString & text)
{
  mSector->setText(text);
  update();
}

void LaborAdvisorButton::setHave(int value)
{
  QString s = QString::number(value);
  mHave->setText(s);
}

void LaborAdvisorButton::setNeed(int value)
{
  QString s = QString::number(value);
  mNeed->setText(s);
  update();
}
