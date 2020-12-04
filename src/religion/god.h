#ifndef GOD_H
#define GOD_H

#include "tiberius.h"

#include <QString>

#include <cstdint>

class God
{
public:
  enum class Type
  {
    Ceres = 0,
    Neptune = 1,
    Mercury = 2,
    Mars = 3,
    Venus = 4
  };

  enum class Sentiment
  {
    Wrathful = 0,
    VeryAngry = 1,
    Angry = 2,
    Irritated = 3,
    Displeased = 4,
    Indifferent = 5,
    Pleased = 6,
    Happy = 7,
    Charmed = 8,
    Delighted = 9,
    Exalted = 10
  };

public:
  TIBERIUS_LIB_DECL God(Type type);

public:
  TIBERIUS_LIB_DECL int32_t angerBolts() const;
  TIBERIUS_LIB_DECL int32_t largeTemples() const;
  TIBERIUS_LIB_DECL int32_t monthsSinceFestival() const;
  TIBERIUS_LIB_DECL Sentiment sentiment() const;
  TIBERIUS_LIB_DECL int32_t smallTemples() const;
  TIBERIUS_LIB_DECL Type type() const;
  TIBERIUS_LIB_DECL void setAngerBolts(int32_t value);
  TIBERIUS_LIB_DECL void setLargeTemples(int32_t value);
  TIBERIUS_LIB_DECL void setMonthsSinceFestival(int32_t value);
  TIBERIUS_LIB_DECL void setSentiment(Sentiment value);
  TIBERIUS_LIB_DECL void setSmallTemples(int32_t value);

public:
  TIBERIUS_LIB_DECL QString description() const;
  TIBERIUS_LIB_DECL QString name() const;
  TIBERIUS_LIB_DECL QString sentimentString() const;

public:
  TIBERIUS_LIB_DECL static QString description(Type type);
  TIBERIUS_LIB_DECL static QString name(Type type);
  TIBERIUS_LIB_DECL static QString sentimentString(Sentiment type);

private:
  int32_t mAngerBolts;
  int32_t mLargeTemples;
  int32_t mMonthsSinceFestival;
  int32_t mSmallTemples;
  Sentiment mSentiment;
  Type mType;
};

#endif // GOD_H
