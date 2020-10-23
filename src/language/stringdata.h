#ifndef STRINGDATA_H
#define STRINGDATA_H

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

#include "tiberius.h"

class StringDataGroup;

class StringData
{
public:
  TIBERIUS_LIB_DECL StringData();
  TIBERIUS_LIB_DECL ~StringData();

public:
  TIBERIUS_LIB_DECL void addGroup(std::unique_ptr<StringDataGroup> group);
  TIBERIUS_LIB_DECL void clearGroups();
  TIBERIUS_LIB_DECL const StringDataGroup * groupAt(std::size_t index) const;
  TIBERIUS_LIB_DECL QString getString(uint32_t groupId, uint32_t number) const;
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL std::size_t totalGroups() const;
  TIBERIUS_LIB_DECL std::size_t totalStrings() const;

private:
  struct Header
  {
    char description[16];
    uint32_t totalGroups;
    uint32_t totalStrings;
    uint32_t totalWords;
  };

  struct Index
  {
    uint32_t offset;
    uint32_t numStrings;
  };

private:
  static const int32_t MAX_INDEX = 1000;

private:
  typedef std::unique_ptr<StringDataGroup> StringDataGroupPtr;
  typedef std::vector<StringDataGroupPtr> StringGroupVector;

private:
  StringGroupVector mGroups;
};

inline const StringDataGroup * StringData::groupAt(std::size_t index) const
{
  return mGroups.at(index).get();
}

#endif // STRINGDATA_H
