#include "sound.h"

#include <QUrl>

Sound::Sound(int id, const QString & fileName)
  : mId(id)
  , mFileName(fileName)
  , mLoaded(false)
{
  mSoundEffect = new QSoundEffect;
}

Sound::~Sound()
{
  // For some unknown reason this is causing a crash
  //delete mSoundEffect;
}

int Sound::id() const
{
  return mId;
}

QString Sound::fileName() const
{
  return mFileName;
}

void Sound::play()
{
  if (!mLoaded) {
    mSoundEffect->setSource(QUrl::fromLocalFile(mFileName));
    mLoaded = true;
  }

  mSoundEffect->play();
}

void Sound::stop()
{
  if (!mLoaded)
    return;

  mSoundEffect->stop();
}
