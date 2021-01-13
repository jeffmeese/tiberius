#ifndef CULTUREDATA_H
#define CULTUREDATA_H

#include "tiberius.h"

class CultureData
{
public:
  TIBERIUS_LIB_DECL CultureData();

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  int32_t mTotalAcademies;
  int32_t mTotalAmpitheaters;
  int32_t mTotalBarbers;
  int32_t mTotalBaths;
  int32_t mTotalClinics;
  int32_t mTotalColosseums;
  int32_t mTotalHippodromes;
  int32_t mTotalHospitals;
  int32_t mTotalLargeCeresTemples;
  int32_t mTotalLargeMarsTemples;
  int32_t mTotalLargeMercuryTemples;
  int32_t mTotalLargeNeptuneTemples;
  int32_t mTotalLargeVenusTemples;
  int32_t mTotalLibraries;
  int32_t mTotalOracles;
  int32_t mTotalSchools;
  int32_t mTotalSmallCeresTemples;
  int32_t mTotalSmallMarsTemples;
  int32_t mTotalSmallMercuryTemples;
  int32_t mTotalSmallNeptuneTemples;
  int32_t mTotalSmallVenusTemples;
  int32_t mTotalTheaters;
  int32_t mWorkingAcademies;
  int32_t mWorkingAmpitheaters;
  int32_t mWorkingBarbers;
  int32_t mWorkingBaths;
  int32_t mWorkingClinics;
  int32_t mWorkingColosseums;
  int32_t mWorkingHippodromes;
  int32_t mWorkingHospitals;
  int32_t mWorkingLibraries;
  int32_t mWorkingOracles;
  int32_t mWorkingSchools;
  int32_t mWorkingTheaters;
};

#endif // CULTUREDATA_H
