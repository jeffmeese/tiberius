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

void GridView::displayAnimationGrid(const UnsignedByteGrid * grid)
{
  int32_t index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mGreen[index] = 0;
      mBlue[index] = grid->getData(index)*255;
      index++;
    }
  }
  update();
}

void GridView::displayAqueductGrid(const UnsignedByteGrid * grid)
{
  int32_t index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mGreen[index] = 0;
      mBlue[index] = grid->getData(index)*255;
      index++;
    }
  }
  update();
}

void GridView::displayBitfieldGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      uint32_t value = grid->getData(index);
      if (value & 0x01) {
        mRed[index] = 255;
      }
      else if (value & 0x02) {
        mBlue[index] = 255;
      }
      else if (value & 0x04) {
        mGreen[index] = 255;
      }
      else if (value & 0x08) {
        mRed[index] = 255;
        mGreen[index] = 255;
      }

      index++;
    }
  }
  update();
}

void GridView::displayBuildingGrid(const UnsignedShortGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      int value = grid->getData(index);
      if (value > 1) {
        mRed[index] = 255;
      }
      index++;
    }
  }
  update();
}

void GridView::displayDamageGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      int value = grid->getData(index);
      if (value > 1) {
        mRed[index] = 255;
      }
      index++;
    }
  }
  update();
}

void GridView::displayDesirabilityGrid(const ByteGrid * grid)
{
  int32_t min = 1000;
  int32_t max = -1000;
  for (int i = 0; i < MapSize; i++) {
    int value = grid->getData(i);
    if (value > max)
      max = value;
    if (value < min)
      min = value;

    if (value != 0) {
      qDebug() << value;
    }
  }

  qDebug() << min << " " << max;

  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      int value = grid->getData(index);
      if (value != 0) {
        if (value < -50) {
          mRed[index] = (value * 255) / 100;
        }
        else if (value >= -50 && value < 0) {
          mRed[index] = (value * 255) / 100;
          mGreen[index] = (value * 255) / 100;
        }
        else if (value > 0 && value < 20) {
          mGreen[index] = (value * 255) / 100;
        }
        else if (value >= 20 && value < 40) {
          mGreen[index] = (value * 255) / 100;
          mBlue[index] = (value * 255) / 100;
        }
        else {
          mBlue[index] = (value * 255) / 100;
        }
      }
      index++;
    }
  }
  update();
}

void GridView::displayEdgeGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      int value = grid->getData(index);
      if (value > 1) {
        mRed[index] = 255;
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

void GridView::displayMergingGrid(const UnsignedByteGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      int value = grid->getData(index);
      mRed[index] = value;
      mBlue[index] = value;
      mGreen[index] = value;
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
}

void GridView::displayWalkerGrid(const UnsignedShortGrid * grid)
{
  int index = 0;
  for (int i = 0; i < GridSize; i++) {
    for (int j = 0; j < GridSize; j++) {
      mRed[index] = 0;
      mBlue[index] = 0;
      mGreen[index] = 0;

      int value = grid->getData(index);
      if (value > 1) {
        mRed[index] = 255;
      }
      index++;
    }
  }
  update();

    for (int i = 0; i < MapSize; i++) {
      if (grid->getData(i) > 255)
        qDebug() << grid->getData(i);
    }
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
