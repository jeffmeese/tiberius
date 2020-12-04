#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <memory>

#include <QWidget>

class Game;
namespace Ui
{
  class GameWindow;
}

class GameWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit GameWindow(QWidget *parent = nullptr);
  GameWindow(Game * game, QWidget * parent = nullptr);
  ~GameWindow();

public:
  Game * game();
  const Game * game() const;
  void setGame(Game * game);

protected:
  void mousePressEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;

private:
  void init(Game * game);

private:
  std::unique_ptr<Ui::GameWindow> mUi;
  Game * mGame;
};

inline Game * GameWindow::game()
{
  return mGame;
}

inline const Game * GameWindow::game() const
{
  return mGame;
}

#endif // GAMEVIEW_H
