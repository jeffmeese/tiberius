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
  mEstimatedTaxes = 0;
  mPercentRegistered = 0;
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

  mTotalDenarii = 2000;
  mEstimatedTaxes = 109;
  mPercentRegistered = 45;
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

int32_t FinanceData::percentRegistered() const
{
  return mPercentRegistered;
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

void FinanceData::setCurrentYearConstruction(int32_t value)
{
  mCurrentYearConstruction = value;
}

void FinanceData::setCurrentYearDonated(int32_t value)
{
  mCurrentYearDonated = value;
}

void FinanceData::setCurrentYearExports(int32_t value)
{
  mCurrentYearExports = value;
}

void FinanceData::setCurrentYearImports(int32_t value)
{
  mCurrentYearImports = value;
}

void FinanceData::setCurrentYearInterest(int32_t value)
{
  mCurrentYearInterest = value;
}

void FinanceData::setCurrentYearSalary(int32_t value)
{
  mCurrentYearSalary = value;
}

void FinanceData::setCurrentYearSundries(int32_t value)
{
  mCurrentYearSundries = value;
}

void FinanceData::setCurrentYearTaxes(int32_t value)
{
  mCurrentYearTaxes = value;
}

void FinanceData::setCurrentYearTribute(int32_t value)
{
  mCurrentYearTribute = value;
}

void FinanceData::setCurrentYearWages(int32_t value)
{
  mCurrentYearWages = value;
}

void FinanceData::setEstimatedTaxes(int32_t value)
{
  mEstimatedTaxes = value;
  emit changed();
}

void FinanceData::setPercentRegistered(int32_t value)
{
  mPercentRegistered = value;
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

void FinanceData::setTextRate(int32_t value)
{
  mTaxRate = value;
  emit changed();
}

void FinanceData::setTotalDenarii(int32_t value)
{
  mTotalDenarii = value;
  emit changed();
}

int32_t FinanceData::taxRate() const
{
  return mTaxRate;
}
int32_t FinanceData::totalDenarii() const
{
  return mTotalDenarii;
}
