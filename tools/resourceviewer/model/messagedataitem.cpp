#include "messagedataitem.h"
#include "messageitem.h"

#include "language/message.h"
#include "language/messagedata.h"

#include "properties/property.h"

MessageDataItem::MessageDataItem(const MessageData * messageData)
  : mMessageData(messageData)
{
  for (int32_t i = 0; i < messageData->totalIndexEntries(); i++) {
    QString itemText("Message" + QString::number(i+1));
    const Message * message = messageData->getMessage(i);
    MessageItem * messageItem = new MessageItem(message);
    messageItem->setText(itemText);
    appendRow(messageItem);
  }
}

QWidget * MessageDataItem::createView() const
{
  return nullptr;
}

QList<Property> MessageDataItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.push_back(Property("Description", mMessageData->description()));
  propertyList.push_back(Property("Total Messages", QString::number(mMessageData->totalIndexEntries())));
  propertyList.push_back(Property("Last Index", QString::number(mMessageData->lastEntryUsed())));

  return propertyList;
}
