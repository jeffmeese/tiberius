#ifndef EMPIREDATA_H
#define EMPIREDATA_H

#include "tiberius.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

namespace Empire
{
  class City;
}

class EmpireData
{
public:
  static const int32_t MAX_CITIES = 41;

public:
  TIBERIUS_LIB_DECL EmpireData();
  TIBERIUS_LIB_DECL ~EmpireData();

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  using CityPtr = std::unique_ptr<Empire::City>;
  using CityVector = std::vector<CityPtr>;

private:
  CityVector mCities;
};

#endif // EMPIREDATA_H
