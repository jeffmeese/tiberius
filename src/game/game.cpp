#include "game.h"

#include "core/streamio.h"

#include "city/buildingdata.h"
#include "city/camera.h"
#include "city/city.h"
#include "city/educationdata.h"
#include "city/entertainmentdata.h"
#include "city/figuredata.h"
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

#include "game/player.h"

#include "map/map.h"

#include "mission/gladiatorrevolt.h"
#include "mission/mission.h"

#include <QDir>
#include <QFile>

#include <sstream>
#include <stdexcept>

Game::Game()
  : mCity(new City)
  , mGladiatorRevolt(new GladiatorRevolt)
  , mDifficulty(Difficulty::Type::Hard)
  , mMap(new Map)
  , mMission(new Mission)
  , mPlayer(new Player)
{
  mEmperorChangeState = 0;
  mGameDay = mGameMonth = mGameTick = mGameYear = mTotalGameDays = 0;
  mMaxGameYear = 0;
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
  dataStream.setByteOrder(QDataStream::LittleEndian);

  mMission.reset(new Mission);
  mFileVersion = streamio::readInt32(dataStream);
  mMission->setCampaignMission(streamio::readInt32(dataStream));

  // Read grids
  mMap->graphicGrid()->loadFromDataStream(dataStream, 52488, true);
  mMap->edgeGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->buildingGrid()->loadFromDataStream(dataStream, 52488, true);
  mMap->terrainGrid()->loadFromDataStream(dataStream, 52488, true);
  mMap->aqueductGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->figureGrid()->loadFromDataStream(dataStream, 52488, true);
  mMap->bitfieldsGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->spriteGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->randomGrid()->loadFromDataStream(dataStream, 26244, false);
  mMap->desirabilityGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->elevationGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->buildingDamageGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->aqueductBackupGrid()->loadFromDataStream(dataStream, 26244, true);
  mMap->spriteBackupGrid()->loadFromDataStream(dataStream, 26244, true);
  mCity->figureData()->loadFromDataStream(dataStream);
  mCity->routeData()->loadFromDataStream(dataStream);
  mCity->militaryData()->loadFromDataStream(dataStream);
  streamio::readCompressedData(dataStream, 36136); // City data
  dataStream.skipRawData(2); // Unknown
  readPlayerName(dataStream);
  dataStream.skipRawData(4); // City faction
  mCity->buildingData()->loadFromDataStream(dataStream);
  mCity->setOrientation(City::Orientation(streamio::readInt32(dataStream)));
  readGameTime(dataStream);
  dataStream.skipRawData(8); // Building highest id
  dataStream.skipRawData(8); // Random IV
  mCity->camera()->loadFromDataStream(dataStream);
  dataStream.skipRawData(132); // Culture count
  dataStream.skipRawData(8); // Graph order
  dataStream.skipRawData(8); // Emperor change time
  dataStream.skipRawData(12); // Empire
  streamio::readCompressedData(dataStream, 2706); // Empire cities
  dataStream.skipRawData(128); // Industry count
  dataStream.skipRawData(128); // Trade prices
  dataStream.skipRawData(84); // Figure names
  dataStream.skipRawData(60); // Culture coverage
  dataStream.skipRawData(1720); // Mission data
  mMaxGameYear = streamio::readInt32(dataStream);
  dataStream.skipRawData(60); // Earthquake data
  mEmperorChangeState = streamio::readInt32(dataStream);
  streamio::readCompressedData(dataStream, 16000); // Message data
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
  dataStream.skipRawData(284); // End marker (71 4-byte entries)
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
  char playerName[32];
  dataStream.skipRawData(32);
  dataStream.readRawData(playerName, 32);
  mPlayer->setName(playerName);
}

void Game::saveToFile(const QString &fileName) const
{
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly)) {
    std::ostringstream oss;
    oss << "Could not open file " << fileName.toStdString();
    throw std::invalid_argument(oss.str());
  }

  QDataStream dataStream(&file);
  saveToStream(dataStream);
}

void Game::saveToStream(QDataStream &dataStream) const
{
  dataStream.setByteOrder(QDataStream::LittleEndian);
}
