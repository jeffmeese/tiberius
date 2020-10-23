#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>
#include <QString>

#include "tiberius.h"

class Message
{
public:
  TIBERIUS_LIB_DECL Message();

public:
  TIBERIUS_LIB_DECL QString content() const;
  TIBERIUS_LIB_DECL int16_t dialogHeight() const;
  TIBERIUS_LIB_DECL int16_t dialogWidth() const;
  TIBERIUS_LIB_DECL int16_t dialogXPos() const;
  TIBERIUS_LIB_DECL int16_t dialogYPos() const;
  TIBERIUS_LIB_DECL int16_t imageId() const;
  TIBERIUS_LIB_DECL int16_t imageXPos() const;
  TIBERIUS_LIB_DECL int16_t imageYPos() const;
  TIBERIUS_LIB_DECL int16_t secondaryImageId() const;
  TIBERIUS_LIB_DECL int16_t secondaryImageXPos() const;
  TIBERIUS_LIB_DECL int16_t secondaryImageYPos() const;
  TIBERIUS_LIB_DECL QString subtitle() const;
  TIBERIUS_LIB_DECL int16_t subtitleXPos() const;
  TIBERIUS_LIB_DECL int16_t subtitleYPos() const;
  TIBERIUS_LIB_DECL int16_t subtype() const;
  TIBERIUS_LIB_DECL QString title() const;
  TIBERIUS_LIB_DECL int16_t titleXPos() const;
  TIBERIUS_LIB_DECL int16_t titleYPos() const;
  TIBERIUS_LIB_DECL int16_t type() const;
  TIBERIUS_LIB_DECL int32_t urgent() const;
  TIBERIUS_LIB_DECL QString videoFile() const;
  TIBERIUS_LIB_DECL int16_t videoXPos() const;
  TIBERIUS_LIB_DECL int16_t videoYPos() const;
  TIBERIUS_LIB_DECL void setContent(const QString & value);
  TIBERIUS_LIB_DECL void setDialogHeight(int16_t value);
  TIBERIUS_LIB_DECL void setDialogWidth(int16_t value);
  TIBERIUS_LIB_DECL void setDialogXPos(int16_t value);
  TIBERIUS_LIB_DECL void setDialogYPos(int16_t value);
  TIBERIUS_LIB_DECL void setImageId(int16_t value);
  TIBERIUS_LIB_DECL void setImageXPos(int16_t value);
  TIBERIUS_LIB_DECL void setImageYPos(int16_t value);
  TIBERIUS_LIB_DECL void setSecondaryImageId(int16_t value);
  TIBERIUS_LIB_DECL void setSecondaryImageXPos(int16_t value);
  TIBERIUS_LIB_DECL void setSecondaryImageYPos(int16_t value);
  TIBERIUS_LIB_DECL void setSubtitle(const QString & value);
  TIBERIUS_LIB_DECL void setSubtitleXPos(int16_t value);
  TIBERIUS_LIB_DECL void setSubtitleYPos(int16_t value);
  TIBERIUS_LIB_DECL void setSubtype(int16_t value);
  TIBERIUS_LIB_DECL void setTitle(const QString & value);
  TIBERIUS_LIB_DECL void setTitleXPos(int16_t value);
  TIBERIUS_LIB_DECL void setTitleYPos(int16_t value);
  TIBERIUS_LIB_DECL void setType(int16_t value);
  TIBERIUS_LIB_DECL void setUrgent(int32_t value);
  TIBERIUS_LIB_DECL void setVideoFile(const QString & value);
  TIBERIUS_LIB_DECL void setVideoXPos(int16_t value);
  TIBERIUS_LIB_DECL void setVideoYPos(int16_t value);

private:
  int16_t mType;
  int16_t mSubType;
  int16_t mDialogXPos;
  int16_t mDialogYPos;
  int16_t mDialogWidth;
  int16_t mDialogHeight;
  int16_t mImageId;
  int16_t mImageXPos;
  int16_t mImageYPos;
  int16_t mSecondaryImageId;
  int16_t mSecondaryImageXPos;
  int16_t mSecondaryImageYPos;
  int16_t mTitleXPos;
  int16_t mTitleYPos;
  int16_t mSubtitleXPos;
  int16_t mSubtitleYPos;
  int16_t mVideoXPos;
  int16_t mVideoYPos;
  int32_t mUrgent;
  QString mContent;
  QString mSubtitle;
  QString mTitle;
  QString mVideoFile;
};

inline QString Message::content() const
{
  return mContent;
}

inline int16_t Message::dialogHeight() const
{
  return mDialogHeight;
}

inline int16_t Message::dialogWidth() const
{
  return mDialogWidth;
}

inline int16_t Message::dialogXPos() const
{
  return mDialogXPos;
}

inline int16_t Message::dialogYPos() const
{
  return mDialogYPos;
}

inline int16_t Message::imageId() const
{
  return mImageId;
}

inline int16_t Message::imageXPos() const
{
  return mImageXPos;
}

inline int16_t Message::imageYPos() const
{
  return mImageYPos;
}

inline int16_t Message::secondaryImageId() const
{
  return mSecondaryImageId;
}

inline int16_t Message::secondaryImageXPos() const
{
  return mSecondaryImageXPos;
}

inline int16_t Message::secondaryImageYPos() const
{
  return mSecondaryImageYPos;
}

inline QString Message::subtitle() const
{
  return mSubtitle;
}

inline int16_t Message::subtitleXPos() const
{
  return mSubtitleXPos;
}

inline int16_t Message::subtitleYPos() const
{
  return mSubtitleYPos;
}

inline int16_t Message::subtype() const
{
  return mSubType;
}

inline QString Message::title() const
{
  return mTitle;
}

inline int16_t Message::titleXPos() const
{
  return mTitleXPos;
}

inline int16_t Message::titleYPos() const
{
  return mTitleYPos;
}

inline int16_t Message::type() const
{
  return mType;
}

inline int32_t Message::urgent() const
{
  return mUrgent;
}

inline QString Message::videoFile() const
{
  return mVideoFile;
}

inline int16_t Message::videoXPos() const
{
  return mVideoXPos;
}

inline int16_t Message::videoYPos() const
{
  return mVideoYPos;
}

inline void Message::setContent(const QString &value)
{
  mContent = value;
}

inline void Message::setDialogHeight(int16_t value)
{
  mDialogHeight = value;
}

inline void Message::setDialogWidth(int16_t value)
{
  mDialogWidth = value;
}

inline void Message::setDialogXPos(int16_t value)
{
  mDialogXPos = value;
}

inline void Message::setDialogYPos(int16_t value)
{
  mDialogYPos = value;
}

inline void Message::setImageId(int16_t value)
{
  mImageId = value;
}

inline void Message::setImageXPos(int16_t value)
{
  mImageXPos = value;
}

inline void Message::setImageYPos(int16_t value)
{
  mImageYPos = value;
}

inline void Message::setSecondaryImageId(int16_t value)
{
  mSecondaryImageId = value;
}

inline void Message::setSecondaryImageXPos(int16_t value)
{
  mSecondaryImageXPos = value;
}

inline void Message::setSecondaryImageYPos(int16_t value)
{
  mSecondaryImageYPos = value;
}

inline void Message::setSubtitle(const QString &value)
{
  mSubtitle = value;
}

inline void Message::setSubtitleXPos(int16_t value)
{
  mSubtitleXPos = value;
}

inline void Message::setSubtitleYPos(int16_t value)
{
  mSubtitleYPos = value;
}

inline void Message::setSubtype(int16_t value)
{
  mSubType = value;
}

inline void Message::setTitle(const QString &value)
{
  mTitle = value;
}

inline void Message::setTitleXPos(int16_t value)
{
  mTitleXPos = value;
}

inline void Message::setTitleYPos(int16_t value)
{
  mTitleYPos = value;
}

inline void Message::setType(int16_t value)
{
  mType = value;
}

inline void Message::setUrgent(int32_t value)
{
  mUrgent = value;
}

inline void Message::setVideoXPos(int16_t value)
{
  mVideoXPos = value;
}

inline void Message::setVideoFile(const QString &value)
{
  mVideoFile = value;
}

inline void Message::setVideoYPos(int16_t value)
{
  mVideoYPos = value;
}

#endif // MESSAGE_H
