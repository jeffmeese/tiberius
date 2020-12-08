#ifndef MAP_H
#define MAP_H

#include "tiberius.h"
#include "grid.h"

#include <memory>

class Bookmark;

class Map
{
public:
  TIBERIUS_LIB_DECL Map();
  TIBERIUS_LIB_DECL ~Map();

public:
  static const int MAX_BOOKMARKS = 4;

  // Grids
public:
  TIBERIUS_LIB_DECL UnsignedByteGrid * aqueductGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * aqueductGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * aqueductBackupGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * aqueductBackupGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * bitfieldsGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * bitfieldsGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * buildingGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * buildingGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * buildingDamageGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * buildingDamageGrid() const;
  TIBERIUS_LIB_DECL ByteGrid * desirabilityGrid();
  TIBERIUS_LIB_DECL const ByteGrid * desirabilityGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * edgeGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * edgeGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * elevationGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * elevationGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * figureGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * figureGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * graphicGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * graphicGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * randomGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * randomGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * spriteGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * spriteGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * spriteBackupGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * spriteBackupGrid() const;
  TIBERIUS_LIB_DECL UnsignedShortGrid * terrainGrid();
  TIBERIUS_LIB_DECL const UnsignedShortGrid * terrainGrid() const;
  TIBERIUS_LIB_DECL UnsignedByteGrid * terrainRandomGrid();
  TIBERIUS_LIB_DECL const UnsignedByteGrid * terrainRandomGrid() const;

private:
  using BookmarkPtr = std::unique_ptr<Bookmark>;
  using ByteGridPtr = std::unique_ptr<ByteGrid>;
  using UnsignedByteGridPtr = std::unique_ptr<UnsignedByteGrid>;
  using UnsignedShortGridPtr = std::unique_ptr<UnsignedShortGrid>;
  using BookmarkVector = std::vector<BookmarkPtr>;

private:
  BookmarkVector mBookmarks;
  UnsignedByteGridPtr mAqueductGrid;
  UnsignedByteGridPtr mAqueductBackupGrid;
  UnsignedByteGridPtr mBitfieldsGrid;
  UnsignedShortGridPtr mBuildingGrid;
  UnsignedByteGridPtr mBuildingDamageGrid;
  ByteGridPtr mDesirabilityGrid;
  UnsignedByteGridPtr mEdgeGrid;
  UnsignedByteGridPtr mElevationGrid;
  UnsignedShortGridPtr mFigureGrid;
  UnsignedShortGridPtr mGraphicGrid;
  UnsignedByteGridPtr mRandomGrid;
  UnsignedByteGridPtr mSpriteGrid;
  UnsignedByteGridPtr mSpriteGridBackup;
  UnsignedShortGridPtr mTerrainGrid;
  UnsignedByteGridPtr mTerrainRandomGrid;
};

#endif // MAP_H
