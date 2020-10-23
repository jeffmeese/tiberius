#ifndef MENUBAR_H
#define MENUBAR_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QMenuBar>

class Painter;

class MenuBar
    : public QMenuBar
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit MenuBar(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL bool eventFilter(QObject * source, QEvent * event);

protected:
  void mousePressEvent(QMouseEvent *) override;
  void paintEvent(QPaintEvent *event) override;

private:
  void activateMenu(QMenu * menu, const QPoint & menuPos);
  void deactivateMenu(QMenu * menu);
  void drawBackground(Painter & painter);
  void drawMenus(Painter & painter);
  QMenu * menuAt(const QPoint & pos, QRect & menuRect);

private slots:
  void handleAboutToHide();

private:
  QMenu * mActiveMenu;
};

#endif // MENUBAR_H
