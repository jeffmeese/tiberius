#ifndef FINANCEDATA_H
#define FINANCEDATA_H

#include "tiberius.h"

#include <cstdint>

class FinanceData
{
public:
  TIBERIUS_LIB_DECL FinanceData();

public:
  TIBERIUS_LIB_DECL int32_t previousYearBalance() const;
  TIBERIUS_LIB_DECL int32_t totalDenarii() const;
  TIBERIUS_LIB_DECL void setPreviousYearBalance(int32_t value);
  TIBERIUS_LIB_DECL void setTotalDenarii(int32_t value);

public:
  TIBERIUS_LIB_DECL void decreaseDenarii(int32_t value);
  TIBERIUS_LIB_DECL void increaseDenarii(int32_t value);

private:
  int32_t mPreviousYearBalance;
  int32_t mTotalDenarii;
};

#endif // FINANCEDATA_H
