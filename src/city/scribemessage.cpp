#include "scribemessage.h"

#include "core/streamio.h"

ScribeMessage::ScribeMessage()
{
  mData1 = 0;
  mData2 = 0;
  mType = Type::None;
  mMonth = 0;
  mYear = 0;
  mEntryNumber = 0;
}

uint8_t ScribeMessage::data1() const
{
  return mData1;
}

uint8_t ScribeMessage::data2() const
{
  return mData2;
}

void ScribeMessage::loadFromStream(QDataStream &dataStream)
{
  dataStream.skipRawData(4);
  mYear = streamio::readInt16(dataStream);
  mData1 = streamio::readInt8(dataStream);
  mData2 = streamio::readInt8(dataStream);
  mType = static_cast<Type>(streamio::readInt16(dataStream));
  mEntryNumber = streamio::readInt16(dataStream);
  mRead = streamio::readUInt8(dataStream);
  mMonth = streamio::readUInt8(dataStream);
  dataStream.skipRawData(2);
}

uint8_t ScribeMessage::month() const
{
  return mMonth;
}

int16_t ScribeMessage::entryNumber() const
{
  return mEntryNumber;
}


uint8_t ScribeMessage::read() const
{
  return mRead;
}

void ScribeMessage::saveToStream(QDataStream &dataStream) const
{
  for (int i = 0; i < 4; i++)
    streamio::writeUInt8(dataStream, 0);

   streamio::writeInt16(dataStream, mYear);
   streamio::writeUInt8(dataStream, mData1);
   streamio::writeUInt8(dataStream, mData2);
   streamio::writeInt16(dataStream, static_cast<int>(mType));
   streamio::writeInt16(dataStream, mEntryNumber);
   streamio::writeUInt8(dataStream, mRead);
   streamio::writeUInt8(dataStream, mMonth);

  for (int i = 0; i < 2; i++)
    streamio::writeUInt8(dataStream, 0);
}

void ScribeMessage::setData1(uint8_t value)
{
  mData1 = value;
}

void ScribeMessage::setData2(uint8_t value)
{
  mData2 = value;
}

void ScribeMessage::setMonth(uint8_t value)
{
  mMonth = value;
}

void ScribeMessage::setRead(uint8_t value)
{
  mRead = value;
}

void ScribeMessage::setEntryNumber(int16_t value)
{
  mEntryNumber = value;
}

void ScribeMessage::setYear(int16_t value)
{
  mYear = value;
}

void ScribeMessage::setType(Type type)
{
  mType = type;
}

ScribeMessage::Type ScribeMessage::type() const
{
  return mType;
}

int16_t ScribeMessage::year() const
{
  return mYear;
}
