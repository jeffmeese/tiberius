#ifndef MENU_H
#define MENU_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QMenu>

class MenuItem;
class Painter;

class Menu
    : public QMenu
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit Menu(QWidget * parentWidget = nullptr);
  TIBERIUS_LIB_DECL Menu(const QString & title, QWidget * parentWidget = nullptr);

protected:
  void mouseMoveEvent(QMouseEvent * event) override;
  void mouseReleaseEvent(QMouseEvent * event) override;
  void paintEvent(QPaintEvent *) override;

private:
  void computeAdjustedDimensions();
  void drawBackground(Painter & painter);
  void drawMenuItems(Painter & painter);
  void init(const QString & title = QString());

private:
  int32_t mFocusedItem;
  int32_t mAdjustedWidth;
  int32_t mAdjustedHeight;
};

#endif // MENU_H
