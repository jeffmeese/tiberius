#include "financedata.h"

FinanceData::FinanceData()
{
  mTotalDenarii = 0;
  mPreviousYearBalance = 4159;
}

void FinanceData::decreaseDenarii(int32_t value)
{
  mTotalDenarii -= value;
}

void FinanceData::increaseDenarii(int32_t value)
{
  mTotalDenarii += value;
}

int32_t FinanceData::previousYearBalance() const
{
  return mPreviousYearBalance;
}

void FinanceData::setPreviousYearBalance(int32_t value)
{
  mPreviousYearBalance = value;
}

void FinanceData::setTotalDenarii(int32_t value)
{
  mTotalDenarii = value;
}

int32_t FinanceData::totalDenarii() const
{
  return mTotalDenarii;
}
