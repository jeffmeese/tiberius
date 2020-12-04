#ifndef RATINGSDATA_H
#define RATINGSDATA_H

#include "datamodel.h"

class RatingsData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL RatingsData();

public:
  TIBERIUS_LIB_DECL int32_t culture() const;
  TIBERIUS_LIB_DECL int32_t favor() const;
  TIBERIUS_LIB_DECL int32_t peace() const;
  TIBERIUS_LIB_DECL int32_t prosperity() const;
  TIBERIUS_LIB_DECL int32_t targetCulture() const;
  TIBERIUS_LIB_DECL int32_t targetFavor() const;
  TIBERIUS_LIB_DECL int32_t targetPeace() const;
  TIBERIUS_LIB_DECL int32_t targetPopulation() const;
  TIBERIUS_LIB_DECL int32_t targetProsperity() const;
  TIBERIUS_LIB_DECL void setCulture(int32_t value);
  TIBERIUS_LIB_DECL void setFavor(int32_t value);
  TIBERIUS_LIB_DECL void setPeace(int32_t value);
  TIBERIUS_LIB_DECL void setProsperity(int32_t value);
  TIBERIUS_LIB_DECL void setTargetCulture(int32_t value);
  TIBERIUS_LIB_DECL void setTargetFavor(int32_t value);
  TIBERIUS_LIB_DECL void setTargetPeace(int32_t value);
  TIBERIUS_LIB_DECL void setTargetPopulation(int32_t value);
  TIBERIUS_LIB_DECL void setTargetProsperity(int32_t value);

private:
  int32_t mCulture;
  int32_t mFavor;
  int32_t mPeace;
  int32_t mProsperity;
  int32_t mTargetCulture;
  int32_t mTargetFavor;
  int32_t mTargetPeace;
  int32_t mTargetPopulation;
  int32_t mTargetProsperity;
};

#endif // RATINGSDATA_H
