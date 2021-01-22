#ifndef VIDEO_H
#define VIDEO_H

#include "tiberius.h"

#include "libsmacker/smacker.h"

#include <QString>
#include <QVideoWidget>

class Video
{
public:
  TIBERIUS_LIB_DECL Video(int id, const QString & fileName);
  TIBERIUS_LIB_DECL ~Video();

public:
  TIBERIUS_LIB_DECL int id() const;
  TIBERIUS_LIB_DECL QString fileName() const;

public:
  TIBERIUS_LIB_DECL int frame() const;
  TIBERIUS_LIB_DECL int frameCount() const;
  TIBERIUS_LIB_DECL int framesPerSecond() const;
  TIBERIUS_LIB_DECL int height() const;
  TIBERIUS_LIB_DECL void play(QVideoWidget * widget);
  TIBERIUS_LIB_DECL QString scaleMode() const;
  TIBERIUS_LIB_DECL void stop();
  TIBERIUS_LIB_DECL int width() const;
  TIBERIUS_LIB_DECL double usf() const;

private:
  bool mLoaded;
  int mId;
  unsigned long mFrame;
  unsigned long mFrameCount;
  unsigned long mHeight;
  unsigned long mWidth;
  unsigned char mScaleMode;
  double mUsf;
  QString mFileName;
  smk mSmkVideo;
};

#endif // VIDEO_H
