#include "map.h"
#include "bookmark.h"

Map::Map()
{
  mBookmarks.resize(MAX_BOOKMARKS);
  for (int i = 0; i < MAX_BOOKMARKS; i++) {
    mBookmarks[i].reset(new Bookmark);
  }
}

Map::~Map()
{

}
