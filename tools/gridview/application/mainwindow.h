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
class Scenario;
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
    BuildingGrid = 2,
    TerrainGrid = 3,
    AqueductGrid = 4,
    WalkerGrid = 5,
    BitfieldGrid = 6,
    AnimationGrid = 7,
    MergingGrid = 8,
    DesirabilityGrid = 9,
    ElevationGrid = 10,
    DamageGrid = 11,
    BackupAqueductGrid = 12,
    BackpuAnimationGrid = 13
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
  using MissionPtr = std::unique_ptr<Scenario>;
  using MissionVector = std::vector<MissionPtr>;
  using MissionMap = std::map<QStandardItem*, Scenario*>;

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
