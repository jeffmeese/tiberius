#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "resourceitem.h"

class Game;

class GameItem
    : public QObject
    , public ResourceItem
{
  Q_OBJECT

public:
  GameItem(const QString & filePath);
  ~GameItem();

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private slots:
  void fileRead();

private:
  std::unique_ptr<Game> mGame;
};

#endif // GAMEITEM_H
