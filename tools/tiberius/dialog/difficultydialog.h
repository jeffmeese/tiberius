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
  explicit DifficultyDialog(QWidget *parent = nullptr);
  ~DifficultyDialog();

public:
  Difficulty::Type difficulty() const;
  bool godsEffectsOn() const;
  void setDifficulty(Difficulty::Type value);
  void setGodsEffectsOn(bool value);

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
