#include "videodata.h"
#include "video.h"

VideoData::VideoData()
{
}

void VideoData::addVideo(std::unique_ptr<Video> video)
{
  mIndexMap[video->id()] = static_cast<int>(mVideos.size());
  mVideos.push_back(std::move(video));
}

Video * VideoData::findVideo(int id)
{
  IndexMap::iterator itr = mIndexMap.find(id);
  if (itr == mIndexMap.end()) {
    return nullptr;
  }

  return mVideos[itr->second].get();
}

const Video * VideoData::findVideo(int id) const
{
  IndexMap::const_iterator itr = mIndexMap.find(id);
  if (itr == mIndexMap.end()) {
    return nullptr;
  }

  return mVideos.at(itr->second).get();
}

Video * VideoData::getVideo(int index)
{
  return mVideos[index].get();
}

const Video * VideoData::getVideo(int index) const
{
  return mVideos[index].get();
}

int VideoData::totalVideos() const
{
  return static_cast<int>(mVideos.size());
}
