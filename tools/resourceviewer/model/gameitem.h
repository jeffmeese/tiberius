#ifndef GAMEITEM_H
#define GAMEITEM_H

#include "resourceitem.h"

class Game;

class GameItem
    : public ResourceItem
{
public:
  GameItem(const QString & filePath);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  void loadBuildings();

private:
  std::unique_ptr<Game> mGame;
};

#endif // GAMEITEM_H
