#ifndef SALARYDIALOG_H
#define SALARYDIALOG_H

#include "dialog/dialog.h"

#include "game/player.h"

class Label;
namespace Ui {
  class SalaryDialog;
}

class SalaryDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit SalaryDialog(QWidget *parent = nullptr);
  ~SalaryDialog();

public:
  Player::Rank salaryRank() const;
  void setEnableWarning(bool enable);

private:
  void init();
  void initSalaryString(Label * label, int32_t textId, Player::Rank rank);

private slots:
  void handleAedile();
  void handleArchitect();
  void handleCaesar();
  void handleCitizen();
  void handleClerk();
  void handleConsul();
  void handleEngineer();
  void handlePraetor();
  void handleProconsul();
  void handleProcurator();
  void handleQuaestor();

private:
  Ui::SalaryDialog * mUi;
  Player::Rank mSalaryRank;
  bool mEnableWarning;
};

#endif // SALARYDIALOG_H
