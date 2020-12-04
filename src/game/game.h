#ifndef GAME_H
#define GAME_H

#include "tiberius.h"
#include "difficulty.h"

#include <QDataStream>
#include <QString>

#include <memory>
#include <vector>

class City;
class GladiatorRevolt;
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
  TIBERIUS_LIB_DECL GladiatorRevolt * gladiatorRevolt();
  TIBERIUS_LIB_DECL const GladiatorRevolt * gladiatorRevolt() const;
  TIBERIUS_LIB_DECL Map * map();
  TIBERIUS_LIB_DECL const Map * map() const;
  TIBERIUS_LIB_DECL Mission * mission();
  TIBERIUS_LIB_DECL const Mission * mission() const;
  TIBERIUS_LIB_DECL Player * player();
  TIBERIUS_LIB_DECL const Player * player() const;

public:
  TIBERIUS_LIB_DECL void loadFromFile(const QString & fileName);
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToFile(const QString & fileName) const;
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  void readGameTime(QDataStream & dataStream);
  void readPlayerName(QDataStream & dataStream);

private:
  using CityPtr = std::unique_ptr<City>;
  using GladiatorRevoltPtr = std::unique_ptr<GladiatorRevolt>;
  using MapPtr = std::unique_ptr<Map>;
  using MissionPtr = std::unique_ptr<Mission>;
  using PlayerPtr = std::unique_ptr<Player>;

private:
  int32_t mEmperorChangeState;
  int32_t mFileVersion;
  int32_t mGameDay;
  int32_t mGameTick;
  int32_t mGameMonth;
  int32_t mGameYear;
  int32_t mMaxGameYear;
  int32_t mTotalGameDays;
  CityPtr mCity;
  GladiatorRevoltPtr mGladiatorRevolt;
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

inline GladiatorRevolt * Game::gladiatorRevolt()
{
  return mGladiatorRevolt.get();
}

inline const GladiatorRevolt * Game::gladiatorRevolt() const
{
  return mGladiatorRevolt.get();
}

inline Map * Game::map()
{
  return mMap.get();
}

inline const Map * Game::map() const
{
  return mMap.get();
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
