#include "resource.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

static const int32_t DEFAULT_BUY_PRICES[] = {
  28, 38, 38, 42, 44,     // Wheat, Vegetables, Friut, Olives, Vines
  44, 215, 180, 60, 50,   // Meat, Wine, Oil, Iron, Timber
  40, 200, 250, 200, 180  // Clay, Marble, Weapons, Furniture, Pottery
};

static const int32_t DEFAULT_SELL_PRICES[] = {
  22, 30, 30, 34, 36,     // Wheat, Vegetables, Friut, Olives, Vines
  36, 160, 140, 40, 35,   // Meat, Wine, Oil, Iron, Timber
  30, 140, 180, 150, 140  // Clay, Marble, Weapons, Furniture, Pottery
};

Resource::Resource(Type type)
{
  mCanProduce = true;
  mIndustryOn = true;
  mStockpiling = false;
  mCanImport = true;
  mCanExport = true;
  mAmountStored = 10;
  mExportUnits = 0;
  mActiveIndustries = 0;
  mTotalIndustries = 0;
  mTradeStatus = TradeStatus::Exporting;
  mType = type;
  mBuyPrice = DEFAULT_BUY_PRICES[static_cast<int32_t>(type) - 1];
  mSellPrice = DEFAULT_SELL_PRICES[static_cast<int32_t>(type) - 1];
}

int32_t Resource::activeIndustries() const
{
  return mActiveIndustries;
}

int32_t Resource::amountStored() const
{
  return mAmountStored;
}

int32_t Resource::buyPrice() const
{
  return mBuyPrice;
}

bool Resource::canExport() const
{
  return mCanExport;
}

bool Resource::canImport() const
{
  return mCanImport;
}

bool Resource::canProduce() const
{
  return mCanProduce;
}

int32_t Resource::exportUnits() const
{
  return mExportUnits;
}

QPixmap Resource::getImage() const
{
  return getImage(mType);
}

QPixmap Resource::getImage(Type type)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  int32_t imageId = baseId + static_cast<int32_t>(type);
  QPixmap pixmap = QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage());
  return pixmap;
}

QString Resource::getString() const
{
  return getString(mType);
}

QString Resource::getString(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  return stringData->getString(23, static_cast<int>(type));
}

bool Resource::isIndustryOn() const
{
  return mIndustryOn;
}

int32_t Resource::sellPrice() const
{
  return mSellPrice;
}

void Resource::setActiveIndustries(int32_t value)
{
  mActiveIndustries = value;
}

void Resource::setAmountStored(int32_t value)
{
  mAmountStored = value;
}

void Resource::setBuyPrice(int32_t value)
{
  mBuyPrice = value;
}

void Resource::setCanExport(bool value)
{
  mCanExport = value;
}

void Resource::setCanImport(bool value)
{
  mCanImport = value;
}

void Resource::setCanProduce(bool value)
{
  mCanProduce = value;
}

void Resource::setExportUnits(int32_t value)
{
  mExportUnits = value;
}

void Resource::setIndustryOn(bool on)
{
  mIndustryOn = on;
}

void Resource::setSellPrice(int32_t value)
{
  mSellPrice = value;
}

void Resource::setStockpiling(bool value)
{
  mStockpiling = value;
}

void Resource::setTotalIndustries(int32_t value)
{
  mTotalIndustries = value;
}

void Resource::setTradeStatus(TradeStatus value)
{
  mTradeStatus = value;
}

bool Resource::stockpiling() const
{
  return mStockpiling;
}

int32_t Resource::totalIndustries() const
{
  return mTotalIndustries;
}

bool Resource::tradeAvailable() const
{
  return (mCanExport || mCanImport);
}

Resource::TradeStatus Resource::tradeStatus() const
{
  return mTradeStatus;
}

Resource::Type Resource::type() const
{
  return mType;
}
