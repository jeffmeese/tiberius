#include "gridview.h"

#include <QDebug>
#include <QPainter>

GridView::GridView(QWidget *parent)
  : QWidget(parent)
{
  for (int i = 0; i < MapSize; i++) {
    mRed[i] = -1;
    mGreen[i] = -1;
    mBlue[i] = -1;
  }
}

void GridView::displayEdgeGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      if (value == 64) {
        mRed[index] = 255;
        mGreen[index] = 0;
        mBlue[index] = 0;
      }
      else {
        mRed[index] = 0;
        mBlue[index] = 255;
        mGreen[index] = 0;
      }
      index++;
    }
  }
  update();
}

void GridView::displayElevationGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      mRed[index] = value*100;
      mBlue[index] = 0;
      mGreen[index] = 0;
      index++;
    }
  }
  update();
}

void GridView::displayGraphicGrid(const UnsignedShortGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      while (value > 765)
        value -= 765;

      if (value < 255) {
        mRed[index] = value;
        mBlue[index] = mGreen[index] = 0;
      }
      else if (value < 512) {
        mRed[index] = 255;
        mBlue[index] = value-255;
        mGreen[index] = 0;
      }
      else {
        mRed[index] = 255;
        mBlue[index] = 255;
        mGreen[index] = value-512;
      }

      index++;
    }
  }
  update();
}

void GridView::displayRandomGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      if (value == 64) {
        mRed[index] = 255;
        mGreen[index] = 0;
        mBlue[index] = 0;
      }
      else {
        mRed[index] = 0;
        mBlue[index] = 255;
        mGreen[index] = 0;
      }
      index++;
    }
  }
  update();
}

void GridView::displayTerrainGrid(const UnsignedShortGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      while (value > 765)
        value -= 765;

      if (value < 255) {
        mRed[index] = value;
        mBlue[index] = mGreen[index] = 0;
      }
      else if (value < 512) {
        mRed[index] = 255;
        mBlue[index] = value-255;
        mGreen[index] = 0;
      }
      else {
        mRed[index] = 255;
        mBlue[index] = 255;
        mGreen[index] = value-512;
      }

      index++;
    }
  }
  update();

//  static const int r[] = {0, 0, 0, 0, 127, 127, 127, 127, 0, 0, 0, 0, 255, 255, 255, 255};
//  static const int g[] = {0, 0, 127, 127, 0, 0, 127, 127, 0, 0, 127, 127, 0, 0, 127, 127};
//  static const int b[] = {0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255};

//  int index = 0;
//  for (int i = 0; i < GridSize; i++) {
//    for (int j = 0; j < GridSize; j++) {
//      int value = grid->getData(index);
//      qDebug() << value;
//      switch (value) {
//      case 1:
//        mRed[index] = r[0];
//        mGreen[index] = g[0];
//        mBlue[index] = b[0];
//        break;;
//      case 2:
//        mRed[index] = r[1];
//        mGreen[index] = g[1];
//        mBlue[index] = b[1];
//        break;
//      case 4:
//        mRed[index] = r[2];
//        mGreen[index] = g[2];
//        mBlue[index] = b[2];
//        break;
//      case 8:
//        mRed[index] = r[3];
//        mGreen[index] = g[3];
//        mBlue[index] = b[3];
//        break;
//      case 16:
//        mRed[index] = r[4];
//        mGreen[index] = g[4];
//        mBlue[index] = b[4];
//        break;
//      case 32:
//        mRed[index] = r[5];
//        mGreen[index] = g[5];
//        mBlue[index] = b[5];
//        break;
//      case 64:
//        mRed[index] = r[6];
//        mGreen[index] = g[6];
//        mBlue[index] = b[6];
//        break;
//      case 128:
//        mRed[index] = r[7];
//        mGreen[index] = g[7];
//        mBlue[index] = b[7];
//        break;
//      case 256:
//        mRed[index] = r[8];
//        mGreen[index] = g[8];
//        mBlue[index] = b[8];
//        break;
//      case 512:
//        mRed[index] = r[9];
//        mGreen[index] = g[9];
//        mBlue[index] = b[9];
//        break;
//      case 1024:
//        mRed[index] = r[10];
//        mGreen[index] = g[10];
//        mBlue[index] = b[10];
//        break;
//      case 2048:
//        mRed[index] = r[11];
//        mGreen[index] = g[11];
//        mBlue[index] = b[11];
//        break;
//      case 4096:
//        mRed[index] = r[12];
//        mGreen[index] = g[12];
//        mBlue[index] = b[12];
//        break;
//      case 8192:
//        mRed[index] = r[13];
//        mGreen[index] = g[13];
//        mBlue[index] = b[13];
//        break;
//      case 16384:
//        mRed[index] = r[14];
//        mGreen[index] = g[14];
//        mBlue[index] = b[14];
//        break;
//      case 32768:
//        mRed[index] = r[15];
//        mGreen[index] = g[15];
//        mBlue[index] = b[15];
//        break;
//      }
//      index++;
//    }
//  }
//  update();

  //      if (value == 1) {
  //        mRed[index] = r[0];
  //        mGreen[index] = g[0];
  //        mBlue[index] = b[0];
  //      }
  //      else
  //      for (int k = 0; k < 16; k++) {
  //        if (((value >> k) & 0x0001) == 1) {
  //          mRed[index] = r[k];
  //          mGreen[index] = g[k];
  //          mBlue[index] = b[k];
  //        }
  //      }
}

void GridView::displayRandomTerrainGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      if (value == 64) {
        mRed[index] = 255;
        mGreen[index] = 0;
        mBlue[index] = 0;
      }
      else {
        mRed[index] = 0;
        mBlue[index] = 255;
        mGreen[index] = 0;
      }
      index++;
    }
  }
  update();
}

void GridView::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  int w = width();
  int h = height();

  int dx = w / GridSize;
  int dy = h / GridSize;
  int xOffset = 0;
  int yOffset = 0;
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      if (mRed[index] >= 0 && mGreen[index] >= 0 && mBlue[index] >= 0) {
        QBrush brush(Qt::SolidPattern);
        QColor color(mRed[index], mGreen[index], mBlue[index]);
        brush.setColor(color);
        painter.fillRect(xOffset, yOffset, dx, dy, brush);
      }
      index++;
      xOffset += dx;
    }
    yOffset += dy;
    xOffset = 0;
  }
}
