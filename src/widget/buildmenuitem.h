#ifndef BUILDMENUITEM_H
#define BUILDMENUITEM_H

#include "button.h"

class BuildMenuItem
    : public Button
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit BuildMenuItem(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL bool available() const;
  TIBERIUS_LIB_DECL int32_t price() const;
  TIBERIUS_LIB_DECL void setAvailable(bool value);
  TIBERIUS_LIB_DECL void setPrice(int32_t price);

protected:
  void paintEvent(QPaintEvent *) override;

private:
  bool mAvailable;
  int32_t mPrice;
};

inline bool BuildMenuItem::available() const
{
  return mAvailable;
}

inline int32_t BuildMenuItem::price() const
{
  return mPrice;
}

inline void BuildMenuItem::setAvailable(bool value)
{
  mAvailable = value;
}

inline void BuildMenuItem::setPrice(int32_t price)
{
  mPrice = price;
}

#endif // BUILDMENUITEM_H
