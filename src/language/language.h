#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>

#include <memory>

#include "tiberius.h"

class MessageData;
class StringData;

class Language
{
public:
  TIBERIUS_LIB_DECL Language();
  TIBERIUS_LIB_DECL ~Language();

public:
  TIBERIUS_LIB_DECL const MessageData * messageData() const;
  TIBERIUS_LIB_DECL const StringData * stringData() const;

public:
  TIBERIUS_LIB_DECL uint32_t mapCharToId(char c) const;
  TIBERIUS_LIB_DECL void load(const QString & textFile, const QString & messageFile);
  TIBERIUS_LIB_DECL void setData(std::unique_ptr<StringData> stringData, std::unique_ptr<MessageData> messageData);

private:
  std::unique_ptr<MessageData> mMessageData;
  std::unique_ptr<StringData> mStringData;
};

inline const MessageData * Language::messageData() const
{
  return mMessageData.get();
}

inline const StringData * Language::stringData() const
{
  return mStringData.get();
}

#endif // LANGUAGE_H
