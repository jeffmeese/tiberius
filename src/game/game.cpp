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

  mFileVersion = streamio::readInt32(dataStream);                             // 1 General data
  mMission->setCampaignMission(streamio::readInt32(dataStream));              // 1 General data
  mMap->graphicGrid()->loadFromDataStream(dataStream, 52488, true);           // 2 Graphic ID grid
  mMap->edgeGrid()->loadFromDataStream(dataStream, 26244, true);              // 3 Edge grid
  mMap->buildingGrid()->loadFromDataStream(dataStream, 52488, true);          // 4 Building Id grid
  mMap->terrainGrid()->loadFromDataStream(dataStream, 52488, true);           // 5 Terrain grid
  mMap->aqueductGrid()->loadFromDataStream(dataStream, 26244, true);          // 6 Aqueduct grid
  mMap->figureGrid()->loadFromDataStream(dataStream, 52488, true);            // 7 Figure ID grid
  mMap->bitfieldsGrid()->loadFromDataStream(dataStream, 26244, true);         // 8 Bitfields grid
  mMap->spriteGrid()->loadFromDataStream(dataStream, 26244, true);            // 9 Animation grid
  mMap->randomGrid()->loadFromDataStream(dataStream, 26244, false);           // 10 Merging grid
  mMap->desirabilityGrid()->loadFromDataStream(dataStream, 26244, true);      // 11 Desirability Grid
  mMap->elevationGrid()->loadFromDataStream(dataStream, 26244, true);         // 12 Elevation grid
  mMap->buildingDamageGrid()->loadFromDataStream(dataStream, 26244, true);    // 13 Damage grid
  mMap->aqueductBackupGrid()->loadFromDataStream(dataStream, 26244, true);    // 14 Aqueduct Grid 2
  mMap->spriteBackupGrid()->loadFromDataStream(dataStream, 26244, true);      // 15 Animation Grid 2
  mCity->walkerData()->loadFromDataStream(dataStream);                        // 16 Walker data (12800 compressed)

  mCity->routeData()->loadFromDataStream(dataStream);                         // 17 & 18 Route data (1200 and 300000 compressed)
  mCity->militaryData()->loadFromDataStream(dataStream);                      // 19&20 Formation Data
  streamio::readCompressedData(dataStream, 36136);                            // 21 Unknown
  //readPlayerName(dataStream);                                                 // 22 Player name (70 uncompressed)
  dataStream.skipRawData(70);
  mCity->buildingData()->loadFromDataStream(dataStream);                      // 23 Building data

  //streamio::readCompressedData(dataStream, 6400);
  //mCity->figureData()->loadFromDataStream(dataStream);
  //mCity->routeData()->loadFromDataStream(dataStream);                         // 17&18 Destination walkers and paths
  //mCity->militaryData()->loadFromDataStream(dataStream);                      // 19 Formation Data
  //dataStream.skipRawData(12);                                                 // 20 Unknown

  return;



//
//  readPlayerName(dataStream);                                                 // 22 Governor name
//  mCity->buildingData()->loadFromDataStream(dataStream);                      // 23 Building data
//  dataStream.skipRawData(208);                                                // 24 Unknown
//  streamio::readCompressedData(dataStream, 2706);                             // 25 Empire cities
//  dataStream.skipRawData(2188);                                               // 26 Scenario settings
//  streamio::readCompressedData(dataStream, 16000);                            // 27 Message data
//  dataStream.skipRawData(206);                                                // 28 Unknown
//  streamio::readCompressedData(dataStream, 3232);                             // 29 Unknown
//  dataStream.skipRawData(13772);                                              // 30 Unknown
//  streamio::readCompressedData(dataStream, 1000);                             // 31 Burning buildings
//  streamio::readCompressedData(dataStream, 1000);                             // 32 Unknown
//  streamio::readCompressedData(dataStream, 4000);                             // 33 Housing list
//  dataStream.skipRawData(6544);                                               // 34 Storage facilities
//  streamio::readCompressedData(dataStream, 1280);                             // 35 Trade quotas
//  streamio::readCompressedData(dataStream, 1280);                             // 36 Trade volumes
//  dataStream.skipRawData(1379);                                               // 37 Unknown

  //dataStream.skipRawData(2);
  //dataStream.skipRawData(4);
//  mCity->setOrientation(City::Orientation(streamio::readInt32(dataStream)));  // 24
//  readGameTime(dataStream);                                                   // 24
//  mCity->buildingData()->setHighestIdInUse(streamio::readInt32(dataStream));  // 24
//  mCity->buildingData()->setHighestIdUsed(streamio::readInt32(dataStream));   // 24
//  mRandom1 = streamio::readUInt32(dataStream);                                // 24
//  mRandom2 = streamio::readUInt32(dataStream);                                // 24
//  mCity->camera()->loadFromDataStream(dataStream);                            // 24
//  dataStream.skipRawData(132); // Culture count                               // 24
//  dataStream.skipRawData(8); // Graph order                                   // 24
//  dataStream.skipRawData(8); // Emperor change time                           // 24
//  dataStream.skipRawData(12); // Empire                                       // 24

  /*dataStream.skipRawData(128); // Industry count
  dataStream.skipRawData(128); // Trade prices
  dataStream.skipRawData(84); // Figure names
  dataStream.skipRawData(60); // Culture coverage
  dataStream.skipRawData(1720); // Mission data
  mMaxGameYear = streamio::readInt32(dataStream);
  dataStream.skipRawData(60); // Earthquake data
  mEmperorChangeState = streamio::readInt32(dataStream);

  dataStream.skipRawData(12); // Message extra data
  dataStream.skipRawData(10); // Population messages
  dataStream.skipRawData(80); // Message counts
  dataStream.skipRawData(80); // Message delays
  dataStream.skipRawData(8); // Total burning buildings
  dataStream.skipRawData(4); // Figure sequence
  dataStream.skipRawData(12); // Scenario settings
  streamio::readCompressedData(dataStream, 3232); // Invasion warnings
  dataStream.skipRawData(4); // Custom scenario
  dataStream.skipRawData(8960); // City sounds
  dataStream.skipRawData(4); // Building extra highest ID
  dataStream.skipRawData(4804); // Trader figures
  streamio::readCompressedData(dataStream, 1000); // Building burnings
  streamio::readCompressedData(dataStream, 1000); // Small Building burnings
  streamio::readCompressedData(dataStream, 1000); // Large Building burnings
  dataStream.skipRawData(32); // Tutorial 1
  dataStream.skipRawData(16); // Military building count
  dataStream.skipRawData(20); // Enemy army totals
  dataStream.skipRawData(6400); // Building storage
  dataStream.skipRawData(32); // Culture count 2
  dataStream.skipRawData(24); // Count support
  dataStream.skipRawData(4); // Tutorial 2
  mGladiatorRevolt->loadFromDataStream(dataStream);
  //dataStream.skipRawData(16); // Gladiator revolt
  streamio::readCompressedData(dataStream, 1280); // Trade route limit
  streamio::readCompressedData(dataStream, 1280); // Trade route traded
  dataStream.skipRawData(4); // Barracks sentry
  dataStream.skipRawData(4); // Building extra
  dataStream.skipRawData(16); // Routing counters
  dataStream.skipRawData(40); // Culture count 3
  dataStream.skipRawData(900); // Enemy armies
  dataStream.skipRawData(16); // Entry/Exit locations
  dataStream.skipRawData(2); // Last invasion ID
  dataStream.skipRawData(8); // corrupt houses
  dataStream.skipRawData(65); // scenario name
  dataStream.skipRawData(32); // bookmarks
  dataStream.skipRawData(4); // Tutorial 3
  dataStream.skipRawData(8); // Entry exit grid offset
  dataStream.skipRawData(284); // End marker (71 4-byte entries)*/
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
}

void Game::readGameTime(QDataStream & dataStream)
{
  mGameTick = streamio::readInt32(dataStream);
  mGameDay = streamio::readInt32(dataStream);
  mGameMonth = streamio::readInt32(dataStream);
  mGameYear = streamio::readInt32(dataStream);
  mTotalGameDays = streamio::readInt32(dataStream);
}

void Game::readPlayerName(QDataStream & dataStream)
{
  for (int32_t i = 0; i < 70; i++) {
    int8_t value = streamio::readInt8(dataStream);
    //qDebug() << value;

//    char playerName[32];
//    dataStream.skipRawData(32);
//    dataStream.readRawData(playerName, 32);
//    mPlayer->setName(playerName);
  }
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
//  mMap->edgeGrid()->saveToDataStream(dataStream, 26244, compressed);              // 3 Edge grid
//  mMap->buildingGrid()->saveToDataStream(dataStream, 52488, compressed);          // 4 Building Id grid
//  mMap->terrainGrid()->saveToDataStream(dataStream, 52488, compressed);           // 5 Terrain grid
//  mMap->aqueductGrid()->saveToDataStream(dataStream, 26244, compressed);          // 6 Aqueduct grid
//  mMap->figureGrid()->saveToDataStream(dataStream, 52488, compressed);            // 7 Figure ID grid
//  mMap->bitfieldsGrid()->saveToDataStream(dataStream, 26244, compressed);         // 8 Bitfields grid
//  mMap->spriteGrid()->saveToDataStream(dataStream, 26244, compressed);            // 9 Animation grid
//  mMap->randomGrid()->saveToDataStream(dataStream, 26244, false);                 // 10 Merging grid
//  mMap->desirabilityGrid()->saveToDataStream(dataStream, 26244, compressed);      // 11 Desirability Grid
//  mMap->elevationGrid()->saveToDataStream(dataStream, 26244, compressed);         // 12 Elevation grid
//  mMap->buildingDamageGrid()->saveToDataStream(dataStream, 26244, compressed);    // 13 Damage grid
//  mMap->aqueductBackupGrid()->saveToDataStream(dataStream, 26244, compressed);    // 14 Aqueduct Grid 2
//  mMap->spriteBackupGrid()->saveToDataStream(dataStream, 26244, compressed);      // 15 Animation Grid 2

//  mCity->walkerData()->saveToDataStream(dataStream, compressed);                        // 16 Walker data (12800 compressed)
//  mCity->routeData()->saveToDataStream(dataStream, compressed);                         // 17 & 18 Route data (1200 and 300000 compressed)
//  mCity->militaryData()->saveToDataStream(dataStream, compressed);                      // 19&20 Formation Data
//  streamio::readCompressedData(dataStream, 36136);                            // 21 Unknown
//  writePlayerName(dataStream);                                                 // 22 Player name (70 uncompressed)
}

void Game::writePlayerName(QDataStream & dataStream) const
{

}
