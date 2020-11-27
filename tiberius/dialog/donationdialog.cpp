#include "donationdialog.h"
#include "ui_donationdialog.h"

#include "application/application.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

DonationDialog::DonationDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::DonationDialog)
  , mDonationAmount(0)
  , mPersonalSavings(0)
{
  init();
}

DonationDialog::~DonationDialog()
{
  delete mUi;
}

int32_t DonationDialog::donationAmount() const
{
  return mDonationAmount;
}

void DonationDialog::handle500()
{
  updateDonationAmount(500);
}

void DonationDialog::handle2000()
{
  updateDonationAmount(2000);
}

void DonationDialog::handle5000()
{
  updateDonationAmount(5000);
}

void DonationDialog::handleAll()
{
  updateDonationAmount(mPersonalSavings);
}

void DonationDialog::handleCancel()
{
  reject();
}

void DonationDialog::handleDown()
{
  updateDonationAmount(mDonationAmount-10);
}

void DonationDialog::handleGive()
{
  accept();
}

void DonationDialog::handleUp()
{
  updateDonationAmount(mDonationAmount+10);
}

void DonationDialog::handleZero()
{
  updateDonationAmount(0);
}

void DonationDialog::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t resourceId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  Font normalWhite(Font::Type::NormalWhite);
  Font largeBlack(Font::Type::LargeBlack);

  mUi->setupUi(this);

  mUi->cIcon->setImage(imageData->getImageRecord(resourceId+16)->createImage());

  mUi->cZero->setTextFont(normalWhite);
  mUi->cZero->setText("0");

  mUi->c500->setTextFont(normalWhite);
  mUi->c500->setText("500");

  mUi->c2000->setTextFont(normalWhite);
  mUi->c2000->setText("2000");

  mUi->c5000->setTextFont(normalWhite);
  mUi->c5000->setText("5000");

  mUi->cAll->setTextFont(normalWhite);
  mUi->cAll->setText(stringData->getString(52, 19));

  mUi->cGiveMoney->setTextFont(normalWhite);
  mUi->cGiveMoney->setText(stringData->getString(52, 18));

  mUi->cCancel->setTextFont(normalWhite);
  mUi->cCancel->setText(stringData->getString(44, 17));

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(52, 16));

  mUi->cDonationLabel->setTextFont(normalWhite);
  mUi->cDonationLabel->setText(stringData->getString(52, 17));
  mUi->cDonationLabel->resize(normalWhite.calculateTextWidth(mUi->cDonationLabel->text()), 20);

  mUi->cDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDown->setPressedImage(imageData->getImageRecord(18)->createImage());
  mUi->cUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cDonationAmount->setTextFont(normalWhite);

  connect(mUi->cZero, SIGNAL(clicked()), SLOT(handleZero()));
  connect(mUi->c500, SIGNAL(clicked()), SLOT(handle500()));
  connect(mUi->c2000, SIGNAL(clicked()), SLOT(handle2000()));
  connect(mUi->c5000, SIGNAL(clicked()), SLOT(handle5000()));
  connect(mUi->cAll, SIGNAL(clicked()), SLOT(handleAll()));
  connect(mUi->cGiveMoney, SIGNAL(clicked()), SLOT(handleGive()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(handleCancel()));
  connect(mUi->cUp, SIGNAL(clicked()), SLOT(handleUp()));
  connect(mUi->cDown, SIGNAL(clicked()), SLOT(handleDown()));
}

void DonationDialog::setPersonalSavings(int32_t value)
{
  mPersonalSavings = value;
}

void DonationDialog::updateDonationAmount(int32_t value)
{
  if (value < 0)
    value = 0;

  if (value > mPersonalSavings)
    value = mPersonalSavings;

  Font f(Font::Type::NormalWhite);
  int32_t textWidth = f.calculateTextWidth(QString::number(value));

  mDonationAmount = value;
  mUi->cDonationAmount->setText(QString::number(value));
  mUi->cDonationAmount->resize(textWidth, 20);
}
