#ifndef GAMEGRIDGROUP_H
#define GAMEGRIDGROUP_H

#include "resourceitem.h"

class Game;

class GameGridGroup : public ResourceItem
{
public:
  GameGridGroup(Game * game);

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;

private:
  Game * mGame;
};

#endif // GAMEGRIDGROUP_H
