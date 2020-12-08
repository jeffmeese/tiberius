#include "map.h"
#include "bookmark.h"

Map::Map()
{
  mBookmarks.resize(MAX_BOOKMARKS);
  for (int i = 0; i < MAX_BOOKMARKS; i++) {
    mBookmarks[i].reset(new Bookmark);
  }

  mAqueductGrid.reset(new UnsignedByteGrid);
  mAqueductBackupGrid.reset(new UnsignedByteGrid);
  mBitfieldsGrid.reset(new UnsignedByteGrid);
  mBuildingGrid.reset(new UnsignedShortGrid);
  mBuildingDamageGrid.reset(new UnsignedByteGrid);
  mDesirabilityGrid.reset(new ByteGrid);
  mEdgeGrid.reset(new UnsignedByteGrid);
  mElevationGrid.reset(new UnsignedByteGrid);
  mFigureGrid.reset(new UnsignedShortGrid);
  mGraphicGrid.reset(new UnsignedShortGrid);
  mRandomGrid.reset(new UnsignedByteGrid);
  mSpriteGrid.reset(new UnsignedByteGrid);
  mSpriteGridBackup.reset(new UnsignedByteGrid);
  mTerrainGrid.reset(new UnsignedShortGrid);
  mTerrainRandomGrid.reset(new UnsignedByteGrid);
}

Map::~Map()
{
}

UnsignedByteGrid * Map::aqueductGrid()
{
  return mAqueductGrid.get();
}

const UnsignedByteGrid * Map::aqueductGrid() const
{
  return mAqueductGrid.get();
}

UnsignedByteGrid * Map::aqueductBackupGrid()
{
  return mAqueductBackupGrid.get();
}

const UnsignedByteGrid * Map::aqueductBackupGrid() const
{
  return mAqueductBackupGrid.get();
}

UnsignedByteGrid * Map::bitfieldsGrid()
{
  return mBitfieldsGrid.get();
}

const UnsignedByteGrid * Map::bitfieldsGrid() const
{
  return mBitfieldsGrid.get();
}

UnsignedShortGrid * Map::buildingGrid()
{
  return mBuildingGrid.get();
}

const UnsignedShortGrid * Map::buildingGrid() const
{
  return mBuildingGrid.get();
}

UnsignedByteGrid * Map::buildingDamageGrid()
{
  return mBuildingDamageGrid.get();
}

const UnsignedByteGrid * Map::buildingDamageGrid() const
{
  return mBuildingDamageGrid.get();
}

ByteGrid * Map::desirabilityGrid()
{
  return mDesirabilityGrid.get();
}

const ByteGrid * Map::desirabilityGrid() const
{
  return mDesirabilityGrid.get();
}

UnsignedByteGrid * Map::edgeGrid()
{
  return mEdgeGrid.get();
}

const UnsignedByteGrid * Map::edgeGrid() const
{
  return mEdgeGrid.get();
}

UnsignedByteGrid * Map::elevationGrid()
{
  return mElevationGrid.get();
}

const UnsignedByteGrid * Map::elevationGrid() const
{
  return mElevationGrid.get();
}

UnsignedShortGrid * Map::figureGrid()
{
  return mFigureGrid.get();
}

const UnsignedShortGrid * Map::figureGrid() const
{
  return mFigureGrid.get();
}

UnsignedShortGrid * Map::graphicGrid()
{
  return mGraphicGrid.get();
}

const UnsignedShortGrid * Map::graphicGrid() const
{
  return mGraphicGrid.get();
}

UnsignedByteGrid * Map::randomGrid()
{
  return mRandomGrid.get();
}

const UnsignedByteGrid * Map::randomGrid() const
{
  return mRandomGrid.get();
}

UnsignedByteGrid * Map::spriteGrid()
{
  return mSpriteGrid.get();
}

const UnsignedByteGrid * Map::spriteGrid() const
{
  return mSpriteGrid.get();
}

UnsignedByteGrid * Map::spriteBackupGrid()
{
  return mSpriteGridBackup.get();
}

const UnsignedByteGrid * Map::spriteBackupGrid() const
{
  return mSpriteGridBackup.get();
}

UnsignedShortGrid * Map::terrainGrid()
{
  return mTerrainGrid.get();
}

const UnsignedShortGrid * Map::terrainGrid() const
{
  return mTerrainGrid.get();
}

UnsignedByteGrid * Map::terrainRandomGrid()
{
  return mTerrainRandomGrid.get();
}

const UnsignedByteGrid * Map::terrainRandomGrid() const
{
  return mTerrainRandomGrid.get();
}
