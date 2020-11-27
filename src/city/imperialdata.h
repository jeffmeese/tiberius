#ifndef IMPERIALDATA_H
#define IMPERIALDATA_H

#include "tiberius.h"

#include "imperial/gift.h"

#include <cstdint>
#include <memory>
#include <vector>

class Gift;
class Request;

class ImperialData
{
public:
  static const int32_t TOTAL_REQUESTS = 20;

public:
  TIBERIUS_LIB_DECL ImperialData();
  TIBERIUS_LIB_DECL ~ImperialData();

public:
  TIBERIUS_LIB_DECL int32_t favor() const;
  TIBERIUS_LIB_DECL int32_t generousGiftId() const;
  TIBERIUS_LIB_DECL int32_t giftPenalty() const;
  TIBERIUS_LIB_DECL int32_t lavishGiftId() const;
  TIBERIUS_LIB_DECL int32_t modestGiftId() const;
  TIBERIUS_LIB_DECL int32_t monthsSinceGift() const;
  TIBERIUS_LIB_DECL void setFavor(int32_t value);
  TIBERIUS_LIB_DECL void setGenerousGiftId(int32_t value);
  TIBERIUS_LIB_DECL void setGiftPenalty(int32_t value);
  TIBERIUS_LIB_DECL void setLavishGiftId(int32_t value);
  TIBERIUS_LIB_DECL void setModestGiftId(int32_t value);
  TIBERIUS_LIB_DECL void setMonthsSinceGift(int32_t value);

public:
  TIBERIUS_LIB_DECL void dispatchGift(Gift * gift);
  TIBERIUS_LIB_DECL Request * requestAt(int32_t index);
  TIBERIUS_LIB_DECL int32_t totalRequests() const;

public:
  TIBERIUS_LIB_DECL void addRequest(std::unique_ptr<Request> request);

private:
  typedef std::unique_ptr<Request> RequestPtr;
  typedef std::vector<RequestPtr> RequestVector;

private:
  int32_t mFavor;
  int32_t mGiftPenalty;
  int32_t mMonthsSinceGift;
  int32_t mGenerousGiftId;
  int32_t mLavishGiftId;
  int32_t mModestGiftId;
  RequestVector mRequests;
};

#endif // IMPERIALDATA_H
