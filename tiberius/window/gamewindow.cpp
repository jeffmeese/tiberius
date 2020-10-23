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

  //connect(mUi->cSidebar, SIGNAL(collapsed()), SLOT(update()));
  //connect(mUi->cSidebar, SIGNAL(expanded()), SLOT(update()));
  //connect(mUi->cSidebar, SIGNAL(orientNorth()), mUi->cCity, SLOT(orientNorth()));
  //connect(mUi->cSidebar, SIGNAL(rotateLeft()), mUi->cCity, SLOT(rotateLeft()));
  //connect(mUi->cSidebar, SIGNAL(rotateRight()), mUi->cCity, SLOT(rotateRight()));
  //connect(mUi->cSidebar, SIGNAL(showAdvisors()), SLOT(showAdvisors()));
  //connect(mUi->cSidebar, SIGNAL(showEmpire()), SLOT(showEmpire()));
  //connect(mUi->cSidebar, SIGNAL(showMessages()), SLOT(showMessages()));
  //connect(mUi->cSidebar, SIGNAL(undoLastAction()), SLOT(undoLastAction()));
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
//  if (event->button() == Qt::RightButton) {
//    mUi->cSidebar->cancelMenu();
//    mUi->cCity->cancelConstruction();
//  }
}

void GameWindow::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.fillRect(0, 0, width(), height(), QBrush(Qt::black));
}

void GameWindow::resizeEvent(QResizeEvent *)
{
}

void GameWindow::setGame(Game *game)
{
  mGame = game;
  //mUi->cCity->setGame(game);
}
