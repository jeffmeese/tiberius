#ifndef DONATIONDIALOG_H
#define DONATIONDIALOG_H

#include "dialog/dialog.h"

namespace Ui {
  class DonationDialog;
}

class DonationDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit DonationDialog(QWidget *parent = nullptr);
  ~DonationDialog();

public:
  int32_t donationAmount() const;
  void setPersonalSavings(int32_t value);

private:
  void init();
  void updateDonationAmount(int32_t value);

private slots:
  void handle500();
  void handle2000();
  void handle5000();
  void handleAll();
  void handleCancel();
  void handleDown();
  void handleGive();
  void handleUp();
  void handleZero();

private:
  Ui::DonationDialog *mUi;
  int32_t mDonationAmount;
  int32_t mPersonalSavings;
};

#endif // DONATIONDIALOG_H
