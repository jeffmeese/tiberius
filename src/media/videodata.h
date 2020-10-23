#ifndef VIDEODATA_H
#define VIDEODATA_H

#include "tiberius.h"

#include <map>
#include <memory>
#include <vector>

class Video;

class VideoData
{
public:
 TIBERIUS_LIB_DECL VideoData();

public:
 TIBERIUS_LIB_DECL void addVideo(std::unique_ptr<Video> video);
 TIBERIUS_LIB_DECL Video * findVideo(int id);
 TIBERIUS_LIB_DECL const Video * findVideo(int id) const;
 TIBERIUS_LIB_DECL Video * getVideo(int index);
 TIBERIUS_LIB_DECL const Video * getVideo(int index) const;
 TIBERIUS_LIB_DECL int totalVideos() const;

private:
 using VideoPtr = std::unique_ptr<Video>;
 using VideoVector = std::vector<VideoPtr>;
 using IndexMap = std::map<int, int>;

private:
 VideoVector mVideos;
 IndexMap mIndexMap;
};
#endif // VIDEODATA_H
