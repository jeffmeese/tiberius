#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "tiberius.h"

class Dialog
    : public QDialog
{
public:
  TIBERIUS_LIB_DECL Dialog(QWidget * parentWidget = nullptr);

protected:
  TIBERIUS_LIB_DECL void paintEvent(QPaintEvent * event) override;

private:
  void drawBorder(QPainter & painter);
};

#endif // DIALOG_H
