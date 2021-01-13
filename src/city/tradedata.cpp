#include "tradedata.h"

#include "core/streamio.h"

#include <QByteArray>

static const int32_t DATA_SIZE = 1280;

TradeData::TradeData()
{

}

void TradeData::loadFromDataStream(QDataStream &dataStream)
{
  QByteArray quotaData = streamio::readCompressedData(dataStream, DATA_SIZE);
  QByteArray volumeData = streamio::readCompressedData(dataStream, DATA_SIZE);
}

void TradeData::saveToDataStream(QDataStream &dataStream) const
{

}
