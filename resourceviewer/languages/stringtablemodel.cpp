#include "stringtablemodel.h"

#include "language/stringdata.h"
#include "language/stringdatagroup.h"

StringTableModel::StringTableModel()
  : mStringData(nullptr)
{
}

int32_t StringTableModel::columnCount(const QModelIndex & parent) const
{
  return 3;
}

QVariant StringTableModel::data(const QModelIndex & modelIndex, int32_t role) const
{
  if (!modelIndex.isValid())
    return QVariant();

  if (role == Qt::DisplayRole) {
    if (mStringData != nullptr) {
      int32_t row = modelIndex.row();
      int32_t col = modelIndex.column();
      if (col == 0) {
        return mRecords.at(row).groupId;
      }
      else if (col == 1) {
        return mRecords.at(row).stringId;
      }
      else if (col == 2) {
        return mRecords.at(row).string;
      }
    }
  }

  return QVariant();
}

QVariant StringTableModel::headerData(int32_t section, Qt::Orientation orientation, int32_t role) const
{
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      if (section == 0) {
        return "Group ID";
      }
      else if (section == 1) {
        return "Image ID";
      }
      else if (section == 2) {
        return "String";
      }
    }
  }

  return QVariant();
}

QModelIndex StringTableModel::parent(const QModelIndex &child) const
{
  return QModelIndex();
}

int32_t StringTableModel::rowCount(const QModelIndex & parent) const
{
  return static_cast<int32_t>(mRecords.size());
}

void StringTableModel::setStringData(const StringData * data)
{
  mRecords.clear();

  mStringData = data;
  for (std::size_t i = 0; i < mStringData->totalGroups(); i++) {
    const StringDataGroup* group = mStringData->groupAt(i);
    for (std::size_t j = 0; j < group->totalStrings(); j++) {
      QString s = group->stringAt(j);
      Record record = {i + 1, j, s};
      mRecords.push_back(record);
    }
  }
}

