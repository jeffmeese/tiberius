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

  if (type == GameItem) {
    QStandardItem * animationGrid = new QStandardItem("Animation");
    animationGrid->setData(AnimationGrid);
    fileItem->appendRow(animationGrid);
  }

  if (type == GameItem) {
    QStandardItem * aqueductItem = new QStandardItem("Aqueduct");
    aqueductItem->setData(AqueductGrid);
    fileItem->appendRow(aqueductItem);
  }

  if (type == GameItem) {
    QStandardItem * backupAnimationItem = new QStandardItem("Backup Animation");
    backupAnimationItem->setData(BackpuAnimationGrid);
    fileItem->appendRow(backupAnimationItem);
  }

  if (type == GameItem) {
    QStandardItem * backupAqueductItem = new QStandardItem("Backup Aqueduct");
    backupAqueductItem->setData(BackupAqueductGrid);
    fileItem->appendRow(backupAqueductItem);
  }

  if (type == GameItem) {
    QStandardItem * bitfieldItem = new QStandardItem("Bitfields");
    bitfieldItem->setData(BitfieldGrid);
    fileItem->appendRow(bitfieldItem);
  }

  if (type == GameItem) {
    QStandardItem * buildingItem = new QStandardItem("Building");
    buildingItem->setData(BuildingGrid);
    fileItem->appendRow(buildingItem);
  }

  if (type == GameItem) {
    QStandardItem * damageGrid = new QStandardItem("Damage");
    damageGrid->setData(DamageGrid);
    fileItem->appendRow(damageGrid);
  }

  if (type == GameItem) {
    QStandardItem * desirabilityItem = new QStandardItem("Desirability");
    desirabilityItem->setData(DesirabilityGrid);
    fileItem->appendRow(desirabilityItem);
  }

  QStandardItem * edgeItem = new QStandardItem("Edge");
  edgeItem->setData(EdgeGrid);
  fileItem->appendRow(edgeItem);

  QStandardItem * elevationItem = new QStandardItem("Elevation");
  elevationItem->setData(ElevationGrid);
  fileItem->appendRow(elevationItem);

  QStandardItem * graphicItem = new QStandardItem("Graphic");
  graphicItem->setData(GraphicGrid);
  fileItem->appendRow(graphicItem);

  QStandardItem * mergingGrid = new QStandardItem("Merging");
  mergingGrid->setData(MergingGrid);
  fileItem->appendRow(mergingGrid);

  if (type == GameItem) {
    QStandardItem * walkerItem = new QStandardItem("Walkers");
    walkerItem->setData(WalkerGrid);
    fileItem->appendRow(walkerItem);
  }

  QStandardItem * terrainItem = new QStandardItem("Terrain");
  terrainItem->setData(TerrainGrid);
  fileItem->appendRow(terrainItem);

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
    else if (gridType == MergingGrid) {
      mUi->cGridView->displayMergingGrid(mission->randomGrid());
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
    else if (gridType == BuildingGrid) {
      mUi->cGridView->displayBuildingGrid(game->map()->buildingGrid());
    }
    else if (gridType == TerrainGrid) {
      mUi->cGridView->displayTerrainGrid(game->map()->terrainGrid());
    }
    else if (gridType == AqueductGrid) {
      mUi->cGridView->displayAqueductGrid(game->map()->aqueductGrid());
    }
    else if (gridType == WalkerGrid) {
      mUi->cGridView->displayWalkerGrid(game->map()->figureGrid());
    }
    else if (gridType == BitfieldGrid) {
      mUi->cGridView->displayBitfieldGrid(game->map()->bitfieldsGrid());
    }
    else if (gridType == AnimationGrid) {
      mUi->cGridView->displayAnimationGrid(game->map()->spriteGrid());
    }
    else if (gridType == MergingGrid) {
      mUi->cGridView->displayMergingGrid(game->map()->randomGrid());
    }
    else if (gridType == DesirabilityGrid) {
      mUi->cGridView->displayDesirabilityGrid(game->map()->desirabilityGrid());
    }
    else if (gridType == ElevationGrid) {
      mUi->cGridView->displayElevationGrid(game->map()->elevationGrid());
    }
    else if (gridType == DamageGrid) {
      mUi->cGridView->displayDamageGrid(game->map()->buildingDamageGrid());
    }
    else if (gridType == BackupAqueductGrid) {
      mUi->cGridView->displayAqueductGrid(game->map()->aqueductBackupGrid());
    }
    else if (gridType == BackpuAnimationGrid) {
      mUi->cGridView->displayAnimationGrid(game->map()->spriteBackupGrid());
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
