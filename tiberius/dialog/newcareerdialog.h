#ifndef NEWCAREERDIALOG_H
#define NEWCAREERDIALOG_H

#include "dialog/dialog.h"

namespace Ui {
  class NewCareerDialog;
}

class NewCareerDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit NewCareerDialog(QWidget *parent = nullptr);
  ~NewCareerDialog();

public:
  QString name() const;
  void setName(const QString & name);

protected:
  void showEvent(QShowEvent *event) override;

private:
  void init();

private slots:
  void updateData();

private:
  Ui::NewCareerDialog * mUi;
};

#endif // NEWCAREERDIALOG_H
