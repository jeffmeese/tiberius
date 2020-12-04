#ifndef DATAVECTOR_H
#define DATAVECTOR_H

#include "core/streamio.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

template <typename T>
class DataVector
{
public:
  T * get(int32_t index);
  const T * get(int32_t index) const;
  int32_t total() const;

protected:
  DataVector(int32_t maxObjects);

private:
  using Ptr = std::unique_ptr<T>;
  using Vector = std::vector<Ptr>;

private:
  int32_t mMaxObjects;
  Vector mData;
};

template <typename T>
inline DataVector<T>::DataVector(int32_t maxObjects)
{
  mMaxObjects = maxObjects;
  for (int32_t i = 0; i < maxObjects; i++) {
    Ptr p(new T());
    mData.push_back(std::move(p));
  }
}

template <typename T>
inline T * DataVector<T>::get(int32_t index)
{
  return mData.at(index).get();
}

template <typename T>
inline const T * DataVector<T>::get(int32_t index) const
{
  return mData.at(index).get();
}

template <typename T>
inline int32_t DataVector<T>::total() const
{
  return static_cast<int32_t>(mData.size());
}

#endif // DATAVECTOR_H
