#include "speedoptionsdialog.h"
#include "ui_speedoptionsdialog.h"

#include "application/tiberiusapplication.h"

#include "graphics/font.h"
#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include "language/language.h"
#include "language/stringdata.h"

SpeedOptionsDialog::SpeedOptionsDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::SpeedOptionsDialog)
  , mGameSpeed(70)
  , mScrollSpeed(70)
{
  initUi();
  updateData();
}

SpeedOptionsDialog::~SpeedOptionsDialog()
{
  delete mUi;
}

int SpeedOptionsDialog::gameSpeed() const
{
  return mGameSpeed;
}

void SpeedOptionsDialog::handleDecreaseGameSpeed()
{
  mGameSpeed = (mGameSpeed > 10) ? mGameSpeed - 10 : mGameSpeed;
  updateData();
  emit changed();
}

void SpeedOptionsDialog::handleDecreaseScrollSpeed()
{
  mScrollSpeed = (mScrollSpeed > 10) ? mScrollSpeed - 10 : mScrollSpeed;
  updateData();
  emit changed();
}

void SpeedOptionsDialog::handleIncreaseGameSpeed()
{
  mGameSpeed = (mGameSpeed < 100) ? mGameSpeed + 10 : mGameSpeed;
  updateData();
  emit changed();
}

void SpeedOptionsDialog::handleIncreaseScrollSpeed()
{
  mScrollSpeed = (mScrollSpeed < 100) ? mScrollSpeed + 10 : mScrollSpeed;
  updateData();
  emit changed();
}

void SpeedOptionsDialog::initButton(Button *button, const Font &font, const QString &text)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);

  int32_t w = button->width();
  int32_t h = button->height();

  button->setTextFont(font);
  button->setText(text);
  button->setImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+46));
  button->setHoverImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+43));
}

void SpeedOptionsDialog::initUi()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(45, 0));

  mUi->cGameSpeedLabel->setTextFont(Font::Type::NormalPlain);
  mUi->cGameSpeedLabel->setText(stringData->getString(45, 2));

  mUi->cScrollSpeedLabel->setTextFont(Font::Type::NormalPlain);
  mUi->cScrollSpeedLabel->setText(stringData->getString(45, 3));

  mUi->cIncreaseGameSpeed->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cIncreaseGameSpeed->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cDecreaseGameSpeed->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDecreaseGameSpeed->setPressedImage(imageData->getImageRecord(18)->createImage());

  mUi->cIncreaseScrollSpeed->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cIncreaseScrollSpeed->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cDecreaseScrollSpeed->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDecreaseScrollSpeed->setPressedImage(imageData->getImageRecord(18)->createImage());

  initButton(mUi->cOK, Font::Type::NormalBlack, stringData->getString(45, 4));
  initButton(mUi->cCancel, Font::Type::NormalBlack, stringData->getString(45, 1));

  connect(mUi->cOK, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cDecreaseGameSpeed, SIGNAL(clicked()), SLOT(handleDecreaseGameSpeed()));
  connect(mUi->cDecreaseScrollSpeed, SIGNAL(clicked()), SLOT(handleDecreaseScrollSpeed()));
  connect(mUi->cIncreaseGameSpeed, SIGNAL(clicked()), SLOT(handleIncreaseGameSpeed()));
  connect(mUi->cIncreaseScrollSpeed, SIGNAL(clicked()), SLOT(handleIncreaseScrollSpeed()));
}

int SpeedOptionsDialog::scrollSpeed() const
{
  return mScrollSpeed;
}

void SpeedOptionsDialog::setGameSpeed(int value)
{
  mGameSpeed = value;
  updateData();
}

void SpeedOptionsDialog::setScrollSpeed(int value)
{
  mScrollSpeed = value;
  updateData();
}

void SpeedOptionsDialog::updateData()
{
  mUi->cScrollSpeedPercent->setText(QString::number(mScrollSpeed) + "%");
  mUi->cGameSpeedPercent->setText(QString::number(mGameSpeed) + "%");
}
