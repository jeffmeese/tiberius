#include "displayoptionsdialog.h"
#include "ui_displayoptionsdialog.h"

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

DisplayOptionsDialog::DisplayOptionsDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::DisplayOptionsDialog)
  , mFullscreen(true)
  , mScreenResolution(Resolution1024x768)
{
  initUi();
  updateData();
}

DisplayOptionsDialog::~DisplayOptionsDialog()
{
  delete mUi;
}

bool DisplayOptionsDialog::fullscreen() const
{
  return mFullscreen;
}

ScreenResolution DisplayOptionsDialog::resolution() const
{
  return mScreenResolution;
}

void DisplayOptionsDialog::setFullscreen(bool value)
{
  mFullscreen = value;
  updateData();
}

void DisplayOptionsDialog::setScreenResolution(ScreenResolution value)
{
  mScreenResolution = value;
  updateData();
}

void DisplayOptionsDialog::handleFullscreen()
{
  mFullscreen = !mFullscreen;
  updateData();
  emit applyFullScreen(mFullscreen);
  accept();
}

void DisplayOptionsDialog::handle640x480()
{
  mScreenResolution = Resolution640x480;
  updateData();
  emit changeResolution(mScreenResolution);
  accept();
}

void DisplayOptionsDialog::handle800x600()
{
  mScreenResolution = Resolution800x600;
  updateData();
  emit changeResolution(mScreenResolution);
  accept();
}

void DisplayOptionsDialog::handle1024x768()
{
  mScreenResolution = Resolution1024x768;
  updateData();
  emit changeResolution(mScreenResolution);
  accept();
}

void DisplayOptionsDialog::initButton(Button *button, const Font &font)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);

  button->setTextFont(font);
  button->setImage(StitchedImage::create(button->width(), button->height(), 16, 20, 3, 1, baseImageId+46));
  button->setHoverImage(StitchedImage::create(button->width(), button->height(), 16, 20, 3, 1, baseImageId+43));
}

void DisplayOptionsDialog::initUi()
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  const StringData * stringData = TiberiusApplication::language()->stringData();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_PANEL_BUTTON);

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(42, 0));

  std::vector<Button*> buttonList;
  buttonList.push_back(mUi->cFullScreen);
  buttonList.push_back(mUi->c640x480);
  buttonList.push_back(mUi->c800x600);
  buttonList.push_back(mUi->c1024x768);
  buttonList.push_back(mUi->cCancel);

  for (std::size_t i = 0; i < buttonList.size(); i++) {
    Button * button = buttonList.at(i);
    int w = button->width();
    int h = button->height();
    button->setTextFont(Font::Type::NormalGreen);
    button->setImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+46));
    button->setHoverImage(StitchedImage::create(w, h, 16, 20, 3, 1, baseImageId+43));
  }

  connect(mUi->cFullScreen, SIGNAL(clicked()), SLOT(handleFullscreen()));
  connect(mUi->c640x480, SIGNAL(clicked()), SLOT(handle640x480()));
  connect(mUi->c800x600, SIGNAL(clicked()), SLOT(handle800x600()));
  connect(mUi->c1024x768, SIGNAL(clicked()), SLOT(handle1024x768()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
}

void DisplayOptionsDialog::updateData()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  int32_t fullScreenId = mFullscreen ? 2 : 1;
  mUi->cFullScreen->setText(stringData->getString(42, fullScreenId));
  mUi->c640x480->setText(stringData->getString(42, 3));
  mUi->c800x600->setText(stringData->getString(42, 4));
  mUi->c1024x768->setText(stringData->getString(42, 5));
  mUi->cCancel->setText(stringData->getString(42, 6));
}
