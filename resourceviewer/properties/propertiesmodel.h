#ifndef PROPERTIESMODEL_H
#define PROPERTIESMODEL_H

#include <QAbstractTableModel>

#include "property.h"

class PropertiesModel
    : public QAbstractTableModel
{
public:
  PropertiesModel();

public:
  void addProperty(const Property & property);

public:
  int32_t columnCount(const QModelIndex & parentIndex = QModelIndex()) const override;
  QVariant data(const QModelIndex & modelIndex, int32_t role = Qt::DisplayRole) const override;
  QVariant headerData(int32_t section, Qt::Orientation orientation, int32_t role = Qt::DisplayRole) const override;
  QModelIndex parent(const QModelIndex &child) const override;;
  int32_t rowCount(const QModelIndex & parentIndex = QModelIndex()) const override;

private:
  std::vector<Property> mProperties;
};

#endif // PROPERTIESMODEL_H
