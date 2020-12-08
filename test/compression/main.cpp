#include <iostream>
#include <memory>

#include <QString>

#include "game/game.h"

int main(int argc, char ** argv)
{
  std::unique_ptr<Game> game(new Game);

  QString inputFile("/data/caesar3/das-miletus-finish.sav");
  QString outputFile("/home/jmeese/temp.sav");

  game->loadFromFile(inputFile);
  game->saveToFile(outputFile);

  return 0;
}
