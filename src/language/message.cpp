#include "message.h"

Message::Message()
{
  mType = mSubType = 0;
  mDialogXPos = mDialogYPos = mDialogWidth = mDialogHeight = 0;
  mImageId = mImageXPos = mImageYPos = 0;
  mSecondaryImageId = mSecondaryImageXPos = mSecondaryImageYPos = 0;
  mTitleXPos = mTitleYPos = 0;
  mSubtitleXPos = mSubtitleYPos = 0;
  mVideoXPos = mVideoYPos = 0;
  mUrgent = 0;
}
