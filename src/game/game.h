#ifndef GAME_H
#define GAME_H

#include "tiberius.h"
#include "difficulty.h"

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

class City;
class Map;
class Mission;
class Player;

class Game
{
public:
  TIBERIUS_LIB_DECL Game();
  TIBERIUS_LIB_DECL ~Game();

public:
  TIBERIUS_LIB_DECL City * city();
  TIBERIUS_LIB_DECL const City * city() const;
  TIBERIUS_LIB_DECL Mission * mission();
  TIBERIUS_LIB_DECL const Mission * mission() const;
  TIBERIUS_LIB_DECL Player * player();
  TIBERIUS_LIB_DECL const Player * player() const;
  TIBERIUS_LIB_DECL void setMission(std::unique_ptr<Mission> mission);

public:
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  using CityPtr = std::unique_ptr<City>;
  using MapPtr = std::unique_ptr<Map>;
  using MissionPtr = std::unique_ptr<Mission>;
  using PlayerPtr = std::unique_ptr<Player>;

private:
  int32_t mFileVersion;
  int32_t mGameDay;
  int32_t mGameTick;
  int32_t mGameMonth;
  int32_t mGameYear;
  int32_t mTotalGameDays;
  CityPtr mCity;
  Difficulty mDifficulty;
  MapPtr mMap;
  MissionPtr mMission;
  PlayerPtr mPlayer;
};

inline City * Game::city()
{
  return mCity.get();
}

inline const City * Game::city() const
{
  return mCity.get();
}

inline Mission * Game::mission()
{
  return mMission.get();
}

inline const Mission * Game::mission() const
{
  return mMission.get();
}

inline Player * Game::player()
{
  return mPlayer.get();
}

inline const Player * Game::player() const
{
  return mPlayer.get();
}

#endif // GAME_H
