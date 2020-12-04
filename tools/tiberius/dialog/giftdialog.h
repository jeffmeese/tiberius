#ifndef GIFTDIALOG_H
#define GIFTDIALOG_H

#include "dialog/dialog.h"

class Gift;
class ImperialData;
class Label;
class Player;
namespace Ui {
  class GiftDialog;
}

class GiftDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit GiftDialog(QWidget *parent = nullptr);
  ~GiftDialog();

public:
  Gift * selectedGift();
  void setGenerousGiftId(int32_t value);
  void setLavishGiftId(int32_t value);
  void setModestGiftId(int32_t value);
  void setPlayerSavings(int32_t value);

private:
  void init();
  void initGiftString(int32_t textId, Label * label, Gift * gift);

private slots:
  void handleSelectGenerous();
  void handleSelectLavish();
  void handleSelectModest();

private:
  Ui::GiftDialog * mUi;
  int32_t mGenerousGiftId;
  int32_t mLavishGiftId;
  int32_t mModestGiftId;
  int32_t mPlayerSavings;
  Gift * mSelectedGift;
  std::unique_ptr<Gift> mGenerousGift;
  std::unique_ptr<Gift> mLavishGift;
  std::unique_ptr<Gift> mModestGift;
};

#endif // GIFTDIALOG_H
