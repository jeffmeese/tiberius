#ifndef RESOURCETRADEDIALOG_H
#define RESOURCETRADEDIALOG_H

#include "dialog/dialog.h"

class Resource;
namespace Ui {
  class ResourceTradeDialog;
}

class ResourceTradeDialog : public Dialog
{
  Q_OBJECT

public:
  explicit ResourceTradeDialog(Resource * resouce, QWidget *parent = nullptr);
  ~ResourceTradeDialog();

public:
  void setCanProduce(bool value);
  void setIndustryOn(bool value);
  void setStockpiling(bool value);
  void setTradeAvailable(bool value);
  void setUnitsStored(int32_t value);

private:
  void init();
  void updateAmountStored();
  void updateIndustryStatus();
  void updateStockpileStatus();
  void updateTradeStatus();

private slots:
  void handleDecreaseExports();
  void handleIncreaseExports();
  void handleIndustry();
  void handleStockpile();
  void handleTradeStatus();

private:
  Ui::ResourceTradeDialog * mUi;
  Resource * mResource;
  bool mCanProduce;
  bool mTradeAvailable;
};

#endif // RESOURCETRADEDIALOG_H
