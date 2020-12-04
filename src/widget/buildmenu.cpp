#include "buildmenu.h"

#include "buildmenuitem.h"

#include <QImage>
#include <QPainter>

BuildMenu::BuildMenu(QWidget * parentWidget)
  : QWidget(parentWidget)
  , mItemMargin(5)
{
  setWindowFlags(Qt::FramelessWindowHint);
}

void BuildMenu::addItem(std::unique_ptr<BuildMenuItem> item)
{
  item->setParent(this);
  mItems.push_back(std::move(item));
  calcLayout();
}

void BuildMenu::calcLayout()
{
  int32_t yOffset = mItemMargin;
  for (std::size_t i = 0; i < mItems.size(); i++) {
    BuildMenuItem * menuItem = mItems.at(i).get();
    if (menuItem->isEnabled()) {
      //menuItem->move(0, i*(menuItem->height() + mItemMargin));
      menuItem->move(0, yOffset);
      yOffset += menuItem->height() + mItemMargin;
    }
  }
}

void BuildMenu::clear()
{
  mItems.clear();
  calcLayout();
}

BuildMenuItem * BuildMenu::itemAt(std::size_t index)
{
  return mItems.at(index).get();
}

const BuildMenuItem * BuildMenu::itemAt(std::size_t index) const
{
  return mItems.at(index).get();
}

void BuildMenu::resizeEvent(QResizeEvent *)
{
  calcLayout();
}

std::size_t BuildMenu::totalItems() const
{
  return mItems.size();
}
