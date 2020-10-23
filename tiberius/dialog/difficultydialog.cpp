#include "difficultydialog.h"
#include "ui_difficultydialog.h"

#include "application/tiberiusapplication.h"

#include "graphics/font.h"
#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QMouseEvent>

DifficultyDialog::DifficultyDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::DifficultyDialog)
  , mType(Difficulty::Type::Normal)
  , mGodsEffects(true)
{
  initUi();
  updateData();
}

DifficultyDialog::~DifficultyDialog()
{
  delete mUi;
}

void DifficultyDialog::handleDecreaseDifficulty()
{
  Difficulty d(mType);
  d.decrease();
  mType = d.type();
  updateData();
  emit changed();
}

void DifficultyDialog::handleIncreaseDifficulty()
{
  Difficulty d(mType);
  d.increase();
  mType = d.type();
  updateData();
  emit changed();
}

void DifficultyDialog::handleGodEffects()
{
  mGodsEffects = !mGodsEffects;
  updateData();
  emit changed();
}

void DifficultyDialog::initUi()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(153, 0));
  mUi->cDifficulty->setTextFont(Font::Type::NormalBlack);
  mUi->cGodEffects->setTextFont(Font::Type::NormalBlack);
  mUi->cExit->setTextFont(Font::Type::NormalBlack);
  mUi->cExit->setText(stringData->getString(153, 8));

  mUi->cUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cUp->setPressedImage(imageData->getImageRecord(16)->createImage());
  mUi->cDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cDown->setPressedImage(imageData->getImageRecord(18)->createImage());
  mUi->cRight->setImage(imageData->getImageRecord(21)->createImage());
  mUi->cRight->setPressedImage(imageData->getImageRecord(22)->createImage());

  connect(mUi->cUp, SIGNAL(clicked()), SLOT(handleIncreaseDifficulty()));
  connect(mUi->cDown, SIGNAL(clicked()), SLOT(handleDecreaseDifficulty()));
  connect(mUi->cRight, SIGNAL(clicked()), SLOT(handleGodEffects()));
}

Difficulty::Type DifficultyDialog::difficulty() const
{
  return mType;
}

bool DifficultyDialog::godsEffectsOn() const
{
  return mGodsEffects;
}

void DifficultyDialog::setDifficulty(Difficulty::Type value)
{
  mType = value;
  updateData();
}

void DifficultyDialog::setGodsEffectsOn(bool value)
{
  mGodsEffects = value;
  updateData();
}

void DifficultyDialog::mousePressEvent(QMouseEvent * event)
{
  if (event->button() == Qt::RightButton) {
    reject();
    return;
  }

  return Dialog::mousePressEvent(event);
}


void DifficultyDialog::updateData()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  QString godString = mGodsEffects ? stringData->getString(153, 7) : stringData->getString(153, 6);
  QString difficultyString = stringData->getString(153, static_cast<int32_t>(mType));

  mUi->cDifficulty->setText(difficultyString);
  mUi->cGodEffects->setText(godString);
  mUi->cExit->setText(stringData->getString(153, 8));
}
