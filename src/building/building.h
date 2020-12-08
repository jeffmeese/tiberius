#ifndef BUILDING_H
#define BUILDING_H

#include "tiberius.h"

#include <QPixmap>
#include <QString>

class Building
{
public:
  enum class Type
  {
    None = 0
  };

public:
  TIBERIUS_LIB_DECL Building(int32_t id);

public:
  TIBERIUS_LIB_DECL int32_t id() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setType(Type type);

  TIBERIUS_LIB_DECL int32_t getField(int32_t index) const { return mFields[index]; }
  TIBERIUS_LIB_DECL int32_t totalFields() const { return static_cast<int32_t>(mFields.size()); }

public:
  TIBERIUS_LIB_DECL QPixmap getImage() const;
  TIBERIUS_LIB_DECL QString getName() const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mId;
  Type mType;
  std::vector<int32_t> mFields;
};

#endif // BUILDING_H
