#ifndef MESSAGEITEM_H
#define MESSAGEITEM_H

#include "resourceitem.h"

class Message;

class MessageItem
    : public ResourceItem
{
public:
  MessageItem(const Message * message);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  const Message * mMessage;
};

#endif // MESSAGEITEM_H
