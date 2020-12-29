#include <iostream>
#include <memory>
#include <sstream>

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QString>

#include "core/streamio.h"

#include "map/grid.h"
#include "map/map.h"

#include "game/game.h"

#include "zip/pkzipdata.h"

int main(int argc, char ** argv)
{
  PkZipData zipData;

  QByteArray byteArray;
  byteArray.append((int8_t)65);
  byteArray.append((int8_t)73);

  QByteArray c = zipData.compress(byteArray, 0, 4);
  for (int i = 0; i < c.size(); i++) {
    qDebug() << QStringLiteral("%1").arg((uint8_t)c.at(i), 2, 16, QChar('0'));
  }

  QByteArray d = zipData.decompress(c);
  for (int i = 0; i < d.size(); i++) {
    qDebug() << QStringLiteral("%1").arg((uint8_t)d.at(i), 2, 16, QChar('0'));
  }

//  QString fileName("/home/jmeese/applications/caesar3/das-miletus-finish.sav");
//  QFile inputFile(fileName);
//  inputFile.open(QIODevice::ReadOnly);

//  int32_t fileVersion;
//  int32_t missionId;
//  int32_t dataSize;
//  QDataStream dataStream(&inputFile);
//  dataStream >> fileVersion >> missionId;
//  dataStream >> dataSize;
//  QByteArray byteData = dataStream.device()->read(dataSize);

//  PkZipData zip;
//  QByteArray gridData = zip.decompress(byteData);
//  QByteArray compressedGridData = zip.compress(gridData);

  return 0;
}
