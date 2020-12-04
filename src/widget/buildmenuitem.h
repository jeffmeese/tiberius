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
  TIBERIUS_LIB_DECL int32_t price() const;
  TIBERIUS_LIB_DECL void setPrice(int32_t price);

protected:
  void paintEvent(QPaintEvent *) override;

private:
  int32_t mPrice;
};

inline int32_t BuildMenuItem::price() const
{
  return mPrice;
}

inline void BuildMenuItem::setPrice(int32_t price)
{
  mPrice = price;
}

#endif // BUILDMENUITEM_H
