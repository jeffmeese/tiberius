#ifndef FINANCEDATA_H
#define FINANCEDATA_H

#include "datamodel.h"

class FinanceData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL FinanceData();

public:
  TIBERIUS_LIB_DECL int32_t currentYearConstruction() const;
  TIBERIUS_LIB_DECL int32_t currentYearDonated() const;
  TIBERIUS_LIB_DECL int32_t currentYearExports() const;
  TIBERIUS_LIB_DECL int32_t currentYearImports() const;
  TIBERIUS_LIB_DECL int32_t currentYearInterest() const;
  TIBERIUS_LIB_DECL int32_t currentYearSalary() const;
  TIBERIUS_LIB_DECL int32_t currentYearSundries() const;
  TIBERIUS_LIB_DECL int32_t currentYearTaxes() const;
  TIBERIUS_LIB_DECL int32_t currentYearTribute() const;
  TIBERIUS_LIB_DECL int32_t currentYearWages() const;
  TIBERIUS_LIB_DECL int32_t estimatedTaxes() const;
  TIBERIUS_LIB_DECL int32_t percentRegistered() const;
  TIBERIUS_LIB_DECL int32_t previousYearBalance() const;
  TIBERIUS_LIB_DECL int32_t previousYearConstruction() const;
  TIBERIUS_LIB_DECL int32_t previousYearDonated() const;
  TIBERIUS_LIB_DECL int32_t previousYearExports() const;
  TIBERIUS_LIB_DECL int32_t previousYearImports() const;
  TIBERIUS_LIB_DECL int32_t previousYearInterest() const;
  TIBERIUS_LIB_DECL int32_t previousYearSalary() const;
  TIBERIUS_LIB_DECL int32_t previousYearSundries() const;
  TIBERIUS_LIB_DECL int32_t previousYearTaxes() const;
  TIBERIUS_LIB_DECL int32_t previousYearTribute() const;
  TIBERIUS_LIB_DECL int32_t previousYearWages() const;
  TIBERIUS_LIB_DECL int32_t taxRate() const;
  TIBERIUS_LIB_DECL int32_t totalDenarii() const;
  TIBERIUS_LIB_DECL void setCurrentYearConstruction(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearDonated(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearExports(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearImports(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearInterest(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearSalary(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearSundries(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearTaxes(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearTribute(int32_t value);
  TIBERIUS_LIB_DECL void setCurrentYearWages(int32_t value);
  TIBERIUS_LIB_DECL void setEstimatedTaxes(int32_t value);
  TIBERIUS_LIB_DECL void setPercentRegistered(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearBalance(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearConstruction(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearDonated(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearExports(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearImports(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearInterest(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearSalary(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearSundries(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearTaxes(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearTribute(int32_t value);
  TIBERIUS_LIB_DECL void setPreviousYearWages(int32_t value);
  TIBERIUS_LIB_DECL void setTextRate(int32_t value);
  TIBERIUS_LIB_DECL void setTotalDenarii(int32_t value);

public:
  TIBERIUS_LIB_DECL int32_t currentYearExpenses() const;
  TIBERIUS_LIB_DECL int32_t currentYearIncome() const;
  TIBERIUS_LIB_DECL void decreaseDenarii(int32_t value);
  TIBERIUS_LIB_DECL void decreaseTaxes(int32_t value);
  TIBERIUS_LIB_DECL void increaseDenarii(int32_t value);
  TIBERIUS_LIB_DECL void increaseTaxes(int32_t value);
  TIBERIUS_LIB_DECL int32_t previousYearExpenses() const;
  TIBERIUS_LIB_DECL int32_t previousYearIncome() const;

private:
  int32_t mCurrentYearConstruction;
  int32_t mCurrentYearDonated;
  int32_t mCurrentYearExports;
  int32_t mCurrentYearImports;
  int32_t mCurrentYearInterest;
  int32_t mCurrentYearSalary;
  int32_t mCurrentYearSundries;
  int32_t mCurrentYearTaxes;
  int32_t mCurrentYearTribute;
  int32_t mCurrentYearWages;
  int32_t mEstimatedTaxes;
  int32_t mPercentRegistered;
  int32_t mPreviousYearBalance;
  int32_t mPreviousYearConstruction;
  int32_t mPreviousYearDonated;
  int32_t mPreviousYearExports;
  int32_t mPreviousYearImports;
  int32_t mPreviousYearInterest;
  int32_t mPreviousYearSalary;
  int32_t mPreviousYearSundries;
  int32_t mPreviousYearTaxes;
  int32_t mPreviousYearTribute;
  int32_t mPreviousYearWages;
  int32_t mTaxRate;
  int32_t mTotalDenarii;
};

#endif // FINANCEDATA_H
