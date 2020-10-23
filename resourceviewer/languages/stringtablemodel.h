#ifndef STRINGTABLEMODEL_H
#define STRINGTABLEMODEL_H

#include <QAbstractTableModel>

class StringData;

class StringTableModel
    : public QAbstractTableModel
{
public:
  StringTableModel();

public:
  const StringData * stringData() const;
  void setStringData(const StringData * data);

public:
  int32_t columnCount(const QModelIndex & parent = QModelIndex()) const override;
  QVariant data(const QModelIndex & modelIndex, int32_t role = Qt::DisplayRole) const override;
  QVariant headerData(int32_t section, Qt::Orientation orientation, int32_t role = Qt::DisplayRole) const override;
  QModelIndex parent(const QModelIndex &child) const override;
  int32_t rowCount(const QModelIndex & parent = QModelIndex()) const override;

private:
  struct Record
  {
    std::size_t groupId;
    std::size_t stringId;
    QString string;
  };

private:
  const StringData * mStringData;
  std::vector<Record> mRecords;
};

inline const StringData * StringTableModel::stringData() const
{
  return mStringData;
}

#endif // STRINGTABLEMODEL_H
