#ifndef CAMERA_H
#define CAMERA_H

#include "tiberius.h"

#include <QDataStream>

class Camera
    : public QObject
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL Camera();

public:
  TIBERIUS_LIB_DECL int32_t x() const;
  TIBERIUS_LIB_DECL int32_t y() const;
  TIBERIUS_LIB_DECL void setPosition(int32_t x, int32_t y);
  TIBERIUS_LIB_DECL void setX(int32_t x);
  TIBERIUS_LIB_DECL void setY(int32_t y);

public:
  TIBERIUS_LIB_DECL void loadFromDataStream(QDataStream & dataStream);
  TIBERIUS_LIB_DECL void saveToDataStream(QDataStream & dataStream) const;

private:
  int32_t mX;
  int32_t mY;
};

#endif // CAMERA_H
