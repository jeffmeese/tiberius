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
  void displayAnimationGrid(const UnsignedByteGrid * grid);
  void displayAqueductGrid(const UnsignedByteGrid * grid);
  void displayBitfieldGrid(const UnsignedByteGrid * grid);
  void displayBuildingGrid(const UnsignedShortGrid * grid);
  void displayDamageGrid(const UnsignedByteGrid * grid);
  void displayDesirabilityGrid(const ByteGrid * grid);
  void displayEdgeGrid(const UnsignedByteGrid * grid);
  void displayElevationGrid(const UnsignedByteGrid * grid);
  void displayGraphicGrid(const UnsignedShortGrid * grid);
  void displayMergingGrid(const UnsignedByteGrid * grid);
  void displayTerrainGrid(const UnsignedShortGrid * grid);
  void displayWalkerGrid(const UnsignedShortGrid * grid);

private:
  int mRed[MapSize];
  int mGreen[MapSize];
  int mBlue[MapSize];
};

#endif // GRIDVIEW_H
