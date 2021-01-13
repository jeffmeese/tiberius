#include "scribemessagedata.h"

#include "scribemessage.h"

#include "core/streamio.h"

static const int32_t DATA_SIZE = 16000;

ScribeMessageData::ScribeMessageData()
{
  mScribeMessages.resize(MAX_MESSAGES);
  for (int i = 0; i < MAX_MESSAGES; i++) {
    mScribeMessages[i].reset(new ScribeMessage);
  }
}

ScribeMessageData::~ScribeMessageData()
{

}

void ScribeMessageData::loadFromDataStream(QDataStream & dataStream)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);
  for (int i = 0; i < MAX_MESSAGES; i++) {
    mScribeMessages.at(i)->loadFromStream(byteStream);
  }
}

void ScribeMessageData::saveToDataStream(QDataStream & dataStream) const
{
  QByteArray byteArray;
  QDataStream byteStream(&byteArray, QIODevice::WriteOnly);
  for (int i = 0; i < MAX_MESSAGES; i++) {
    mScribeMessages.at(i)->saveToStream(byteStream);
  }

  streamio::writeCompressedData(dataStream, byteArray);
}
