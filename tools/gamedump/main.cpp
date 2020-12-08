#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

#include <QDir>
#include <QFile>
#include <QString>

#include "city/city.h"
#include "city/walkerdata.h"

#include "figure/figure.h"

#include "game/game.h"

void initHeaders(QStringList & headers)
{
  for (int i = 0; i < 120; i++) {
    QString header = "Unknown " + QString::number(i);
    headers << header;
  }
  headers[0] = "ID";
  headers[5] = "Image ID";
  headers[6] = "Cart Image ID";
  headers[8] = "Type";
  headers[18] = "Pos X";
  headers[19] = "Pos Y";
  headers[20] = "Prev Pos X";
  headers[21] = "Prev Pos Y";
}

int main(int argc, char *argv[])
{
  QString dirName = argv[1];

  QStringList headers;
  initHeaders(headers);

  std::map<int32_t, int32_t> typeMap;

  QStringList filters;
  filters << "*.sav";
  QDir dir(dirName);
  QFileInfoList list = dir.entryInfoList(filters, QDir::Files);
  for (int i = 0; i < list.size(); i++) {
    QFileInfo fileInfo = list.at(i);
    QString pathName = fileInfo.absoluteFilePath();

    Game game;
    game.loadFromFile(pathName);

    WalkerData * walkerData = game.city()->walkerData();
    for (int32_t i = 0; i < walkerData->total(); i++) {
      Figure * figure = walkerData->get(i);
      int32_t typeId = figure->getField(7);
      int32_t imageId = figure->getField(4);
      if (typeId != 0) {
        if (typeMap.find(typeId) == typeMap.end()) {
          typeMap[typeId] = imageId;
        }
      }
    }

    QString outputFileName = fileInfo.baseName() + ".csv";
    std::ofstream output(outputFileName.toStdString());
    output << "Type, Image\n";
    for (std::map<int32_t, int32_t>::iterator itr = typeMap.begin(); itr != typeMap.end(); ++itr)
    {
      output << itr->first << "," << itr->second << "\n";
    }
  }

//  std::ofstream output("figures.csv");
//  output << "Type, Image\n";
//  for (std::map<int32_t, int32_t>::iterator itr = typeMap.begin(); itr != typeMap.end(); ++itr)
//  {
//    output << itr->first << "," << itr->second << "\n";
//  }

//  std::ofstream output("figures.csv");
//  output << headers[0].toStdString();
//  for (int i = 1; i < headers.size(); i++) {
//    output << "," << headers[i].toStdString();
//  }
//  output << "\n";

//  WalkerData * walkerData = game.city()->walkerData();
//  for (int32_t i = 0; i < walkerData->total(); i++) {
//    Figure * figure = walkerData->get(i);
//    output << i;
//    for (int32_t j = 0; j < figure->totalFields(); j++) {
//      output << "," << figure->getField(j);
//    }
//    if (figure->getField(7) == 6) {
//      std::cout << "Use\n";
//    }
//    output << "\n";
//  }

  return 0;
}
