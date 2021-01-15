#ifndef EMPIREDATA_H
#define EMPIREDATA_H

#include "tiberius.h"

#include "datavector.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

namespace Empire
{
  class City;
}

class EmpireData
    : public DataVector<Empire::City>
{
public:
  static const int32_t MAX_CITIES = 41;

public:
  TIBERIUS_LIB_DECL EmpireData();
  TIBERIUS_LIB_DECL ~EmpireData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;
};

#endif // EMPIREDATA_H
