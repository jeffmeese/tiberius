#include "gameitem.h"

#include "gamegridgroup.h"
#include "empirecitygroup.h"

#include "game/game.h"

#include <QDebug>
#include <QFileInfo>
#include <QThread>

class GameReader : public QThread
{
  Q_OBJECT

public:
  GameReader(Game * game, const QString & filePath)
    : mGame(game)
    , mFilePath(filePath)
  { }

  void run() override
  {
    mGame->loadFromFile(mFilePath);
    emit ready();
  }

signals:
  void ready();

private:
  Game * mGame;
  QString mFilePath;
};

GameItem::GameItem(std::unique_ptr<Game> game, const QString & filePath)
  : mGame(std::move(game))
{
  QFileInfo fileInfo(filePath);
  setText(fileInfo.fileName());
  QString dirName = fileInfo.path();

  mGame->loadFromFile(filePath);
  fileRead();
  //GameReader * gameReader = new GameReader(mGame.get(), filePath);
  //connect(gameReader, &GameReader::ready, this, &GameItem::fileRead);
  //connect(gameReader, &GameReader::finished, gameReader, &QObject::deleteLater);
  //gameReader->start();
}

GameItem::~GameItem()
{

}

void GameItem::fileRead()
{
  appendRow(new GameGridGroup(mGame.get()));
  appendRow(new EmpireCityGroup(mGame->city()));
}

QWidget * GameItem::createView() const
{
//  if (!mGameLoaded) {
//    mGame->loadFromFile(mFilePath);
//    mGameLoaded = true;
//  }

  return nullptr;
}

QList<Property> GameItem::getProperties() const
{
//  if (!mGameLoaded) {
//    mGame->loadFromFile(mFilePath);
//    mGameLoaded = true;
//  }

  QList<Property> propertyList;
  return propertyList;
}

#include "gameitem.moc"

