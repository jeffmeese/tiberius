#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "application.h"

#include "game/game.h"
#include "map/grid.h"
#include "map/map.h"
#include "mission/mission.h"

#include <QFileDialog>
#include <QItemSelectionModel>

MainWindow::MainWindow(Application & application, QWidget *parent)
  : QMainWindow(parent)
  , mUi(new Ui::MainWindow)
  , mApplication(application)
  , mModel(new QStandardItemModel)
{
  mUi->setupUi(this);

  mMissionItem = new QStandardItem("Missions");
  mModel->appendRow(mMissionItem);

  mGameItem = new QStandardItem("Games");
  mModel->appendRow(mGameItem);

  mUi->cDataView->setModel(mModel);

  QItemSelectionModel * selectionModel = mUi->cDataView->selectionModel();
  connect(mUi->actionLoad_Mission, SIGNAL(triggered()), SLOT(handleLoadMission()));
  connect(mUi->actionLoad_Game, SIGNAL(triggered()), SLOT(handleLoadGame()));
  connect(mUi->actionExit, SIGNAL(triggered()), SLOT(handleExit()));
  connect(selectionModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), SLOT(handleSelectionChanged()));
}

MainWindow::~MainWindow()
{
  delete mUi;
  delete mModel;
}

QStandardItem * MainWindow::createFileItem(QStandardItem * parentItem, const QString & text, Type type)
{
  QStandardItem * fileItem = new QStandardItem(text);
  fileItem->setData(type);

  QStandardItem * graphicItem = new QStandardItem("Graphic");
  graphicItem->setData(GraphicGrid);
  fileItem->appendRow(graphicItem);

  QStandardItem * edgeItem = new QStandardItem("Edge");
  edgeItem->setData(EdgeGrid);
  fileItem->appendRow(edgeItem);

  QStandardItem * terrainItem = new QStandardItem("Terrain");
  terrainItem->setData(TerrainGrid);
  fileItem->appendRow(terrainItem);

  QStandardItem * randomTerrainItem = new QStandardItem("TerrainRandom");
  randomTerrainItem->setData(RandomTerrainGrid);
  fileItem->appendRow(randomTerrainItem);

  QStandardItem * randomItem = new QStandardItem("Random");
  randomItem->setData(RandomGrid);
  fileItem->appendRow(randomItem);

  QStandardItem * elevationItem = new QStandardItem("Elevation");
  elevationItem->setData(ElevationGrid);
  fileItem->appendRow(elevationItem);

  parentItem->appendRow(fileItem);

  return fileItem;
}

void MainWindow::handleExit()
{
  QApplication::quit();
}

void MainWindow::handleLoadGame()
{
  QString caption("Open File");
  QString dirName(QDir::currentPath());
  QString filters("Game files (*.sav)");

  QString fileName = QFileDialog::getOpenFileName(this, caption, dirName, filters);
  if (fileName.isEmpty())
    return;

  loadGame(fileName);
}

void MainWindow::handleLoadMission()
{
  QString caption("Open File");
  QString dirName(QDir::currentPath());
  QString filters("Mission files (*.map)");

  QString fileName = QFileDialog::getOpenFileName(this, caption, dirName, filters);
  if (fileName.isEmpty())
    return;

  loadMission(fileName);
}

void MainWindow::handleSelectionChanged()
{
  QModelIndexList selectedIndex = mUi->cDataView->selectionModel()->selectedIndexes();
  if (selectedIndex.size() != 1) {
    return;
  }

  QModelIndex index = selectedIndex.at(0);
  QStandardItem * item = mModel->itemFromIndex(index);
  MissionMap::iterator missionItr = mMissionMap.find(item);
  if (missionItr != mMissionMap.end()) {
    const Mission * mission = missionItr->second;
    int data = item->data().toInt();
    GridType gridType = GridType(data);
    if (gridType == GraphicGrid) {
      mUi->cGridView->displayGraphicGrid(mission->graphicGrid());
    }
    else if (gridType == EdgeGrid) {
      mUi->cGridView->displayEdgeGrid(mission->edgeGrid());
    }
    else if (gridType == TerrainGrid) {
      mUi->cGridView->displayTerrainGrid(mission->graphicGrid());
    }
    else if (gridType == RandomTerrainGrid) {
      mUi->cGridView->displayRandomTerrainGrid(mission->terrainRandomGrid());
    }
    else if (gridType == RandomGrid) {
      mUi->cGridView->displayRandomGrid(mission->randomGrid());
    }
    else if (gridType == ElevationGrid) {
      mUi->cGridView->displayElevationGrid(mission->elevationGrid());
    }
  }

  GameMap::iterator gameItr = mGameMap.find(item);
  if (gameItr != mGameMap.end()) {
    const Game * game = gameItr->second;
    GridType gridType = GridType(item->data().toInt());

    if (gridType == GraphicGrid) {
       mUi->cGridView->displayGraphicGrid(game->map()->graphicGrid());
    }
    else if (gridType == EdgeGrid) {
      mUi->cGridView->displayEdgeGrid(game->map()->edgeGrid());
    }
    else if (gridType == TerrainGrid) {
      mUi->cGridView->displayTerrainGrid(game->map()->terrainGrid());
    }
    else if (gridType == RandomTerrainGrid) {
      mUi->cGridView->displayRandomTerrainGrid(game->map()->terrainRandomGrid());
    }
    else if (gridType == RandomGrid) {
      mUi->cGridView->displayRandomGrid(game->map()->randomGrid());
    }
    else if (gridType == ElevationGrid) {
      mUi->cGridView->displayElevationGrid(game->map()->elevationGrid());
    }
  }
}

void MainWindow::loadGame(const QString & fileName)
{
  std::unique_ptr<Game> game(new Game);
  game->loadFromFile(fileName);

  QFileInfo fileInfo(fileName);
  QStandardItem * item = createFileItem(mGameItem, fileInfo.fileName(), GameItem);
  for (int i = 0; i < item->rowCount(); i++) {
    QStandardItem * childItem = item->child(i);
    mGameMap[childItem] = game.get();
  }
  mGameVector.push_back(std::move(game));
}

void MainWindow::loadMission(const QString & fileName)
{
  std::unique_ptr<Mission> mission(new Mission);
  mission->loadFromFile(fileName);

  QFileInfo fileInfo(fileName);
  QStandardItem * item = createFileItem(mMissionItem, fileInfo.fileName(), MissionItem);
  for (int i = 0; i < item->rowCount(); i++) {
    QStandardItem * childItem = item->child(i);
    mMissionMap[childItem] = mission.get();
  }
  mMissionVector.push_back(std::move(mission));
}
