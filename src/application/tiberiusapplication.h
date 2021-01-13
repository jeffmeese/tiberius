#ifndef TIBERIUSAPPLICATION_H
#define TIBERIUSAPPLICATION_H

#include <QApplication>
#include <QSettings>
#include <QString>

#include <memory>

#include "tiberius.h"

class ImageData;
class Language;
class SgImageData;
class SoundData;
class VideoData;

class TiberiusApplication
    : public QApplication
{
public:
  TIBERIUS_LIB_DECL TiberiusApplication(int & argc, char ** argv);
  TIBERIUS_LIB_DECL ~TiberiusApplication();

public:
  TIBERIUS_LIB_DECL static QString c3Dir();
  TIBERIUS_LIB_DECL static SgImageData * climateImages();
  TIBERIUS_LIB_DECL static QString getPixelFileName(const QString & sgFileName, const QString & dirName);
  TIBERIUS_LIB_DECL static SgImageData * enemyImages();
  TIBERIUS_LIB_DECL static bool isPatched();
  TIBERIUS_LIB_DECL static ImageData * imageData();
  TIBERIUS_LIB_DECL static Language * language();
  TIBERIUS_LIB_DECL static SoundData * soundData();
  TIBERIUS_LIB_DECL static VideoData * videoData();

private:
  void loadImageData(const QString & dirName);
  void loadLanguage(const QString & dirName);
  void loadSoundData(const QString & dirName);
  void loadVideoData(const QString & dirName);

private:
  static QSettings mSettings;
  static std::unique_ptr<ImageData> mImageData;
  static std::unique_ptr<Language> mLanguage;
  static std::unique_ptr<SoundData> mSoundData;
  static std::unique_ptr<VideoData> mVideoData;
  static SgImageData * mClimateImages;
  static SgImageData * mEnemyImages;
};

#endif // TIBERIUSAPPLICATION_H
