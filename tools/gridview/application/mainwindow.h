#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>

#include <map>
#include <memory>
#include <vector>

#include "map/grid.h"

class Application;
class Game;
class Mission;
namespace Ui
{
  class MainWindow;
}

class MainWindow
    : public QMainWindow
{
  Q_OBJECT

private:
  enum Type
  {
    MissionItem = 0,
    GameItem = 1,
  };

  enum GridType
  {
    GraphicGrid = 0,
    EdgeGrid = 1,
    TerrainGrid = 2,
    RandomTerrainGrid = 3,
    RandomGrid = 4,
    ElevationGrid = 5
  };

public:
  MainWindow(Application & application, QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void handleExit();
  void handleLoadGame();
  void handleLoadMission();
  void handleSelectionChanged();

private:
  QStandardItem * createFileItem(QStandardItem * parent, const QString & text, Type type);
  void loadGame(const QString & fileName);
  void loadMission(const QString & fileName);

private:
  using GamePtr = std::unique_ptr<Game>;
  using GameVector = std::vector<GamePtr>;
  using GameMap = std::map<QStandardItem*, Game*>;
  using MissionPtr = std::unique_ptr<Mission>;
  using MissionVector = std::vector<MissionPtr>;
  using MissionMap = std::map<QStandardItem*, Mission*>;

private:
  Ui::MainWindow * mUi;
  Application & mApplication;
  QStandardItemModel * mModel;
  QStandardItem * mMissionItem;
  QStandardItem * mGameItem;
  GameMap mGameMap;
  GameVector mGameVector;
  MissionMap mMissionMap;
  MissionVector mMissionVector;
};

#endif
