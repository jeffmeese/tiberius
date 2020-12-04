#include "empirewindow.h"
#include "ui_empirewindow.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "widget/button.h"

#include <QDebug>
#include <QPainter>
#include <QPixmap>

EmpireWindow::EmpireWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::EmpireWindow)
{
  init();
}

EmpireWindow::~EmpireWindow()
{
}

void EmpireWindow::handleExit()
{
  emit closed();
}

void EmpireWindow::handleTrade()
{
  emit tradeRequested();
}

void EmpireWindow::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t mapId = imageData->getGroupBaseImageId(GROUP_EMPIRE_MAP);
  uint32_t panelBase = imageData->getGroupBaseImageId(GROUP_EMPIRE_PANELS);
  uint32_t contextBase = imageData->getGroupBaseImageId(GROUP_CONTEXT_ICONS);
  uint32_t advisorBase = imageData->getGroupBaseImageId(GROUP_MESSAGE_ADVISOR_BUTTONS);

  mUi->setupUi(this);

  mBackgroundImage.reset(new QImage(imageData->getImageRecord(mapId)->createImage()));
  mCityTitle.reset(new QImage(imageData->getImageRecord(panelBase+8)->createImage()));

  QIcon exitIcon;
  exitIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(contextBase+4)->createImage()));
  exitIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(contextBase+5)->createImage()), QIcon::Active);

  mExit.reset(new Button(this));
  mExit->resize(24, 24);
  mExit->setIcon(exitIcon);
  mExit->setIconSize(QSize(24, 24));

  QIcon tradeIcon;
  tradeIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(advisorBase+12)->createImage()));
  tradeIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(advisorBase+13)->createImage()), QIcon::Active);
  mTrade.reset(new Button(this));
  mTrade->setMouseTracking(true);
  mTrade->resize(24, 24);
  mTrade->setIcon(tradeIcon);
  mTrade->setIconSize(QSize(24, 24));

  connect(mExit.get(), SIGNAL(clicked()), SLOT(handleExit()));
  connect(mTrade.get(), SIGNAL(clicked()), SLOT(handleTrade()));
}

void EmpireWindow::paintEvent(QPaintEvent *)
{
  int w = width();
  int h = height();

  QPainter painter(this);
  painter.drawImage(0, 0, *mBackgroundImage);

  int xOffset = (w - 332) / 2;
  int yOffset = (h - 92 - 100);
  painter.drawImage(xOffset, yOffset, *mCityTitle);
}

void EmpireWindow::resizeEvent(QResizeEvent *)
{
  QRect r = rect();
  mExit->move(r.right()-28, r.bottom()-36);
  mTrade->move(r.right()-28, r.bottom()-72);
}
