#include "militarydata.h"

#include "military/legion.h"
#include "military/soldier.h"

static const int32_t DATA_SIZE = 6400;

MilitaryData::MilitaryData()
  : DataVector<Legion>(MAX_LEGIONS)
{
  mLastLegion = 0;
  mLastUsed = 0;
  mNumActive = 0;
}

MilitaryData::~MilitaryData()
{
}

int32_t MilitaryData::lastLegion() const
{
  return mLastUsed;
}

int32_t MilitaryData::lastUsed() const
{
  return mLastLegion;
}

void MilitaryData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int32_t i = 0; i < MAX_LEGIONS; i++) {
    get(i)->loadFromDataStream(dataStream);
  }

  mLastUsed = streamio::readInt32(dataStream);
  mLastLegion = streamio::readInt32(dataStream);
  mNumActive = streamio::readInt32(dataStream);
}

int32_t MilitaryData::numActive() const
{
  return mNumActive;
}

void MilitaryData::saveToDataStream(QDataStream & dataStream) const
{
  QDataStream byteStream;
  byteStream.setByteOrder(QDataStream::LittleEndian);

  for (int i = 0; i < MAX_LEGIONS; i++) {
    get(i)->saveToDataStream(byteStream);
  }

  QByteArray byteArray;
  streamio::writeCompressedData(byteStream, byteArray, DATA_SIZE);
  dataStream.device()->write(byteArray);

  dataStream << mLastUsed << mLastLegion << mNumActive;
}

void MilitaryData::setLastLegion(int32_t value)
{
  mLastLegion = value;
}

void MilitaryData::setLastUsed(int32_t value)
{
  mLastUsed = value;
}

void MilitaryData::setNumActive(int32_t value)
{
  mNumActive = value;
}
