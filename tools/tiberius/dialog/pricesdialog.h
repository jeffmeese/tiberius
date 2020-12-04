#ifndef PRICESDIALOG_H
#define PRICESDIALOG_H

#include "dialog/dialog.h"

namespace Ui {
  class PricesDialog;
}

class PricesDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit PricesDialog(QWidget *parent = nullptr);
  ~PricesDialog();

public:
  void setClayBuyPrice(int32_t value);
  void setClaySellPrice(int32_t value);
  void setFurnitureBuyPrice(int32_t value);
  void setFurnitureSellPrice(int32_t value);
  void setFruitBuyPrice(int32_t value);
  void setFruitSellPrice(int32_t value);
  void setIronBuyPrice(int32_t value);
  void setIronSellPrice(int32_t value);
  void setMarbleBuyPrice(int32_t value);
  void setMarbleSellPrice(int32_t value);
  void setMeatBuyPrice(int32_t value);
  void setMeatSellPrice(int32_t value);
  void setOilBuyPrice(int32_t value);
  void setOilSellPrice(int32_t value);
  void setOliveBuyPrice(int32_t value);
  void setOliveSellPrice(int32_t value);
  void setPotteryBuyPrice(int32_t value);
  void setPotterySellPrice(int32_t value);
  void setTimberBuyPrice(int32_t value);
  void setTimberSellPrice(int32_t value);
  void setVegetableBuyPrice(int32_t value);
  void setVegetableSellPrice(int32_t value);
  void setVineBuyPrice(int32_t value);
  void setVineSellPrice(int32_t value);
  void setWeaponsBuyPrice(int32_t value);
  void setWeaponsSellPrice(int32_t value);
  void setWheatBuyPrice(int32_t value);
  void setWheatSellPrice(int32_t value);
  void setWineBuyPrice(int32_t value);
  void setWineSellPrice(int32_t value);

protected:
  void mousePressEvent(QMouseEvent * event) override;

private:
  void init();

private:
  Ui::PricesDialog * mUi;
};

#endif // PRICESDIALOG_H
