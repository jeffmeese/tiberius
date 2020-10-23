#include "soundoptionsdialog.h"
#include "ui_soundoptionsdialog.h"

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

#include <QDebug>

SoundOptionsDialog::SoundOptionsDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::SoundOptionsDialog)
  , mCitySoundsOn(true)
  , mMusicOn(true)
  , mSoundEffectsOn(true)
  , mSpeechOn(true)
  , mCityVolume(70)
  , mMusicVolume(70)
  , mSoundEffectsVolume(70)
  , mSpeechVolume(70)
{
  initUi();
  updateData();
}

SoundOptionsDialog::~SoundOptionsDialog()
{
  delete mUi;
}

bool SoundOptionsDialog::citySoundsOn() const
{
  return mCitySoundsOn;
}

int SoundOptionsDialog::citySoundsVolume() const
{
  return mCityVolume;
}

void SoundOptionsDialog::handleCity()
{
  mCitySoundsOn = !mCitySoundsOn;
  emit changed();
  updateData();
}

void SoundOptionsDialog::handleCityDown()
{
  mCityVolume = (mCityVolume > 10) ? mCityVolume - 10 : mCityVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleCityUp()
{
  mCityVolume = (mCityVolume < 100) ? mCityVolume + 10 : mCityVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleMusic()
{
  mMusicOn = !mMusicOn;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleMusicDown()
{
  mMusicVolume = (mMusicVolume > 10) ? mMusicVolume - 10 : mMusicVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleMusicUp()
{
  mMusicVolume = (mMusicVolume < 100) ? mMusicVolume + 10 : mMusicVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSounds()
{
  mSoundEffectsOn = !mSoundEffectsOn;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSoundsDown()
{
  mSoundEffectsVolume = (mSoundEffectsVolume > 10) ? mSoundEffectsVolume - 10 : mSoundEffectsVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSoundsUp()
{
  mSoundEffectsVolume = (mSoundEffectsVolume < 100) ? mSoundEffectsVolume + 10 : mSoundEffectsVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSpeech()
{
  mSpeechOn = !mSpeechOn;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSpeechDown()
{
  mSpeechVolume = (mSpeechVolume > 10) ? mSpeechVolume - 10 : mSpeechVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::handleSpeechUp()
{
  mSpeechVolume = (mSpeechVolume < 100) ? mSpeechVolume + 10 : mSpeechVolume;
  updateData();
  emit changed();
}

void SoundOptionsDialog::initButton(Button *button, const Font &font, const QString &text)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);

  int32_t w = button->width();
  int32_t h = button->height();

  button->setTextFont(Font::Type::NormalGreen);
  button->setText(text);
  button->setImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+46));
  button->setHoverImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+43));
}

void SoundOptionsDialog::initUi()
{
  const StringData * textData = TiberiusApplication::language()->stringData();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(textData->getString(46, 0));

  mUi->cMusicVolumeLabel->setTextFont(Font::Type::NormalPlain);
  mUi->cMusicVolumeLabel->setText(textData->getString(46, 1));

  mUi->cSpeechVolumeLabel->setTextFont(Font::Type::NormalPlain);
  mUi->cSpeechVolumeLabel->setText(textData->getString(46, 4));

  mUi->cSoundsVolumeLabel->setTextFont(Font::Type::NormalPlain);
  mUi->cSoundsVolumeLabel->setText(textData->getString(46, 6));

  mUi->cCityVolumeLevel->setTextFont(Font::Type::NormalPlain);
  mUi->cCityVolumeLevel->setText(textData->getString(46, 8));

  mUi->cStateLabel->setTextFont(Font::Type::SmallPlain);
  mUi->cStateLabel->setText(textData->getString(46, 10));

  mUi->cVolumeLabel->setTextFont(Font::Type::SmallPlain);
  mUi->cVolumeLabel->setText(textData->getString(46, 11));

  initButton(mUi->cOk, Font::Type::NormalGreen, textData->getString(46, 12));
  initButton(mUi->cCancel, Font::Type::NormalGreen, textData->getString(46, 9));
  initButton(mUi->cMusic, Font::Type::NormalGreen, textData->getString(46, 4));
  initButton(mUi->cSpeech, Font::Type::NormalGreen, textData->getString(46, 6));
  initButton(mUi->cSounds, Font::Type::NormalGreen, textData->getString(46, 8));
  initButton(mUi->cCity, Font::Type::NormalGreen, textData->getString(46, 10));

  mUi->cMusicUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cMusicUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cMusicDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cMusicDown->setPressedImage(imageData->getImageRecord(18)->createImage());

  mUi->cSpeechUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cSpeechUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cSpeechDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cSpeechDown->setPressedImage(imageData->getImageRecord(18)->createImage());

  mUi->cSoundsUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cSoundsUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cSoundsDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cSoundsDown->setPressedImage(imageData->getImageRecord(18)->createImage());

  mUi->cCityUp->setImage(imageData->getImageRecord(15)->createImage());
  mUi->cCityUp->setPressedImage(imageData->getImageRecord(16)->createImage());

  mUi->cCityDown->setImage(imageData->getImageRecord(17)->createImage());
  mUi->cCityDown->setPressedImage(imageData->getImageRecord(18)->createImage());

  connect(mUi->cOk, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cMusic, SIGNAL(clicked()), SLOT(handleMusic()));
  connect(mUi->cMusicUp, SIGNAL(clicked()), SLOT(handleMusicUp()));
  connect(mUi->cMusicDown, SIGNAL(clicked()), SLOT(handleMusicDown()));
  connect(mUi->cSpeech, SIGNAL(clicked()), SLOT(handleSpeech()));
  connect(mUi->cSpeechUp, SIGNAL(clicked()), SLOT(handleSpeechUp()));
  connect(mUi->cSpeechDown, SIGNAL(clicked()), SLOT(handleSpeechDown()));
  connect(mUi->cSounds, SIGNAL(clicked()), SLOT(handleSounds()));
  connect(mUi->cSoundsUp, SIGNAL(clicked()), SLOT(handleSoundsUp()));
  connect(mUi->cSoundsDown, SIGNAL(clicked()), SLOT(handleSoundsDown()));
  connect(mUi->cCity, SIGNAL(clicked()), SLOT(handleCity()));
  connect(mUi->cCityUp, SIGNAL(clicked()), SLOT(handleCityUp()));
  connect(mUi->cCityDown, SIGNAL(clicked()), SLOT(handleCityDown()));
}

bool SoundOptionsDialog::musicOn() const
{
  return mMusicOn;
}

int SoundOptionsDialog::musicVolume() const
{
  return mMusicVolume;
}

bool SoundOptionsDialog::soundEffectsOn() const
{
  return mSoundEffectsOn;
}

int SoundOptionsDialog::soundEffectsVolume() const
{
  return mSoundEffectsVolume;
}

bool SoundOptionsDialog::speechOn() const
{
  return mSpeechOn;
}

int SoundOptionsDialog::speechVolume() const
{
  return mSpeechVolume;
}

void SoundOptionsDialog::setCitySoundsOn(bool value)
{
  mCitySoundsOn = value;
  updateData();
}

void SoundOptionsDialog::setCitySoundsVolume(int value)
{
  mCityVolume = value;
  updateData();
}

void SoundOptionsDialog::setMusicOn(bool value)
{
  mMusicOn = value;
  updateData();
}

void SoundOptionsDialog::setMusicVolume(int value)
{
  mMusicVolume = value;
  updateData();
}

void SoundOptionsDialog::setSoundEffectsOn(bool value)
{
  mSoundEffectsOn = value;
  updateData();
}

void SoundOptionsDialog::setSoundEffectsVolume(int value)
{
  mSoundEffectsVolume = value;
  updateData();
}

void SoundOptionsDialog::setSpeechOn(bool value)
{
  mSpeechOn = value;
  updateData();
}

void SoundOptionsDialog::setSpeechVolume(int value)
{
  mSpeechVolume = value;
  updateData();
}

void SoundOptionsDialog::updateData()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  mUi->cMusic->setText(stringData->getString(46, (mMusicOn) ? 1 : 2));
  mUi->cSpeech->setText(stringData->getString(46, (mSpeechOn) ? 3 : 4));
  mUi->cSounds->setText(stringData->getString(46, (mSoundEffectsOn) ? 5 : 6));
  mUi->cCity->setText(stringData->getString(46, (mCitySoundsOn) ? 7 : 8));

  mUi->cMusicVolumeLabel->setText(QString::number(mMusicVolume) + "%");
  mUi->cSpeechVolumeLabel->setText(QString::number(mSpeechVolume) + "%");
  mUi->cSoundsVolumeLabel->setText(QString::number(mSoundEffectsVolume) + "%");
  mUi->cCityVolumeLevel->setText(QString::number(mCityVolume) + "%");
}
