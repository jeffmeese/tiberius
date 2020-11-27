#include "sgimagegroup.h"

SgImageGroup::SgImageGroup()
{
  mFirstImageIndex = mLastImageIndex = 0;
  mHeight = mWidth = 0;
  mTotalImages = 0;
}

bool SgImageGroup::loadFromDataStream(QDataStream & dataStream)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  char fileName[65];
  char description[51];
  dataStream.readRawData(fileName, 65);
  dataStream.readRawData(description, 51);
  dataStream >> mWidth;
  dataStream >> mHeight;
  dataStream >> mTotalImages;
  dataStream >> mFirstImageIndex;
  dataStream >> mLastImageIndex;
  dataStream.skipRawData(64);

  mFileName = fileName;
  mDescription = description;

  return true;
}

bool SgImageGroup::saveToDataStream(QDataStream & dataStream) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  dataStream.writeRawData(mFileName.toStdString().c_str(), 65);
  dataStream.writeRawData(mDescription.toStdString().c_str(), 51);
  dataStream << mWidth;
  dataStream << mHeight;
  dataStream << mTotalImages;
  dataStream << mFirstImageIndex;
  dataStream << mLastImageIndex;

  return true;
}
