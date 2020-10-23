#include "empirewindow.h"
#include "ui_empirewindow.h"

EmpireWindow::EmpireWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::EmpireWindow)
{
  mUi->setupUi(this);
}

EmpireWindow::~EmpireWindow()
{
}
