#include "messagedata.h"
#include "message.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>

#include <sstream>
#include <stdexcept>

MessageData::MessageData()
{
  mLastEntry = mTotalEntries = 0;
}

MessageData::~MessageData()
{
}

const Message * MessageData::getMessage(int32_t index) const
{
  return mMessages.at(index).get();
}

void MessageData::loadFromDataStream(QDataStream &dataStream)
{
  mData.reset(new QByteArray);
  mIndexVector.clear();
  mLastEntry = mTotalEntries = 0;

  dataStream.setByteOrder(QDataStream::LittleEndian);

  char buffer[16];
  dataStream.readRawData(buffer, 16);
  mDescription = buffer;

  dataStream >> mTotalEntries;
  dataStream >> mLastEntry;
  for (uint16_t i = 0; i < mTotalEntries; i++) {
    MessageIndex index;
    readMessageIndex(dataStream, index);
    mIndexVector.push_back(std::move(index));
  }

  // Read the message contents
  std::unique_ptr<QByteArray> byteArray(new QByteArray(dataStream.device()->readAll()));
  setByteData(std::move(byteArray));
}

void MessageData::readMessageIndex(QDataStream & dataStream, MessageIndex & messageIndex)
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  dataStream >> messageIndex.type;
  dataStream >> messageIndex.subType;
  dataStream.skipRawData(2);
  dataStream >> messageIndex.dialogXPos;
  dataStream >> messageIndex.dialogYPos;
  dataStream >> messageIndex.dialogWidth;
  dataStream >> messageIndex.dialogHeight;
  dataStream >> messageIndex.imageId;
  dataStream >> messageIndex.imageXPos;
  dataStream >> messageIndex.imageYPos;
  dataStream >> messageIndex.secondaryImageId;
  dataStream >> messageIndex.secondaryImageXPos;
  dataStream >> messageIndex.secondaryImageYPos;
  dataStream >> messageIndex.titleXPos;
  dataStream >> messageIndex.titleYPos;
  dataStream >> messageIndex.subtitleXPos;
  dataStream >> messageIndex.subtitleYPos;
  dataStream.skipRawData(2);
  dataStream.skipRawData(2);
  dataStream >> messageIndex.videoXPos;
  dataStream >> messageIndex.videoYPos;
  dataStream.skipRawData(14);
  dataStream >> messageIndex.urgent;
  dataStream >> messageIndex.videoFileOffset;
  dataStream.skipRawData(4);
  dataStream >> messageIndex.titleOffset;
  dataStream >> messageIndex.subtitleOffset;
  dataStream >> messageIndex.contentOffset;
}

void MessageData::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open message data file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  loadFromDataStream(dataStream);
}

QString MessageData::readString(int32_t offset, const QByteArray * data)
{
  QString s;

  int32_t index = offset;
  while (true) {
    qint8 byte = data->at(index++);
    if (byte == '\0')
      break;

    QChar c(byte);
    if (c == '@') {
      c = data->at(index);
      if (c == 'P') {
        s += "\n    ";
        index++;
      }
      else if (c == 'L') {
        s += "\n";
        index++;
      }
    }
    else {
      s += c;
    }
  }

  return s;
}

void MessageData::saveMessageIndex(QDataStream &dataStream, const MessageIndex &messageIndex) const
{
  int16_t dummy16 = 0;
  int32_t dummy32 = 0;

  dataStream.setByteOrder(QDataStream::LittleEndian);

  dataStream << messageIndex.type;
  dataStream << messageIndex.subType;
  dataStream << dummy16;
  dataStream << messageIndex.dialogXPos;
  dataStream << messageIndex.dialogYPos;
  dataStream << messageIndex.dialogWidth;
  dataStream << messageIndex.dialogHeight;
  dataStream << messageIndex.imageId;
  dataStream << messageIndex.imageXPos;
  dataStream << messageIndex.imageYPos;
  dataStream << messageIndex.secondaryImageId;
  dataStream << messageIndex.secondaryImageXPos;
  dataStream << messageIndex.secondaryImageYPos;
  dataStream << messageIndex.titleXPos;
  dataStream << messageIndex.titleYPos;
  dataStream << messageIndex.subtitleXPos;
  dataStream << messageIndex.subtitleYPos;
  dataStream << dummy16;
  dataStream << dummy16;
  dataStream << messageIndex.videoXPos;
  dataStream << messageIndex.videoYPos;
  dataStream << dummy32;
  dataStream << dummy32;
  dataStream << dummy32;
  dataStream << dummy16;
  dataStream << messageIndex.urgent;
  dataStream << messageIndex.videoFileOffset;
  dataStream << dummy32;
  dataStream << messageIndex.titleOffset;
  dataStream << messageIndex.subtitleOffset;
  dataStream << messageIndex.contentOffset;
}

void MessageData::saveToDataStream(QDataStream & dataStream) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  dataStream << mDescription;
  dataStream << mTotalEntries;
  dataStream << mLastEntry;
  for (uint16_t i = 0; i < mTotalEntries; i++) {
    const MessageIndex & messageIndex = mIndexVector.at(i);
    saveMessageIndex(dataStream, messageIndex);
  }

  if (mData.get() != nullptr) {
    dataStream << *mData;
  }
}

void MessageData::saveToFile(const QString & fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open message data file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToDataStream(dataStream);
}

void MessageData::setByteData(std::unique_ptr<QByteArray> byteArray)
{
  mData = std::move(byteArray);

  mMessages.clear();
  for (std::size_t i = 0; i < mIndexVector.size(); i++) {
    const MessageIndex & messageIndex = mIndexVector.at(i);

    int32_t videoOffset = messageIndex.videoFileOffset;
    int32_t titleOffset = messageIndex.titleOffset;
    int32_t subtitleOffset = messageIndex.subtitleOffset;
    int32_t contentOffset = messageIndex.contentOffset;

    std::unique_ptr<Message> message(new Message);
    message->setType(messageIndex.type);
    message->setUrgent(messageIndex.urgent);
    message->setImageId(messageIndex.imageId);
    message->setSubtype(messageIndex.subType);
    message->setImageXPos(messageIndex.imageXPos);
    message->setImageYPos(messageIndex.imageYPos);
    message->setTitleXPos(messageIndex.titleXPos);
    message->setTitleYPos(messageIndex.titleYPos);
    message->setVideoXPos(messageIndex.videoXPos);
    message->setVideoYPos(messageIndex.videoYPos);
    message->setDialogXPos(messageIndex.dialogXPos);
    message->setDialogYPos(messageIndex.dialogYPos);
    message->setDialogWidth(messageIndex.dialogWidth);
    message->setDialogHeight(messageIndex.dialogHeight);
    message->setSubtitleXPos(messageIndex.subtitleXPos);
    message->setSubtitleYPos(messageIndex.subtitleYPos);
    message->setSecondaryImageId(messageIndex.secondaryImageId);
    message->setSecondaryImageXPos(messageIndex.secondaryImageXPos);
    message->setSecondaryImageYPos(messageIndex.secondaryImageYPos);

    if (videoOffset > 0) {
      QString s = readString(videoOffset, mData.get());
      message->setVideoFile(s);
    }

    if (titleOffset > 0) {
      QString s = readString(titleOffset, mData.get());
      message->setTitle(s);
    }

    if (subtitleOffset > 0) {
      QString s = readString(subtitleOffset, mData.get());
      message->setSubtitle(s);
    }

    if (contentOffset > 0) {
      QString s = readString(contentOffset, mData.get());
      message->setContent(s);
    }

    mMessages.push_back(std::move(message));
  }
}
