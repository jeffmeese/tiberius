#include "titlewindow.h"
#include "ui_titlewindow.h"

#include "application/application.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QDebug>
#include <QPainter>

TitleWindow::TitleWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::TitleWindow)
{
  init();
}

TitleWindow::~TitleWindow()
{
}

void TitleWindow::init()
{
  mUi->setupUi(this);

  const SgImageData * imageData = Application::climateImages();
  uint32_t imageId = imageData->getGroupBaseImageId(GROUP_LOGO);
  mUi->cBackground->setPixmap(QPixmap::fromImage(imageData->getImageRecord(imageId)->createImage()));

  const StringData * stringData = Application::language()->stringData();

  // Create the label
  Font f(Font::Type::NormalWhite);
  QString textString = stringData->getString(13, 7);
  int32_t textWidth = f.calculateTextWidth(textString);

  mUi->cLabel->setText(textString);
  mUi->cLabel->setTextFont(f);
  mUi->cLabel->resize(textWidth, 24);
}

void TitleWindow::mouseReleaseEvent(QMouseEvent *)
{
  emit closed();
}

void TitleWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void TitleWindow::resizeEvent(QResizeEvent *)
{
  int w = width();
  int h = height();

  int xOffset = (w - mUi->cBackground->width()) / 2;
  int yOffset = (h - mUi->cBackground->height()) / 2;
  mUi->cBackground->move(xOffset, yOffset);

  Font f = mUi->cLabel->textFont();
  QString textString = mUi->cLabel->text();
  int32_t textWidth = f.calculateTextWidth(textString);
  xOffset = (w - textWidth) / 2;
  yOffset = yOffset + mUi->cBackground->height() - 30;
  mUi->cLabel->move(xOffset, yOffset);
}
