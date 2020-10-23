#ifndef MISSIONDIALOG_H
#define MISSIONDIALOG_H

#include <memory>

#include "dialog/dialog.h"

namespace Ui {
  class MissionDialog;
}

class MissionDialog : public Dialog
{
  Q_OBJECT

public:
  explicit MissionDialog(QWidget *parent = nullptr);
  ~MissionDialog();

public:
  void setMission(int missionNumber);

private:
  void init();

private:
  std::unique_ptr<Ui::MissionDialog> mUi;
  int mMissionNumber;
};

#endif // MISSIONDIALOG_H
