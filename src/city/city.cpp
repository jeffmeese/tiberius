#include "city.h"

#include "buildingdata.h"
#include "camera.h"
#include "educationdata.h"
#include "entertainmentdata.h"
#include "financedata.h"
#include "healthdata.h"
#include "imperialdata.h"
#include "labordata.h"
#include "militarydata.h"
#include "populationdata.h"
#include "ratingsdata.h"
#include "religiondata.h"
#include "resourcedata.h"
#include "routedata.h"
#include "tradedata.h"
#include "walkerdata.h"

#include "imperial/request.h"
#include "military/legion.h"
#include "military/soldier.h"

City::City()
{
  mBuildingData.reset(new BuildingData);
  mCamera.reset(new Camera);
  mEducationData.reset(new EducationData);
  mEntertainmentData.reset(new EntertainmentData);
  mWalkerData.reset(new WalkerData);
  mFinanceData.reset(new FinanceData);
  mHealthData.reset(new HealthData);
  mImperialData.reset(new ImperialData);
  mLaborData.reset(new LaborData);
  mMilitaryData.reset(new MilitaryData);
  mPopulationData.reset(new PopulationData);
  mRatingsData.reset(new RatingsData);
  mReligionData.reset(new ReligionData);
  mResourceData.reset(new ResourceData);
  mRouteData.reset(new RouteData);
  mTradeData.reset(new TradeData);

  for (int i = 0; i < 1; i++) {
    std::unique_ptr<Request> request(new Request);
    request->setAmount(10);
    request->setResourceType(Resource::Type::Wheat);
    request->setMonthsToComply(24);
    mImperialData->addRequest(std::move(request));
  }

  mResourceData->addAvailableResource(Resource::Type::Wheat);
  mResourceData->addAvailableResource(Resource::Type::Fruit);
  mResourceData->addAvailableResource(Resource::Type::Iron);
  mResourceData->addAvailableResource(Resource::Type::Timber);
  mResourceData->addAvailableResource(Resource::Type::Clay);
  mResourceData->addAvailableResource(Resource::Type::Marble);
  mResourceData->addAvailableResource(Resource::Type::Weapons);
  mResourceData->addAvailableResource(Resource::Type::Furniture);
  mResourceData->addAvailableResource(Resource::Type::Pottery);
}

City::~City()
{
  mOrientation = Orientation::North;
}

City::Orientation City::orientation() const
{
  return mOrientation;
}

void City::setOrientation(Orientation value)
{
  mOrientation = value;
}

