#ifndef SCRIBEMESSAGEDATA_H
#define SCRIBEMESSAGEDATA_H

#include "tiberius.h"

#include <cstdint>
#include <memory>
#include <vector>

#include <QDataStream>

class ScribeMessage;

class ScribeMessageData
{
public:
  static const int MAX_MESSAGES = 1000;

public:
  TIBERIUS_LIB_DECL ScribeMessageData();
  TIBERIUS_LIB_DECL ~ScribeMessageData();

public:
  TIBERIUS_LIB_DECL void loadFromStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToStream(QDataStream & dataStream) const;

private:
  using ScribeMessagePtr = std::unique_ptr<ScribeMessage>;
  using ScribeMessageVector = std::vector<ScribeMessagePtr>;

private:
  ScribeMessageVector mScribeMessages;
};

#endif // SCRIBEMESSAGEDATA_H
