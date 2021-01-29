#ifndef C3DATA_H
#define C3DATA_H

#include "tiberius.h"

#include <memory>

class ImageData;
class Language;
class SgImageData;
class SoundData;
class VideoData;

class C3Data
{
public:
  C3Data();
  C3Data(const QString & dirName);
  ~C3Data();

public:
  TIBERIUS_LIB_DECL SgImageData * climateImages();
  TIBERIUS_LIB_DECL QString getPixelFileName(const QString & sgFileName, const QString & dirName);
  TIBERIUS_LIB_DECL SgImageData * enemyImages();
  TIBERIUS_LIB_DECL bool isPatched();
  TIBERIUS_LIB_DECL ImageData * imageData();
  TIBERIUS_LIB_DECL Language * language();
  TIBERIUS_LIB_DECL SoundData * soundData();
  TIBERIUS_LIB_DECL VideoData * videoData();

public:
  TIBERIUS_LIB_DECL void load(const QString & dirName);

private:
  void loadImageData(const QString & dirName);
  void loadLanguage(const QString & dirName);
  void loadSoundData(const QString & dirName);
  void loadVideoData(const QString & dirName);

private:
  std::unique_ptr<ImageData> mImageData;
  std::unique_ptr<Language> mLanguage;
  std::unique_ptr<SoundData> mSoundData;
  std::unique_ptr<VideoData> mVideoData;
  SgImageData * mClimateImages;
  SgImageData * mEnemyImages;
};

#endif // C3DATA_H
