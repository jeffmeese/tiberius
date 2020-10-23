#include "video.h"

#include <QDebug>

Video::Video(int id, const QString & fileName)
  : mId(id)
  , mFileName(fileName)
  , mLoaded(false)
{
}

int Video::id() const
{
  return mId;
}

QString Video::fileName() const
{
  return mFileName;
}

void Video::play()
{
  smk s = smk_open_file(mFileName.toStdString().c_str(), SMK_MODE_DISK);
  qDebug() << s << "\n";
  if (s != nullptr) {
    smk_first(s);
    const unsigned char * image_data = smk_get_video(s);
    const unsigned char * pallete = smk_get_palette(s);
    const unsigned char * audioData = smk_get_audio(s, 0);

    while(true) {
      char r = smk_next(s);
      if (r == SMK_DONE) {
        break;
      }
    }

    smk_close(s);
  }
}

void Video::stop()
{
  if (!mLoaded)
    return;

  //mSoundEffect.stop();
}
