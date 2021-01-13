#include "tiberiusapplication.h"

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

static const QString C3_DIR_SETTING("c3Dir");
QSettings TiberiusApplication::mSettings("JaMSoft", "Tiberius");
std::unique_ptr<ImageData> TiberiusApplication::mImageData;
std::unique_ptr<Language> TiberiusApplication::mLanguage;
std::unique_ptr<SoundData> TiberiusApplication::mSoundData;
std::unique_ptr<VideoData> TiberiusApplication::mVideoData;
SgImageData * TiberiusApplication::mClimateImages = nullptr;
SgImageData * TiberiusApplication::mEnemyImages = nullptr;

TiberiusApplication::TiberiusApplication(int & argc, char ** argv)
  : QApplication(argc, argv)
{
  QString dirName = c3Dir();
  loadImageData(dirName);
  loadLanguage(dirName);
  loadSoundData(dirName);
  loadVideoData(dirName);
}

TiberiusApplication::~TiberiusApplication()
{

}

QString TiberiusApplication::c3Dir()
{
  QString dirName = mSettings.value(C3_DIR_SETTING).toString();
  if (dirName.isEmpty()) {
    char title[] = {"Choose Caesar3 Directory"};
    const char * path = tinyfd_selectFolderDialog(title, QDir::currentPath().toStdString().c_str());
    if (path == nullptr) {
      throw std::invalid_argument("No Casear 3 directory specified");
    }

    dirName = path;
    mSettings.setValue(C3_DIR_SETTING, dirName);
  }
  return dirName;
}

SgImageData * TiberiusApplication::climateImages()
{
  return mClimateImages;
}

SgImageData * TiberiusApplication::enemyImages()
{
  return mEnemyImages;
}

// Returns the pixel file name associated with the SG file name without regarding case
QString TiberiusApplication::getPixelFileName(const QString &sgFileName, const QString & dirName)
{
  QStringList nameFilters;
  nameFilters << "*.555";

  QFileInfo fileInfo(sgFileName);
  QString fileTitle = fileInfo.baseName().toLower();
  QString fileName = fileInfo.fileName().toLower();
  QDir dir(dirName);
  QFileInfoList fileList = dir.entryInfoList(nameFilters, QDir::Files);
  for (int i = 0; i < fileList.size(); i++) {
    QFileInfo info(fileList.at(i));
    QString title = info.baseName().toLower();
    if (title == fileTitle) {
      return info.absoluteFilePath();
    }
  }

  return QString("");
}

ImageData * TiberiusApplication::imageData()
{
  return mImageData.get();
}

Language * TiberiusApplication::language()
{
  return mLanguage.get();
}

void TiberiusApplication::loadImageData(const QString &dirName)
{
  mImageData.reset(new ImageData);
  mImageData->loadFromDir(dirName);

  mClimateImages = mImageData->getImageSet("c3")->imageData();
  mEnemyImages = mImageData->getImageSet("goths")->imageData();
}

void TiberiusApplication::loadLanguage(const QString &dirName)
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

  mLanguage.reset(new Language);
  mLanguage->load(stringFilePath, messageFilePath);
}

void TiberiusApplication::loadSoundData(const QString & dirName)
{
  mSoundData.reset(new SoundData);

  for (int i = 0; i < MAX_SOUNDS; i++) {
    int id = sounds[i].first;
    QString fileName = sounds[i].second;
    QString pathName = dirName + QDir::separator() + fileName;
    std::unique_ptr<Sound> sound(new Sound(id, pathName));
    mSoundData->addSound(std::move(sound));
  }
}

void TiberiusApplication::loadVideoData(const QString &dirName)
{
  mVideoData.reset(new VideoData);

  for (int i = 0; i < MAX_VIDEOS; i++) {
    int id = videos[i].first;
    QString fileName = videos[i].second;
    QString pathName = dirName + QDir::separator() + fileName;
    std::unique_ptr<Video> video(new Video(id, pathName));
    mVideoData->addVideo(std::move(video));
  }
}

SoundData * TiberiusApplication::soundData()
{
  return mSoundData.get();
}

VideoData * TiberiusApplication::videoData()
{
  return mVideoData.get();
}
