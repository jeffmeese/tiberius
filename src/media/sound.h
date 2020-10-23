#ifndef SOUND_H
#define SOUND_H

#include "tiberius.h"

#include <QSoundEffect>
#include <QString>

class Sound
{
public:
  TIBERIUS_LIB_DECL Sound(int id, const QString & fileName);

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
  QSoundEffect mSoundEffect;
};

#endif // SOUND_H
