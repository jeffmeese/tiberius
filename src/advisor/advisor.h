#ifndef ADVISOR_H
#define ADVISOR_H

#include "tiberius.h"

class Advisor
{
public:
  enum class Type
  {
    Chief = 0,
    Labor = 1,
    Ratings = 2,
    Population = 3,
    Education = 4,
    Emperor = 5,
    Entertainment = 6,
    Military = 7,
    Religion = 8,
    Trade = 9,
    Health = 10,
    Government = 11
  };

public:
  TIBERIUS_LIB_DECL Advisor();
};

#endif // ADVISOR_H
