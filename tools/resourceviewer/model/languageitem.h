#ifndef LANGUAGEITEM_H
#define LANGUAGEITEM_H

#include <memory>

#include "resourceitem.h"

class Language;

class LanguageItem
    : public ResourceItem
{
public:
  LanguageItem(const QString & textPath);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  std::unique_ptr<Language> mLanguage;
};

#endif // LANGUAGEITEM_H
