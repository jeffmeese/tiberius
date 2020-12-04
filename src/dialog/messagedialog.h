#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include "dialog/dialog.h"

class Button;
class Font;
namespace Ui {
  class MessageDialog;
}

class MessageDialog
    : public Dialog
{
  Q_OBJECT

public:
  enum Type
  {
    LeaveEmpire = 0,
    OpenTradeRoute = 1,
    DispatchGoods = 2,
    InsufficientGoods = 3,
    InsufficientLegions = 4,
    NoSelectedLegions = 5,
    SendLegions = 6,
    RemoveFort = 7,
    RemoveBridge = 8,
  };

public:
  TIBERIUS_LIB_DECL explicit MessageDialog(QWidget *parent = nullptr);
  TIBERIUS_LIB_DECL MessageDialog(Type type, QWidget *parent = nullptr);
  TIBERIUS_LIB_DECL ~MessageDialog();

public:
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

protected:
  void mousePressEvent(QMouseEvent * event) override;

private:
   void initUi();

private:
  Ui::MessageDialog * mUi;
  Type mType;
};

inline MessageDialog::Type MessageDialog::type() const
{
  return mType;
}

#endif // MESSAGEDIALOG_H
