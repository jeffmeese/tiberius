#ifndef WALKERDATA_H
#define WALKERDATA_H

#include "datamodel.h"
#include "datavector.h"

#include "figure/figure.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

class WalkerData
    : public DataModel
    , public DataVector<Figure>
{
public:
  static const int32_t MAX_FIGURES = 1000;

public:
  TIBERIUS_LIB_DECL WalkerData();
  TIBERIUS_LIB_DECL ~WalkerData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream, bool compressed = true) const;
};

#endif // WALKERDATA_H
