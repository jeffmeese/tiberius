#include "laboradvisorbutton.h"

#include "application/application.h"

#include "graphics/font.h"
#include "graphics/imagegroups.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "widget/label.h"

#include <QDebug>

LaborAdvisorButton::LaborAdvisorButton(QWidget * widget)
  : BorderedButton(widget)
{
  init();
}

void LaborAdvisorButton::init()
{
  const SgImageData * imageData = Application::climateImages();

  mLock.reset(new QLabel(this));
  mPriority.reset(new Label(this));
  mSector.reset(new Label(this));
  mHave.reset(new Label(this));
  mNeed.reset(new Label(this));

  mPriority->setTextFont(Font::Type::NormalWhite);
  mSector->setTextFont(Font::Type::NormalWhite);
  mHave->setTextFont(Font::Type::NormalWhite);
  mNeed->setTextFont(Font::Type::NormalWhite);

  mLock->move(24, 4);
  mPriority->move(52, 2);
  mSector->move(130, 5);
  mHave->move(360, 2);
  mNeed->move(452, 2);

  mPriority->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  mSector->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mHave->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  mNeed->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

  mSector->resize(210, 22);
  mLock->resize(11, 17);
  mPriority->resize(24, 20);
  mHave->resize(48, 20);
  mNeed->resize(48, 20);

  int32_t baseImageId = imageData->getGroupBaseImageId(GROUP_LABOR_PRIORITY_LOCK);
  QPixmap p = QPixmap::fromImage(imageData->getImageRecord(baseImageId)->createImage());
  mLock->setPixmap(p);
}

void LaborAdvisorButton::setPriority(int level)
{
  if (level == 0) {
    mLock->setVisible(false);
    mPriority->setVisible(false);
    update();
    return;
  }

  mLock->setVisible(true);
  mPriority->setVisible(true);
  QString s = QString::number(level);
  mPriority->setText(s);
  update();
}

void LaborAdvisorButton::setSector(const QString & text)
{
  mSector->setText(text);
  update();
}

void LaborAdvisorButton::setHave(int value)
{
  QString s = QString::number(value);
  mHave->setText(s);
}

void LaborAdvisorButton::setNeed(int value)
{
  QString s = QString::number(value);
  mNeed->setText(s);
  update();
}
