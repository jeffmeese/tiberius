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

struct DataSet
{
  int sz;
  int compressed;
};

static const DataSet gameData[] = {
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

void testByteStream(char * fileName);

int main(int argc, char ** argv)
{
  if (argc < 2) {
    std::cout << "Usage: test_compression <save-file-name> [output-file-name]\n";
    return -1;
  }

  PkZipData zipData;
  QString inputFileName(argv[1]);
  QFile inputFile(inputFileName);
  if (!inputFile.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << inputFileName.toStdString();
    std::cerr << oss.str() << "\n";
    return -1;
  }

  QDataStream inputStream(&inputFile);
  inputStream.setByteOrder(QDataStream::LittleEndian);

  // Decompress the original data
  std::cout << "Decompress original\n";
  QByteArray origDecompData[37];
  for (int i = 0; i < 37; i++) {
    origDecompData[i] = gameData[i].compressed ? streamio::readCompressedData(inputStream, gameData[i].sz) : streamio::readUncompressedData(inputStream, gameData[i].sz);
  }

  // Compress the data using our algorithm
  std::cout << "Compress\n";
  QByteArray compData[37];
  for (int i = 0; i < 37; i++) {
    compData[i] = gameData[i].compressed ? zipData.compress(origDecompData[i]) : origDecompData[i];
  }

  // Decompress the newly compressed data
  std::cout << "Decompress new\n";
  QByteArray newDecompData[37];
  for (int i = 0; i < 37; i++) {
    newDecompData[i] = gameData[i].compressed ? zipData.decompress(compData[i]) : compData[i];
  }

  // Check that the original decompressed data is equal to the newly compressed data
  for (int i = 0; i < 37; i++) {
    if (newDecompData[i].size() != origDecompData[i].size()) {
      std::cerr << "Sizes do not match for section " << i + 1 << "\n";
      std::cerr << "Original Size : " << origDecompData[i].size() << "\n";
      std::cerr << "New Size      : " << newDecompData[i].size() << "\n";
      return -1;
    }
    for (int j = 0; j < newDecompData[i].size(); j++) {
      if (origDecompData[i][j] != newDecompData[i][j]) {
        std::cerr << "Byte Mismatch for section : " << i+1 << " at byte " << j+1 << "\n";
        std::cerr << "Original Data             : " << (int)origDecompData[i][j] << "\n";
        std::cerr << "New Data                  : " << (int)newDecompData[i][j] << "\n";
        return -1;
      }
    }
  }
  std::cout << "Compression/Decompress Tests Passed\n";

  // Write an output file if desired
  if (argc > 2) {
    QString outputFileName(argv[2]);
    QFile outputFile(outputFileName);
    if (!outputFile.open(QIODevice::WriteOnly)) {
      std::ostringstream oss;
      oss << "Could not open file " << outputFileName.toStdString();
      std::cerr << oss.str() << "\n";
      return -1;
    }

    QDataStream outputStream(&outputFile);
    outputStream.setByteOrder(QDataStream::LittleEndian);

    for (int i = 0; i < 37; i++) {
      if (gameData[i].compressed) {
        int32_t dataSize = compData[i].size();
        outputStream << dataSize;
      }
      outputStream.device()->write(compData[i]);
    }
  }

  return 0;
}

void testByteStream(char * fileName)
{
  PkZipData zip;

  QFile inputFile(fileName);
  if (!inputFile.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName;
    std::cerr << oss.str() << "\n";
  }

  QDataStream inputStream(&inputFile);
  inputStream.setByteOrder(QDataStream::LittleEndian);

  // Decompress the original data
  inputStream.skipRawData(8);
  QByteArray byteArray = streamio::readCompressedData(inputStream, 52488);
  byteArray = byteArray.mid(0, 52488);
  for (int i = 0; i < byteArray.size(); i++) {
  }

  qDebug() << "Compress";
  QByteArray compressed = zip.compress(byteArray, 0, 6);
  qDebug() << "Decompress";
  QByteArray decompressed = zip.decompress(compressed);
  qDebug() << byteArray.size() << " " << compressed.size() << "\n";
  qDebug() << byteArray.size() << " " << decompressed.size() << "\n";

  if (byteArray.size() == decompressed.size()) {
    for (int j = 0; j < decompressed.size(); j++) {
      if (byteArray[j] != decompressed[j]) {
        std::cerr << "Byte Mismatch at byte : " << j+1 << " (" << (int)byteArray[j] << "," << (int)decompressed[j]<< ")\n";
      }
    }
    std::cout << "Test Passed\n";
  }

}
