#include "advisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include <QPainter>

AdvisorWidget::AdvisorWidget(QWidget *parent)
  : QWidget(parent)
  , mGame(nullptr)
{
}

Game * AdvisorWidget::game()
{
  return mGame;
}

void AdvisorWidget::drawBorder(QPainter & painter)
{
  SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageIndex = imageData->getGroupBaseImageId(GROUP_DIALOG_BACKGROUND);

  int w = width();
  int h = height();
  StitchedImage stitchedImage(16, 16, 12, 12, baseImageIndex);
  painter.drawImage(0, 0, stitchedImage.constructImage(w, h));
}

void AdvisorWidget::paintEvent(QPaintEvent * event)
{
  QPainter painter(this);
  drawBorder(painter);
}

void AdvisorWidget::setGame(Game *game)
{
  mGame = game;
  update();
}

void AdvisorWidget::update()
{
  doUpdate();
}
