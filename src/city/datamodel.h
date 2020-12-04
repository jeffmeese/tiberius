#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "tiberius.h"

#include <QObject>

#include <cstdint>

class DataModel
    : public QObject
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL int32_t calcPercent(int32_t working, int32_t population) const;
  TIBERIUS_LIB_DECL QString coverageString(int32_t coverage) const;

protected:
  TIBERIUS_LIB_DECL DataModel();

signals:
  TIBERIUS_LIB_DECL void changed();
};

#endif // DATAMODEL_H
