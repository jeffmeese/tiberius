#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>

namespace Ui
{
  class TitleWindow;
}

class TitleWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit TitleWindow(QWidget *parent = nullptr);
  ~TitleWindow();

protected:
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  void init();

signals:
  void closed();

private:
  std::unique_ptr<Ui::TitleWindow> mUi;
};

#endif // TITLEWINDOW_H
