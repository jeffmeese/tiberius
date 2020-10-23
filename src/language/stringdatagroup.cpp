#include "stringdatagroup.h"

StringDataGroup::StringDataGroup(int32_t groupId)
  : mGroupId(groupId)
{
}

void StringDataGroup::addString(const QString &s)
{
  mStrings.push_back(s);
}

void StringDataGroup::clearStrings()
{
  mStrings.clear();
}

QString StringDataGroup::stringAt(std::size_t index) const
{
  return mStrings.at(index);
}
