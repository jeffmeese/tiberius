#ifndef TIBERIUSAPPLICATION_H
#define TIBERIUSAPPLICATION_H

#include <QApplication>
#include <QSettings>
#include <QString>

#include <memory>

#include "tiberius.h"

class C3Data;
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
  TIBERIUS_LIB_DECL TiberiusApplication(const QString & c3Dir, int & argc, char ** argv);
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
  TIBERIUS_LIB_DECL void setC3Dir(const QString & dirName);

private:
  static std::unique_ptr<C3Data> mC3Data;
  static QString mC3Dir;
};

#endif // TIBERIUSAPPLICATION_H
