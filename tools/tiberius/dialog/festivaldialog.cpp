#include "festivaldialog.h"
#include "ui_festivaldialog.h"

#include "application/application.h"

#include "core/painter.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

FestivalDialog::FestivalDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::FestivalDialog)
{
  init();
}

FestivalDialog::~FestivalDialog()
{
  delete mUi;
}

Festival::Type FestivalDialog::festivalType() const
{
  return mFestivalType;
}

int32_t FestivalDialog::festivalCost() const
{
  return mFestivalCost;
}

int32_t FestivalDialog::festivalWine() const
{
  return mFestivalWine;
}

void FestivalDialog::handleCeres()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mFestivalCost = 0;
  mFestivalType = Festival::Type::Small;
  mFestivalWine = 0;

  mUi->cTitle->setText(stringData->getString(58, 25));
  mUi->cCeresButton->setSelected(true);
  mUi->cNeptuneButton->setSelected(false);
  mUi->cMercuryButton->setSelected(false);
  mUi->cMarsButton->setSelected(false);
  mUi->cVenusButton->setSelected(false);

  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+21)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+17)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+18)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+19)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+20)->createImage());
  update();
}

void FestivalDialog::handleGrandFestival()
{
  Font f(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();
  mUi->cSizeLabel->setText(stringData->getString(58, 33));
  mUi->cSizeLabel->resize(f.calculateTextWidth(mUi->cSizeLabel->text()), 20);
  mFestivalCost = mUi->cGrandFestivalButton->cost();
  mFestivalWine = mUi->cGrandFestivalButton->wine();
  mFestivalType = Festival::Type::Grand;
}

void FestivalDialog::handleLargeFestival()
{
  Font f(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();
  mUi->cSizeLabel->setText(stringData->getString(58, 32));
  mUi->cSizeLabel->resize(f.calculateTextWidth(mUi->cSizeLabel->text()), 20);
  mFestivalCost = mUi->cLargeFestivalButton->cost();
  mFestivalWine = mUi->cLargeFestivalButton->wine();
  mFestivalType = Festival::Type::Large;
}

void FestivalDialog::handleMars()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mUi->cTitle->setText(stringData->getString(58, 28));

  mUi->cCeresButton->setSelected(false);
  mUi->cNeptuneButton->setSelected(false);
  mUi->cMercuryButton->setSelected(false);
  mUi->cMarsButton->setSelected(true);
  mUi->cVenusButton->setSelected(false);
  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+16)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+17)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+18)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+24)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+20)->createImage());
  update();
}

void FestivalDialog::handleMercury()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mUi->cTitle->setText(stringData->getString(58, 27));

  mUi->cCeresButton->setSelected(false);
  mUi->cNeptuneButton->setSelected(false);
  mUi->cMercuryButton->setSelected(true);
  mUi->cMarsButton->setSelected(false);
  mUi->cVenusButton->setSelected(false);
  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+16)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+17)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+23)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+19)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+20)->createImage());
  update();
}

void FestivalDialog::handleNeptune()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mUi->cTitle->setText(stringData->getString(58, 26));

  mUi->cCeresButton->setSelected(false);
  mUi->cNeptuneButton->setSelected(true);
  mUi->cMercuryButton->setSelected(false);
  mUi->cMarsButton->setSelected(false);
  mUi->cVenusButton->setSelected(false);
  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+16)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+22)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+18)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+19)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+20)->createImage());
  update();
}

void FestivalDialog::handleSmallFestival()
{
  Font f(Font::Type::NormalBlack);
  const StringData * stringData = Application::language()->stringData();
  mUi->cSizeLabel->setText(stringData->getString(58, 31));
  mUi->cSizeLabel->resize(f.calculateTextWidth(mUi->cSizeLabel->text()), 20);
  mFestivalCost = mUi->cSmallFestivalButton->cost();
  mFestivalWine = mUi->cSmallFestivalButton->wine();
  mFestivalType = Festival::Type::Small;
}

void FestivalDialog::handleVenus()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);

  mUi->cTitle->setText(stringData->getString(58, 29));

  mUi->cCeresButton->setSelected(false);
  mUi->cNeptuneButton->setSelected(false);
  mUi->cMercuryButton->setSelected(false);
  mUi->cMarsButton->setSelected(false);
  mUi->cVenusButton->setSelected(true);
  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+16)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+17)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+18)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+19)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+25)->createImage());
  update();
}

void FestivalDialog::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t panelId = imageData->getGroupBaseImageId(GROUP_PANEL_WINDOWS);
  int32_t buttonId = imageData->getGroupBaseImageId(GROUP_OK_CANCEL_SCROLL_BUTTONS);
  int32_t contextId = imageData->getGroupBaseImageId(GROUP_CONTEXT_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);

  mSelectedGod = God::Type::Ceres;

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(58, 25));

  mUi->cSizeLabel->setTextFont(normalBlack);
  mUi->cSizeLabel->setText(stringData->getString(58, 31));
  mUi->cSizeLabel->resize(normalBlack.calculateTextWidth(stringData->getString(58, 31)), 20);

  mUi->cCeresButton->setImage(imageData->getImageRecord(panelId+21)->createImage());
  mUi->cNeptuneButton->setImage(imageData->getImageRecord(panelId+17)->createImage());
  mUi->cMercuryButton->setImage(imageData->getImageRecord(panelId+18)->createImage());
  mUi->cMarsButton->setImage(imageData->getImageRecord(panelId+19)->createImage());
  mUi->cVenusButton->setImage(imageData->getImageRecord(panelId+20)->createImage());

  mUi->cAccept->setImage(imageData->getImageRecord(buttonId)->createImage());
  mUi->cCancel->setImage(imageData->getImageRecord(buttonId+4)->createImage());
  mUi->cHelp->setImage(imageData->getImageRecord(contextId)->createImage());
  mUi->cReturn->setImage(imageData->getImageRecord(contextId+4)->createImage());

  mUi->cSmallFestivalButton->setType(stringData->getString(58, 31));
  mUi->cSmallFestivalButton->setCost(10);
  mUi->cSmallFestivalButton->setWineRequired(0);
  mUi->cSmallFestivalButton->setEnableBorder(true);
  mUi->cSmallFestivalButton->setEnableFocusBorder(true);

  mUi->cLargeFestivalButton->setType(stringData->getString(58, 32));
  mUi->cLargeFestivalButton->setCost(20);
  mUi->cLargeFestivalButton->setWineRequired(0);
  mUi->cLargeFestivalButton->setEnableBorder(true);
  mUi->cLargeFestivalButton->setEnableFocusBorder(true);

  mUi->cGrandFestivalButton->setType(stringData->getString(58, 33));
  mUi->cGrandFestivalButton->setCost(40);
  mUi->cGrandFestivalButton->setWineRequired(1);
  mUi->cGrandFestivalButton->setEnableBorder(true);
  mUi->cGrandFestivalButton->setEnableFocusBorder(true);

  connect(mUi->cCeresButton, SIGNAL(clicked()), SLOT(handleCeres()));
  connect(mUi->cNeptuneButton, SIGNAL(clicked()), SLOT(handleNeptune()));
  connect(mUi->cMercuryButton, SIGNAL(clicked()), SLOT(handleMercury()));
  connect(mUi->cMarsButton, SIGNAL(clicked()), SLOT(handleMars()));
  connect(mUi->cVenusButton, SIGNAL(clicked()), SLOT(handleVenus()));
  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cReturn, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cAccept, SIGNAL(clicked()), SLOT(accept()));
  connect(mUi->cSmallFestivalButton, SIGNAL(clicked()), SLOT(handleSmallFestival()));
  connect(mUi->cLargeFestivalButton, SIGNAL(clicked()), SLOT(handleLargeFestival()));
  connect(mUi->cGrandFestivalButton, SIGNAL(clicked()), SLOT(handleGrandFestival()));
}

God::Type FestivalDialog::selectedGod() const
{
  return mSelectedGod;
}

void FestivalDialog::setSelectedGod(God::Type type)
{
  switch (type)
  {
  case God::Type::Ceres:
    handleCeres();
    break;
  case God::Type::Neptune:
    handleNeptune();
    break;
  case God::Type::Mercury:
    handleMercury();
    break;
  case God::Type::Mars:
    handleMars();
    break;
  case God::Type::Venus:
    handleVenus();
    break;
  }
}

FestivalButton::FestivalButton(QWidget * parentWidget)
  : Button(parentWidget)
{
  const SgImageData * imageData = Application::climateImages();
  int32_t baseId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  Font f(Font::Type::NormalBlack);

  mCost = 0;
  mWine = 0;

  mType.reset(new Label(this));
  mCostLabel.reset(new Label(this));
  mWineLabel.reset(new Label(this));
  mWineImage.reset(new QLabel(this));

  mType->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  mType->move(8, 8);
  mType->setTextFont(f);

  mCostLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  mCostLabel->setTextFont(f);

  mWineLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  mWineLabel->setTextFont(f);
  mWineLabel->setVisible(false);

  mWineImage->setPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId+7)->createImage()));
  mWineImage->setVisible(false);

  setCost(0);
  setWineRequired(0);
  recalcLayout();
}

void FestivalButton::recalcLayout()
{
  Font f(Font::Type::NormalBlack);

  int32_t width = f.calculateTextWidth(mType->text() + " ");
  mType->resize(width, 20);

  mCostLabel->move(width + 8, 8);
  mCostLabel->resize(f.calculateTextWidth(mCostLabel->text()), 20);

  width += f.calculateTextWidth(mCostLabel->text() + " ");
  mWineLabel->resize(f.calculateTextWidth(mWineLabel->text()), 20);
  mWineLabel->move(width+18, 8);

  width += f.calculateTextWidth(mWineLabel->text() + " ");
  mWineImage->move(width+18, 3);
}

int32_t FestivalButton::cost() const
{
  return mCost;
}

void FestivalButton::setCost(int32_t value)
{
  mCost = value;

  const StringData * stringData = Application::language()->stringData();
  mCostLabel->setText(QString::number(value) + " " + stringData->getString(8, 1));
  recalcLayout();
}

void FestivalButton::setType(const QString &text)
{
  mType->setText(text);
  recalcLayout();
}

void FestivalButton::setWineRequired(int32_t value)
{
  mWine = value;
  const StringData * stringData = Application::language()->stringData();
  mWineLabel->setText(QString::number(value) + " " + stringData->getString(8, value == 1 ? 10 : 11));
  mWineImage->setVisible(value > 0);
  mWineLabel->setVisible(value > 0);
  recalcLayout();
}

int32_t FestivalButton::wine() const
{
  return mWine;
}

GodButton::GodButton(QWidget * parentWidget)
  : Button(parentWidget)
{
  mSelected = false;
}

void GodButton::paintEvent(QPaintEvent * event)
{
  Button::paintEvent(event);
  if (mSelected) {
    Painter painter(this);
    painter.drawBorder(0, 0, width(), height(), true);
  }
}

void GodButton::setSelected(bool value)
{
  mSelected = value;
}
