#include "resourcetradedialog.h"
#include "ui_resourcetradedialog.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "resource/resource.h"

#include <algorithm>

ResourceTradeDialog::ResourceTradeDialog(Resource * resource, QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::ResourceTradeDialog)
  , mResource(resource)
  , mCanProduce(false)
  , mTradeAvailable(false)
{
  init();
}

ResourceTradeDialog::~ResourceTradeDialog()
{
  delete mUi;
}

void ResourceTradeDialog::handleDecreaseExports()
{
  mResource->setExportUnits((mResource->exportUnits() == 0) ? 0 : mResource->exportUnits()-1);
  updateTradeStatus();
}

void ResourceTradeDialog::handleIncreaseExports()
{
  mResource->setExportUnits( (mResource->exportUnits() == 100) ? 100 : mResource->exportUnits()+1);
  updateTradeStatus();
}

void ResourceTradeDialog::handleTradeStatus()
{
  if (mResource->tradeStatus() == Resource::TradeStatus::NotTrading) {
    if (mResource->canImport()) {
      mResource->setTradeStatus(Resource::TradeStatus::Importing);
    }
    else {
      mResource->setTradeStatus(Resource::TradeStatus::Exporting);
      mResource->setStockpiling(false);
    }
  }
  else if (mResource->tradeStatus() == Resource::TradeStatus::Importing) {
    if (mResource->canExport()) {
      mResource->setTradeStatus(Resource::TradeStatus::Exporting);
      mResource->setStockpiling(false);
    }
    else {
      mResource->setTradeStatus(Resource::TradeStatus::NotTrading);
    }
  }
  else {
    mResource->setTradeStatus(Resource::TradeStatus::NotTrading);
  }

  updateStockpileStatus();
  updateTradeStatus();
}

void ResourceTradeDialog::handleIndustry()
{
  mResource->setIndustryOn(!mResource->isIndustryOn());
  updateIndustryStatus();
}

void ResourceTradeDialog::handleStockpile()
{
  mResource->setTradeStatus(Resource::TradeStatus::NotTrading);
  mResource->setStockpiling(!mResource->stockpiling());
  updateTradeStatus();
  updateStockpileStatus();
}

void ResourceTradeDialog::init()
{
  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_CONTEXT_ICONS);

  mUi->setupUi(this);

  mUi->cIcon->setPixmap(mResource->getImage());

  mUi->cName->setTextFont(largeBlack);
  mUi->cName->setText(mResource->getString());

  mUi->cTotalIndustries->setTextFont(normalBlack);
  mUi->cTradeStatusButton->setTextFont(normalBlack);
  mUi->cIndustryOnButton->setTextFont(normalBlack);
  mUi->cUnitsStored->setTextFont(normalBlack);
  mUi->cNoTradeRoutes->setTextFont(normalBlack);
  mUi->cStockpilingButton->setTextFont(normalBlack);
  mUi->cUsingTradingLabel->setTextFont(normalBlack);
  mUi->cStockpiledLabel->setTextFont(normalBlack);
  mUi->cStockpileLabel->setTextFont(normalBlack);
  mUi->cUseTradeLabel->setTextFont(normalBlack);
  mUi->cExportLabel->setTextFont(normalBlack);
  mUi->cUnitsLabel->setTextFont(normalBlack);
  mUi->cImportingLabel->setTextFont(normalBlack);
  mUi->cNotTradingLabel->setTextFont(normalBlack);

  mUi->cExportLabel->setText(stringData->getString(54, 20));
  mUi->cStockpiledLabel->setText(stringData->getString(54, 26));
  mUi->cUseTradeLabel->setText(stringData->getString(54, 27));
  mUi->cUsingTradingLabel->setText(stringData->getString(54, 28));
  mUi->cStockpileLabel->setText(stringData->getString(54, 29));
  mUi->cNoTradeRoutes->setText(stringData->getString(54, 24));
  mUi->cNoTradeRoutes->resize(normalBlack.calculateTextWidth(mUi->cNoTradeRoutes->text()), 20);

  mUi->cExportLabel->setParent(mUi->cTradeStatusButton);
  mUi->cImportingLabel->setParent(mUi->cTradeStatusButton);
  mUi->cNotTradingLabel->setParent(mUi->cTradeStatusButton);
  mUi->cUnitsLabel->setParent(mUi->cTradeStatusButton);
  mUi->cUp->setParent(mUi->cTradeStatusButton);
  mUi->cDown->setParent(mUi->cTradeStatusButton);

  mUi->cExportLabel->move(16, 9);
  mUi->cImportingLabel->move(16, 9);
  mUi->cNotTradingLabel->move(16, 9);
  mUi->cUnitsLabel->move(288, 9);
  mUi->cDown->move(216, 3);
  mUi->cUp->move(240, 3);

  mUi->cUseTradeLabel->setParent(mUi->cStockpilingButton);
  mUi->cStockpiledLabel->setParent(mUi->cStockpilingButton);
  mUi->cUsingTradingLabel->setParent(mUi->cStockpilingButton);
  mUi->cStockpileLabel->setParent(mUi->cStockpilingButton);

  mUi->cUsingTradingLabel->move(16, 8);
  mUi->cStockpiledLabel->move(16, 8);
  mUi->cStockpileLabel->move(16, 28);
  mUi->cUseTradeLabel->move(16, 28);

  mUi->cDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDown->setPressedImage(imageData->getImageRecord(18)->createImage());
  mUi->cUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cUp->setPressedImage(imageData->getImageRecord(16)->createImage());
  mUi->cExit->setImage(imageData->getImageRecord(baseId+4)->createImage());

  updateAmountStored();
  updateTradeStatus();
  updateIndustryStatus();
  updateStockpileStatus();

  connect(mUi->cExit, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cTradeStatusButton, SIGNAL(clicked()), SLOT(handleTradeStatus()));
  connect(mUi->cIndustryOnButton, SIGNAL(clicked()), SLOT(handleIndustry()));
  connect(mUi->cStockpilingButton, SIGNAL(clicked()), SLOT(handleStockpile()));
  connect(mUi->cUp, SIGNAL(clicked()), SLOT(handleIncreaseExports()));
  connect(mUi->cDown, SIGNAL(clicked()), SLOT(handleDecreaseExports()));
}

void ResourceTradeDialog::setCanProduce(bool value)
{
  mCanProduce = value;
  mUi->cIndustryOnButton->setVisible(value);

  const StringData * stringData = Application::language()->stringData();
  Font normalBlack(Font::Type::NormalBlack);
  if (value) {
    if (mResource->isIndustryOn()) {
      int32_t totalIndustries = 1;
      mUi->cTotalIndustries->setTextFont(normalBlack);
      QString industryText = QString::number(totalIndustries) + " ";
      industryText += (totalIndustries == 1) ? stringData->getString(54, 9) : stringData->getString(54, 8);
      mUi->cTotalIndustries->setText(industryText);
      mUi->cTotalIndustries->resize(normalBlack.calculateTextWidth(industryText), 20);
    }
    else {
      int32_t totalIndustries = 1;
      mUi->cTotalIndustries->setTextFont(normalBlack);
      QString industryText = QString::number(totalIndustries) + " ";
      industryText += (totalIndustries == 1) ? stringData->getString(54, 10) : stringData->getString(54, 11);
      mUi->cTotalIndustries->setText(industryText);
      mUi->cTotalIndustries->resize(normalBlack.calculateTextWidth(industryText), 20);
    }
  }
}

void ResourceTradeDialog::setTradeAvailable(bool value)
{
  mTradeAvailable = value;
  mUi->cTradeStatusButton->setVisible(value);
}

void ResourceTradeDialog::updateAmountStored()
{
  Font normalBlack(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();

  QString text = QString::number(mResource->amountStored()) + " ";
  text += (mResource->amountStored() == 1) ? stringData->getString(8, 11) : stringData->getString(8, 10);
  text += " " + stringData->getString(54, 15);
  mUi->cUnitsStored->setText(text);
  mUi->cUnitsStored->resize(normalBlack.calculateTextWidth(text), 20);
  mUi->cNoTradeRoutes->setVisible(!mResource->tradeAvailable());
}

void ResourceTradeDialog::updateIndustryStatus()
{
  Font normalBlack(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();

  int32_t totalIndustries = mResource->totalIndustries();
  int32_t activeIndustries = mResource->activeIndustries();

  mUi->cIndustryOnButton->setVisible(mResource->canProduce() && totalIndustries > 0);
  if (mResource->canProduce()) {
    if (mResource->isIndustryOn()) { // Industry on
      mUi->cIndustryOnButton->setText(stringData->getString(54, 16));
      if (totalIndustries == activeIndustries) { // All working
        QString industryText = QString::number(totalIndustries) + " ";
        industryText += (totalIndustries == 1) ? stringData->getString(54, 10) : stringData->getString(54, 11);
        mUi->cTotalIndustries->setText(industryText);
        mUi->cTotalIndustries->resize(normalBlack.calculateTextWidth(industryText), 20);
      }
      else { // Some working
        int32_t idleIndustries = totalIndustries - activeIndustries;
        QString industryText = QString::number(activeIndustries) + " ";
        industryText += stringData->getString(54, 12) + "  ";
        industryText += QString::number(idleIndustries) + " ";
        industryText += (idleIndustries == 1) ? stringData->getString(54, 14) : stringData->getString(54, 13);
        mUi->cTotalIndustries->setText(industryText);
        mUi->cTotalIndustries->resize(normalBlack.calculateTextWidth(industryText), 20);
      }
    }
    else { // Industry off
      mUi->cIndustryOnButton->setText(stringData->getString(54, 17));
      QString industryText = QString::number(totalIndustries) + " ";
      industryText += (totalIndustries == 1) ? stringData->getString(54, 10) : stringData->getString(54, 11);
      mUi->cTotalIndustries->setText(industryText);
      mUi->cTotalIndustries->resize(normalBlack.calculateTextWidth(industryText), 20);
    }
  }
  else {
    mUi->cTotalIndustries->setText(stringData->getString(54, 25));
  }
}

void ResourceTradeDialog::updateStockpileStatus()
{
  mUi->cUseTradeLabel->setVisible(mResource->stockpiling());
  mUi->cStockpiledLabel->setVisible(mResource->stockpiling());
  mUi->cUsingTradingLabel->setVisible(!mResource->stockpiling());
  mUi->cStockpileLabel->setVisible(!mResource->stockpiling());
}

void ResourceTradeDialog::updateTradeStatus()
{
  Font normalBlack(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();

  mUi->cDown->setVisible(false);
  mUi->cUp->setVisible(false);
  mUi->cImportingLabel->setVisible(false);
  mUi->cNotTradingLabel->setVisible(false);
  mUi->cExportLabel->setVisible(false);
  mUi->cUnitsLabel->setVisible(false);
  mUi->cTradeStatusButton->setVisible(mResource->tradeAvailable());
  if (mResource->tradeAvailable()) {
    if (mResource->tradeStatus() == Resource::TradeStatus::NotTrading) {
      mUi->cNotTradingLabel->setVisible(true);
      mUi->cNotTradingLabel->setText(stringData->getString(54, 4));
    }
    else if (mResource->tradeStatus() == Resource::TradeStatus::Importing) {
      mUi->cImportingLabel->setVisible(true);
      mUi->cImportingLabel->setText(stringData->getString(54, 5));
    }
    else if (mResource->tradeStatus() == Resource::TradeStatus::Exporting) {
      int32_t exportUnits = mResource->exportUnits();
      mUi->cExportLabel->setVisible(true);
      mUi->cDown->setVisible(true);
      mUi->cUp->setVisible(true);
      mUi->cUnitsLabel->setVisible(true);

      QString text = QString::number(exportUnits) + " ";
      text += (exportUnits == 1) ? stringData->getString(8, 10) : stringData->getString(8, 11);
      mUi->cUnitsLabel->setText(text);
      mUi->cUnitsLabel->resize(normalBlack.calculateTextWidth(text), 20);
    }
  }
}
