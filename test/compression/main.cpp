#include <iostream>
#include <memory>
#include <sstream>

#include <QDataStream>
#include <QFile>
#include <QString>

#include "core/streamio.h"

#include "map/grid.h"
#include "map/map.h"

#include "game/game.h"

#include "zip/pkzipdata.h"

int main(int argc, char ** argv)
{
  QString bitString;
  bitString += "00000000";
  bitString += "00000100";
  bitString += "10000010";
  bitString += "00100100";
  bitString += "00100101";
  bitString += "10000110";
  bitString += "10000000";
  bitString += "01111111";

  QByteArray byteArray;
  for (int i = 0; i < bitString.size() / 8; i++) {
    QString s = bitString.mid(i*8, 8);
    uint8_t value = s.toUInt(nullptr, 2);
    std::cout << QStringLiteral("%1").arg(value, 2, 16, QChar('0')).toStdString() << "\n";
    byteArray.append(value);
  }

  PkZipData zipData;
  QByteArray decompressed = zipData.decompress(byteArray);
  for (int i = 0; i < decompressed.size(); i++) {
    uint8_t data = decompressed.at(i);
    QString s = QStringLiteral("%1").arg(data, 2, 16, QChar('0'));
    std::cout << char(data) << "\n";
  }

  return 0;
}
