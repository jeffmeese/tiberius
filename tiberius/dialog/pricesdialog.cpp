#include "pricesdialog.h"
#include "ui_pricesdialog.h"

#include "application/application.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "resource/resource.h"

#include <QMouseEvent>

PricesDialog::PricesDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::PricesDialog)
{
  init();
}

PricesDialog::~PricesDialog()
{
  delete mUi;
}

void PricesDialog::init()
{
  const StringData * stringData = Application::language()->stringData();

  Font normalBlack(Font::Type::NormalBlack);
  Font largeBlack(Font::Type::LargeBlack);
  Font smallPlain(Font::Type::SmallPlain);

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(54, 21));
  mUi->cTitle->resize(largeBlack.calculateTextWidth(mUi->cTitle->text()), 32);

  mUi->cBuyers->setTextFont(normalBlack);
  mUi->cBuyers->setText(stringData->getString(54, 22));
  mUi->cBuyers->resize(normalBlack.calculateTextWidth(mUi->cBuyers->text()), 20);

  mUi->cSellers->setTextFont(normalBlack);
  mUi->cSellers->setText(stringData->getString(54, 23));
  mUi->cSellers->resize(normalBlack.calculateTextWidth(mUi->cSellers->text()), 20);

  mUi->cWheatBuyer->setTextFont(smallPlain);
  mUi->cWheatSeller->setTextFont(smallPlain);

  mUi->cVegetableBuyer->setTextFont(smallPlain);
  mUi->cVegetableSeller->setTextFont(smallPlain);

  mUi->cFruitBuyer->setTextFont(smallPlain);
  mUi->cFruitSeller->setTextFont(smallPlain);

  mUi->cOliveBuyer->setTextFont(smallPlain);
  mUi->cOliveSeller->setTextFont(smallPlain);

  mUi->cVineBuyer->setTextFont(smallPlain);
  mUi->cVineSeller->setTextFont(smallPlain);

  mUi->cMeatBuyer->setTextFont(smallPlain);
  mUi->cMeatSeller->setTextFont(smallPlain);

  mUi->cWineBuyer->setTextFont(smallPlain);
  mUi->cWineSeller->setTextFont(smallPlain);

  mUi->cOilBuyer->setTextFont(smallPlain);
  mUi->cOilSeller->setTextFont(smallPlain);

  mUi->cIronBuyer->setTextFont(smallPlain);
  mUi->cIronSeller->setTextFont(smallPlain);

  mUi->cTimberBuyer->setTextFont(smallPlain);
  mUi->cTimberSeller->setTextFont(smallPlain);

  mUi->cClayBuyer->setTextFont(smallPlain);
  mUi->cClaySeller->setTextFont(smallPlain);

  mUi->cMarbleBuyer->setTextFont(smallPlain);
  mUi->cMarbleSeller->setTextFont(smallPlain);

  mUi->cWeaponsBuyer->setTextFont(smallPlain);
  mUi->cWeaponsSeller->setTextFont(smallPlain);

  mUi->cFurnitureBuyer->setTextFont(smallPlain);
  mUi->cFurnitureSeller->setTextFont(smallPlain);

  mUi->cPotteryBuyer->setTextFont(smallPlain);
  mUi->cPotterySeller->setTextFont(smallPlain);

  mUi->cRightClick->setTextFont(normalBlack);
  mUi->cRightClick->setText(stringData->getString(13, 1));

  mUi->cWheatIcon->setPixmap(Resource::getImage(Resource::Type::Wheat));
  mUi->cVegetableIcon->setPixmap(Resource::getImage(Resource::Type::Vegetables));
  mUi->cFruitIcon->setPixmap(Resource::getImage(Resource::Type::Fruit));
  mUi->cOliveIcon->setPixmap(Resource::getImage(Resource::Type::Olives));
  mUi->cVineIcon->setPixmap(Resource::getImage(Resource::Type::Vines));
  mUi->cMeatIcon->setPixmap(Resource::getImage(Resource::Type::Meat));
  mUi->cWineIcon->setPixmap(Resource::getImage(Resource::Type::Wine));
  mUi->cOilIcon->setPixmap(Resource::getImage(Resource::Type::Oil));
  mUi->cIronIcon->setPixmap(Resource::getImage(Resource::Type::Iron));
  mUi->cTimberIcon->setPixmap(Resource::getImage(Resource::Type::Timber));
  mUi->cClayIcon->setPixmap(Resource::getImage(Resource::Type::Clay));
  mUi->cMarbleIcon->setPixmap(Resource::getImage(Resource::Type::Marble));
  mUi->cWeaponsIcon->setPixmap(Resource::getImage(Resource::Type::Weapons));
  mUi->cFurnitureIcon->setPixmap(Resource::getImage(Resource::Type::Furniture));
  mUi->cPotteryIcon->setPixmap(Resource::getImage(Resource::Type::Pottery));
}

void PricesDialog::mousePressEvent(QMouseEvent * event)
{
  if (event->button() == Qt::RightButton)
    reject();
}

void PricesDialog::setClayBuyPrice(int32_t value)
{
  mUi->cClayBuyer->setText(QString::number(value));
}

void PricesDialog::setClaySellPrice(int32_t value)
{
  mUi->cClaySeller->setText(QString::number(value));
}

void PricesDialog::setFurnitureBuyPrice(int32_t value)
{
  mUi->cFurnitureBuyer->setText(QString::number(value));
}

void PricesDialog::setFurnitureSellPrice(int32_t value)
{
  mUi->cFurnitureSeller->setText(QString::number(value));
}

void PricesDialog::setFruitBuyPrice(int32_t value)
{
  mUi->cFruitBuyer->setText(QString::number(value));
}

void PricesDialog::setFruitSellPrice(int32_t value)
{
  mUi->cFruitSeller->setText(QString::number(value));
}

void PricesDialog::setIronBuyPrice(int32_t value)
{
  mUi->cIronBuyer->setText(QString::number(value));
}

void PricesDialog::setIronSellPrice(int32_t value)
{
  mUi->cIronSeller->setText(QString::number(value));
}

void PricesDialog::setMarbleBuyPrice(int32_t value)
{
  mUi->cMarbleBuyer->setText(QString::number(value));
}

void PricesDialog::setMarbleSellPrice(int32_t value)
{
  mUi->cMarbleSeller->setText(QString::number(value));
}

void PricesDialog::setMeatBuyPrice(int32_t value)
{
  mUi->cMeatBuyer->setText(QString::number(value));
}

void PricesDialog::setMeatSellPrice(int32_t value)
{
  mUi->cMeatSeller->setText(QString::number(value));
}

void PricesDialog::setOilBuyPrice(int32_t value)
{
  mUi->cOilBuyer->setText(QString::number(value));
}

void PricesDialog::setOilSellPrice(int32_t value)
{
  mUi->cOilSeller->setText(QString::number(value));
}

void PricesDialog::setOliveBuyPrice(int32_t value)
{
  mUi->cOliveBuyer->setText(QString::number(value));
}

void PricesDialog::setOliveSellPrice(int32_t value)
{
  mUi->cOliveSeller->setText(QString::number(value));
}

void PricesDialog::setPotteryBuyPrice(int32_t value)
{
  mUi->cPotteryBuyer->setText(QString::number(value));
}

void PricesDialog::setPotterySellPrice(int32_t value)
{
  mUi->cPotterySeller->setText(QString::number(value));
}

void PricesDialog::setTimberBuyPrice(int32_t value)
{
  mUi->cTimberBuyer->setText(QString::number(value));
}

void PricesDialog::setTimberSellPrice(int32_t value)
{
  mUi->cTimberSeller->setText(QString::number(value));
}

void PricesDialog::setVegetableBuyPrice(int32_t value)
{
  mUi->cVegetableBuyer->setText(QString::number(value));
}

void PricesDialog::setVegetableSellPrice(int32_t value)
{
  mUi->cVegetableSeller->setText(QString::number(value));
}

void PricesDialog::setVineBuyPrice(int32_t value)
{
  mUi->cVineBuyer->setText(QString::number(value));
}

void PricesDialog::setVineSellPrice(int32_t value)
{
  mUi->cVineSeller->setText(QString::number(value));
}

void PricesDialog::setWeaponsBuyPrice(int32_t value)
{
  mUi->cWeaponsBuyer->setText(QString::number(value));
}

void PricesDialog::setWeaponsSellPrice(int32_t value)
{
  mUi->cWeaponsSeller->setText(QString::number(value));
}

void PricesDialog::setWheatBuyPrice(int32_t value)
{
  mUi->cWheatBuyer->setText(QString::number(value));
}

void PricesDialog::setWheatSellPrice(int32_t value)
{
  mUi->cWheatSeller->setText(QString::number(value));
}

void PricesDialog::setWineBuyPrice(int32_t value)
{
  mUi->cWineBuyer->setText(QString::number(value));
}

void PricesDialog::setWineSellPrice(int32_t value)
{
  mUi->cWineSeller->setText(QString::number(value));
}

