#include "missionwindow.h"
#include "ui_missionwindow.h"

#include "application/application.h"

#include "dialog/missiondialog.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "media/sound.h"
#include "media/sounds.h"
#include "media/sounddata.h"

#include <QDir>
#include <QMediaPlayer>
#include <QPainter>
#include <QTimer>
#include <QUrl>

MissionWindow::MissionWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::MissionWindow)
{
  init();
  setMissionNumber(1);
}

MissionWindow::~MissionWindow()
{
}

void MissionWindow::init()
{
  mUi->setupUi(this);
  mTimer.setInterval(1000);
  connect(&mTimer, SIGNAL(timeout()), SLOT(showDialog()));
}

void MissionWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void MissionWindow::resizeEvent(QResizeEvent *)
{

}

void MissionWindow::setMissionNumber(int number)
{
  mMissionNumber = number;

  SgImageData * imageData = Application::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_INTERMEZZO_BACKGROUND) + 1; // First image is the "fired" image
  uint32_t imageId = baseId + number;
  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));
}

void MissionWindow::showDialog()
{
  mTimer.stop();

  MissionDialog dialog(this);
  dialog.setMission(mMissionNumber);
  dialog.exec();

  mMediaPlayer.stop();
  emit startMission(mMissionNumber);
}

void MissionWindow::showEvent(QShowEvent * e)
{
  QWidget::showEvent(e);
  mTimer.start();

  Sound * sound = TiberiusApplication::soundData()->findSound(SOUND_01B);
  QString fileName = sound->fileName();
  mMediaPlayer.setMedia(QUrl::fromLocalFile(fileName));
  mMediaPlayer.play();
}
