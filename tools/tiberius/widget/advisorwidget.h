#ifndef ADVISORWIDGET_H
#define ADVISORWIDGET_H

#include <QWidget>

class Game;

class AdvisorWidget
    : public QWidget
{
  Q_OBJECT

public:
  explicit AdvisorWidget(QWidget *parent = nullptr);

public:
  Game * game();
  void setGame(Game * game);

public slots:
  void update();

protected:
  void paintEvent(QPaintEvent * event) override;

protected:
  virtual void doUpdate() = 0;

private:
  void drawBorder(QPainter & painter);

signals:
  void changed();

private:
  Game * mGame;
};

#endif // ADVISORWIDGET_H
