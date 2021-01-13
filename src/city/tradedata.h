#ifndef TRADEDATA_H
#define TRADEDATA_H

#include "datamodel.h"

#include "resource/resource.h"

class TradeData
    : public DataModel
{
public:
  TIBERIUS_LIB_DECL TradeData();

public:
  TIBERIUS_LIB_DECL int32_t buyPrice(Resource::Type type) const;
  TIBERIUS_LIB_DECL int32_t sellPrice(Resource::Type type);
  TIBERIUS_LIB_DECL void setBuyPrice(Resource::Type type, int32_t value);
  TIBERIUS_LIB_DECL void setSellPrice(Resource::Type type, int32_t value);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:

};

#endif // TRADEDATA_H
