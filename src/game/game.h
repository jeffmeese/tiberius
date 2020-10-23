#ifndef GAME_H
#define GAME_H

#include "tiberius.h"
#include "difficulty.h"

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

class Building;
class Empire;
class Formation;
class Map;
class Mission;
class Resource;

class Game
{
public:
  TIBERIUS_LIB_DECL Game();
  TIBERIUS_LIB_DECL ~Game();

public:
  TIBERIUS_LIB_DECL Mission * mission();
  TIBERIUS_LIB_DECL const Mission * mission() const;
  TIBERIUS_LIB_DECL void setMission(std::unique_ptr<Mission> mission);

public:
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

public:
  static const int MAX_BUILDINGS = 2000;
  static const int MAX_CHARACTERS = 10000;
  static const int MAX_FORMATIONS = 50;
  static const int MAX_LEGIONS = 6;

private:
  //using BuildingPtr = std::unique_ptr<Building>;
  using MapPtr = std::unique_ptr<Map>;
  using MissionPtr = std::unique_ptr<Mission>;

private:
  int32_t mFileVersion;
  int32_t mGameDay;
  int32_t mGameTick;
  int32_t mGameMonth;
  int32_t mGameYear;
  int32_t mTotalGameDays;
  Difficulty mDifficulty;
  MapPtr mMap;
  MissionPtr mMission;
};

inline Mission * Game::mission()
{
  return mMission.get();
}

inline const Mission * Game::mission() const
{
  return mMission.get();
}

#endif // GAME_H
