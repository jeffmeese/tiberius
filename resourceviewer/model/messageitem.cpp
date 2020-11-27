#include "messageitem.h"

#include "language/message.h"

#include "widget/messagewidget.h"

#include <QDebug>
#include <QTextEdit>
#include <QTextStream>

MessageItem::MessageItem(const Message * message)
  : mMessage(message)
{
}

QWidget * MessageItem::createView() const
{
  //MessageWidget * widget = new MessageWidget;
  //widget->setMessage(mMessage);
  //return widget;

  QTextEdit * textEdit = new QTextEdit;
  QTextCursor cursor = textEdit->textCursor();
  QString content = mMessage->content();
  for (int i = 0; i < content.size(); i++) {
    QChar c = content.at(i);
    if (c.isNumber()) {

      QString linkText;
      while (c.isNumber()) {
        linkText.append(c);
        c = content.at(++i);
      }

      QTextCharFormat format = cursor.charFormat();
      format.setForeground(Qt::blue);
      format.setAnchor(true);
      format.setAnchorHref(linkText);
      format.setToolTip(linkText);

      QString text;
      while (c != ' ' && i < content.size()-1) {
        text.append(c);
        c = content.at(++i);
      }
      text += " ";
      cursor.insertText(text, format);
    }
    else {
      QTextCharFormat format = cursor.charFormat();
      format.setAnchor(false);
      format.setForeground(Qt::black);
      cursor.insertText(c, format);
    }
  }

  return textEdit;
}

QList<Property> MessageItem::getProperties() const
{
  QList<Property> propertyList;

  propertyList.push_back(Property("Message Type", QString::number(mMessage->type())));
  propertyList.push_back(Property("Message Subtype", QString::number(mMessage->subtype())));
  propertyList.push_back(Property("Dialog X Pos", QString::number(mMessage->dialogXPos())));
  propertyList.push_back(Property("Dialog X Pos", QString::number(mMessage->dialogYPos())));
  propertyList.push_back(Property("Dialog Width", QString::number(mMessage->dialogWidth())));
  propertyList.push_back(Property("Dialog Height", QString::number(mMessage->dialogHeight())));
  propertyList.push_back(Property("Image ID", QString::number(mMessage->imageId())));
  propertyList.push_back(Property("Image X Pos", QString::number(mMessage->imageXPos())));
  propertyList.push_back(Property("Image Y Pos", QString::number(mMessage->imageYPos())));
  propertyList.push_back(Property("Secondary Image ID", QString::number(mMessage->secondaryImageId())));
  propertyList.push_back(Property("Secondary Image X Pos", QString::number(mMessage->secondaryImageXPos())));
  propertyList.push_back(Property("Secondary Image Y Pos", QString::number(mMessage->secondaryImageYPos())));
  propertyList.push_back(Property("Title X Pos", QString::number(mMessage->titleXPos())));
  propertyList.push_back(Property("Title Y Pos", QString::number(mMessage->titleYPos())));
  propertyList.push_back(Property("Subtitle X Pos", QString::number(mMessage->subtitleXPos())));
  propertyList.push_back(Property("Subtitle Y Pos", QString::number(mMessage->subtitleYPos())));
  propertyList.push_back(Property("Video X Pos", QString::number(mMessage->videoXPos())));
  propertyList.push_back(Property("Video Y Pos", QString::number(mMessage->videoYPos())));
  propertyList.push_back(Property("Urgent", QString::number(mMessage->urgent())));
  propertyList.push_back(Property("Video File", mMessage->videoFile()));
  propertyList.push_back(Property("Title", mMessage->title()));
  propertyList.push_back(Property("Subtitle", mMessage->subtitle()));
  //propertyList.push_back(Property("Content", mMessage->content()));

  return propertyList;
}
