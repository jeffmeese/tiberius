#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include "dialog/dialog.h"

#include "game/difficulty.h"

class Application;
namespace Ui {
  class DifficultyDialog;
}

class DifficultyDialog
    : public Dialog
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit DifficultyDialog(QWidget *parent = nullptr);
  TIBERIUS_LIB_DECL ~DifficultyDialog();

public:
  TIBERIUS_LIB_DECL Difficulty::Type difficulty() const;
  TIBERIUS_LIB_DECL bool godsEffectsOn() const;
  TIBERIUS_LIB_DECL void setDifficulty(Difficulty::Type value);
  TIBERIUS_LIB_DECL void setGodsEffectsOn(bool value);

protected:
  void mousePressEvent(QMouseEvent * event) override;

private:
  void initUi();
  void updateData();

private slots:
  void handleDecreaseDifficulty();
  void handleIncreaseDifficulty();
  void handleGodEffects();

signals:
  void changed();

private:
  Ui::DifficultyDialog * mUi;
  Difficulty::Type mType;
  bool mGodsEffects;
};

#endif // DIFFICULTYDIALOG_H
