#include "video.h"

#include "3rdparty/libsmacker/smacker.h"

#include <QAbstractVideoSurface>
#include <QDebug>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>

Video::Video(int id, const QString & fileName)
  : mLoaded(false)
  , mId(id)
  , mFrame(0)
  , mFrameCount(0)
  , mHeight(0)
  , mWidth(0)
  , mScaleMode(SMK_FLAG_Y_NONE)
  , mFileName(fileName)
{
  mSmkVideo = smk_open_file(fileName.toStdString().c_str(), SMK_MODE_DISK);
  smk_info_video(mSmkVideo, &mWidth, &mHeight, &mScaleMode);
  smk_info_all(mSmkVideo, &mFrame, &mFrameCount, &mUsf);
}

Video::~Video()
{
  smk_close(mSmkVideo);
}

int Video::id() const
{
  return mId;
}

QString Video::fileName() const
{
  return mFileName;
}

int Video::frame() const
{
  return mFrame;
}

int Video::frameCount() const
{
  return mFrameCount;
}

int Video::framesPerSecond() const
{
  if (mUsf <= 0.0)
    return 0;

  return static_cast<int>(1.0 / (mUsf/1e6));
}

int Video::height() const
{
  return mHeight;
}

void Video::play(QVideoWidget * widget)
{
  QSize sz(mWidth, mHeight);
  QVideoSurfaceFormat format(sz, QVideoFrame::Format_RGB32);

  widget->videoSurface()->start(format);

  char r = smk_first(mSmkVideo);
  while (r == SMK_MORE) {
    QVideoFrame videoFrame(mWidth*mHeight, sz, mWidth, QVideoFrame::Format_RGB32);
    unsigned int index = 0;
    const unsigned char * frame = smk_get_video(mSmkVideo);
    for (unsigned int i = 0; i < mHeight; i++) {
      for (unsigned int j = 0; j < mWidth; j++) {
        unsigned char byte = frame[index];
        //qDebug() << (int)byte;
        index++;
      }
    }
    widget->videoSurface()->present(videoFrame);
    r = smk_next(mSmkVideo);
    qDebug() << (int)r;
  }
}

QString Video::scaleMode() const
{
  switch (mScaleMode) {
  case SMK_FLAG_Y_NONE:
    return "None";
  case SMK_FLAG_Y_INTERLACE:
    return "Interlaced";
  case SMK_FLAG_Y_DOUBLE:
    return "Doubled";
  }
  return "Unknown";
}

void Video::stop()
{
  if (!mLoaded)
    return;

  //mSoundEffect.stop();
}

int Video::width() const
{
  return mWidth;
}

double Video::usf() const
{
  return mUsf;
}
