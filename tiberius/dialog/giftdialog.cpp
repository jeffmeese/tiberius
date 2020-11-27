#include "giftdialog.h"
#include "ui_giftdialog.h"

#include "application/application.h"

#include "city/imperialdata.h"

#include "game/player.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "imperial/gift.h"

#include "language/language.h"
#include "language/stringdata.h"

GiftDialog::GiftDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::GiftDialog)
  , mGenerousGiftId(55)
  , mLavishGiftId(59)
  , mModestGiftId(51)
  , mPlayerSavings(0)
  , mGenerousGift(new Gift)
  , mLavishGift(new Gift)
  , mModestGift(new Gift)
{
  init();
  setPlayerSavings(0);
}

GiftDialog::~GiftDialog()
{
  delete mUi;
}

void GiftDialog::handleSelectGenerous()
{
  const StringData * stringData = Application::language()->stringData();
  mUi->cDispatch->setText(stringData->getString(52, 67));
  mSelectedGift = mGenerousGift.get();
}

void GiftDialog::handleSelectLavish()
{
  const StringData * stringData = Application::language()->stringData();
  mUi->cDispatch->setText(stringData->getString(52, 68));
  mSelectedGift = mLavishGift.get();
}

void GiftDialog::handleSelectModest()
{
  const StringData * stringData = Application::language()->stringData();
  mUi->cDispatch->setText(stringData->getString(52, 66));
  mSelectedGift = mModestGift.get();
}

void GiftDialog::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t resourceId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  Font normalWhite(Font::Type::NormalWhite);
  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);

  int32_t textWidth;

  mUi->setupUi(this);

  mGenerousGift->setType(Gift::Type::Generous);
  mModestGift->setType(Gift::Type::Modest);
  mLavishGift->setType(Gift::Type::Lavish);

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(52, 69));

  mUi->cIcon->setImage(imageData->getImageRecord(resourceId+16)->createImage());

  mUi->cDispatch->setTextFont(normalBlack);
  mUi->cDispatch->setText(stringData->getString(52, 66));

  mUi->cCancel->setTextFont(normalBlack);
  mUi->cCancel->setText(stringData->getString(13, 4));

  textWidth = normalWhite.calculateTextWidth(stringData->getString(52, 63));
  mUi->cModestLabel->setTextFont(normalWhite);
  mUi->cModestLabel->setText(stringData->getString(52, 63));
  mUi->cModestLabel->resize(textWidth, 20);

  mUi->cModestGift->setTextFont(normalWhite);
  mUi->cModestGift->move(128, 74);
  mUi->cModestGift->setEnableHover(true);
  initGiftString(mModestGiftId, mUi->cModestGift, mModestGift.get());

  textWidth = normalWhite.calculateTextWidth(stringData->getString(52, 64));
  mUi->cGenerousLabel->setTextFont(normalWhite);
  mUi->cGenerousLabel->setText(stringData->getString(52, 64));
  mUi->cGenerousLabel->resize(textWidth, 20);

  mUi->cGenerousGift->setTextFont(normalWhite);
  mUi->cGenerousGift->move(128, 94);
  mUi->cGenerousGift->setEnableHover(true);
  initGiftString(mGenerousGiftId, mUi->cGenerousGift, mGenerousGift.get());

  textWidth = normalWhite.calculateTextWidth(stringData->getString(52, 65));
  mUi->cLavishLabel->setTextFont(normalWhite);
  mUi->cLavishLabel->setText(stringData->getString(52, 65));
  mUi->cLavishLabel->resize(textWidth, 20);

  mUi->cLavishGift->setTextFont(normalWhite);
  mUi->cLavishGift->move(128, 114);
  mUi->cLavishGift->setEnableHover(true);
  initGiftString(mLavishGiftId, mUi->cLavishGift, mLavishGift.get());

  mUi->cTimeSinceLabel->setTextFont(normalBlack);
  mUi->cTimeSinceLabel->setText(stringData->getString(52, 50) + " ");
  textWidth = normalBlack.calculateTextWidth(mUi->cTimeSinceLabel->text());
  mUi->cTimeSinceLabel->resize(textWidth, 20);

  mUi->cTimeSinceAmount->setTextFont(normalBlack);
  mUi->cTimeSinceAmount->move(48+textWidth, 162);

  QString textString = QString::number(0);
  textString += " " + stringData->getString(59, 6);
  textWidth = normalBlack.calculateTextWidth(textString);
  mUi->cTimeSinceAmount->setText(textString);
  mUi->cTimeSinceAmount->resize(textWidth, 20);

  mSelectedGift = mModestGift.get();

  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cDispatch, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cGenerousGift, SIGNAL(clicked()), SLOT(handleSelectGenerous()));
  connect(mUi->cModestGift, SIGNAL(clicked()), SLOT(handleSelectModest()));
  connect(mUi->cLavishGift, SIGNAL(clicked()), SLOT(handleSelectLavish()));
}

void GiftDialog::initGiftString(int32_t textId, Label * label, Gift * gift)
{
  const StringData * stringData = Application::language()->stringData();

  Font normalWhite(Font::Type::NormalWhite);
  Font normalRed(Font::Type::NormalRed);

  int32_t cost = gift->calculateCost(mPlayerSavings);
  QString giftString = stringData->getString(52, textId);
  giftString += " " + QString::number(cost) + " ";
  giftString += stringData->getString(6, 0);

  int32_t textWidth = normalRed.calculateTextWidth(giftString);
  label->setText(giftString);
  label->resize(textWidth, 20);
}

Gift * GiftDialog::selectedGift()
{
  return mSelectedGift;
}

void GiftDialog::setGenerousGiftId(int32_t value)
{
  mGenerousGiftId = value;
  //mGenerousGift->setTextId(value);
  initGiftString(value, mUi->cGenerousGift, mGenerousGift.get());
}

void GiftDialog::setLavishGiftId(int32_t value)
{
  mLavishGiftId = value;
  //mLavishGift->setTextId(value);
  initGiftString(value, mUi->cLavishGift, mLavishGift.get());
}

void GiftDialog::setModestGiftId(int32_t value)
{
  mModestGiftId = value;
  //mModestGift->setTextId(value);
  initGiftString(value, mUi->cModestGift, mModestGift.get());
}

void GiftDialog::setPlayerSavings(int32_t value)
{
  mPlayerSavings = value;
  int32_t modestCost = mModestGift->calculateCost(mPlayerSavings);
  int32_t generousCost = mGenerousGift->calculateCost(mPlayerSavings);
  int32_t lavishCost = mLavishGift->calculateCost(mPlayerSavings);
  initGiftString(mModestGiftId, mUi->cModestGift, mModestGift.get());
  initGiftString(mLavishGiftId, mUi->cLavishGift, mLavishGift.get());
  initGiftString(mGenerousGiftId, mUi->cGenerousGift, mGenerousGift.get());

  mUi->cModestLabel->setVisible(mPlayerSavings >= modestCost);
  mUi->cModestGift->setVisible(mPlayerSavings >= modestCost);

  mUi->cGenerousLabel->setVisible(mPlayerSavings >= generousCost);
  mUi->cGenerousGift->setVisible(mPlayerSavings >= generousCost);

  mUi->cLavishLabel->setVisible(mPlayerSavings >= lavishCost);
  mUi->cLavishGift->setVisible(mPlayerSavings >= lavishCost);
}
