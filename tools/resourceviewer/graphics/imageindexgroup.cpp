#include "imageindexgroup.h"

ImageIndexGroup::ImageIndexGroup(int32_t id)
  : mId(id)
{

}

int32_t ImageIndexGroup::id() const
{
  return mId;
}

void ImageIndexGroup::addImage(uint32_t imageOffset)
{
  mImageOffsets.push_back(imageOffset);
}

int32_t ImageIndexGroup::getImageOffset(std::size_t index) const
{
  return mImageOffsets.at(index);
}

std::size_t ImageIndexGroup::totalImages() const
{
  return mImageOffsets.size();
}

bool ImageIndexGroup::operator<(const ImageIndexGroup & other)
{
  return mId < other.mId;
}
