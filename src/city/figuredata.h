#ifndef FIGUREDATA_H
#define FIGUREDATA_H

#include "datamodel.h"

#include <cstdint>

class FigureData
    : public DataModel
{
public:
  static const int32_t MAX_CHARACTERS = 10000;

public:
  TIBERIUS_LIB_DECL FigureData();
};

#endif // FIGUREDATA_H
