#include "culturedata.h"

#include "core/streamio.h"

CultureData::CultureData()
{
  mTotalTheaters = 0;
  mWorkingTheaters = 0;
  mTotalAmpitheaters = 0;
  mWorkingAmpitheaters = 0;
  mTotalColosseums = 0;
  mWorkingColosseums = 0;
  mTotalHippodromes = 0;
  mWorkingHippodromes = 0;
  mTotalSchools = 0;
  mWorkingSchools = 0;
  mTotalLibraries = 0;
  mWorkingLibraries = 0;
  mTotalAcademies = 0;
  mWorkingAcademies = 0;
  mTotalBarbers = 0;
  mWorkingBarbers = 0;
  mTotalClinics = 0;
  mWorkingClinics = 0;
  mTotalHospitals = 0;
  mWorkingHospitals = 0;
  mTotalSmallCeresTemples = 0;
  mTotalSmallNeptuneTemples = 0;
  mTotalSmallMercuryTemples = 0;
  mTotalSmallMarsTemples = 0;
  mTotalSmallVenusTemples = 0;
  mTotalLargeCeresTemples = 0;
  mTotalLargeNeptuneTemples = 0;
  mTotalLargeMercuryTemples = 0;
  mTotalLargeMarsTemples = 0;
  mTotalLargeVenusTemples = 0;
  mTotalOracles = 0;
}

void CultureData::loadFromDataStream(QDataStream & dataStream)
{
  mTotalTheaters = streamio::readInt32(dataStream);
  mWorkingTheaters = streamio::readInt32(dataStream);
  mTotalAmpitheaters = streamio::readInt32(dataStream);
  mWorkingAmpitheaters = streamio::readInt32(dataStream);
  mTotalColosseums = streamio::readInt32(dataStream);
  mWorkingColosseums = streamio::readInt32(dataStream);
  mTotalHippodromes = streamio::readInt32(dataStream);
  mWorkingHippodromes = streamio::readInt32(dataStream);
  mTotalSchools = streamio::readInt32(dataStream);
  mWorkingSchools = streamio::readInt32(dataStream);
  mTotalLibraries = streamio::readInt32(dataStream);
  mWorkingLibraries = streamio::readInt32(dataStream);
  mTotalAcademies = streamio::readInt32(dataStream);
  mWorkingAcademies = streamio::readInt32(dataStream);
  mTotalBarbers = streamio::readInt32(dataStream);
  mWorkingBarbers = streamio::readInt32(dataStream);
  mTotalClinics = streamio::readInt32(dataStream);
  mWorkingClinics = streamio::readInt32(dataStream);
  mTotalHospitals = streamio::readInt32(dataStream);
  mWorkingHospitals = streamio::readInt32(dataStream);
  mTotalSmallCeresTemples = streamio::readInt32(dataStream);
  mTotalSmallNeptuneTemples = streamio::readInt32(dataStream);
  mTotalSmallMercuryTemples = streamio::readInt32(dataStream);
  mTotalSmallMarsTemples = streamio::readInt32(dataStream);
  mTotalSmallVenusTemples = streamio::readInt32(dataStream);
  mTotalLargeCeresTemples = streamio::readInt32(dataStream);
  mTotalLargeNeptuneTemples = streamio::readInt32(dataStream);
  mTotalLargeMercuryTemples = streamio::readInt32(dataStream);
  mTotalLargeMarsTemples = streamio::readInt32(dataStream);
  mTotalLargeVenusTemples = streamio::readInt32(dataStream);
  mTotalOracles = streamio::readInt32(dataStream);
}

void CultureData::saveToDataStream(QDataStream & dataStream) const
{

}

