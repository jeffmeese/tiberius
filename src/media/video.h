#ifndef VIDEO_H
#define VIDEO_H

#include "tiberius.h"

#include "libsmacker/smacker.h"

#include <QString>

class Video
{
public:
  TIBERIUS_LIB_DECL Video(int id, const QString & fileName);

public:
  TIBERIUS_LIB_DECL int id() const;
  TIBERIUS_LIB_DECL QString fileName() const;

public:
  TIBERIUS_LIB_DECL void play();
  TIBERIUS_LIB_DECL void stop();

private:
  int mId;
  QString mFileName;
  bool mLoaded;
  smk mSmkVideo;
};

#endif // VIDEO_H
