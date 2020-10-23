#include "newcareerdialog.h"
#include "ui_newcareerdialog.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

NewCareerDialog::NewCareerDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::NewCareerDialog)
{
  init();
}

NewCareerDialog::~NewCareerDialog()
{
  delete mUi;
}

void NewCareerDialog::init()
{
  mUi->setupUi(this);

  const StringData * textData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();

  mUi->cName->setTextFont(Font::Type::NormalWhite);
  mUi->cName->setFocus();

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(textData->getString(31, 0));

  mUi->cBackLabel->setTextFont(Font::Type::NormalBlack);
  mUi->cBackLabel->setText(textData->getString(12, 0));

  mUi->cContinueLabel->setTextFont(Font::Type::NormalBlack);
  mUi->cContinueLabel->setText(textData->getString(13, 5));

  mUi->cBackButton->setImage(imageData->getImageRecord(975)->createImage());
  mUi->cBackButton->setPressedImage(imageData->getImageRecord(976)->createImage());
  mUi->cBackButton->setHoverImage(imageData->getImageRecord(977)->createImage());

  mUi->cContinueButton->setImage(imageData->getImageRecord(1049)->createImage());
  mUi->cContinueButton->setPressedImage(imageData->getImageRecord(1050)->createImage());
  mUi->cContinueButton->setHoverImage(imageData->getImageRecord(1051)->createImage());

  connect(mUi->cBackButton, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cContinueButton, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cName, SIGNAL(textChanged(const QString &)), SLOT(updateData()));
}

QString NewCareerDialog::name() const
{
  return mUi->cName->text().trimmed();
}

void NewCareerDialog::setName(const QString & name)
{
  mUi->cName->setText(name);
}

void NewCareerDialog::showEvent(QShowEvent * e)
{
  mUi->cName->setFocus();
  Dialog::showEvent(e);
}

void NewCareerDialog::updateData()
{
  QString name = mUi->cName->text().trimmed();
  mUi->cContinueButton->setEnabled(!name.isEmpty());
}
