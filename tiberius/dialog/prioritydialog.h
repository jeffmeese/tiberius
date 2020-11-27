#ifndef PRIORITYDIALOG_H
#define PRIORITYDIALOG_H

#include "dialog/dialog.h"

namespace Ui {
  class PriorityDialog;
}

class PriorityDialog : public Dialog
{
  Q_OBJECT

public:
  explicit PriorityDialog(QWidget *parent = nullptr);
  ~PriorityDialog();

public:
  int selectedPriority() const;
  void setMaxPriority(int value);

protected:
  bool eventFilter(QObject * object, QEvent * event) override;
  void mousePressEvent(QMouseEvent * event) override;

private:
  void init();

private slots:
  void click1();
  void click2();
  void click3();
  void click4();
  void click5();
  void click6();
  void click7();
  void click8();
  void click9();
  void clickNone();

private:
  Ui::PriorityDialog *mUi;
  int mSelectedPriority;
};

inline int PriorityDialog::selectedPriority() const
{
  return mSelectedPriority;
}

#endif // PRIORITYDIALOG_H
