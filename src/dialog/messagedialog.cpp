#include "messagedialog.h"
#include "ui_messagedialog.h"

#include "application/tiberiusapplication.h"

#include "graphics/font.h"
#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

MessageDialog::MessageDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::MessageDialog)
  , mType(LeaveEmpire)
{
  initUi();
}

MessageDialog::MessageDialog(Type type, QWidget * parentWidget)
  : Dialog(parentWidget)
  , mUi(new Ui::MessageDialog)
{
  initUi();
  setType(type);
}

MessageDialog::~MessageDialog()
{
  delete mUi;
}

void MessageDialog::initUi()
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_OK_CANCEL_SCROLL_BUTTONS);

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cSubtitle->setTextFont(Font::Type::NormalBlack);

  mUi->cOk->setImage(imageData->getImageRecord(baseImageId)->createImage());
  mUi->cOk->setPressedImage(imageData->getImageRecord(baseImageId+1)->createImage());

  mUi->cCancel->setImage(imageData->getImageRecord(baseImageId+4)->createImage());
  mUi->cCancel->setPressedImage(imageData->getImageRecord(baseImageId+5)->createImage());

  connect(mUi->cOk, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
}

void MessageDialog::setType(Type type)
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  mType = type;
  if (mType == LeaveEmpire) {
    mUi->cTitle->setText(stringData->getString(5, 0));
    mUi->cSubtitle->setText(stringData->getString(5, 1));
  }
  else if (mType == OpenTradeRoute) {
    mUi->cTitle->setText(stringData->getString(5, 2));
    mUi->cTitle->setText(stringData->getString(5, 3));
  }
  else if (mType == DispatchGoods) {
    mUi->cTitle->setText(stringData->getString(5, 4));
    mUi->cTitle->setText(stringData->getString(5, 5));
  }
  else if (mType == InsufficientGoods) {
    mUi->cTitle->setText(stringData->getString(5, 6));
    mUi->cTitle->setText(stringData->getString(5, 7));
  }
  else if (mType == InsufficientLegions) {
    mUi->cTitle->setText(stringData->getString(5, 8));
    mUi->cTitle->setText(stringData->getString(5, 9));
  }
  else if (mType == NoSelectedLegions) {
    mUi->cTitle->setText(stringData->getString(5, 10));
    mUi->cTitle->setText(stringData->getString(5, 11));
  }
  else if (mType == SendLegions) {
    mUi->cTitle->setText(stringData->getString(5, 12));
    mUi->cTitle->setText(stringData->getString(5, 13));
  }
  else if (mType == RemoveFort) {
    mUi->cTitle->setText(stringData->getString(5, 14));
    mUi->cTitle->setText(stringData->getString(5, 15));
  }
  else if (mType == RemoveBridge) {
    mUi->cTitle->setText(stringData->getString(5, 16));
    mUi->cTitle->setText(stringData->getString(5, 17));
  }
}

