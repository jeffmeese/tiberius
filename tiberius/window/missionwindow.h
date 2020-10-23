#ifndef MISSIONWINDOW_H
#define MISSIONWINDOW_H

#include <QMediaPlayer>
#include <QTimer>
#include <QWidget>

#include <memory>

namespace Ui {
  class MissionWindow;
}

class MissionWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit MissionWindow(QWidget *parent = nullptr);
  ~MissionWindow();

public:
  int missionNumber() const;
  void setMissionNumber(int number);

protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;
  void showEvent(QShowEvent *event) override;

private slots:
  void showDialog();

private:
  void init();

signals:
  void startMission(int missionNumber);

private:
  std::unique_ptr<Ui::MissionWindow> mUi;
  int mMissionNumber;
  QTimer mTimer;
  QMediaPlayer mMediaPlayer;
};

inline int MissionWindow::missionNumber() const
{
  return mMissionNumber;
}

#endif // MISSIONWINDOW_H
