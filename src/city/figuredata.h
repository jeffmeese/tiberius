#ifndef FIGUREDATA_H
#define FIGUREDATA_H

#include "datamodel.h"
#include "datavector.h"

#include "figure/figure.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

class Figure;
class FigureData
    : public DataModel
    , public DataVector<Figure>
{
public:
  static const int32_t MAX_CHARACTERS = 10000;

public:
  TIBERIUS_LIB_DECL FigureData();
  TIBERIUS_LIB_DECL ~FigureData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
};

#endif // FIGUREDATA_H
