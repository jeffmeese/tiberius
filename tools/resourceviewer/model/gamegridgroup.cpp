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
  handleGameChanged();
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

void GameGridGroup::handleGameChanged()
{
  removeRows(0, rowCount());
  appendRow(new AqueductGridItem(mGame->map()->aqueductGrid()));
  appendRow(new BuildingGridItem(mGame->map()->buildingGrid()));
  appendRow(new DamageGridItem(mGame->map()->buildingDamageGrid()));
  appendRow(new DesirabilityGridItem(mGame->map()->desirabilityGrid()));
  appendRow(new EdgeGridItem(mGame->map()->edgeGrid()));
  appendRow(new ElevationGridItem(mGame->map()->elevationGrid()));
  appendRow(new GraphicGridItem(mGame->map()->graphicGrid()));
  appendRow(new MergingGridItem(mGame->map()->randomGrid()));
  appendRow(new TerrainGridItem(mGame->map()->terrainGrid()));
  appendRow(new WalkerGridItem(mGame->map()->figureGrid()));
}
