#include "cityconstructionwindow.h"
#include "ui_cityconstructionwindow.h"

CityConstructionWindow::CityConstructionWindow(QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::CityConstructionWindow)
{
  mUi->setupUi(this);
}

CityConstructionWindow::~CityConstructionWindow()
{
}
