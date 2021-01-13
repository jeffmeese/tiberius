#include "gridgroup.h"

#include "edgegriditem.h"
#include "elevationgriditem.h"
#include "graphicgriditem.h"
#include "terraingriditem.h"

#include "scenario/scenario.h"

GridGroup::GridGroup(Scenario * sccenario)
  : mScenario(sccenario)
{
  setText("Grids");
  appendRow(new EdgeGridItem(mScenario->edgeGrid()));
  appendRow(new ElevationGridItem(mScenario->elevationGrid()));
  appendRow(new GraphicGridItem(mScenario->graphicGrid()));
  appendRow(new TerrainGridItem(mScenario->terrainGrid()));
}

QWidget * GridGroup::createView() const
{
  return nullptr;
}

QList<Property> GridGroup::getProperties() const
{
  QList<Property> propertyList;
  return propertyList;
}
