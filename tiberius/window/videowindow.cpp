#include "videowindow.h"
#include "ui_videowindow.h"

#include <QDir>
#include <QVBoxLayout>

VideoWindow::VideoWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::VideoWindow)
{
  ui->setupUi(this);

  setLayout(new QVBoxLayout(this));

  mVideoWidget = new QVideoWidget(this);
  mVideoWidget->move(0, 0);
  mVideoWidget->resize(width(), height());
  layout()->addWidget(mVideoWidget);

  //QString fileName("C:\\vid.avi");
  //QString fileName("D:\\videos/HBSquirtB2018.avi");
  //QString fileName("D:\\videos\\hb.avi");
  QString fileName("C:\\applications\\Impressions Games\\Caesar3\\smk\\city_Fire.smk");
  QUrl url = QUrl::fromLocalFile(fileName);
  qDebug() << QDir::fromNativeSeparators(fileName);
  //QUrl url = QUrl::fromLocalFile("C:\\applications\\Impressions Games\\Caesar3\\smk\\hb.avi");
  qDebug() << url.isValid();
  mPlayer.setMedia(url);
  mPlayer.setVideoOutput(mVideoWidget);
  mPlayer.play();
}

VideoWindow::~VideoWindow()
{
  delete ui;
}
