#include "prioritydialog.h"
#include "ui_prioritydialog.h"

#include "application/application.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "language/language.h"
#include "language/stringdata.h"
#include "language/stringdatagroup.h"

#include <QMouseEvent>

PriorityDialog::PriorityDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::PriorityDialog)
  , mSelectedPriority(0)
{
  init();
}

PriorityDialog::~PriorityDialog()
{
  delete mUi;
}

void PriorityDialog::click1()
{
  mSelectedPriority = 1;
  accept();
}

void PriorityDialog::click2()
{
  mSelectedPriority = 2;
  accept();
}

void PriorityDialog::click3()
{
  mSelectedPriority = 3;
  accept();
}

void PriorityDialog::click4()
{
  mSelectedPriority = 4;
  accept();
}

void PriorityDialog::click5()
{
  mSelectedPriority = 5;
  accept();
}

void PriorityDialog::click6()
{
  mSelectedPriority = 6;
  accept();
}

void PriorityDialog::click7()
{
  mSelectedPriority = 7;
  accept();
}

void PriorityDialog::click8()
{
  mSelectedPriority = 8;
  accept();
}

void PriorityDialog::click9()
{
  mSelectedPriority = 9;
  accept();
}

void PriorityDialog::clickNone()
{
  mSelectedPriority = 0;
  accept();
}

void PriorityDialog::init()
{
  mUi->setupUi(this);

  const StringData * stringData = Application::language()->stringData();

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(50, 25));

  mUi->cExit->setTextFont(Font::Type::NormalBlack);
  mUi->cExit->setText(stringData->getString(13, 3));

  mUi->cPriority1->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority2->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority3->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority4->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority5->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority6->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority7->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority8->setTextFont(Font::Type::LargeBrown);
  mUi->cPriority9->setTextFont(Font::Type::LargeBrown);

  mUi->cPriority1->installEventFilter(this);
  mUi->cPriority2->installEventFilter(this);
  mUi->cPriority3->installEventFilter(this);
  mUi->cPriority4->installEventFilter(this);
  mUi->cPriority5->installEventFilter(this);
  mUi->cPriority6->installEventFilter(this);
  mUi->cPriority7->installEventFilter(this);
  mUi->cPriority8->installEventFilter(this);
  mUi->cPriority9->installEventFilter(this);
  mUi->cNone->installEventFilter(this);

  mUi->cNone->setTextFont(Font::Type::NormalBlack);
  mUi->cNone->setText(stringData->getString(50, 26));
}

bool PriorityDialog::eventFilter(QObject *watched, QEvent *event)
{
  if (event->type() == QEvent::MouseButtonPress) {
    QMouseEvent * mouseEvent = dynamic_cast<QMouseEvent*>(event);
    if (mouseEvent->button() == Qt::LeftButton) {
      if (watched == mUi->cPriority1 && mUi->cPriority1->isEnabled()) {
        click1();
      }
      if (watched == mUi->cPriority2 && mUi->cPriority2->isEnabled()) {
        click2();
      }
      if (watched == mUi->cPriority3 && mUi->cPriority3->isEnabled()) {
        click3();
      }
      if (watched == mUi->cPriority4 && mUi->cPriority4->isEnabled()) {
        click4();
      }
      if (watched == mUi->cPriority5 && mUi->cPriority5->isEnabled()) {
        click5();
      }
      if (watched == mUi->cPriority6 && mUi->cPriority6->isEnabled()) {
        click6();
      }
      if (watched == mUi->cPriority7 && mUi->cPriority7->isEnabled()) {
        click7();
      }
      if (watched == mUi->cPriority8 && mUi->cPriority8->isEnabled()) {
        click8();
      }
      if (watched == mUi->cPriority9 && mUi->cPriority9->isEnabled()) {
        click9();
      }
      if (watched == mUi->cNone && mUi->cNone->isEnabled()) {
        clickNone();
      }
    }
  }
  return false;
}

void PriorityDialog::mousePressEvent(QMouseEvent * event)
{
  if (event->button() == Qt::RightButton)
    reject();
}

void PriorityDialog::setMaxPriority(int value)
{
  if (value < 9)
    mUi->cPriority9->setEnabled(false);

  if (value < 8)
    mUi->cPriority8->setEnabled(false);

  if (value < 7)
    mUi->cPriority7->setEnabled(false);

  if (value < 6)
    mUi->cPriority6->setEnabled(false);

  if (value < 5)
    mUi->cPriority5->setEnabled(false);

  if (value < 4)
    mUi->cPriority4->setEnabled(false);

  if (value < 3)
    mUi->cPriority3->setEnabled(false);

  if (value < 2)
    mUi->cPriority2->setEnabled(false);
}
