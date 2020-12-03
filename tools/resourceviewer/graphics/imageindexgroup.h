#ifndef IMAGEINDEXGROUP_H
#define IMAGEINDEXGROUP_H

#include <cstdint>
#include <vector>

class ImageIndexGroup
{
public:
  ImageIndexGroup(int32_t id);

public:
  int32_t id() const;

public:
  void addImage(uint32_t imageOffset);
  int32_t getImageOffset(std::size_t index) const;
  std::size_t totalImages() const;
  bool operator<(const ImageIndexGroup & other);

private:
  int32_t mId;
  std::vector<uint32_t> mImageOffsets;
};

#endif // IMAGEINDEXGROUP_H
