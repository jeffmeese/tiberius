#ifndef TEXTDATAITEM_H
#define TEXTDATAITEM_H

#include "resourceitem.h"

#include <memory>

#include <QSortFilterProxyModel>
#include <QTableView>

class StringTableModel;
class StringData;

class TextDataItem
    : public ResourceItem
{
public:
  TextDataItem(const StringData * textData);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  std::unique_ptr<StringTableModel> mModel;
  std::unique_ptr<QSortFilterProxyModel> mSortModel;
  const StringData * mStringData;
};

#endif // TEXTDATAITEM_H
