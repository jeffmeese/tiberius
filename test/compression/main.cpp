#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QString>

#include "core/streamio.h"

#include "map/grid.h"
#include "map/map.h"

#include "game/game.h"

#include "zip/pkzipdata.h"

QString createBitString(const QByteArray & byteArray)
{
  QString bitString;
  for (int i = 0; i < byteArray.size(); i++) {
    uint8_t data = byteArray.at(i);
    QString s = QStringLiteral("%1").arg(data, 8, 2, QChar('0'));
    bitString += s;
  }
  return bitString;
}

void writeBytes(const QString & fileName, const QByteArray & byteArray)
{
  std::ofstream file(fileName.toStdString().c_str());

  for (int i = 0; i < byteArray.size(); i++) {
    uint8_t data = byteArray.at(i);
    QString s = QStringLiteral("%1").arg(data, 8, 2, QChar('0'));
    file << s.toStdString() << "\n";
  }
}

void writeArray(QDataStream & dataStream, const QByteArray & array)
{
  std::cout << array.size() << "\n";
  for (int i = 0; i < array.size(); i++) {
    dataStream << (uint8_t)array.at(i);
  }
}

struct DataSet
{
  int sz;
  int compressed;
};

static const DataSet data[] = {
  {8, 0},               // 1 Mission number
  {52488, 1},           // 2 Graphic ID grid (52488 compressed)
  {26244, 1},           // 3 Edge grid  (26244 compressed)
  {52488, 1},           // 4 Building Id grid  (52488 compressed)
  {52488, 1},           // 5 Terrain grid  (52488 compressed)
  {26244, 1},           // 6 Aqueduct grid  (26244 compressed)
  {52488, 1},           // 7 Figure ID grid  (52488 compressed)
  {26244, 1},           // 8 Bitfields grid  (26244 compressed)
  {26244, 1},           // 9 Animation grid  (26244 compressed)
  {26244, 0},           // 10 Merging grid  (26244 uncompressed)
  {26244, 1},           // 11 Desirability Grid  (26244 compressed)
  {26244, 1},           // 12 Elevation grid  (26244 compressed)
  {26244, 1},           // 13 Damage grid  (26244 compressed)
  {26244, 1},           // 14 Aqueduct Grid 2  (26244 compressed)
  {26244, 1},           // 15 Animation Grid 2  (26244 compressed)
  {128000, 1},          // 16 Walker data (128000 compressed)
  {1200, 1},            // 17 Route data  (1200 compressed)
  {300000, 1},          // 18 Route Data  (300000 compressed)
  {6400, 1},            // 19 Formation Data (6400 compressed)
  {12, 0},              // 20 Formation Data (1200 uncompressed)
  {36136, 1},           // 21 City Data (36136 compressed)
  {70, 0},              // 22 Player Name (70 uncompressed)
  {256000, 1},          // 23 Building data (256000 compressed)
  {208, 0},             // 24 Unknown (208 uncompressed)
  {2706, 1},            // 25 Empire Cities (2706 compressed)
  {2188, 0},            // 26 Scenario Data (2188 uncompressed)
  {16000, 1},           // 27 Message data (16000 compressed)
  {206, 0},             // 28 Unknown (206 uncompressed)
  {3232, 1},            // 29 Unknown (3232 compressed)
  {13772, 0},           // 30 Unknown (13772 uncompressed)
  {1000, 1},            // 31 Burning buildings (1000 compressed)
  {1000, 1},            // 32 Unknown (1000 compressed)
  {4000, 1},            // 33 Housing List (4000 compressed)
  {6544, 0},            // 34 Storage Facilities (6544 uncompressed)
  {1280, 1},            // 35 Trade Quotas (1280 compressed)
  {1280, 1},            // 36 Trade Volumes (1280 compressed)
  {1379, 0}             // 37 Unknown (1379 uncompressed)
};

int main(int argc, char ** argv)
{
  QString inputFileName("/data/caesar3/das-tarsus-2.sav");
  QFile inputFile(inputFileName);
  if (!inputFile.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << inputFileName.toStdString();
    return -1;
  }

  QDataStream inputStream(&inputFile);
  inputStream.setByteOrder(QDataStream::LittleEndian);

  // Read the original data
  QByteArray originalData[37];
  for (int i = 0; i < 37; i++) {
    originalData[i] = data[i].compressed ? streamio::readCompressedData(inputStream, data[i].sz) : streamio::readUncompressedData(inputStream, data[i].sz);
  }

  // Compress the data
  PkZipData zipData;
  QByteArray saveData[37];
  for (int i = 0; i < 37; i++) {
    saveData[i] = data[i].compressed ? zipData.compress(originalData[i]) : originalData[i];
    //saveData[i] = originalData[i];
  }

  zipData.decompress(saveData[15]);

  QByteArray compressedData[37];
  for (int i = 0; i < 37; i++) {
    compressedData[i] = data[i].compressed ? zipData.decompress(saveData[i]) : saveData[i];
  }

  // Write output file
//  QString outputFileName("/data/caesar3/das-tarsus-2-unc.sav");
//  QFile outputFile(outputFileName);
//  if (!outputFile.open(QIODevice::WriteOnly)) {
//    std::ostringstream oss;
//    oss << "Could not open file " << outputFileName.toStdString();
//    return -1;
//  }

//  QDataStream outputStream(&outputFile);
//  outputStream.setByteOrder(QDataStream::LittleEndian);
//  for (int i = 0; i < 37; i++) {
//    writeArray(outputStream, saveData[i]);
//  }

  return 0;
}
