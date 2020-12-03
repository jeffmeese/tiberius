#ifndef GRIDVIEW_H
#define GRIDVIEW_H

#include <QWidget>

#include "map/grid.h"

class GridView
    : public QWidget
{
  Q_OBJECT

public:
  explicit GridView(QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent * event) override;

public:
  void displayEdgeGrid(const UnsignedByteGrid * grid);
  void displayElevationGrid(const UnsignedByteGrid * grid);
  void displayGraphicGrid(const UnsignedShortGrid * grid);
  void displayRandomGrid(const UnsignedByteGrid * grid);
  void displayTerrainGrid(const UnsignedShortGrid * grid);
  void displayRandomTerrainGrid(const UnsignedByteGrid * grid);

private:
  int mRed[MapSize];
  int mGreen[MapSize];
  int mBlue[MapSize];
};

#endif // GRIDVIEW_H
