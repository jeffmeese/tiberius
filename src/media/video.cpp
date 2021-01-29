#include "video.h"

#include "3rdparty/libsmacker/smacker.h"

#include <QAbstractVideoSurface>
#include <QDebug>
#include <QVideoFrame>
#include <QThread>
#include <QVideoSurfaceFormat>

class VideoSurface
    : public QAbstractVideoSurface
{
public:
  QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const override;
//  //bool isFormatSupported(const QVideoSurfaceFormat &format, QVideoSurfaceFormat *similar) const;
  bool present(const QVideoFrame & frame) override;

//  bool start(const QVideoSurfaceFormat &format);
//  void stop();
};

QList<QVideoFrame::PixelFormat> VideoSurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType) const
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()
                << QVideoFrame::Format_RGB32
                << QVideoFrame::Format_ARGB32
                << QVideoFrame::Format_ARGB32_Premultiplied
                << QVideoFrame::Format_RGB565
                << QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }
}

bool VideoSurface::present(const QVideoFrame & frame)
{
  return true;
}

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
    //QVideoFrame videoFrame(mWidth*mHeight, sz, mWidth, QVideoFrame::Format_RGB32);
    //unsigned int index = 0;
    const unsigned char * frame = smk_get_video(mSmkVideo);
    QImage image(frame, mWidth, mHeight, mWidth, QImage::Format_RGB32);
    QVideoFrame videoFrame(image);
    //for (unsigned int i = 0; i < mHeight; i++) {
    //  for (unsigned int j = 0; j < mWidth; j++) {
        //unsigned char  = frame[index];
        //qDebug() << (int)byte;
    //    index++;
    //  }
   // }
    widget->videoSurface()->present(videoFrame);
    widget->repaint();
    QThread::currentThread()->msleep(10);
    r = smk_next(mSmkVideo);
    qDebug() << (int)r;
  }

  widget->videoSurface()->stop();
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
