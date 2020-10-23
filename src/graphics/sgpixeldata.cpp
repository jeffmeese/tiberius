#include "sgpixeldata.h"

#include <QByteArray>
#include <QDataStream>
#include <QFile>

SgPixelData::SgPixelData()
{
}

SgPixelData::~SgPixelData()
{
}

bool SgPixelData::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    return false;
  }

  mData = file.readAll();
  return true;
}
