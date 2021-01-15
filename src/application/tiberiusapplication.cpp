#include "tiberiusapplication.h"

#include "c3data.h"

#include "tinyfiledialogs/tinyfiledialogs.h"

#include <QDir>
#include <stdexcept>

static const QString C3_DIR_SETTING("c3Dir");
QString TiberiusApplication::mC3Dir;
std::unique_ptr<C3Data> TiberiusApplication::mC3Data;
QSettings TiberiusApplication::mSettings;

TiberiusApplication::TiberiusApplication(int & argc, char ** argv)
  : QApplication(argc, argv)
{
}

TiberiusApplication::~TiberiusApplication()
{
}

QString TiberiusApplication::c3Dir()
{
  QString dirName = mC3Dir;
  if (dirName.isEmpty())
    dirName = mSettings.value(C3_DIR_SETTING).toString();

  if (dirName.isEmpty()) {
    char title[] = {"Choose Caesar3 Directory"};
    const char * path = tinyfd_selectFolderDialog(title, QDir::currentPath().toStdString().c_str());
    if (path == nullptr) {
      throw std::invalid_argument("No Casear 3 directory specified");
    }

    dirName = path;
    mC3Data.reset(new C3Data(dirName));
    mSettings.setValue(C3_DIR_SETTING, dirName);
  }
  return dirName;
}

SgImageData * TiberiusApplication::climateImages()
{
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
  return mC3Data->climateImages();
}

SgImageData * TiberiusApplication::enemyImages()
{
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
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
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
  return mC3Data->imageData();
}

Language * TiberiusApplication::language()
{
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
  return mC3Data->language();
}

void TiberiusApplication::setC3Dir(const QString &dirName)
{
  mC3Dir = dirName;
  mC3Data.reset(new C3Data(dirName));
}

SoundData * TiberiusApplication::soundData()
{
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
  return mC3Data->soundData();
}

VideoData * TiberiusApplication::videoData()
{
  if (mC3Dir.isEmpty()) mC3Dir = c3Dir();
  return mC3Data->videoData();
}
