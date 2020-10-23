#include "citywidget.h"

#include <QPainter>

CityWidget::CityWidget(QWidget * parentWidget)
  : QWidget(parentWidget)
{
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

void CityWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  QImage image(width(), height(), QImage::Format_ARGB32);
  image.fill(Qt::black);

  QPainter imagePainter(&image);
  //if (mGame != nullptr) {
  //  drawTerrain(imagePainter);
  //}

  painter.drawImage(0, 0, image);
}

//#include "application/jcaesarapplication.h"

//#include "city/camera.h"
//#include "city/city.h"

//#include "game/game.h"

//#include "graphics/imagedata.h"
//#include "graphics/imageset.h"
//#include "graphics/sgimagedata.h"
//#include "graphics/sgimagerecord.h"
//#include "graphics/sgpixeldata.h"

//#include "map/grid.h"
//#include "map/map.h"

//#include <QDebug>
//#include <QImage>
//#include <QPainter>

//static const int32_t TILE_WIDTH_PIXELS = 60;
//static const int32_t TILE_HEIGHT_PIXELS = 30;
//static const int32_t HALF_TILE_WIDTH_PIXELS = 30;
//static const int32_t HALF_TILE_HEIGHT_PIXELS = 15;
//static const int32_t VIEW_X_MAX = 165;
//static const int32_t VIEW_Y_MAX = 325;

//CityView::CityView(QWidget * parentWidget)
//  : QWidget(parentWidget)
//  , mGame(nullptr)
//{
//  setBackgroundRole(QPalette::Base);
//  setAutoFillBackground(true);

//  mViewToGrid.resize(GridSize);
//  for (int32_t i = 0; i < GridSize; i++) {
//    mViewToGrid[i].resize(GridSize);
//    for (int32_t j = 0; j < GridSize; j++) {
//      mViewToGrid[i][j] = -1;
//    }
//  }
//}

//void CityView::cancelConstruction()
//{

//}

//void CityView::drawTerrain(QPainter &painter)
//{
//  QString climateFile = JCaesarApplication::getClimateImageFile();
//  const SgImageData * imageData = JCaesarApplication::getImageData()->getImageSet(climateFile)->imageData();

//  const City * city = mGame->getCity();
//  const Camera * camera = city->camera();
//  const Map * map = mGame->getMap();
//  const Grid<uint16_t> * imageGrid = map->imageGrid();
//  Location viewTile = camera->viewTile();

//  int xView = viewTile.x();
//  int yView = viewTile.y();

//  int32_t xGraphic = mWidth / 2 - HALF_TILE_WIDTH_PIXELS;
//  int32_t yGraphic = HALF_TILE_HEIGHT_PIXELS - 8;
//  int gridOffset = 6683;
//  for (int i = 0; i < 20; i++) {
//    int imageId = imageGrid->getData(gridOffset);
//    const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
//    QImage recordImage = imageRecord->createImage();
//    painter.drawImage(xGraphic, yGraphic, recordImage);
//    xGraphic += HALF_TILE_WIDTH_PIXELS;
//    yGraphic += HALF_TILE_HEIGHT_PIXELS;
//    gridOffset++;
//  }

////  int gridIds[] = {9440, 9440, 9440, 9440, 9440, 9440, 9440};
////  int32_t xGraphic = mWidth / 2 - HALF_TILE_WIDTH_PIXELS;
////  int32_t yGraphic = HALF_TILE_HEIGHT_PIXELS - 8;
////  for (int i = 0; i < 7; i++) {
////    int gridOffset = gridIds[i];
////    int imageId = imageGrid->getData(gridOffset);
////    const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
////    QImage recordImage = imageRecord->createImage();
////    painter.drawImage(xGraphic, yGraphic, recordImage);
////    xGraphic += HALF_TILE_WIDTH_PIXELS;
////    yGraphic += HALF_TILE_HEIGHT_PIXELS;
////  }

//  //int gridOffset = (viewTile.y()) + (viewTile.x()*GridSize);
////  int gridOffset = 10419;
////  int imageId = imageGrid->getData(gridOffset);

////  int32_t xGraphic = mWidth / 2 - HALF_TILE_WIDTH_PIXELS;
////  int32_t yGraphic = HALF_TILE_HEIGHT_PIXELS - 8;
////  const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
////  QImage recordImage = imageRecord->createImage();
////  painter.drawImage(xGraphic, yGraphic, imageData->getImageRecord(imageId)->createImage());

////  imageId = imageGrid->getData(11771);
////  imageRecord = imageData->getImageRecord(imageId);
////  recordImage = imageRecord->createImage();
////  painter.drawImage(xGraphic+HALF_TILE_WIDTH_PIXELS, yGraphic+HALF_TILE_HEIGHT_PIXELS, recordImage);

////  imageId = imageGrid->getData(11610);
////  imageRecord = imageData->getImageRecord(imageId);
////  recordImage = imageRecord->createImage();
////  painter.drawImage(xGraphic+2*HALF_TILE_WIDTH_PIXELS, yGraphic+2*HALF_TILE_HEIGHT_PIXELS, recordImage);


////  painter.drawImage(xGraphic+HALF_TILE_WIDTH_PIXELS, yGraphic+HALF_TILE_HEIGHT_PIXELS, recordImage);

////  int32_t gridOffset = 6683;

////  uint16_t imageId = imageGrid->getData(gridOffset);

////  const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
////  QImage recordImage = imageRecord->createImage();
////  painter.drawImage(xGraphic, yGraphic, recordImage);

////  int32_t xTile = camera->viewTile().x();
////  int32_t yTile = camera->viewTile().y();
////  int32_t xPixel = camera->pixelOffset().x();
////  int32_t yPixel = camera->pixelOffset().y();

////  for (int32_t i = 0; i < Grid::GridSize; i++) {
////    for (int32_t j = 0; j < Grid::GridSize; j++) {
////      int32_t gridOffset = i*Grid::GridSize + j;
////      uint16_t id = imageGrid->getData(gridOffset);
////      if (id > 0) {
////        qDebug() << gridOffset;
////      }
////    }
////  }
////  bool odd = false;
////  int32_t yView = yTile - 8;
////  int32_t yGraphic = mViewportY - 9*HALF_TILE_HEIGHT_PIXELS - yPixel;
////  for (int32_t y = 0; y < mTileHeight + 21; y++) {
////    int32_t xGraphic = -(4*TILE_WIDTH_PIXELS) - xPixel + mViewportX;
////    if (odd) {
////      xGraphic -= HALF_TILE_WIDTH_PIXELS;
////    }

////    int32_t xView = xTile - 4;
////    for (int32_t x = 0; x < mTileWidth  + 7; x++) {
////      int32_t gridOffset = 10000;

////      uint16_t imageId = imageGrid->getData(gridOffset);
////      const SgImageRecord * imageRecord = imageData->getImageRecord(imageId);
////      QImage recordImage = imageRecord->createImage();
////      painter.drawImage(xGraphic, yGraphic, recordImage);

////      xGraphic += TILE_WIDTH_PIXELS;
////      xView++;
////    }
////    odd = !odd;
////    yGraphic += HALF_TILE_HEIGHT_PIXELS;
////    yView++;
////  }
//}

//Game * CityView::game()
//{
//  return mGame;
//}

//const Game * CityView::game() const
//{
//  return mGame;
//}

//void CityView::paintEvent(QPaintEvent *)
//{
//  QPainter painter(this);

//  QImage image(width(), height(), QImage::Format_ARGB32);
//  image.fill(Qt::black);

//  QPainter imagePainter(&image);
//  if (mGame != nullptr) {
//    drawTerrain(imagePainter);
//  }

//  painter.drawImage(0, 0, image);
//}

//void CityView::orientNorth()
//{

//}

//void CityView::resizeEvent(QResizeEvent *)
//{
//  mWidth = width();
//  mHeight = height();
//  mWidthTiles = mWidth / TILE_WIDTH_PIXELS;
//  mHeightTiles = mHeight / HALF_TILE_HEIGHT_PIXELS;

//  for (int y = 0; y < GridSize; y++) {
//    for (int x = 0; x < GridSize; x++) {
//      mViewToGrid[x][y] = -1;
//    }
//  }

//  if (mGame != nullptr) {
//    const Map * map = mGame->getMap();
//    const Grid<uint16_t> * imageGrid = map->imageGrid();
//    for (int y = 0; y < GridSize; y++) {
//      for (int x = 0; x < GridSize; x++) {
//        int gridOffset = y*GridSize + x;
//        if (gridOffset > 5) {

//        }
//      }
//    }
//  }

//}

//void CityView::rotateRight()
//{

//}

//void CityView::rotateLeft()
//{

//}

//void CityView::setGame(Game *game)
//{
//  mGame = game;
//}

//void CityView::showAcademyOverlay()
//{

//}

//void CityView::showAmpitheaterOverlay()
//{

//}

//void CityView::showBarberOverlay()
//{

//}

//void CityView::showBathsOverlay()
//{

//}

//void CityView::showClinicOverlay()
//{

//}

//void CityView::showColoseumOverlay()
//{

//}

//void CityView::showCrimeOverlay()
//{

//}

//void CityView::showDamageOverlay()
//{

//}

//void CityView::showDesirabilityOverlay()
//{

//}

//void CityView::showEducationOverlay()
//{

//}

//void CityView::showEntertainmentOverlay()
//{

//}

//void CityView::showFireOverlay()
//{

//}

//void CityView::showFoodOverlay()
//{

//}

//void CityView::showHippodromeOverlay()
//{

//}

//void CityView::showHospitalOverlay()
//{

//}

//void CityView::showLibraryOverlay()
//{

//}

//void CityView::showNativeOverlay()
//{

//}

//void CityView::showNormalOverlay()
//{

//}

//void CityView::showProblemsOverlay()
//{

//}

//void CityView::showReligionOverlay()
//{

//}

//void CityView::showSchoolOverlay()
//{

//}

//void CityView::showTaxOverlay()
//{

//}

//void CityView::showTheaterOverlay()
//{

//}

//void CityView::showWaterOverlay()
//{

//}
