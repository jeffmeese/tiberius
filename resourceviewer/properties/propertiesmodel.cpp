#include "propertiesmodel.h"

#include "graphics/sgimagerecord.h"

PropertiesModel::PropertiesModel()
{
}

void PropertiesModel::addProperty(const Property &property)
{
  mProperties.push_back(property);
}

int32_t PropertiesModel::columnCount(const QModelIndex &) const
{
  return 2;
}

QVariant PropertiesModel::data(const QModelIndex & modelIndex, int32_t role) const
{
  if (role == Qt::DisplayRole) {
    int32_t row = modelIndex.row();
    int32_t col = modelIndex.column();

    const Property & property = mProperties.at(row);
    if (col == 0) {
      return property.name();
    }
    else if (col == 1) {
      return property.value();
    }
  }

  return QVariant();
}

QVariant PropertiesModel::headerData(int32_t section, Qt::Orientation orientation, int32_t role) const
{
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      if (section == 0) {
        return "Property";
      }
      else if (section == 1) {
        return "Value";
      }
    }
  }
  return QAbstractTableModel::headerData(section, orientation, role);
}

QModelIndex PropertiesModel::parent(const QModelIndex &) const
{
  return QModelIndex();
}

int32_t PropertiesModel::rowCount(const QModelIndex &) const
{
  return mProperties.size();
}
