#ifndef SGPIXELDATA_H
#define SGPIXELDATA_H

#include <cstdint>

#include <QByteArray>
#include <QString>

#include "tiberius.h"

class SgPixelData
{
public:
  TIBERIUS_LIB_DECL SgPixelData();
  TIBERIUS_LIB_DECL ~SgPixelData();

public:
  TIBERIUS_LIB_DECL const char * data() const;
  TIBERIUS_LIB_DECL int32_t size() const;

public:
  TIBERIUS_LIB_DECL bool loadFromFile(const QString & fileName);

private:
  QByteArray mData;
};

inline const char * SgPixelData::data() const
{
  return mData.constData();
}

inline int32_t SgPixelData::size() const
{
  return mData.size();
}

#endif // SGPIXELDATA_H
