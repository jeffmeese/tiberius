#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QListWidget>

class Painter;

class ListWidget
    : public QListWidget
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit ListWidget(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL int firstVisibleItem() const;
  TIBERIUS_LIB_DECL QListWidgetItem * itemAt(const QPoint & pt);
  TIBERIUS_LIB_DECL int totalVisibleItems() const;
  TIBERIUS_LIB_DECL void setFirstVisibleItem(int item);

protected:
  void mousePressEvent(QMouseEvent * event) override;
  void mouseMoveEvent(QMouseEvent * event) override;
  void paintEvent(QPaintEvent * event) override;

private:
  void drawBackground(Painter & painter);
  void drawText(Painter & painter);

private:
  QListWidgetItem * mActiveItem;
  int mFirstVisibleItem;
};

#endif // LISTWIDGET_H
