#include "requestitem.h"

#include "event/emperorrequest.h"

RequestItem::RequestItem(EmperorRequest * request)
  : mRequest(request)
{

}

QWidget * RequestItem::createView() const
{
  return nullptr;
}

QList<Property> RequestItem::getProperties() const
{
  QList<Property> propertyList;
  propertyList.append(Property("Year", QString::number(mRequest->year())));
  propertyList.append(Property("Month", QString::number(mRequest->month())));
  propertyList.append(Property("Amount", QString::number(mRequest->amount())));
  propertyList.append(Property("Resource", QString::number(mRequest->resourceId())));
  propertyList.append(Property("Deadline", QString::number(mRequest->deadline())));
  propertyList.append(Property("Favor", QString::number(mRequest->favor())));
  return propertyList;
}
