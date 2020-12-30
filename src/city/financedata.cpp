#include "financedata.h"

FinanceData::FinanceData()
{
  mCurrentYearConstruction = 0;
  mCurrentYearDonated = 0;
  mCurrentYearExports = 0;
  mCurrentYearImports = 0;
  mCurrentYearInterest = 0;
  mCurrentYearSalary = 0;
  mCurrentYearSundries = 0;
  mCurrentYearTaxes = 0;
  mCurrentYearTribute = 0;
  mCurrentYearWages = 0;
  mNumberOfTaxedPatricians = 0;
  mNumberOfTaxedPlebians = 0;
  mNumberOfUntaxedPatricians = 0;
  mNumberOfUntaxedPlebians = 0;
  mEstimatedTaxes = 0;
  mPatricianTaxesCollected = 0;
  mPatricianTaxesUncollected = 0;
  mPercentRegistered = 0;
  mPlebianTaxesCollected = 0;
  mPlebianTaxesUncollected = 0;
  mPreviousYearBalance = 4159;
  mPreviousYearConstruction = 0;
  mPreviousYearDonated = 0;
  mPreviousYearExports = 0;
  mPreviousYearImports = 0;
  mPreviousYearInterest = 0;
  mPreviousYearSalary = 0;
  mPreviousYearSundries = 0;
  mPreviousYearTaxes = 0;
  mPreviousYearTribute = 0;
  mPreviousYearWages = 0;
  mRomeWages = 0;
  mTaxRate = 7;
  mTotalDenarii = 0;

  mPreviousYearTaxes = 1;
  mPreviousYearExports = 2;
  mPreviousYearDonated = 3;
  mPreviousYearImports = 4;
  mPreviousYearWages = 5;
  mPreviousYearConstruction = 6;
  mPreviousYearInterest = 7;
  mPreviousYearSalary = 8;
  mPreviousYearSundries = 9;
  mPreviousYearTribute = 10;

  mCurrentMonthInterest = 0;
  mCurrentYearTaxes = 11;
  mCurrentYearExports = 12;
  mCurrentYearDonated = 13;
  mCurrentYearImports = 14;
  mCurrentYearWages = 15;
  mCurrentYearConstruction = 16;
  mCurrentYearInterest = 17;
  mCurrentYearSalary = 18;
  mCurrentYearSundries = 19;
  mCurrentYearTribute = 20;

  mLastDonationAmount = 0;

  mTotalDenarii = 2000;
  mEstimatedTaxes = 109;
  mPercentRegistered = 45;

  mYearlyPatricianTaxCollected = 0;
  mYearlyPatricianTaxUncollected = 0;
  mYearlyPlebianTaxCollected = 0;
  mYearlyPlebianTaxUncollected = 0;
}

int32_t FinanceData::currentMonthInterest() const
{
  return mCurrentMonthInterest;
}

int32_t FinanceData::currentYearConstruction() const
{
  return mCurrentYearConstruction;
}

int32_t FinanceData::currentYearDonated() const
{
  return mCurrentYearDonated;
}

int32_t FinanceData::currentYearExpenses() const
{
  int32_t expenses = 0;
  expenses += mCurrentYearImports;
  expenses += mCurrentYearWages;
  expenses += mCurrentYearConstruction;
  expenses += mCurrentYearInterest;
  expenses += mCurrentYearSalary;
  expenses += mCurrentYearSundries;
  expenses += mCurrentYearTribute;

  return expenses;
}

int32_t FinanceData::currentYearExports() const
{
  return mCurrentYearExports;
}

int32_t FinanceData::currentYearImports() const
{
  return mCurrentYearImports;
}

int32_t FinanceData::currentYearIncome() const
{
  int32_t income = 0;
  income += mCurrentYearExports;
  income += mCurrentYearTaxes;
  income += mCurrentYearDonated;

  return income;
}

int32_t FinanceData::currentYearInterest() const
{
  return mCurrentYearInterest;
}

int32_t FinanceData::currentYearSalary() const
{
  return mCurrentYearSalary;
}

int32_t FinanceData::currentYearSundries() const
{
  return mCurrentYearSundries;
}

int32_t FinanceData::currentYearTaxes() const
{
  return mCurrentYearTaxes;
}

int32_t FinanceData::currentYearTribute() const
{
  return mCurrentYearTribute;
}

int32_t FinanceData::currentYearWages() const
{
  return mCurrentYearWages;
}

void FinanceData::decreaseDenarii(int32_t value)
{
  mTotalDenarii -= value;
  emit changed();
}

void FinanceData::decreaseTaxes(int32_t value)
{
  mTaxRate -= value;
  if (mTaxRate < 0)
    mTaxRate = 0;

  emit changed();
}

int32_t FinanceData::estimatedTaxes() const
{
  return mEstimatedTaxes;
}

void FinanceData::increaseDenarii(int32_t value)
{
  mTotalDenarii += value;
  emit changed();
}

void FinanceData::increaseTaxes(int32_t value)
{
  mTaxRate += value;
  if (mTaxRate < 0)
    mTaxRate = 0;

  emit changed();
}

int32_t FinanceData::lastDonationAmount() const
{
  return mLastDonationAmount;
}

int32_t FinanceData::numberOfTaxedPatricians() const
{
  return mNumberOfTaxedPatricians;
}

int32_t FinanceData::numberOfTaxedPlebians() const
{
  return mNumberOfTaxedPlebians;
}

int32_t FinanceData::numberOfUntaxedPatricians() const
{
  return mNumberOfUntaxedPatricians;
}

int32_t FinanceData::numberOfUntaxedPlebians() const
{
  return mNumberOfUntaxedPlebians;
}

int32_t FinanceData::patricianTaxesCollected() const
{
  return mPatricianTaxesCollected;
}

int32_t FinanceData::patricianTaxesUncollected() const
{
  return mPatricianTaxesUncollected;
}

int32_t FinanceData::percentRegistered() const
{
  return mPercentRegistered;
}

int32_t FinanceData::plebianTaxesCollected() const
{
  return mPlebianTaxesCollected;
}

int32_t FinanceData::plebianTaxesUncollected() const
{
  return mPlebianTaxesUncollected;
}

int32_t FinanceData::previousYearBalance() const
{
  return mPreviousYearBalance;
}

int32_t FinanceData::previousYearConstruction() const
{
  return mPreviousYearConstruction;
}

int32_t FinanceData::previousYearDonated() const
{
  return mPreviousYearDonated;
}

int32_t FinanceData::previousYearExpenses() const
{
  int32_t expenses = 0;
  expenses += mPreviousYearImports;
  expenses += mPreviousYearWages;
  expenses += mPreviousYearConstruction;
  expenses += mPreviousYearInterest;
  expenses += mPreviousYearSalary;
  expenses += mPreviousYearSundries;
  expenses += mPreviousYearTribute;

  return expenses;
}

int32_t FinanceData::previousYearExports() const
{
  return mPreviousYearExports;
}

int32_t FinanceData::previousYearImports() const
{
  return mPreviousYearImports;
}

int32_t FinanceData::previousYearIncome() const
{
  int32_t income = 0;
  income += mPreviousYearExports;
  income += mPreviousYearTaxes;
  income += mPreviousYearDonated;

  return income;
}

int32_t FinanceData::previousYearInterest() const
{
  return mPreviousYearInterest;
}

int32_t FinanceData::previousYearSalary() const
{
  return mPreviousYearSalary;
}

int32_t FinanceData::previousYearSundries() const
{
  return mPreviousYearSundries;
}

int32_t FinanceData::previousYearTaxes() const
{
  return mPreviousYearTaxes;
}

int32_t FinanceData::previousYearTribute() const
{
  return mPreviousYearTribute;
}

int32_t FinanceData::previousYearWages() const
{
  return mPreviousYearWages;
}

int32_t FinanceData::romeWages() const
{
  return mRomeWages;
}

void FinanceData::setCurrentMonthInterest(int32_t value)
{
  mCurrentMonthInterest = 0;
}

void FinanceData::setCurrentYearConstruction(int32_t value)
{
  mCurrentYearConstruction = value;
  emit changed();
}

void FinanceData::setCurrentYearDonated(int32_t value)
{
  mCurrentYearDonated = value;
  emit changed();
}

void FinanceData::setCurrentYearExports(int32_t value)
{
  mCurrentYearExports = value;
  emit changed();
}

void FinanceData::setCurrentYearImports(int32_t value)
{
  mCurrentYearImports = value;
  emit changed();
}

void FinanceData::setCurrentYearInterest(int32_t value)
{
  mCurrentYearInterest = value;
  emit changed();
}

void FinanceData::setCurrentYearSalary(int32_t value)
{
  mCurrentYearSalary = value;
  emit changed();
}

void FinanceData::setCurrentYearSundries(int32_t value)
{
  mCurrentYearSundries = value;
  emit changed();
}

void FinanceData::setCurrentYearTaxes(int32_t value)
{
  mCurrentYearTaxes = value;
}

void FinanceData::setCurrentYearTribute(int32_t value)
{
  mCurrentYearTribute = value;
  emit changed();
}

void FinanceData::setCurrentYearWages(int32_t value)
{
  mCurrentYearWages = value;
  emit changed();
}

void FinanceData::setEstimatedTaxes(int32_t value)
{
  mEstimatedTaxes = value;
  emit changed();
}

void FinanceData::setLastDonationAmount(int32_t value)
{
  mLastDonationAmount = value;
  emit changed();
}

void FinanceData::setNumberOfTaxedPatricians(int32_t value)
{
  mNumberOfTaxedPatricians = value;
  emit changed();
}

void FinanceData::setNumberOfTaxedPlebians(int32_t value)
{
  mNumberOfTaxedPlebians = value;
  emit changed();
}

void FinanceData::setNumberOfUntaxedPatricians(int32_t value)
{
  mNumberOfUntaxedPatricians = value;
  emit changed();
}

void FinanceData::setNumberOfUntaxedPlebians(int32_t value)
{
  mNumberOfUntaxedPlebians = value;
  emit changed();
}

void FinanceData::setPatricianTaxesCollected(int32_t value)
{
  mPatricianTaxesCollected = value;
  emit changed();
}

void FinanceData::setPatricianTaxesUncollected(int32_t value)
{
  mPatricianTaxesUncollected = value;
  emit changed();
}

void FinanceData::setPercentRegistered(int32_t value)
{
  mPercentRegistered = value;
  emit changed();
}

void FinanceData::setPlebianTaxesCollected(int32_t value)
{
  mPlebianTaxesCollected = value;
  emit changed();
}

void FinanceData::setPlebianTaxesUncollected(int32_t value)
{
  mPlebianTaxesUncollected = value;
  emit changed();
}

void FinanceData::setPreviousYearBalance(int32_t value)
{
  mPreviousYearBalance = value;
  emit changed();
}

void FinanceData::setPreviousYearConstruction(int32_t value)
{
  mPreviousYearConstruction = value;
  emit changed();
}

void FinanceData::setPreviousYearDonated(int32_t value)
{
  mPreviousYearDonated = value;
  emit changed();
}

void FinanceData::setPreviousYearExports(int32_t value)
{
  mPreviousYearExports = value;
  emit changed();
}

void FinanceData::setPreviousYearImports(int32_t value)
{
  mPreviousYearImports = value;
  emit changed();
}

void FinanceData::setPreviousYearInterest(int32_t value)
{
  mPreviousYearInterest = value;
  emit changed();
}

void FinanceData::setPreviousYearSalary(int32_t value)
{
  mPreviousYearSalary = value;
  emit changed();
}

void FinanceData::setPreviousYearSundries(int32_t value)
{
  mPreviousYearSundries = value;
  emit changed();
}

void FinanceData::setPreviousYearTaxes(int32_t value)
{
  mPreviousYearTaxes = value;
  emit changed();
}

void FinanceData::setPreviousYearTribute(int32_t value)
{
  mPreviousYearTribute = value;
  emit changed();
}

void FinanceData::setPreviousYearWages(int32_t value)
{
  mPreviousYearWages = value;
  emit changed();
}

void FinanceData::setRomeWages(int32_t value)
{
  mRomeWages = value;
  emit changed();
}

void FinanceData::setTaxRate(int32_t value)
{
  mTaxRate = value;
  emit changed();
}

void FinanceData::setTotalDenarii(int32_t value)
{
  mTotalDenarii = value;
  emit changed();
}

void FinanceData::setYearlyPatricianTaxCollected(int32_t value)
{
  mYearlyPatricianTaxCollected = value;
}

void FinanceData::setYearlyPatricianTaxUncollected(int32_t value)
{
  mYearlyPatricianTaxUncollected = value;
}

void FinanceData::setYearlyPlebianTaxCollected(int32_t value)
{
  mYearlyPlebianTaxCollected = value;
}

void FinanceData::setYearlyPlebianTaxUncollected(int32_t value)
{
  mYearlyPlebianTaxUncollected = value;
}

int32_t FinanceData::taxRate() const
{
  return mTaxRate;
}

int32_t FinanceData::totalDenarii() const
{
  return mTotalDenarii;
}

int32_t FinanceData::yearlyPatricianTaxCollected() const
{
  return mYearlyPatricianTaxCollected;
}

int32_t FinanceData::yearlyPatricianTaxUncollected() const
{
  return mYearlyPatricianTaxUncollected;
}

int32_t FinanceData::yearlyPlebianTaxCollected() const
{
  return mYearlyPlebianTaxCollected;
}

int32_t FinanceData::yearlyPlebianTaxUncollected() const
{
  return mYearlyPlebianTaxUncollected;
}
