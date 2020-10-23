#include "videodialog.h"
#include "ui_videodialog.h"

VideoDialog::VideoDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::VideoDialog)
{
  ui->setupUi(this);
}

VideoDialog::~VideoDialog()
{
  delete ui;
}
