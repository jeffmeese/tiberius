#ifndef CITYCONSTRUCTIONWINDOW_H
#define CITYCONSTRUCTIONWINDOW_H

#include <QWidget>

#include <memory>

namespace Ui {
  class CityConstructionWindow;
}

class CityConstructionWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit CityConstructionWindow(QWidget *parent = nullptr);
  ~CityConstructionWindow();

private:
  std::unique_ptr<Ui::CityConstructionWindow> mUi;
};

#endif // CITYCONSTRUCTIONWINDOW_H
