#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "game/game.h"

#include <QDebug>
#include <QPainter>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , mUi(new Ui::GameWindow)
{
  init(nullptr);
}

GameWindow::GameWindow(Game * game, QWidget * parent)
  : QWidget(parent)
{
  init(game);
}

GameWindow::~GameWindow()
{
}

void GameWindow::init(Game *game)
{
  mUi->setupUi(this);
  setGame(game);
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
}

void GameWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void GameWindow::setGame(Game *game)
{
  mGame = game;
  mUi->cMapWidget->setMap(nullptr);
  mUi->cMapWidget->setCity(nullptr);
  if (mGame != nullptr) {
    mUi->cMapWidget->setMap(mGame->map());
    mUi->cMapWidget->setCity(mGame->city());
  }
}
