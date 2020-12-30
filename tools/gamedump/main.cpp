#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

#include <QDir>
#include <QFile>
#include <QString>

#include "building/building.h"

#include "city/buildingdata.h"
#include "city/city.h"
#include "city/militarydata.h"
#include "city/walkerdata.h"

#include "figure/figure.h"

#include "game/game.h"

#include "military/legion.h"

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

void exportBuildingData(const Game * game, const QFileInfo & fileInfo)
{
  static std::ofstream output;
  const BuildingData * buildingData = game->city()->buildingData();

  if (!output.is_open()) {
    QString outputFileName = "buildings.csv";
    output.open(outputFileName.toStdString());
    const Building * building = buildingData->get(0);
    output << "ID,File";
    for (int i = 0; i < building->totalFields(); i++) {
      output << ",Unknown" << i+1;
    }
    output << "\n";

  }

  for (int32_t i = 0; i < buildingData->total(); i++) {
    const Building * building = buildingData->get(i);
    output << i+1 << "," << fileInfo.fileName().toStdString();
    for (int32_t j = 0; j < building->totalFields(); j++) {
      output << "," << building->getField(j);
    }
    output << "\n";
  }
}

void exportLegionData(const Game * game, const QFileInfo & fileInfo)
{
  static std::ofstream output;
  const MilitaryData * militaryData = game->city()->militaryData();

  if (!output.is_open()) {
    QString outputFileName = "legions.csv";
    output.open(outputFileName.toStdString());
    const Legion * legion = militaryData->get(0);
    output << "ID,File";
    for (int i = 0; i < legion->totalFields(); i++) {
      output << ",Unknown" << i+1;
    }
    output << "\n";

  }

  for (int32_t i = 0; i < militaryData->total(); i++) {
    const Legion * legion = militaryData->get(i);
    output << i+1 << "," << fileInfo.fileName().toStdString();
    for (int32_t j = 0; j < legion->totalFields(); j++) {
      output << "," << legion->getField(j);
    }
    output << "\n";
  }
}

void exportWalkerData(const Game * game, const QFileInfo & fileInfo)
{
  static std::ofstream output;
  const WalkerData * walkerData = game->city()->walkerData();

  if (!output.is_open()) {
    QString outputFileName = "walkers.csv";
    output.open(outputFileName.toStdString());
    const Figure * walker = walkerData->get(0);
    output << "ID,File";
    for (int i = 0; i < walker->totalFields(); i++) {
      output << ",Unknown" << i+1;
    }
    output << "\n";
  }

  for (int32_t i = 0; i < walkerData->total(); i++) {
    const Figure * walker = walkerData->get(i);
    output << i+1 << "," << fileInfo.fileName().toStdString();
    for (int32_t j = 0; j < walker->totalFields(); j++) {
      output << "," << walker->getField(j);
    }
    output << "\n";
  }
}

#include<QDebug>

int main(int argc, char *argv[])
{
  QString dirName = argv[1];

  QStringList filters;
  filters << "*.sav";

  QDir dir(dirName);
  QFileInfoList list = dir.entryInfoList(filters, QDir::Files);
  for (int i = 0; i < list.size(); i++) {
    QFileInfo fileInfo = list.at(i);
    QString pathName = fileInfo.absoluteFilePath();
    qDebug() << pathName;

    Game game;
    game.loadFromFile(pathName);
    exportWalkerData(&game, fileInfo);
    exportLegionData(&game, fileInfo);
    exportBuildingData(&game, fileInfo);
  }

  return 0;
}
