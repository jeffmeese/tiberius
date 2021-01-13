#include "gameitem.h"

#include "gamegridgroup.h"

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

GameItem::GameItem(const QString & filePath)
{
  QFileInfo fileInfo(filePath);
  setText(fileInfo.fileName());
  QString dirName = fileInfo.path();

  mGame.reset(new Game);
  setEnabled(false);

  GameReader * gameReader = new GameReader(mGame.get(), filePath);
  connect(gameReader, &GameReader::ready, this, &GameItem::fileRead);
  connect(gameReader, &GameReader::finished, gameReader, &QObject::deleteLater);
  gameReader->start();
}

GameItem::~GameItem()
{

}

void GameItem::fileRead()
{
  setEnabled(true);
  appendRow(new GameGridGroup(mGame.get()));
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

#include "gameitem.moc"

