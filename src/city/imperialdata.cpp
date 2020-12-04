#include "imperialdata.h"
#include "resourcedata.h"

#include "imperial/request.h"

#include "resource/resource.h"

ImperialData::ImperialData()
{
  mFavor = 50;
  mGiftPenalty = 1;
  mMonthsSinceGift = 0;
  mModestGiftId = 51;
  mGenerousGiftId = 55;
  mLavishGiftId = 59;
}

ImperialData::~ImperialData()
{

}

void ImperialData::addRequest(std::unique_ptr<Request> request)
{
  mRequests.push_back(std::move(request));
  emit changed();
}

void ImperialData::dispatchGift(Gift *gift)
{
  // After 4 gifts in less than 1 year there is no favor boost
  static const int32_t modestFavor[] = {3, 1, 0, 0};
  static const int32_t generousFavor[] = {5, 3, 1, 0};
  static const int32_t lavishFavor[] = {10, 5, 3, 1};

  // Update favor and gift IDs
  if (gift->type() == Gift::Type::Modest) {
    if (mGiftPenalty <= 4) mFavor += modestFavor[mGiftPenalty];
    if (++mModestGiftId > 54) mModestGiftId = 51;
  }
  else if (gift->type() == Gift::Type::Generous) {
    if (mGiftPenalty <= 4) mFavor += generousFavor[mGiftPenalty];
    if (++mGenerousGiftId > 58) mModestGiftId = 55;
  }
  else if (gift->type() == Gift::Type::Lavish) {
    if (mGiftPenalty <= 4) mFavor += lavishFavor[mGiftPenalty];
    if (++mLavishGiftId > 62) mModestGiftId = 59;
  }

  // Update the gift penalty
  if (mGiftPenalty <= 4)
    mGiftPenalty++;

  // Reset months since last gift
  mMonthsSinceGift = 0;
  emit changed();
}

void ImperialData::dispatchRequest(Request *request, ResourceData * resourceData)
{
  Resource::Type resourceType = request->resource();
  Resource * resource = resourceData->getResource(resourceType);
  int32_t amount = request->amount();
  resource->setAmountStored(resource->amountStored()-amount);
  for (std::vector<RequestPtr>::iterator itr = mRequests.begin(); itr != mRequests.end(); ++itr) {
    if (itr->get() == request) {
      mRequests.erase(itr);
      break;
    }
  }
  emit changed();
}

int32_t ImperialData::favor() const
{
  return mFavor;
}

int32_t ImperialData::generousGiftId() const
{
  return mGenerousGiftId;
}

int32_t ImperialData::giftPenalty() const
{
  return mGiftPenalty;
}

int32_t ImperialData::lavishGiftId() const
{
  return mLavishGiftId;
}

int32_t ImperialData::modestGiftId() const
{
  return mModestGiftId;
}

int32_t ImperialData::monthsSinceGift() const
{
  return mMonthsSinceGift;
}

Request * ImperialData::requestAt(int32_t index)
{
  return mRequests[index].get();
}

void ImperialData::setFavor(int32_t value)
{
  mFavor = value;
  emit changed();
}

void ImperialData::setGenerousGiftId(int32_t value)
{
  mGenerousGiftId = value;
  emit changed();
}

void ImperialData::setGiftPenalty(int32_t value)
{
  mGiftPenalty = value;
  emit changed();
}

void ImperialData::setLavishGiftId(int32_t value)
{
  mLavishGiftId = value;
  emit changed();
}

void ImperialData::setModestGiftId(int32_t value)
{
  mModestGiftId = value;
  emit changed();
}

void ImperialData::setMonthsSinceGift(int32_t value)
{
  mMonthsSinceGift = value;
  if (mMonthsSinceGift >= 12)
    mGiftPenalty = 0;

  emit changed();
}

int32_t ImperialData::totalRequests() const
{
  return static_cast<int32_t>(mRequests.size());
}
