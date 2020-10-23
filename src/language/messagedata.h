#ifndef MESSAGEDATA_H
#define MESSAGEDATA_H

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

#include "tiberius.h"

class Message;

class MessageData
{
public:
  TIBERIUS_LIB_DECL MessageData();
  TIBERIUS_LIB_DECL ~MessageData();

public:
  TIBERIUS_LIB_DECL QByteArray * byteData();
  TIBERIUS_LIB_DECL const QByteArray * byteData() const;
  TIBERIUS_LIB_DECL QString description() const;
  TIBERIUS_LIB_DECL int32_t lastEntryUsed() const;
  TIBERIUS_LIB_DECL int32_t totalIndexEntries() const;
  TIBERIUS_LIB_DECL std::size_t totalMessages() const;
  TIBERIUS_LIB_DECL void setByteData(std::unique_ptr<QByteArray> byteArray);
  TIBERIUS_LIB_DECL void setDescription(const QString & value);
  TIBERIUS_LIB_DECL void setLastEntryUsed(int32_t value);
  TIBERIUS_LIB_DECL void setTotalIndexEntries(int32_t value);

public:
  TIBERIUS_LIB_DECL const Message * getMessage(int32_t index) const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;

private:
  struct MessageIndex
  {
    int16_t type;
    int16_t subType;
    int16_t dialogXPos;
    int16_t dialogYPos;
    int16_t dialogWidth;
    int16_t dialogHeight;
    int16_t imageId;
    int16_t imageXPos;
    int16_t imageYPos;
    int16_t secondaryImageId;
    int16_t secondaryImageXPos;
    int16_t secondaryImageYPos;
    int16_t titleXPos;
    int16_t titleYPos;
    int16_t subtitleXPos;
    int16_t subtitleYPos;
    int16_t videoXPos;
    int16_t videoYPos;
    int32_t contentOffset;
    int32_t subtitleOffset;
    int32_t titleOffset;
    int32_t urgent;
    int32_t videoFileOffset;
  };

private:
  void readMessageIndex(QDataStream & dataStream, MessageIndex & messageIndex);
  QString readString(int32_t offset, const QByteArray * byteArray);
  void saveMessageIndex(QDataStream & dataStream, const MessageIndex & messageIndex) const;

private:
  typedef std::unique_ptr<QByteArray> BytePtr;
  typedef std::unique_ptr<Message> MessagePtr;
  typedef std::vector<MessageIndex> IndexVector;
  typedef std::vector<MessagePtr> MessageVector;

private:
  QString mDescription;
  int32_t mTotalEntries;
  int32_t mLastEntry;
  IndexVector mIndexVector;
  MessageVector mMessages;
  BytePtr mData;
};

inline QString MessageData::description() const
{
  return mDescription;
}

inline int32_t MessageData::lastEntryUsed() const
{
  return mLastEntry;
}

inline int32_t MessageData::totalIndexEntries() const
{
  return mTotalEntries;
}

inline std::size_t MessageData::totalMessages() const
{
  return mMessages.size();
}

inline void MessageData::setDescription(const QString & value)
{
  mDescription = value;
}

inline void MessageData::setLastEntryUsed(int32_t value)
{
  mLastEntry = value;
}

inline void MessageData::setTotalIndexEntries(int32_t value)
{
  mTotalEntries = value;
}

#endif // MESSAGEDATA_H
