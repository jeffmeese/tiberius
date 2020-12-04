#include "game.h"

#include "core/streamio.h"

#include "city/city.h"

#include "game/player.h"

#include "map/map.h"

#include "mission/mission.h"

#include <QDir>
#include <QFile>

#include <sstream>
#include <stdexcept>

Game::Game()
  : mCity(new City)
  , mDifficulty(Difficulty::Type::Hard)
  , mMap(new Map)
  , mMission(new Mission)
  , mPlayer(new Player)
{
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
