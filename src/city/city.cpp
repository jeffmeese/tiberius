#include "city.h"

#include "buildingdata.h"
#include "burningbuildingdata.h"
#include "camera.h"
#include "culturedata.h"
#include "data.h"
#include "educationdata.h"
#include "empiredata.h"
#include "entertainmentdata.h"
#include "financedata.h"
#include "healthdata.h"
#include "housingdata.h"
#include "imperialdata.h"
#include "labordata.h"
#include "militarydata.h"
#include "populationdata.h"
#include "ratingsdata.h"
#include "religiondata.h"
#include "resourcedata.h"
#include "routedata.h"
#include "scenariodata.h"
#include "scribemessagedata.h"
#include "storagedata.h"
#include "tradedata.h"
#include "walkerdata.h"

#include "game/player.h"
#include "imperial/request.h"
#include "military/legion.h"
#include "military/soldier.h"

static const int32_t DATA_SIZE = 36136;

City::City()
{
  mBuildingData.reset(new BuildingData);
  mBurningBuildingData.reset(new BurningBuildingData);
  mCultureData.reset(new CultureData);
  mCamera.reset(new Camera);
  mData.reset(new Data);
  mEducationData.reset(new EducationData);
  mEmpireData.reset(new EmpireData);
  mEntertainmentData.reset(new EntertainmentData);
  mWalkerData.reset(new WalkerData);
  mFinanceData.reset(new FinanceData);
  mHealthData.reset(new HealthData);
  mHousingData.reset(new HousingData);
  mImperialData.reset(new ImperialData);
  mLaborData.reset(new LaborData);
  mMilitaryData.reset(new MilitaryData);
  mPopulationData.reset(new PopulationData);
  mRatingsData.reset(new RatingsData);
  mReligionData.reset(new ReligionData);
  mResourceData.reset(new ResourceData);
  mRouteData.reset(new RouteData);
  mScenarioData.reset(new ScenarioData);
  mScribeMessageData.reset(new ScribeMessageData);
  mStorageData.reset(new StorageData);
  mTradeData.reset(new TradeData);

//  for (int i = 0; i < 1; i++) {
//    std::unique_ptr<Request> request(new Request);
//    request->setAmount(10);
//    request->setResourceType(Resource::Type::Wheat);
//    request->setMonthsToComply(24);
//    mImperialData->addRequest(std::move(request));
//  }

//  mResourceData->addAvailableResource(Resource::Type::Wheat);
//  mResourceData->addAvailableResource(Resource::Type::Fruit);
//  mResourceData->addAvailableResource(Resource::Type::Iron);
//  mResourceData->addAvailableResource(Resource::Type::Timber);
//  mResourceData->addAvailableResource(Resource::Type::Clay);
//  mResourceData->addAvailableResource(Resource::Type::Marble);
//  mResourceData->addAvailableResource(Resource::Type::Weapons);
//  mResourceData->addAvailableResource(Resource::Type::Furniture);
//  mResourceData->addAvailableResource(Resource::Type::Pottery);
}

City::~City()
{
  mOrientation = Orientation::North;
}

BuildingData * City::buildingData()
{
  return mBuildingData.get();
}

const BuildingData * City::buildingData() const
{
  return mBuildingData.get();
}

BurningBuildingData * City::burningBuildingData()
{
  return mBurningBuildingData.get();
}

const BurningBuildingData * City::burningBuildingData() const
{
  return mBurningBuildingData.get();
}

Camera * City::camera()
{
  return mCamera.get();
}

const Camera * City::camera() const
{
  return mCamera.get();
}

CultureData * City::cultureData()
{
  return mCultureData.get();
}

const CultureData * City::cultureData() const
{
  return mCultureData.get();
}

EducationData * City::educationData()
{
  return mEducationData.get();
}

const EducationData * City::educationData() const
{
  return mEducationData.get();
}

EmpireData * City::empireData()
{
  return mEmpireData.get();
}

const EmpireData * City::empireData() const
{
  return mEmpireData.get();
}

EntertainmentData * City::entertainmentData()
{
  return mEntertainmentData.get();
}

const EntertainmentData * City::entertainmentData() const
{
  return mEntertainmentData.get();
}

FinanceData * City::financeData()
{
  return mFinanceData.get();
}

const FinanceData * City::financeData() const
{
  return mFinanceData.get();
}

HealthData * City::healthData()
{
  return mHealthData.get();
}

const HealthData * City::healthData() const
{
  return mHealthData.get();
}

HousingData * City::housingData()
{
  return mHousingData.get();
}

const HousingData * City::housingData() const
{
  return mHousingData.get();
}

ImperialData * City::imperialData()
{
  return mImperialData.get();
}

const ImperialData * City::imperialData() const
{
  return mImperialData.get();
}

LaborData * City::laborData()
{
  return mLaborData.get();
}

const LaborData * City::laborData() const
{
  return mLaborData.get();
}

void City::loadFromStream(QDataStream &dataStream, Player * player)
{
  QByteArray byteArray = streamio::readCompressedData(dataStream, DATA_SIZE);
  QDataStream byteStream(&byteArray, QIODevice::ReadOnly);

  byteStream.skipRawData(18076); // Unused
  mFinanceData->setTaxRate(streamio::readInt32(byteStream));
  mFinanceData->setTotalDenarii(streamio::readInt32(byteStream));
  byteStream.skipRawData(12); // Unknown
  byteStream.skipRawData(4); // Total Hospital Workers
  byteStream.skipRawData(4); // Unknown
  mPopulationData->setTotalPopulation(streamio::readInt32(byteStream));
  mPopulationData->setPreviousYearPopulation(streamio::readInt32(byteStream));
  mPopulationData->setSchoolAgedChildren(streamio::readInt32(byteStream));
  mPopulationData->setAcademyAgedChildren(streamio::readInt32(byteStream));
  mPopulationData->setPopulationCapacity(streamio::readInt32(byteStream));
  byteStream.skipRawData(4); // Available population capacity
  for (int32_t i = 0; i < PopulationData::MAX_MONTHLY_POPULATION_COUNT; i++) {
    mPopulationData->setMonthlyPopulation(i, streamio::readInt32(byteStream));
  }
  mPopulationData->setMonthlyPopulationIndex(streamio::readInt32(byteStream));

  byteStream.skipRawData(4); // Monthly population total

  for (int32_t i = 0; i < PopulationData::MAX_AGE; i++) {
    mPopulationData->setPopulationByAge(i, streamio::readInt16(byteStream));
  }
  for (int32_t i = 0; i < PopulationData::MAX_STATUS_CATEGORIES; i++) {
    mPopulationData->setPopulatonByStatus(i, streamio::readInt32(byteStream));
  }

  byteStream.skipRawData(776); // Unknown

  // Not sure if I like this, it's dependent on the
  // type being defined in the right order
  for (int32_t i = 0; i < LaborData::MAX_LABOR_CATEGORIES; i++) {
    LaborData::Category & category = mLaborData->category(LaborData::Type(i));
    category.workersNeeded = streamio::readInt32(byteStream);
    category.workersAvaialble = streamio::readInt32(byteStream);
    byteStream.skipRawData(4); // Unknown
    category.numBuildings = streamio::readInt32(byteStream);
    category.priority = streamio::readInt32(byteStream);
  }

  byteStream.skipRawData(20);                                                      // Unused
  mLaborData->setTotalEmployed(streamio::readInt32(byteStream));                   // Total Employed
  mLaborData->setTotalUnemployed(streamio::readInt32(byteStream));                 // Total Unemployed

  byteStream.skipRawData(8);                                                       // Unemployment percentages
  byteStream.skipRawData(4);                                                       // Unknown

  mLaborData->setWage(streamio::readInt32(byteStream));
  mLaborData->setRomeWage(streamio::readInt32(byteStream));
  byteStream.skipRawData(4);                                                       // Unknown

  mLaborData->setWageExpenseThisYear(streamio::readInt32(byteStream));
  mLaborData->setWageExpenseThisMonth(streamio::readInt32(byteStream));
  mLaborData->setWageExpenseLastYear(streamio::readInt32(byteStream));

  mFinanceData->setNumberOfTaxedPlebians(streamio::readInt32(byteStream));
  mFinanceData->setNumberOfTaxedPatricians(streamio::readInt32(byteStream));
  mFinanceData->setNumberOfUntaxedPlebians(streamio::readInt32(byteStream));
  mFinanceData->setNumberOfUntaxedPatricians(streamio::readInt32(byteStream));
  byteStream.skipRawData(4);  // Plebian Tax Percentage
  byteStream.skipRawData(4);  // Patrician Tax Percentage
  byteStream.skipRawData(4);  // Overall Tax Percentage
  mFinanceData->setPlebianTaxesCollected(streamio::readInt32(byteStream));
  mFinanceData->setPatricianTaxesCollected(streamio::readInt32(byteStream));
  mFinanceData->setPlebianTaxesUncollected(streamio::readInt32(byteStream));
  mFinanceData->setPatricianTaxesUncollected(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearTaxes(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearTaxes(streamio::readInt32(byteStream));
  mFinanceData->setYearlyPlebianTaxCollected(streamio::readInt32(byteStream));
  mFinanceData->setYearlyPatricianTaxCollected(streamio::readInt32(byteStream));
  mFinanceData->setYearlyPlebianTaxUncollected(streamio::readInt32(byteStream));
  mFinanceData->setYearlyPatricianTaxUncollected(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearImports(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearImports(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearInterest(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearInterest(streamio::readInt32(byteStream));
  mFinanceData->setCurrentMonthInterest(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearSundries(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearSundries(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearConstruction(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearConstruction(streamio::readInt32(byteStream));
  mFinanceData->setCurrentYearSalary(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearSalary(streamio::readInt32(byteStream));
  byteStream.skipRawData(4); // Salary
  player->setSalaryRank(Player::Rank(streamio::readInt32(byteStream)));
  byteStream.skipRawData(4); // Salary this year
  byteStream.skipRawData(4); // Income last year
  byteStream.skipRawData(4); // Income this year
  byteStream.skipRawData(4); // Expenses last year
  byteStream.skipRawData(4); // Expenses this year
  byteStream.skipRawData(4); // Net flow last year
  byteStream.skipRawData(4); // Net flow this year
  mFinanceData->setPreviousYearBalance(streamio::readInt32(byteStream));
  byteStream.skipRawData(4); // Current year balance

  byteStream.skipRawData(560); // Unknown

  mRatingsData->setCulture(streamio::readInt32(byteStream));
  mRatingsData->setProsperity(streamio::readInt32(byteStream));
  mRatingsData->setPeace(streamio::readInt32(byteStream));
  mRatingsData->setFavor(streamio::readInt32(byteStream));

  byteStream.skipRawData(4); // Unknown
  byteStream.skipRawData(4); // Unknown
  byteStream.skipRawData(4); // Unknown
  byteStream.skipRawData(4); // Unknown
  byteStream.skipRawData(4); // Balance last year again
  byteStream.skipRawData(208); // Unknown

  mReligionData->getGod(God::Type::Ceres)->setMonthsSinceFestival(streamio::readInt32(byteStream));
  mReligionData->getGod(God::Type::Neptune)->setMonthsSinceFestival(streamio::readInt32(byteStream));
  mReligionData->getGod(God::Type::Mercury)->setMonthsSinceFestival(streamio::readInt32(byteStream));
  mReligionData->getGod(God::Type::Mars)->setMonthsSinceFestival(streamio::readInt32(byteStream));
  mReligionData->getGod(God::Type::Venus)->setMonthsSinceFestival(streamio::readInt32(byteStream));

  byteStream.skipRawData(64); // Unknown

  player->setPersonalSavings(streamio::readInt32(byteStream));

  byteStream.skipRawData(8); // Unknown

  mFinanceData->setCurrentYearDonated(streamio::readInt32(byteStream));
  mFinanceData->setPreviousYearDonated(streamio::readInt32(byteStream));
  mFinanceData->setLastDonationAmount(streamio::readInt32(byteStream));

  byteStream.skipRawData(392); // Unknown

  mFinanceData->setEstimatedTaxes(streamio::readInt32(byteStream));

  byteStream.skipRawData(172); // Unknown

  byteStream.skipRawData(4); // Yearly labor cost

  byteStream.skipRawData(368); // Unknown
}

MilitaryData * City::militaryData()
{
  return mMilitaryData.get();
}

const MilitaryData * City::militaryData() const
{
  return mMilitaryData.get();
}

City::Orientation City::orientation() const
{
  return mOrientation;
}

PopulationData * City::populationData()
{
  return mPopulationData.get();
}

const PopulationData * City::populationData() const
{
  return mPopulationData.get();
}

RatingsData * City::ratingsData()
{
  return mRatingsData.get();
}

const RatingsData * City::ratingsData() const
{
  return mRatingsData.get();
}

ReligionData * City::religionData()
{
  return mReligionData.get();
}

const ReligionData * City::religionData() const
{
  return mReligionData.get();
}

ResourceData * City::resourceData()
{
  return mResourceData.get();
}

const ResourceData * City::resourceData() const
{
  return mResourceData.get();
}

RouteData * City::routeData()
{
  return mRouteData.get();
}

const RouteData * City::routeData() const
{
  return mRouteData.get();
}

void City::saveToStream(QDataStream &dataStream) const
{

}

ScenarioData * City::scenarioData()
{
  return mScenarioData.get();
}

const ScenarioData * City::scenarioData() const
{
  return mScenarioData.get();
}

ScribeMessageData * City::scribeMessageData()
{
  return mScribeMessageData.get();
}

const ScribeMessageData * City::scribeMessageData() const
{
  return mScribeMessageData.get();
}

StorageData * City::storageData()
{
  return mStorageData.get();
}

const StorageData * City::storageData() const
{
  return mStorageData.get();
}

TradeData * City::tradeData()
{
  return mTradeData.get();
}

const TradeData * City::tradeData() const
{
  return mTradeData.get();
}

WalkerData * City::walkerData()
{
  return mWalkerData.get();
}

const WalkerData * City::walkerData() const
{
  return mWalkerData.get();
}

void City::setOrientation(Orientation value)
{
  mOrientation = value;
}

