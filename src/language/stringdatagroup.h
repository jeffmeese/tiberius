#ifndef STRINGDATAGROUP_H
#define STRINGDATAGROUP_H

#include <QString>

#include <vector>

#include "tiberius.h"

class StringDataGroup
{
public:
  TIBERIUS_LIB_DECL StringDataGroup(int32_t groupId);

public:
  TIBERIUS_LIB_DECL int groupId() const;
  TIBERIUS_LIB_DECL std::size_t totalStrings() const;

public:
  TIBERIUS_LIB_DECL void addString(const QString & s);
  TIBERIUS_LIB_DECL void clearStrings();
  TIBERIUS_LIB_DECL QString stringAt(std::size_t index) const;

private:
  int mGroupId;
  std::vector<QString> mStrings;
};

inline int StringDataGroup::groupId() const
{
  return mGroupId;
}

inline std::size_t StringDataGroup::totalStrings() const
{
  return mStrings.size();
}

#endif // STRINGDATAGROUP_H
