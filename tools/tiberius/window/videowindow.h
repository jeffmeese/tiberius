#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QWidget>

namespace Ui {
  class VideoWindow;
}

class VideoWindow : public QWidget
{
  Q_OBJECT

public:
  explicit VideoWindow(QWidget *parent = nullptr);
  ~VideoWindow();

private:
  Ui::VideoWindow *ui;
  QMediaPlayer mPlayer;
  QVideoWidget * mVideoWidget;
};

#endif // VIDEOWINDOW_H
