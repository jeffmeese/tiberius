#include "textdataitem.h"

#include "languages/stringtablemodel.h"
#include "language/stringdata.h"

#include <QHeaderView>
#include <QTableView>

TextDataItem::TextDataItem(const StringData * data)
  : mStringData(data)
{
  mSortModel.reset(new QSortFilterProxyModel);
  mModel.reset(new StringTableModel);

  mModel->setStringData(mStringData);
  mSortModel->setSourceModel(mModel.get());
}

QWidget * TextDataItem::createView() const
{
  QTableView * view = new QTableView;
  view->setSortingEnabled(true);
  view->horizontalHeader()->setStretchLastSection(true);
  view->setModel(mSortModel.get());
  return view;
}

QList<Property> TextDataItem::getProperties() const
{
  QList<Property> propertyList;

  propertyList.push_back(Property("Total Groups", QString::number(mStringData->totalGroups())));
  propertyList.push_back(Property("Total Strings", QString::number(mStringData->totalStrings())));

  return propertyList;
}
