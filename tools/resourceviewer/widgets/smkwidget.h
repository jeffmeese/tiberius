#ifndef SMKWIDGET_H
#define SMKWIDGET_H

#include <QWidget>
#include <memory>

class Video;
namespace Ui
{
  class SmkWidget;
}

class SmkWidget : public QWidget
{
  Q_OBJECT
public:
  SmkWidget(Video * video, QWidget *parent = nullptr);
  ~SmkWidget();

private slots:
  void handlePlayButton();
  void handleStopButton();

signals:

private:
  std::unique_ptr<Ui::SmkWidget> mUi;
  Video * mVideo;
};

#endif // SMKWIDGET_H
