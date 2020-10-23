#include "stringdata.h"

#include "stringdatagroup.h"

#include <QDebug>
#include <QDir>
#include <QFile>

#include <sstream>
#include <stdexcept>

StringData::StringData()
{
}

StringData::~StringData()
{

}

void StringData::addGroup(std::unique_ptr<StringDataGroup> textGroup)
{
  mGroups.push_back(std::move(textGroup));
}

QString StringData::getString(uint32_t groupId, uint32_t number) const
{
  const StringDataGroup * textGoup = mGroups.at(groupId-1).get();
  if (textGoup->totalStrings() <= number) {
    return QString();
  }

  return mGroups.at(groupId-1)->stringAt(number);
}

void StringData::loadFromDataStream(QDataStream &dataStream)
{
  mGroups.clear();

  dataStream.setByteOrder(QDataStream::LittleEndian);

  // Read the header data
  Header header;
  dataStream.readRawData(header.description, 16);
  dataStream >> header.totalGroups;
  dataStream >> header.totalStrings;
  dataStream >> header.totalWords;

  // Read index data
  Index indexData[MAX_INDEX];
  for (int32_t i = 0; i < MAX_INDEX; i++) {
    dataStream >> indexData[i].offset;
    dataStream >> indexData[i].numStrings;
  }

  // Read the string data
  // Older versions only specified where the group was used
  // while newer versions specified how many strings were in
  // each group. The following assumes the old format and
  // converts to the new format. For new format files this
  // is unnecessary but it's only done once so the performance
  // impact is minimal.
  for (int32_t i = 0; i < MAX_INDEX-1; i++) {
    uint32_t offset = indexData[i].offset;
    uint32_t numStrings = indexData[i].numStrings;
    if (numStrings > 0) {
      StringDataGroupPtr group(new StringDataGroup(i+1));

      // Read new strings until we hit the offset for the next group
      uint32_t nextOffset = indexData[i+1].offset; // What if the next one isn't used?
      QString currentString;
      while (offset < nextOffset && !dataStream.atEnd()) {
        offset++;

        // Read characters until we find a null
        char c;
        dataStream.readRawData(&c, 1);
        if (c == '\0') {
          group->addString(currentString);
          currentString.clear();
        }
        else {
          currentString += c;
        }
      }
      addGroup(std::move(group));
    }
  }
}

void StringData::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open language file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  loadFromDataStream(dataStream);
}

void StringData::saveToDataStream(QDataStream & dataStream) const
{
  // TODO: Implement
}

void StringData::saveToFile(const QString & fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open language file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }
}

std::size_t StringData::totalGroups() const
{
  return mGroups.size();
}

std::size_t StringData::totalStrings() const
{
  std::size_t total = 0;
  for (std::size_t i = 0; i < mGroups.size(); i++) {
    total += mGroups.at(i)->totalStrings();
  }
  return total;
}
