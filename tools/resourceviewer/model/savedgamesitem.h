#ifndef SAVEDGAMESITEM_H
#define SAVEDGAMESITEM_H

#include "resourceitem.h"

class SavedGamesItem
    : public ResourceItem
{
public:
  SavedGamesItem();

public:
  QWidget * createView() const override;
  QList<Property> getProperties() const override;
};

#endif // SAVEDGAMESITEM_H
