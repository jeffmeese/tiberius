#include "c3data.h"

#include "graphics/imagedata.h"
#include "graphics/imageset.h"

#include "language/language.h"

#include "media/sound.h"
#include "media/sounddata.h"
#include "media/sounds.h"
#include "media/video.h"
#include "media/videodata.h"
#include "media/videos.h"

#include "tinyfiledialogs/tinyfiledialogs.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <stdexcept>

C3Data::C3Data()
{
  mImageData.reset(new ImageData);
  mLanguage.reset(new Language);
  mSoundData.reset(new SoundData);
  mVideoData.reset(new VideoData);
  mClimateImages = nullptr;
  mEnemyImages = nullptr;
}

C3Data::C3Data(const QString & dirName)
{
  load(dirName);

}

C3Data::~C3Data()
{
}

SgImageData * C3Data::climateImages()
{
  return mClimateImages;
}

SgImageData * C3Data::enemyImages()
{
  return mEnemyImages;
}

// Returns the pixel file name associated with the SG file name without regarding case
QString C3Data::getPixelFileName(const QString &sgFileName, const QString & dirName)
{
  QFileInfo fileInfo(sgFileName);
  QString pixelName = fileInfo.baseName() + ".555";
  QDir dir(dirName);
  QFileInfoList infoList = dir.entryInfoList(QStringList(pixelName), QDir::Files);
  if (infoList.size() == 0)
    return QString("");

  return infoList.at(0).absoluteFilePath();
}

ImageData * C3Data::imageData()
{
  return mImageData.get();
}

Language * C3Data::language()
{
  return mLanguage.get();
}

void C3Data::load(const QString &dirName)
{
  mImageData.reset(new ImageData);
  mLanguage.reset(new Language);
  mSoundData.reset(new SoundData);
  mVideoData.reset(new VideoData);

  loadImageData(dirName);
  loadLanguage(dirName);
  loadSoundData(dirName);
  loadVideoData(dirName);
}

void C3Data::loadImageData(const QString &dirName)
{
  mImageData->loadFromDir(dirName);

  mClimateImages = mImageData->getImageSet("c3")->imageData();
  mEnemyImages = mImageData->getImageSet("goths")->imageData();
}

void C3Data::loadLanguage(const QString &dirName)
{
  QDir dir(dirName);

  QFileInfoList stringInfoList = dir.entryInfoList(QStringList() << "c3.eng", QDir::Files);
  if (stringInfoList.size() == 0) {
    throw std::invalid_argument("Could not locate language file");
  }

  QFileInfoList messageInfoList = dir.entryInfoList(QStringList() << "c3_mm.eng", QDir::Files);
  if (messageInfoList.size() == 0) {
    throw std::invalid_argument("Could locate message file");
  }

  QFileInfo stringFileInfo(stringInfoList.at(0));
  QString stringFilePath = stringFileInfo.absoluteFilePath();
  QFileInfo messageFileInfo(messageInfoList.at(0));
  QString messageFilePath = messageFileInfo.absoluteFilePath();

  mLanguage->load(stringFilePath, messageFilePath);
}

void C3Data::loadSoundData(const QString & dirName)
{
  for (int i = 0; i < MAX_SOUNDS; i++) {
    int id = sounds[i].first;
    QString fileName = sounds[i].second;
    QString pathName = dirName + QDir::separator() + fileName;
    std::unique_ptr<Sound> sound(new Sound(id, pathName));
    mSoundData->addSound(std::move(sound));
  }
}

void C3Data::loadVideoData(const QString &dirName)
{
  for (int i = 0; i < MAX_VIDEOS; i++) {
    int id = videos[i].first;
    QString fileName = videos[i].second;
    QString pathName = dirName + QDir::separator() + fileName;
    std::unique_ptr<Video> video(new Video(id, pathName));
    mVideoData->addVideo(std::move(video));
  }
}

SoundData * C3Data::soundData()
{
  return mSoundData.get();
}

VideoData * C3Data::videoData()
{
  return mVideoData.get();
}
