#include "tradeadvisorwidget.h"
#include "ui_tradeadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/resourcedata.h"
#include "city/tradedata.h"

#include "dialog/pricesdialog.h"
#include "dialog/resourcetradedialog.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "resource/resource.h"

#include <QMouseEvent>

TradeAdvisorWidget::TradeAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::TradeAdvisorWidget)
{
  init();
}

TradeAdvisorWidget::~TradeAdvisorWidget()
{
  delete mUi;
}

void TradeAdvisorWidget::doUpdate()
{
  ResourceData * resourceData = game()->city()->resourceData();
  const std::vector<Resource::Type> & resourceTypes =  resourceData->availableResources();
  for (std::size_t i = 0; i < resourceTypes.size(); i++) {
    Resource::Type type = resourceTypes[i];
    Resource * resource = resourceData->getResource(type);
    mResources[i] = resource;
    mRows[i]->setResource(resourceData->getResource(resource->type()));
    mRows[i]->setVisible(true);
    mLeftIcons[i]->setPixmap(resource->getImage());
    mRightIcons[i]->setPixmap(resource->getImage());
    mLeftIcons[i]->setVisible(true);
    mRightIcons[i]->setVisible(true);
  }

  for (std::size_t i = resourceTypes.size(); i < 15; i++) {
    mRows[i]->setVisible(false);
    mResources[i] = nullptr;
    mLeftIcons[i]->setVisible(false);
    mRightIcons[i]->setVisible(false);
  }
}

void TradeAdvisorWidget::handleClick1()
{
  showResourceDialog(mResources[0]);
}

void TradeAdvisorWidget::handleClick2()
{
  showResourceDialog(mResources[1]);
}

void TradeAdvisorWidget::handleClick3()
{
  showResourceDialog(mResources[2]);
}

void TradeAdvisorWidget::handleClick4()
{
  showResourceDialog(mResources[3]);
}

void TradeAdvisorWidget::handleClick5()
{
  showResourceDialog(mResources[4]);
}

void TradeAdvisorWidget::handleClick6()
{
  showResourceDialog(mResources[5]);
}

void TradeAdvisorWidget::handleClick7()
{
  showResourceDialog(mResources[6]);
}

void TradeAdvisorWidget::handleClick8()
{
  showResourceDialog(mResources[7]);
}

void TradeAdvisorWidget::handleClick9()
{
  showResourceDialog(mResources[8]);
}

void TradeAdvisorWidget::handleClick10()
{
  showResourceDialog(mResources[9]);
}

void TradeAdvisorWidget::handleClick11()
{
  showResourceDialog(mResources[10]);
}

void TradeAdvisorWidget::handleClick12()
{
  showResourceDialog(mResources[11]);
}

void TradeAdvisorWidget::handleClick13()
{
  showResourceDialog(mResources[12]);
}

void TradeAdvisorWidget::handleClick14()
{
  showResourceDialog(mResources[13]);
}

void TradeAdvisorWidget::handleClick15()
{
  showResourceDialog(mResources[14]);
}

void TradeAdvisorWidget::handleShowPrices()
{
  ResourceData * resourceData = game()->city()->resourceData();

  PricesDialog dialog(this);
  dialog.setWheatBuyPrice(resourceData->getResource(Resource::Type::Wheat)->buyPrice());
  dialog.setWheatSellPrice(resourceData->getResource(Resource::Type::Wheat)->sellPrice());
  dialog.setVegetableBuyPrice(resourceData->getResource(Resource::Type::Vegetables)->buyPrice());
  dialog.setVegetableSellPrice(resourceData->getResource(Resource::Type::Vegetables)->sellPrice());
  dialog.setFruitBuyPrice(resourceData->getResource(Resource::Type::Fruit)->buyPrice());
  dialog.setFruitSellPrice(resourceData->getResource(Resource::Type::Fruit)->sellPrice());
  dialog.setOliveBuyPrice(resourceData->getResource(Resource::Type::Olives)->buyPrice());
  dialog.setOliveSellPrice(resourceData->getResource(Resource::Type::Olives)->sellPrice());
  dialog.setVineBuyPrice(resourceData->getResource(Resource::Type::Vines)->buyPrice());
  dialog.setVineSellPrice(resourceData->getResource(Resource::Type::Vines)->sellPrice());
  dialog.setMeatBuyPrice(resourceData->getResource(Resource::Type::Meat)->buyPrice());
  dialog.setMeatSellPrice(resourceData->getResource(Resource::Type::Meat)->sellPrice());
  dialog.setWineBuyPrice(resourceData->getResource(Resource::Type::Wine)->buyPrice());
  dialog.setWineSellPrice(resourceData->getResource(Resource::Type::Wine)->sellPrice());
  dialog.setOilBuyPrice(resourceData->getResource(Resource::Type::Oil)->buyPrice());
  dialog.setOilSellPrice(resourceData->getResource(Resource::Type::Oil)->sellPrice());
  dialog.setIronBuyPrice(resourceData->getResource(Resource::Type::Iron)->buyPrice());
  dialog.setIronSellPrice(resourceData->getResource(Resource::Type::Iron)->sellPrice());
  dialog.setTimberBuyPrice(resourceData->getResource(Resource::Type::Timber)->buyPrice());
  dialog.setTimberSellPrice(resourceData->getResource(Resource::Type::Timber)->sellPrice());
  dialog.setClayBuyPrice(resourceData->getResource(Resource::Type::Clay)->buyPrice());
  dialog.setClaySellPrice(resourceData->getResource(Resource::Type::Clay)->sellPrice());
  dialog.setMarbleBuyPrice(resourceData->getResource(Resource::Type::Marble)->buyPrice());
  dialog.setMarbleSellPrice(resourceData->getResource(Resource::Type::Marble)->sellPrice());
  dialog.setWeaponsBuyPrice(resourceData->getResource(Resource::Type::Weapons)->buyPrice());
  dialog.setWeaponsSellPrice(resourceData->getResource(Resource::Type::Weapons)->sellPrice());
  dialog.setFurnitureBuyPrice(resourceData->getResource(Resource::Type::Furniture)->buyPrice());
  dialog.setFurnitureSellPrice(resourceData->getResource(Resource::Type::Furniture)->sellPrice());
  dialog.setPotteryBuyPrice(resourceData->getResource(Resource::Type::Pottery)->buyPrice());
  dialog.setPotterySellPrice(resourceData->getResource(Resource::Type::Pottery)->sellPrice());
  dialog.exec();
}

void TradeAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  Font normalBlack(Font::Type::NormalBlack);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+4)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(54, 0));

  int32_t textWidth = normalBlack.calculateTextWidth(stringData->getString(54, 1));
  mUi->cMessage->setTextFont(normalBlack);
  mUi->cMessage->setText(stringData->getString(54, 1));
  mUi->cMessage->setGeometry(600-textWidth, 38, textWidth, 20);

  mUi->cEmpire->setTextFont(normalBlack);
  mUi->cEmpire->setText(stringData->getString(54, 30));
  mUi->cEmpire->setEnableBorder(true);
  mUi->cEmpire->setEnableFocusBorder(true);

  mUi->cPrices->setTextFont(normalBlack);
  mUi->cPrices->setText(stringData->getString(54, 2));
  mUi->cPrices->setEnableBorder(true);
  mUi->cPrices->setEnableFocusBorder(true);

  mLeftIcons[0] = mUi->cLeftIcon1;
  mLeftIcons[1] = mUi->cLeftIcon2;
  mLeftIcons[2] = mUi->cLeftIcon3;
  mLeftIcons[3] = mUi->cLeftIcon4;
  mLeftIcons[4] = mUi->cLeftIcon5;
  mLeftIcons[5] = mUi->cLeftIcon6;
  mLeftIcons[6] = mUi->cLeftIcon7;
  mLeftIcons[7] = mUi->cLeftIcon8;
  mLeftIcons[8] = mUi->cLeftIcon9;
  mLeftIcons[9] = mUi->cLeftIcon10;
  mLeftIcons[10] = mUi->cLeftIcon11;
  mLeftIcons[11] = mUi->cLeftIcon12;
  mLeftIcons[12] = mUi->cLeftIcon13;
  mLeftIcons[13] = mUi->cLeftIcon14;
  mLeftIcons[14] = mUi->cLeftIcon15;

  mRightIcons[0] = mUi->cRightIcon1;
  mRightIcons[1] = mUi->cRightIcon2;
  mRightIcons[2] = mUi->cRightIcon3;
  mRightIcons[3] = mUi->cRightIcon4;
  mRightIcons[4] = mUi->cRightIcon5;
  mRightIcons[5] = mUi->cRightIcon6;
  mRightIcons[6] = mUi->cRightIcon7;
  mRightIcons[7] = mUi->cRightIcon8;
  mRightIcons[8] = mUi->cRightIcon9;
  mRightIcons[9] = mUi->cRightIcon10;
  mRightIcons[10] = mUi->cRightIcon11;
  mRightIcons[11] = mUi->cRightIcon12;
  mRightIcons[12] = mUi->cRightIcon13;
  mRightIcons[13] = mUi->cRightIcon14;
  mRightIcons[14] = mUi->cRightIcon15;

  for (int i = 0; i < 15; i++) {
    int32_t yOffset = 22*i;
    mRows[i].reset(new TradeAdvisorWidgetRow(this));
    mRows[i]->setGeometry(80, 54 + yOffset, 480, 24);
    mLeftIcons[i]->setVisible(false);
    mRightIcons[i]->setVisible(false);
  }

  connect(mUi->cPrices, SIGNAL(clicked()), SLOT(handleShowPrices()));
  connect(mRows[0].get(), SIGNAL(clicked()), SLOT(handleClick1()));
  connect(mRows[1].get(), SIGNAL(clicked()), SLOT(handleClick2()));
  connect(mRows[2].get(), SIGNAL(clicked()), SLOT(handleClick3()));
  connect(mRows[3].get(), SIGNAL(clicked()), SLOT(handleClick4()));
  connect(mRows[4].get(), SIGNAL(clicked()), SLOT(handleClick5()));
  connect(mRows[5].get(), SIGNAL(clicked()), SLOT(handleClick6()));
  connect(mRows[6].get(), SIGNAL(clicked()), SLOT(handleClick7()));
  connect(mRows[7].get(), SIGNAL(clicked()), SLOT(handleClick8()));
  connect(mRows[8].get(), SIGNAL(clicked()), SLOT(handleClick9()));
  connect(mRows[9].get(), SIGNAL(clicked()), SLOT(handleClick10()));
  connect(mRows[10].get(), SIGNAL(clicked()), SLOT(handleClick11()));
  connect(mRows[11].get(), SIGNAL(clicked()), SLOT(handleClick12()));
  connect(mRows[12].get(), SIGNAL(clicked()), SLOT(handleClick13()));
  connect(mRows[13].get(), SIGNAL(clicked()), SLOT(handleClick14()));
  connect(mRows[14].get(), SIGNAL(clicked()), SLOT(handleClick15()));
}

void TradeAdvisorWidget::showResourceDialog(Resource * resource)
{
  ResourceTradeDialog dialog(resource, this);
  dialog.exec();
}

TradeAdvisorWidgetRow::TradeAdvisorWidgetRow(QWidget * parentWidget)
  : QWidget(parentWidget)
  , mResource(nullptr)
{
  mFocused = false;

  mName.reset(new Label(this));
  mAmount.reset(new Label(this));
  mIndustryOff.reset(new Label(this));
  mTradeStatus.reset(new Label(this));

  Font normalWhite(Font::Type::NormalWhite);

  mName->setTextFont(normalWhite);
  mName->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mName->setGeometry(10, 7, 100, 20);

  mAmount->setTextFont(normalWhite);
  mAmount->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
  mAmount->setGeometry(92, 7, 100, 20);

  mIndustryOff->setTextFont(normalWhite);
  mIndustryOff->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mIndustryOff->setGeometry(212, 7, 100, 20);

  mTradeStatus->setTextFont(normalWhite);
  mTradeStatus->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mTradeStatus->setGeometry(292, 7, 100, 20);
}

void TradeAdvisorWidgetRow::enterEvent(QEvent *)
{
  mFocused = true;
  update();
}

void TradeAdvisorWidgetRow::leaveEvent(QEvent *)
{
  mFocused = false;
  update();
}

void TradeAdvisorWidgetRow::mouseReleaseEvent(QMouseEvent * event)
{
  if (event->button() == Qt::LeftButton)
    emit clicked();
}

void TradeAdvisorWidgetRow::paintEvent(QPaintEvent *)
{
  Painter painter(this);

  if (mFocused) {
    const SgImageData * imageData = TiberiusApplication::climateImages();
    uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_BORDERED_BUTTON)+8;
    int32_t w = width();
    int32_t widthBlocks = w / 16;
    if (widthBlocks % 16)
      widthBlocks++;

    int32_t h = height();
    int32_t heightBlocks = h / 16;
    if (heightBlocks % 16)
      heightBlocks++;

    int last_block_offset_x = 16 * widthBlocks - w;
    int last_block_offset_y = 16 * heightBlocks - h;

    for (int32_t yy = 0; yy < heightBlocks; yy++) {
      for (int32_t xx = 0; xx < widthBlocks; xx++) {
        int32_t imageOffset = 0;
        int32_t xOffset = 16*xx;
        int32_t yOffset = 16*yy;

        if (yy == 0) {
          if (xx == 0) {

          }
          else if (xx < widthBlocks-1) {
            imageOffset += 1;
          }
          else {
            imageOffset += 2;
            xOffset -= last_block_offset_x;
          }
        }
        else if (yy < heightBlocks-1) {
          if (xx == 0) {
            imageOffset += 7;
          }
          else if (xx >= widthBlocks-1) {
            imageOffset += 3;
            xOffset -= last_block_offset_x;
          }
          else {
            continue;
          }
        }
        else {
          if (xx == 0) {
            imageOffset += 6;
            yOffset -= last_block_offset_y;
          }
          else if (xx < widthBlocks-1) {
            imageOffset += 5;
            yOffset -= last_block_offset_y;
          }
          else {
            imageOffset += 4;
            xOffset -= last_block_offset_x;
            yOffset -= last_block_offset_y;
          }
        }

        const SgImageRecord * imageRecord = imageData->getImageRecord(baseImageId + imageOffset);
        painter.drawImage(xOffset, yOffset, imageRecord->createImage());
      }
    }
  }
}

void TradeAdvisorWidgetRow::setResource(const Resource * resource)
{
  const StringData * stringData = Application::language()->stringData();

  mResource = resource;

  mName->setText(resource->getString());
  mAmount->setText(QString::number(resource->amountStored()));

  mIndustryOff->setVisible(!resource->isIndustryOn());
  mIndustryOff->setText(stringData->getString(18, 5));

  mTradeStatus->setVisible(resource->tradeStatus() != Resource::TradeStatus::NotTrading);
  if (resource->stockpiling()) {
    mTradeStatus->setVisible(true);
    mTradeStatus->setText(stringData->getString(54, 3));
  }

  if (resource->tradeStatus() == Resource::TradeStatus::Importing)
    mTradeStatus->setText(stringData->getString(54, 5));
  else if (resource->tradeStatus() == Resource::TradeStatus::Exporting) {
    int32_t exportUnits = resource->exportUnits();
    QString textString = stringData->getString(54, 6) + " ";
    textString += QString::number(exportUnits);
  }
}

