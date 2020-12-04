#include "camera.h"

#include "core/streamio.h"

Camera::Camera()
{
  mX = mY = 0;
}

void Camera::loadFromDataStream(QDataStream & dataStream)
{
  mX = streamio::readInt32(dataStream);
  mY = streamio::readInt32(dataStream);
}

void Camera::saveToDataStream(QDataStream & dataStream) const
{
  streamio::writeInt32(dataStream, mX);
  streamio::writeInt32(dataStream, mY);
}

void Camera::setPosition(int32_t x, int32_t y)
{
  mX = x;
  mY = y;
}

void Camera::setX(int32_t x)
{
  mX = x;
}

void Camera::setY(int32_t y)
{
   mY = y;
}

int32_t Camera::x() const
{
  return mX;
}

int32_t Camera::y() const
{
  return mY;
}
