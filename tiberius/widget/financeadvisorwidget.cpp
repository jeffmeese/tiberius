#include "financeadvisorwidget.h"
#include "ui_financeadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/financedata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

FinanceAdvisorWidget::FinanceAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::FinanceAdvisorWidget)
{
  init();
}

FinanceAdvisorWidget::~FinanceAdvisorWidget()
{
  delete mUi;
}

void FinanceAdvisorWidget::doUpdate()
{
  FinanceData * financeData = game()->city()->financeData();
  const StringData * stringData = Application::language()->stringData();

  Font normalRed(Font::Type::NormalRed);
  Font normalWhite(Font::Type::NormalWhite);
  Font normalBlack(Font::Type::NormalBlack);

  int32_t totalDenarii = financeData->totalDenarii();
  QString assetsLabel;
  if (totalDenarii >= 0) {
    mUi->cAssets->setTextFont(normalWhite);
    assetsLabel = stringData->getString(60, 2) + " ";
    assetsLabel += QString::number(totalDenarii) + " ";
    assetsLabel += stringData->getString(8, 1);
    setLabelText(mUi->cAssets, assetsLabel, normalWhite, 20);
  }
  else {
    mUi->cAssets->setTextFont(normalRed);
    assetsLabel = stringData->getString(60, 3) + " ";
    assetsLabel += QString::number(-totalDenarii) + " ";
    assetsLabel += stringData->getString(8, 1);
    setLabelText(mUi->cAssets, assetsLabel, normalRed, 20);
  }

  QString yieldLabel;
  yieldLabel += QString::number(financeData->taxRate()) + "% ";
  yieldLabel += stringData->getString(60, 4) + " ";
  yieldLabel += QString::number(financeData->estimatedTaxes()) + " ";
  yieldLabel += stringData->getString(8, 1);
  setLabelText(mUi->cEstimatedTax, yieldLabel, normalWhite, 20);

  QString percentLabel;
  percentLabel += QString::number(financeData->percentRegistered()) + "% ";
  percentLabel += stringData->getString(60, 5);
  setLabelText(mUi->cRegistered, percentLabel, normalWhite, 20);

  int32_t currentIncome = financeData->currentYearIncome();
  int32_t currentExpenses = financeData->currentYearExpenses();
  int32_t currentNetFlow = currentIncome - currentExpenses;

  setLabelText(mUi->cCurrentTaxes, QString::number(financeData->currentYearTaxes()), normalBlack, 20);
  setLabelText(mUi->cCurrentExports, QString::number(financeData->currentYearExports()), normalBlack, 20);
  setLabelText(mUi->cCurrentDonated, QString::number(financeData->currentYearDonated()), normalBlack, 20);
  setLabelText(mUi->cCurrentIncome, QString::number(currentIncome), normalBlack, 20);
  setLabelText(mUi->cCurrentImports, QString::number(financeData->currentYearImports()), normalBlack, 20);
  setLabelText(mUi->cCurrentWages, QString::number(financeData->currentYearWages()), normalBlack, 20);
  setLabelText(mUi->cCurrentConstruction, QString::number(financeData->currentYearConstruction()), normalBlack, 20);
  setLabelText(mUi->cCurrentInterest, QString::number(financeData->currentYearInterest()), normalBlack, 20);
  setLabelText(mUi->cCurrentSalary, QString::number(financeData->currentYearSalary()), normalBlack, 20);
  setLabelText(mUi->cCurrentSundries, QString::number(financeData->currentYearSundries()), normalBlack, 20);
  setLabelText(mUi->cCurrentTribute, QString::number(financeData->currentYearTribute()), normalBlack, 20);
  setLabelText(mUi->cCurrentExpenses, QString::number(currentExpenses), normalBlack, 20);
  setLabelText(mUi->cCurrentNetFlow, QString::number(currentNetFlow), normalBlack, 20);
  setLabelText(mUi->cCurrentBalance, QString::number(totalDenarii), normalBlack, 20);

  int32_t previousIncome = financeData->previousYearIncome();
  int32_t previousExpenses = financeData->previousYearExpenses();
  int32_t previousNetFlow = previousIncome - previousExpenses;

  setLabelText(mUi->cPreviousTaxes, QString::number(financeData->previousYearTaxes()), normalBlack, 20);
  setLabelText(mUi->cPreviousExports, QString::number(financeData->previousYearExports()), normalBlack, 20);
  setLabelText(mUi->cPreviousDonated, QString::number(financeData->previousYearDonated()), normalBlack, 20);
  setLabelText(mUi->cPreviousIncome, QString::number(previousIncome), normalBlack, 20);
  setLabelText(mUi->cPreviousImports, QString::number(financeData->previousYearImports()), normalBlack, 20);
  setLabelText(mUi->cPreviousWages, QString::number(financeData->previousYearWages()), normalBlack, 20);
  setLabelText(mUi->cPreviousConstruction, QString::number(financeData->previousYearConstruction()), normalBlack, 20);
  setLabelText(mUi->cPreviousInterest, QString::number(financeData->previousYearInterest()), normalBlack, 20);
  setLabelText(mUi->cPreviousSalary, QString::number(financeData->previousYearSalary()), normalBlack, 20);
  setLabelText(mUi->cPreviousSundries, QString::number(financeData->previousYearSundries()), normalBlack, 20);
  setLabelText(mUi->cPreviousTribute, QString::number(financeData->previousYearTribute()), normalBlack, 20);
  setLabelText(mUi->cPreviousExpenses, QString::number(previousExpenses), normalBlack, 20);
  setLabelText(mUi->cPreviousNetFlow, QString::number(previousNetFlow), normalBlack, 20);
  setLabelText(mUi->cPreviousBalance, QString::number(financeData->previousYearBalance()), normalBlack, 20);
}

void FinanceAdvisorWidget::handleDecreaseTaxes()
{
  FinanceData * financeData = game()->city()->financeData();
  financeData->decreaseTaxes(1);
  doUpdate();
}

void FinanceAdvisorWidget::handleIncreaseTaxes()
{
  FinanceData * financeData = game()->city()->financeData();
  financeData->increaseTaxes(1);
  doUpdate();
}

void FinanceAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalWhite(Font::Type::NormalWhite);
  Font normalRed(Font::Type::NormalRed);
  Font normalBlack(Font::Type::NormalBlack);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+10)->createImage());

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cAssets->setTextFont(normalWhite);
  mUi->cTaxRateLabel->setTextFont(normalWhite);
  mUi->cEstimatedTax->setTextFont(normalWhite);
  mUi->cRegistered->setTextFont(normalWhite);
  mUi->cLastYearHeader->setTextFont(normalBlack);
  mUi->cThisYearHeader->setTextFont(normalBlack);
  mUi->cTaxesIn->setTextFont(normalBlack);
  mUi->cTradeReceipts->setTextFont(normalBlack);
  mUi->cDonated->setTextFont(normalBlack);
  mUi->cIncome->setTextFont(normalBlack);
  mUi->cImports->setTextFont(normalBlack);
  mUi->cWages->setTextFont(normalBlack);
  mUi->cConstruction->setTextFont(normalBlack);
  mUi->cInterest->setTextFont(normalBlack);
  mUi->cSalary->setTextFont(normalBlack);
  mUi->cSundries->setTextFont(normalBlack);
  mUi->cTribute->setTextFont(normalBlack);
  mUi->cExpenses->setTextFont(normalBlack);
  mUi->cNetFlow->setTextFont(normalBlack);
  mUi->cBalance->setTextFont(normalBlack);

  mUi->cPreviousTaxes->setTextFont(normalBlack);
  mUi->cPreviousExports->setTextFont(normalBlack);
  mUi->cPreviousDonated->setTextFont(normalBlack);
  mUi->cPreviousIncome->setTextFont(normalBlack);
  mUi->cPreviousImports->setTextFont(normalBlack);
  mUi->cPreviousWages->setTextFont(normalBlack);
  mUi->cPreviousConstruction->setTextFont(normalBlack);
  mUi->cPreviousInterest->setTextFont(normalBlack);
  mUi->cPreviousSalary->setTextFont(normalBlack);
  mUi->cPreviousSundries->setTextFont(normalBlack);
  mUi->cPreviousTribute->setTextFont(normalBlack);
  mUi->cPreviousExpenses->setTextFont(normalBlack);
  mUi->cPreviousNetFlow->setTextFont(normalBlack);
  mUi->cPreviousBalance->setTextFont(normalBlack);

  mUi->cCurrentTaxes->setTextFont(normalBlack);
  mUi->cCurrentExports->setTextFont(normalBlack);
  mUi->cCurrentDonated->setTextFont(normalBlack);
  mUi->cCurrentIncome->setTextFont(normalBlack);
  mUi->cCurrentImports->setTextFont(normalBlack);
  mUi->cCurrentWages->setTextFont(normalBlack);
  mUi->cCurrentConstruction->setTextFont(normalBlack);
  mUi->cCurrentInterest->setTextFont(normalBlack);
  mUi->cCurrentSalary->setTextFont(normalBlack);
  mUi->cCurrentSundries->setTextFont(normalBlack);
  mUi->cCurrentTribute->setTextFont(normalBlack);
  mUi->cCurrentExpenses->setTextFont(normalBlack);
  mUi->cCurrentNetFlow->setTextFont(normalBlack);
  mUi->cCurrentBalance->setTextFont(normalBlack);

  setLabelText(mUi->cTitle, stringData->getString(60, 0), largeBlack, 32);
  setLabelText(mUi->cAssets, stringData->getString(60, 2), normalWhite, 20);
  setLabelText(mUi->cTaxRateLabel, stringData->getString(60, 1), normalWhite, 20);
  setLabelText(mUi->cEstimatedTax, stringData->getString(60, 4), normalWhite, 20);
  setLabelText(mUi->cAssets, stringData->getString(60, 2), normalWhite, 20);
  setLabelText(mUi->cRegistered, stringData->getString(60, 5), normalWhite, 20);
  setLabelText(mUi->cLastYearHeader, stringData->getString(60, 6), normalBlack, 20);
  setLabelText(mUi->cThisYearHeader, stringData->getString(60, 7), normalBlack, 20);
  setLabelText(mUi->cTaxesIn, stringData->getString(60, 8), normalBlack, 20);
  setLabelText(mUi->cTradeReceipts, stringData->getString(60, 9), normalBlack, 20);
  setLabelText(mUi->cDonated, stringData->getString(60, 20), normalBlack, 20);
  setLabelText(mUi->cIncome, stringData->getString(60, 10), normalBlack, 20);
  setLabelText(mUi->cImports, stringData->getString(60, 11), normalBlack, 20);
  setLabelText(mUi->cWages, stringData->getString(60, 12), normalBlack, 20);
  setLabelText(mUi->cConstruction, stringData->getString(60, 13), normalBlack, 20);
  setLabelText(mUi->cInterest, stringData->getString(60, 14), normalBlack, 20);
  setLabelText(mUi->cSalary, stringData->getString(60, 15), normalBlack, 20);
  setLabelText(mUi->cSundries, stringData->getString(60, 16), normalBlack, 20);
  setLabelText(mUi->cTribute, stringData->getString(60, 21), normalBlack, 20);
  setLabelText(mUi->cExpenses, stringData->getString(60, 17), normalBlack, 20);
  setLabelText(mUi->cNetFlow, stringData->getString(60, 18), normalBlack, 20);
  setLabelText(mUi->cBalance, stringData->getString(60, 19), normalBlack, 20);

  mUi->cDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDown->setPressedImage(imageData->getImageRecord(18)->createImage());
  mUi->cUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  connect(mUi->cDown, SIGNAL(clicked()), SLOT(handleDecreaseTaxes()));
  connect(mUi->cUp, SIGNAL(clicked()), SLOT(handleIncreaseTaxes()));
}

void FinanceAdvisorWidget::setLabelText(Label * label, const QString & text, Font font, int32_t height)
{
  label->setText(text);
  label->resize(font.calculateTextWidth(text), height);
}
