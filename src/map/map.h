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

private:
  using BookmarkPtr = std::unique_ptr<Bookmark>;
  using ByteGridPtr = std::unique_ptr<ByteGrid>;
  using UnsignedByteGridPtr = std::unique_ptr<UnsigedByteGrid>;
  using UnsignedShortGridPtr = std::unique_ptr<UnsignedShortGrid>;
  using BookmarkVector = std::vector<BookmarkPtr>;

private:
  BookmarkVector mBookmarks;
  ByteGridPtr mDesirabiityGrid;
  UnsignedByteGridPtr mAqueductGrid;
  UnsignedByteGridPtr mAqueductBackupGrid;
  UnsignedByteGridPtr mBuildingDamageGrid;
  UnsignedByteGridPtr mSpriteGrid;
  UnsignedByteGridPtr mSpriteGridBackup;
  UnsignedShortGridPtr mFigureGrid;
};

#endif // MAP_H
