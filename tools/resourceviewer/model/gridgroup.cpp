#include "gridgroup.h"

#include "edgegriditem.h"
#include "elevationgriditem.h"
#include "graphicgriditem.h"
#include "terraingriditem.h"

#include "mission/mission.h"

GridGroup::GridGroup(Mission * mission)
  : mMission(mission)
{
  setText("Grids");
  appendRow(new EdgeGridItem(mMission->edgeGrid()));
  appendRow(new ElevationGridItem(mMission->elevationGrid()));
  appendRow(new GraphicGridItem(mMission->graphicGrid()));
  appendRow(new TerrainGridItem(mMission->terrainGrid()));
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
