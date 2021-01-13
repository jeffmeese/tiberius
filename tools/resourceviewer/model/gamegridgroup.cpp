#include "gamegridgroup.h"

#include "aqueductgriditem.h"
#include "buildinggriditem.h"
#include "damagegriditem.h"
#include "desirabilitygriditem.h"
#include "edgegriditem.h"
#include "elevationgriditem.h"
#include "graphicgriditem.h"
#include "merginggriditem.h"
#include "terraingriditem.h"
#include "walkergriditem.h"

#include "game/game.h"
#include "map/map.h"

GameGridGroup::GameGridGroup(Game * game)
  : mGame(game)
{
  setText("Grids");
  appendRow(new AqueductGridItem(game->map()->aqueductGrid()));
  appendRow(new BuildingGridItem(game->map()->buildingGrid()));
  appendRow(new DamageGridItem(game->map()->buildingDamageGrid()));
  appendRow(new DesirabilityGridItem(game->map()->desirabilityGrid()));
  appendRow(new EdgeGridItem(game->map()->edgeGrid()));
  appendRow(new ElevationGridItem(game->map()->elevationGrid()));
  appendRow(new GraphicGridItem(game->map()->graphicGrid()));
  appendRow(new MergingGridItem(game->map()->randomGrid()));
  appendRow(new TerrainGridItem(game->map()->terrainGrid()));
  appendRow(new WalkerGridItem(game->map()->figureGrid()));
}

QWidget * GameGridGroup::createView() const
{
  return nullptr;
}

QList<Property> GameGridGroup::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
