#include "game.h"

#include "core/streamio.h"

#include "city/buildingdata.h"
#include "city/camera.h"
#include "city/city.h"
#include "city/educationdata.h"
#include "city/entertainmentdata.h"
#include "city/financedata.h"
#include "city/healthdata.h"
#include "city/imperialdata.h"
#include "city/labordata.h"
#include "city/militarydata.h"
#include "city/populationdata.h"
#include "city/ratingsdata.h"
#include "city/religiondata.h"
#include "city/resourcedata.h"
#include "city/routedata.h"
#include "city/tradedata.h"
#include "city/walkerdata.h"

#include "game/player.h"

#include "map/map.h"

#include "mission/gladiatorrevolt.h"
#include "mission/mission.h"

#include <QDebug>
#include <QDir>
#include <QFile>

#include <sstream>
#include <stdexcept>

Game::Game()
{
  init();
}

Game::~Game()
{

}

void Game::loadFromFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  loadFromStream(dataStream);
}

void Game::loadFromStream(QDataStream &dataStream)
{
  init();

  dataStream.setByteOrder(QDataStream::LittleEndian);

  mMission->setCampaignMission(streamio::readInt32(dataStream));              // 1 General data (4 uncompressed)
  mFileVersion = streamio::readInt32(dataStream);                             // 1 General data  (4 uncompressed)
  mMap->graphicGrid()->loadFromDataStream(dataStream, 52488, true);           // 2 Graphic ID grid (52488 compressed)
  mMap->edgeGrid()->loadFromDataStream(dataStream, 26244, true);              // 3 Edge grid  (26244 compressed)
  mMap->buildingGrid()->loadFromDataStream(dataStream, 52488, true);          // 4 Building Id grid  (52488 compressed)
  mMap->terrainGrid()->loadFromDataStream(dataStream, 52488, true);           // 5 Terrain grid  (52488 compressed)
  mMap->aqueductGrid()->loadFromDataStream(dataStream, 26244, true);          // 6 Aqueduct grid  (26244 compressed)
  mMap->figureGrid()->loadFromDataStream(dataStream, 52488, true);            // 7 Figure ID grid  (52488 compressed)
  mMap->bitfieldsGrid()->loadFromDataStream(dataStream, 26244, true);         // 8 Bitfields grid  (26244 compressed)
  mMap->spriteGrid()->loadFromDataStream(dataStream, 26244, true);            // 9 Animation grid  (26244 compressed)
  mMap->randomGrid()->loadFromDataStream(dataStream, 26244, false);           // 10 Merging grid  (26244 compressed)
  mMap->desirabilityGrid()->loadFromDataStream(dataStream, 26244, true);      // 11 Desirability Grid  (26244 compressed)
  mMap->elevationGrid()->loadFromDataStream(dataStream, 26244, true);         // 12 Elevation grid  (26244 compressed)
  mMap->buildingDamageGrid()->loadFromDataStream(dataStream, 26244, true);    // 13 Damage grid  (26244 compressed)
  mMap->aqueductBackupGrid()->loadFromDataStream(dataStream, 26244, true);    // 14 Aqueduct Grid 2  (26244 compressed)
  mMap->spriteBackupGrid()->loadFromDataStream(dataStream, 26244, true);      // 15 Animation Grid 2  (26244 compressed)
  mCity->walkerData()->loadFromDataStream(dataStream);                        // 16 Walker data (12800 compressed)
  mCity->routeData()->loadFromDataStream(dataStream);                         // 17 & 18 Route data (1200 and 300000 compressed)
  mCity->militaryData()->loadFromDataStream(dataStream);                      // 19 & 20 Formation Data (6400 compressed and 12 uncompressed)
  mCity->loadFromStream(dataStream, mPlayer.get());                           // 21 City Data (36136 compressed)
  mPlayer->loadFromStream(dataStream);                                        // 22 Player name (70 uncompressed)
  mCity->buildingData()->loadFromDataStream(dataStream);                      // 23 Building data (256000 compressed)
  streamio::readUncompressedData(dataStream, 208);                            // 24 Unknown (208 uncompressed)
  streamio::readUncompressedData(dataStream, 2706);                           // 25 Empire Cities (2706 compressed)
  streamio::readUncompressedData(dataStream, 2188);                           // 26 Scenario Data (2188 uncompressed)
  streamio::readCompressedData(dataStream, 16000);                            // 27 Message data (16000 compressed)
  streamio::readUncompressedData(dataStream, 206);                            // 28 Unknown (206 uncompressed)
  streamio::readCompressedData(dataStream, 3232);                             // 29 Unknown (3232 compressed)
  streamio::readUncompressedData(dataStream, 13772);                          // 30 Unknown (13772 uncompressed)
  streamio::readCompressedData(dataStream, 1000);                             // 31 Burning buildings (1000 compressed)
  streamio::readCompressedData(dataStream, 1000);                             // 32 Unknown (1000 compressed)
  streamio::readCompressedData(dataStream, 4000);                             // 33 Housing List (4000 compressed)
  streamio::readUncompressedData(dataStream, 6544);                           // 34 Storage Facilities (6544 uncompressed)
  streamio::readCompressedData(dataStream, 1280);                             // 35 Trade Quotas (1280 compressed)
  streamio::readCompressedData(dataStream, 1280);                             // 36 Trade Volumes (1280 compressed)
  streamio::readUncompressedData(dataStream, 1379);                           // 37 Unknown (1379 uncompressed)
}

void Game::init()
{
  mCity.reset(new City);
  mGladiatorRevolt.reset(new GladiatorRevolt);
  mMap.reset(new Map);
  mMission.reset(new Mission);
  mPlayer.reset(new Player);

  mDifficulty = Difficulty::Type::Hard;
  mEmperorChangeState = 0;
  mGameDay = mGameMonth = mGameTick = mGameYear = mTotalGameDays = 0;
  mMaxGameYear = 0;
  mFileVersion = 0;
  mRandom1 = 0;
  mRandom2 = 0;
}

void Game::readGameTime(QDataStream & dataStream)
{
  mGameTick = streamio::readInt32(dataStream);
  mGameDay = streamio::readInt32(dataStream);
  mGameMonth = streamio::readInt32(dataStream);
  mGameYear = streamio::readInt32(dataStream);
  mTotalGameDays = streamio::readInt32(dataStream);
}

void Game::saveToFile(const QString &fileName, bool compressed) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToStream(dataStream, compressed);
}

void Game::saveToStream(QDataStream &dataStream, bool compressed) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);

  streamio::writeInt32(dataStream, mFileVersion);
  streamio::writeInt32(dataStream, mMission->campaignMission());

  mMap->graphicGrid()->saveToDataStream(dataStream, 52488, compressed);           // 2 Graphic ID grid
  mMap->edgeGrid()->saveToDataStream(dataStream, 26244, compressed);              // 3 Edge grid
  mMap->buildingGrid()->saveToDataStream(dataStream, 52488, compressed);          // 4 Building Id grid
  mMap->terrainGrid()->saveToDataStream(dataStream, 52488, compressed);           // 5 Terrain grid
  mMap->aqueductGrid()->saveToDataStream(dataStream, 26244, compressed);          // 6 Aqueduct grid
  mMap->figureGrid()->saveToDataStream(dataStream, 52488, compressed);            // 7 Figure ID grid
  mMap->bitfieldsGrid()->saveToDataStream(dataStream, 26244, compressed);         // 8 Bitfields grid
  mMap->spriteGrid()->saveToDataStream(dataStream, 26244, compressed);            // 9 Animation grid
  mMap->randomGrid()->saveToDataStream(dataStream, 26244, false);                 // 10 Merging grid
  mMap->desirabilityGrid()->saveToDataStream(dataStream, 26244, compressed);      // 11 Desirability Grid
  mMap->elevationGrid()->saveToDataStream(dataStream, 26244, compressed);         // 12 Elevation grid
  mMap->buildingDamageGrid()->saveToDataStream(dataStream, 26244, compressed);    // 13 Damage grid
  mMap->aqueductBackupGrid()->saveToDataStream(dataStream, 26244, compressed);    // 14 Aqueduct Grid 2
  mMap->spriteBackupGrid()->saveToDataStream(dataStream, 26244, compressed);      // 15 Animation Grid 2
  mCity->walkerData()->saveToDataStream(dataStream);                              // 16 Walker data (12800 compressed)
  mCity->routeData()->saveToDataStream(dataStream, compressed);                   // 17 & 18 Route data (1200 and 300000 compressed)
  mCity->militaryData()->saveToDataStream(dataStream, compressed);                // 19&20 Formation Data
  mCity->saveToStream(dataStream);                                                // 21 City Data
  mPlayer->saveToStream(dataStream);                                              // 22 Player name (70 uncompressed)
}
