#ifndef RESOURCE_H
#define RESOURCE_H

#include "tiberius.h"

#include <QPixmap>

#include <cstdint>

class Resource
{
public:
  static const int32_t MAX_RESOURCES = 15;

public:
  enum class Type
  {
    None = 0,
    Wheat = 1,
    Vegetables = 2,
    Fruit = 3,
    Olives = 4,
    Vines = 5,
    Meat = 6,
    Wine = 7,
    Oil = 8,
    Iron = 9,
    Timber = 10,
    Clay = 11,
    Marble = 12,
    Weapons = 13,
    Furniture = 14,
    Pottery = 15
  };

  enum class TradeStatus
  {
    NotTrading = 0,
    Importing = 1,
    Exporting = 2,
  };

public:
  TIBERIUS_LIB_DECL Resource(Type type);

public:
  TIBERIUS_LIB_DECL int32_t activeIndustries() const;
  TIBERIUS_LIB_DECL int32_t amountStored() const;
  TIBERIUS_LIB_DECL bool canExport() const;
  TIBERIUS_LIB_DECL bool canImport() const;
  TIBERIUS_LIB_DECL bool canProduce() const;
  TIBERIUS_LIB_DECL int32_t buyPrice() const;
  TIBERIUS_LIB_DECL int32_t exportUnits() const;
  TIBERIUS_LIB_DECL bool isIndustryOn() const;
  TIBERIUS_LIB_DECL int32_t sellPrice() const;
  TIBERIUS_LIB_DECL bool stockpiling() const;
  TIBERIUS_LIB_DECL int32_t totalIndustries() const;
  TIBERIUS_LIB_DECL TradeStatus tradeStatus() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setActiveIndustries(int32_t value);
  TIBERIUS_LIB_DECL void setAmountStored(int32_t value);
  TIBERIUS_LIB_DECL void setBuyPrice(int32_t value);
  TIBERIUS_LIB_DECL void setCanExport(bool value);
  TIBERIUS_LIB_DECL void setCanImport(bool value);
  TIBERIUS_LIB_DECL void setCanProduce(bool value);
  TIBERIUS_LIB_DECL void setExporting(bool value);
  TIBERIUS_LIB_DECL void setExportUnits(int32_t value);
  TIBERIUS_LIB_DECL void setIndustryOn(bool on);
  TIBERIUS_LIB_DECL void setSellPrice(int32_t value);
  TIBERIUS_LIB_DECL void setStockpiling(bool value);
  TIBERIUS_LIB_DECL void setTradeStatus(TradeStatus value);
  TIBERIUS_LIB_DECL void setTotalIndustries(int32_t value);

public:
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getString() const;
  TIBERIUS_LIB_DECL bool tradeAvailable() const;

public:
  TIBERIUS_LIB_DECL static QPixmap getImage(Type type);
  TIBERIUS_LIB_DECL static QString getString(Type type);

private:
  bool mCanExport;
  bool mCanImport;
  bool mCanProduce;
  bool mIndustryOn;
  bool mStockpiling;
  int32_t mActiveIndustries;
  int32_t mAmountStored;
  int32_t mBuyPrice;
  int32_t mExportUnits;
  int32_t mSellPrice;
  int32_t mTotalIndustries;
  TradeStatus mTradeStatus;
  Type mType;
  QString mString;
};

#endif // RESOURCE_H
