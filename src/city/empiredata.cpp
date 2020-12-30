#include "empiredata.h"

#include "empire/city.h"

EmpireData::EmpireData()
{
  for (int32_t i = 0; i < MAX_CITIES; i++) {
    CityPtr city(new Empire::City);
    mCities.push_back(std::move(city));
  }
}

EmpireData::~EmpireData()
{

}

void EmpireData::loadFromStream(QDataStream & dataStream)
{
  for (int32_t i = 0; i < MAX_CITIES; i++) {
    mCities.at(i)->loadFromStream(dataStream);
  }
}

void EmpireData::saveToStream(QDataStream & dataStream) const
{
  for (int32_t i = 0; i < MAX_CITIES; i++) {
    mCities.at(i)->saveToStream(dataStream);
  }
}
