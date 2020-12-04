#include "menuwindow.h"
#include "ui_menuwindow.h"

#include "videowindow.h"

#include "application/tiberiusapplication.h"

#include "dialog/filedialog.h"
#include "dialog/messagedialog.h"
#include "dialog/newcareerdialog.h"

#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "media/video.h"
#include "media/videodata.h"
#include "media/videos.h"

#include "widget/button.h"
//#include "widget/videowindow.h"

#include <QLayout>
#include <QMediaPlayer>
#include <QPainter>
#include <QVideoWidget>

MenuWindow::MenuWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::MenuWindow)
{
  init();
}

MenuWindow::~MenuWindow()
{

}

void MenuWindow::handleExit()
{
  MessageDialog dialog(MessageDialog::LeaveEmpire, this);
  int32_t resp = dialog.exec();
  if (resp == QDialog::Rejected) {
    return;
  }

  QApplication::exit(0);
}

void MenuWindow::handleLoadGame()
{
  FileDialog dialog(this);
  dialog.setType(FileDialog::LoadMap);
  int nResp = dialog.exec();
  if (nResp == QDialog::Rejected) {
    return;
  }

  QString fileName = dialog.fileName();
  emit loadGame(fileName);
}

void MenuWindow::handleNewCareer()
{
  NewCareerDialog dialog(this);
  int nResp = dialog.exec();
  if (nResp == QDialog::Accepted) {
    QString name = dialog.name();
    emit startNewCareer(name);
  }
}

void MenuWindow::handleOptions()
{
  VideoWindow * w = new VideoWindow;
  w->setGeometry(100, 100, 600, 480);
  w->show();

//  QWidget * widget = new QWidget;
//  widget->setGeometry(100, 100, 600, 480);
//  widget->setLayout(new QHBoxLayout);
//  widget->layout()->addWidget(videoWidget);
//  widget->show();

//  QString fileName("D:\\videos\\HBSquirtB2018.avi");
//  mPlayer.setMedia(QUrl::fromLocalFile(fileName));
//  mPlayer.setVideoOutput(videoWidget);
//  mPlayer.play();

  //VideoData * videoData = TiberiusApplication::videoData();
  //Video * video = videoData->findVideo(VIDEO_CITY_FIRE);
  //video->play();
}

void MenuWindow::init()
{
  mUi->setupUi(this);

  const StringData * stringData = TiberiusApplication::language()->stringData();
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_MAIN_MENU_BACKGROUND);
  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(baseImageId)->createImage()));

  initButton(mUi->cStartCareer, stringData->getString(30, 1));
  initButton(mUi->cLoadGame, stringData->getString(30, 2));
  initButton(mUi->cCityConstruction, stringData->getString(30, 3));
  initButton(mUi->cOptions, stringData->getString(2, 0));
  initButton(mUi->cExit, stringData->getString(30, 5));

  connect(mUi->cStartCareer, SIGNAL(clicked()), SLOT(handleNewCareer()));
  connect(mUi->cExit, SIGNAL(clicked()), SLOT(handleExit()));
  connect(mUi->cLoadGame, SIGNAL(clicked()), SLOT(handleLoadGame()));
  connect(mUi->cOptions, SIGNAL(clicked()), SLOT(handleOptions()));
}

void MenuWindow::initButton(Button *button, const QString &text)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);

  button->setText(text);
  button->setTextFont(Font::Type::NormalGreen);

  QImage image(width(), height(), QImage::Format_RGB32);
  QImage hoverImage(width(), height(), QImage::Format_RGB32);
  QPainter normalPainter(&image);
  QPainter hoverPainter(&hoverImage);

  int32_t blocks = width() / 16;
  for (int32_t i = 0; i < blocks; i++) {
    uint32_t imageId = baseImageId + 1;
    uint32_t hoverImageId = baseImageId + 4;
    if (i == 0) {
      imageId = baseImageId;
      hoverImageId = baseImageId + 3;
    }
    if (i == blocks-1) {
      imageId = baseImageId + 2;
      hoverImageId = baseImageId + 5;
    }

    normalPainter.drawImage(i*16, 0, imageData->getImageRecord(imageId)->createImage());
    hoverPainter.drawImage(i*16, 0, imageData->getImageRecord(hoverImageId)->createImage());
  }

  button->setImage(image);
  button->setHoverImage(hoverImage);
}

void MenuWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void MenuWindow::resizeEvent(QResizeEvent *)
{
  static const int NUM_BUTTONS = 5;
  static const int BUTTON_OFFSET = 16;

  int w = width();
  int h = height();

  int xOffset = (w - mUi->cBackground->width()) / 2;
  int yOffset = (h - mUi->cBackground->height()) / 2;
  mUi->cBackground->move(xOffset, yOffset);

  int buttonWidth = mUi->cStartCareer->width();
  int buttonHeight = mUi->cStartCareer->height();
  int buttonAreaHeight = NUM_BUTTONS*buttonHeight + (NUM_BUTTONS-1)*BUTTON_OFFSET;
  xOffset = (w - buttonWidth) / 2;
  yOffset = (h - buttonAreaHeight) / 2;
  mUi->cStartCareer->move(xOffset, yOffset);
  mUi->cLoadGame->move(xOffset, yOffset+buttonHeight+BUTTON_OFFSET);
  mUi->cCityConstruction->move(xOffset, yOffset+2*(buttonHeight+BUTTON_OFFSET));
  mUi->cOptions->move(xOffset, yOffset+3*(buttonHeight+BUTTON_OFFSET));
  mUi->cExit->move(xOffset, yOffset+4*(buttonHeight+BUTTON_OFFSET));
}
