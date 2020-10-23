#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "tiberius.h"
#include "tiberiuswidget.h"

#include <QLineEdit>
#include <QTimer>

class Painter;

class LineEdit
    : public QLineEdit
    , public TiberiusWidget
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit LineEdit(QWidget * parentWidget = nullptr);

protected:
  void keyPressEvent(QKeyEvent *) override;
  void paintEvent(QPaintEvent * event) override;

private slots:
  void updateCursor();

private:
  void addCharacter(const QString & text);
  void drawBackground(Painter & painter);
  void drawCursor(Painter & painter);
  void drawText(Painter & painter);
  void handleBackspace();
  void handleDelete();
  void moveCursorLeft();
  void moveCursorRight();
  void moveCursorHome();
  void moveCursorEnd();
  void removeCharacter();

private:
  QTimer mTimer;
  bool mCursorVisible;
};


#endif // TEXTEDIT_H
