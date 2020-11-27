#include "gameitem.h"

//#include "buildings/building.h"

#include "game/game.h"

#include <QFileInfo>

GameItem::GameItem(const QString & filePath)
{
//  QFileInfo fileInfo(filePath);
//  setText(fileInfo.fileName());
//  QString dirName = fileInfo.path();

//  mGame.reset(new Game(dirName));
//  mGame->loadFromFile(filePath);
//  loadBuildings();
}

QWidget * GameItem::createView() const
{
  return nullptr;
}

QList<Property> GameItem::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}

void GameItem::loadBuildings()
{
  QStandardItem * buildingGroup = new QStandardItem;
  buildingGroup->setText("Buildings");

//  for (int32_t i = 0; i < mGame->totalBuildings(); i++) {
//    Building * building = mGame->getBuilding(i);
//    QStandardItem * item = new QStandardItem;
//    item->setText("Empty Slot");
//    if (building != nullptr) {
//      item->setText(building->name());
//    }
//    buildingGroup->appendRow(item);
//  }
//  appendRow(buildingGroup);
}
