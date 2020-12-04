#ifndef BUILDMENU_H
#define BUILDMENU_H

#include <QWidget>

#include <memory>
#include <vector>

#include "tiberius.h"

class BuildMenuItem;

class BuildMenu
    : public QWidget
{
public:
  TIBERIUS_LIB_DECL explicit BuildMenu(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL int32_t itemMargin() const;
  TIBERIUS_LIB_DECL void setItemMargin(int32_t margin);

public:
  TIBERIUS_LIB_DECL void addItem(std::unique_ptr<BuildMenuItem> item);
  TIBERIUS_LIB_DECL void clear();
  TIBERIUS_LIB_DECL BuildMenuItem * itemAt(std::size_t index);
  TIBERIUS_LIB_DECL const BuildMenuItem * itemAt(std::size_t index) const;
  TIBERIUS_LIB_DECL std::size_t totalItems() const;

protected:
  void resizeEvent(QResizeEvent *event) override;

private:
  void calcLayout();

private:
  typedef std::unique_ptr<BuildMenuItem> MenuItemPtr;

private:
  int32_t mItemMargin;
  std::vector<MenuItemPtr> mItems;
};

inline int32_t BuildMenu::itemMargin() const
{
  return mItemMargin;
}

inline void BuildMenu::setItemMargin(int32_t margin)
{
  mItemMargin = margin;
}

#endif // BUILDMENU_H
