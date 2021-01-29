#include "tiberiusapplication.h"

#include "c3data.h"

#include "tinyfiledialogs/tinyfiledialogs.h"

#include <QDir>
#include <stdexcept>

QString TiberiusApplication::mC3Dir;
std::unique_ptr<C3Data> TiberiusApplication::mC3Data;

TiberiusApplication::TiberiusApplication(int & argc, char ** argv)
  : QApplication(argc, argv)
{
  mC3Data.reset(new C3Data);
}

TiberiusApplication::TiberiusApplication(const QString & c3DirName, int & argc, char ** argv)
  : QApplication(argc, argv)
{
  setC3Dir(c3DirName);
}

TiberiusApplication::~TiberiusApplication()
{
}

QString TiberiusApplication::c3Dir()
{
  return mC3Dir;
}

SgImageData * TiberiusApplication::climateImages()
{
  return mC3Data->climateImages();
}

SgImageData * TiberiusApplication::enemyImages()
{
  return mC3Data->enemyImages();
}

// Returns the pixel file name associated with the SG file name without regarding case
QString TiberiusApplication::getPixelFileName(const QString &sgFileName, const QString & dirName)
{
  QFileInfo fileInfo(sgFileName);
  QString pixelName = fileInfo.baseName() + ".555";
  QDir dir(dirName);
  QFileInfoList infoList = dir.entryInfoList(QStringList(pixelName), QDir::Files);
  if (infoList.size() == 0)
    return QString("");

  return infoList.at(0).absoluteFilePath();
}

ImageData * TiberiusApplication::imageData()
{
  return mC3Data->imageData();
}

Language * TiberiusApplication::language()
{
  return mC3Data->language();
}

void TiberiusApplication::setC3Dir(const QString &dirName)
{
  mC3Dir = dirName;
  mC3Data.reset(new C3Data(dirName));
}

SoundData * TiberiusApplication::soundData()
{
  return mC3Data->soundData();
}

VideoData * TiberiusApplication::videoData()
{
  return mC3Data->videoData();
}
