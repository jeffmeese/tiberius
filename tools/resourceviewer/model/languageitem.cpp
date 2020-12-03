#include "languageitem.h"

#include "language/language.h"
#include "language/stringdata.h"
#include "language/messagedata.h"

#include "messagedataitem.h"
#include "textdataitem.h"

#include <QDir>
#include <QFileInfo>
#include <stdexcept>

LanguageItem::LanguageItem(const QString & textPath)
{
  QFileInfo fileInfo(textPath);
  QString fileName = fileInfo.fileName();
  QString messagePath(textPath);
  messagePath.replace("c3", "c3_mm");
  messagePath.replace("C3", "c3_mm");

  setText(fileName);

  mLanguage.reset(new Language);
  try {
    mLanguage->load(textPath, messagePath);
  }
  catch (std::invalid_argument & ex) {
    messagePath.replace("c3", "C3");
    mLanguage->load(textPath, messagePath);
  }

  QStandardItem * textItem = new TextDataItem(mLanguage->stringData());
  textItem->setText("Text Data");
  appendRow(textItem);

  QStandardItem * messageItem = new MessageDataItem(mLanguage->messageData());
  messageItem->setText("Message Data");
  appendRow(messageItem);
}

QWidget * LanguageItem::createView() const
{
  return nullptr;
}

QList<Property> LanguageItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
