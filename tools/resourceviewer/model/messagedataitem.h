#ifndef MESSAGEDATAITEM_H
#define MESSAGEDATAITEM_H

#include "resourceitem.h"

class MessageData;

class MessageDataItem
    : public ResourceItem
{
public:
  MessageDataItem(const MessageData * messageData);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const MessageData * mMessageData;
};

#endif // MESSAGEDATAITEM_H
