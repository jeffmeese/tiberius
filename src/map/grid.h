#ifndef GRID_H
#define GRID_H

#include <QByteArray>
#include <QDataStream>
#include <QIODevice>

#include "core/streamio.h"

enum {
  GridSize = 162,
  MapSize = 162*162
};

template <typename T>
class Grid
{
public:
  Grid()
  {
    clear();
  }

public:
  void clear()
  {
    for (int i = 0; i < MapSize; i++) {
      mData[i] = T();
    }
  }

  T getData(int index) const
  {
    return mData[index];
  }

  void loadFromDataStream(QDataStream & dataStream, int32_t dataSize, bool compressed)
  {
    QByteArray byteArray = (compressed) ? streamio::readCompressedData(dataStream, dataSize) : streamio::readUncompressedData(dataStream, dataSize);
    QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
    byteStream.setByteOrder(QDataStream::LittleEndian);

    clear();
    for (int i = 0; i < MapSize; i++) {
      T data;
      byteStream >> data;
      mData[i] = data;
    }
  }

  void saveToDataStream(QDataStream & dataStream, int32_t dataSize, bool compressed)
  {
    if (!compressed) {
      for (int i = 0; i < MapSize; i++) {
        dataStream << mData[i];
      }
    }
    else {
      QByteArray byteArray;
      for (int32_t i = 0; i < MapSize; i++)
        byteArray.append(mData[i]);

      streamio::writeCompressedData(dataStream, byteArray);
    }
  }

private:
  T mData[MapSize];
};

using UnsignedShortGrid = Grid<uint16_t>;
using UnsignedByteGrid = Grid<uint8_t>;
using ByteGrid = Grid<int8_t>;

#endif // GRID_H
