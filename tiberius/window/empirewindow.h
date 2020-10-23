#ifndef EMPIREWINDOW_H
#define EMPIREWINDOW_H

#include <QWidget>

namespace Ui {
  class EmpireWindow;
}

class EmpireWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit EmpireWindow(QWidget *parent = nullptr);
  ~EmpireWindow();

signals:
  void closed();

private:
  std::unique_ptr<Ui::EmpireWindow> mUi;
};

#endif // EMPIREWINDOW_H
