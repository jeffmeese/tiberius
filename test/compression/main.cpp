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
  std::unique_ptr<Game> game(new Game);

  QString inputFileName("/data/caesar3/das-miletus-finish.sav");
  QString outputFile("/home/jmeese/temp.sav");

  QFile file(inputFileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << inputFileName.toStdString();
    std::cout << oss.str() << "\n";
    return -1;
  }

  QDataStream dataStream(&file);
  dataStream.skipRawData(8);

  PkZipData zipData;
  int32_t dataSize;
  dataStream >> dataSize;
  QByteArray originalCompressed = dataStream.device()->read(dataSize);
  QByteArray uncompressed = zipData.decompress(originalCompressed);
  QByteArray newCompressed = zipData.compress(uncompressed);

//  if (newCompressed.size() != uncompressed.size()) {
//    std::cout << "Sizes do not match\n";
//    std::cout << "Original " << originalCompressed.size() << "\n";
//    std::cout << "New " << newCompressed.size() << "\n";
//    return -1;
//  }

//  for (int i = 0; i < newCompressed.size(); i++) {
//    if (newCompressed[i] != uncompressed[i]) {
//      std::cout << "Error at index " << i << "\n";
//      return -1;
//    }
//  }

  //std::cout << "Compression test passed\n";

  //game->saveToFile(outputFile);

  return 0;
}
