#include "datamodel.h"

#include "application/tiberiusapplication.h"

#include "language/language.h"
#include "language/stringdata.h"

DataModel::DataModel()
{

}

int32_t DataModel::calcPercent(int32_t working, int32_t population) const
{
  int32_t percent = 0;
  if (population > 0) {
    percent = static_cast<int>(static_cast<float>(working) / population * 100);
  }
  return percent;
}

QString DataModel::coverageString(int32_t coverage) const
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  if (coverage == 0)
    return stringData->getString(57, 10);
  else if (coverage == 100)
    return stringData->getString(57, 21);

  return stringData->getString(57, coverage / 10 + 11);
}
