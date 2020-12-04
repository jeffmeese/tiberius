#ifndef EMPIREWINDOW_H
#define EMPIREWINDOW_H

#include <QWidget>

namespace Ui {
  class EmpireWindow;
}

class Button;
class EmpireWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit EmpireWindow(QWidget *parent = nullptr);
  ~EmpireWindow();

protected:
  void paintEvent(QPaintEvent * paintEvent) override;
  void resizeEvent(QResizeEvent * event) override;

private:
  void init();

private slots:
  void handleExit();
  void handleTrade();

signals:
  void closed();
  void tradeRequested();

private:
  std::unique_ptr<Ui::EmpireWindow> mUi;
  std::unique_ptr<Button> mExit;
  std::unique_ptr<Button> mTrade;
  std::unique_ptr<QImage> mBackgroundImage;
  std::unique_ptr<QImage> mCityTitle;
};

#endif // EMPIREWINDOW_H
