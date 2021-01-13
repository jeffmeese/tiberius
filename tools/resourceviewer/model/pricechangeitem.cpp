#include "pricechangeitem.h"

#include "event/pricechange.h"

PriceChangeItem::PriceChangeItem(PriceChange * priceChange)
  : mPriceChange(priceChange)
{

}

QWidget * PriceChangeItem::createView() const
{
  return nullptr;
}

QList<Property> PriceChangeItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Year", QString::number(mPriceChange->year())));
  propertyList.append(Property("Month", QString::number(mPriceChange->month())));
  propertyList.append(Property("Resource", QString::number(mPriceChange->resourceId())));
  propertyList.append(Property("Amount", QString::number(mPriceChange->amount())));
  propertyList.append(Property("Rise/Fall", QString::number(mPriceChange->rise())));
  return propertyList;
}
