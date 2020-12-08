#include "legionadvisorwidget.h"
#include "ui_legionadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/militarydata.h"

#include "game/game.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "military/legion.h"
#include "military/soldier.h"

#include <QIcon>

LegionAdvisorWidget::LegionAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::LegionAdvisorWidget)
{
  init();
}

LegionAdvisorWidget::~LegionAdvisorWidget()
{
  delete mUi;
}

void LegionAdvisorWidget::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  int32_t imageId = imageData->getGroupBaseImageId(GROUP_BULLET);
  mUi->cReportsButton->setImage(imageData->getImageRecord(imageId)->createImage());
  mUi->cRequestButton->setImage(imageData->getImageRecord(imageId)->createImage());

  mUi->cIcon->setImage(imageData->getImageRecord(advisorsId+1)->createImage());
  mUi->cIcon->setPressedImage(imageData->getImageRecord(advisorsId+14)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(51, 0));

  mUi->cMorale->setTextFont(Font::Type::SmallPlain);
  mUi->cMorale->setText(stringData->getString(138, 36));

  mUi->cGoto->setTextFont(Font::Type::SmallPlain);
  mUi->cGoto->setText(stringData->getString(51, 1));

  mUi->cLegion->setTextFont(Font::Type::SmallPlain);
  mUi->cLegion->setText(stringData->getString(51, 2));

  mUi->cReturn->setTextFont(Font::Type::SmallPlain);
  mUi->cReturn->setText(stringData->getString(51, 3));

  mUi->cToFort->setTextFont(Font::Type::SmallPlain);
  mUi->cToFort->setText(stringData->getString(51, 4));

  mUi->cEmpire->setTextFont(Font::Type::SmallPlain);
  mUi->cEmpire->setText(stringData->getString(51, 5));

  mUi->cService->setTextFont(Font::Type::SmallPlain);
  mUi->cService->setText(stringData->getString(51, 6));

  mUi->cReports->setTextFont(Font::Type::NormalBlack);
  mUi->cReports->setText(stringData->getString(51, 8));

  mUi->cRequests->setTextFont(Font::Type::NormalBlack);
  mUi->cRequests->setText(stringData->getString(51, 12));

  mUi->cNoLegions->setVisible(false);
  mUi->cNoLegions->setTextFont(Font::Type::NormalGreen);
  mUi->cNoLegions->setText(stringData->getString(51, 16));

  int32_t yOffset = 77;
  for (int32_t i = 0; i < 5; i++) {
    mLegionButtons[i].reset(new LegionButton(this));
    mLegionButtons[i]->setGeometry(38, yOffset, 560, 40);
    mLegions[i] = nullptr;
    yOffset += 44;
  }
}

void LegionAdvisorWidget::doUpdate()
{
  MilitaryData * data = game()->city()->militaryData();
  int32_t numLegions = data->total();

  mUi->cNoLegions->setVisible(false);
  for (int32_t i = 0; i < 5; i++) {
    mLegionButtons[i]->setVisible(false);
    mLegions[i] = nullptr;
  }

  if (numLegions <= 0) {
    mUi->cNoLegions->setVisible(true);
  }
  else {
    for (int32_t i = 0; i < data->numActive(); i++) {
      Legion * legion = data->get(i);
      mLegionButtons[i]->setVisible(true);
      mLegionButtons[i]->setLegion(legion);
      mLegions[i] = legion;
    }
  }
}

#include <QPushButton>

LegionButton::LegionButton(QWidget * widget)
  : Button(widget)
{
  const SgImageData * imageData = Application::climateImages();
  uint32_t baseId = imageData->getGroupBaseImageId(GROUP_FORT_ICONS);

  Font normalWhite(Font::Type::NormalWhite);
  Font normalGreen(Font::Type::NormalGreen);

  setEnableBorder(true);

  mIcon.reset(new QLabel(this));
  mIcon->move(16, 5);

  mName.reset(new Label(this));
  mName->setTextFont(normalWhite);
  mName->setAlignment(Qt::AlignTop|Qt::AlignLeft);
  mName->move(40, 6);

  mSoliders.reset(new Label(this));
  mSoliders->setTextFont(normalGreen);
  mSoliders->setAlignment(Qt::AlignTop|Qt::AlignLeft);
  mSoliders->move(40, 23);

  mMorale.reset(new Label(this));
  mMorale->setTextFont(normalGreen);
  mMorale->setAlignment(Qt::AlignTop|Qt::AlignLeft);
  mMorale->setGeometry(240, 14, 150, 20);

  QIcon gotoIcon;
  gotoIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId)->createImage()));

  mGotoLegion.reset(new Button(this));
  mGotoLegion->setGeometry(362, 6, 30, 30);
  mGotoLegion->setIcon(gotoIcon);
  mGotoLegion->setIconSize(QSize(30,30));
  mGotoLegion->setFixedSize(QSize(30,30));
  mGotoLegion->setEnableBorder(true);
  mGotoLegion->setEnableFocusBorder(true);

  QIcon returnIcon;
  returnIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId+1)->createImage()));
  returnIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId+2)->createImage()), QIcon::Disabled);

  mReturnToFort.reset(new Button(this));
  mReturnToFort->setGeometry(442, 6, 30, 30);
  mReturnToFort->setIcon(returnIcon);
  mReturnToFort->setIconSize(QSize(30,30));
  mReturnToFort->setFixedSize(QSize(30,30));
  mReturnToFort->setEnableBorder(true);
  mReturnToFort->setEnableFocusBorder(true);
  mReturnToFort->setDisabled(true);

  QIcon serviceIcon;
  serviceIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId+3)->createImage()));
  serviceIcon.addPixmap(QPixmap::fromImage(imageData->getImageRecord(baseId+4)->createImage()), QIcon::Disabled);
  mEmpireService.reset(new Button(this));
  mEmpireService->setGeometry(522, 6, 30, 30);
  mEmpireService->setIcon(serviceIcon);
  mEmpireService->setIconSize(QSize(30,30));
  mEmpireService->setFixedSize(QSize(30,30));
  mEmpireService->setEnableBorder(true);
  mEmpireService->setEnableFocusBorder(true);
  mEmpireService->setDisabled(true);
}

void LegionButton::setLegion(Legion *legion)
{
  Font normalWhite(Font::Type::NormalWhite);
  Font normalGreen(Font::Type::NormalGreen);

  QString name = legion->name();
  QString morale = legion->moraleString();
  QString type = legion->typeString();

  QString typeText = QString::number(legion->totalSoldiers()) + " " + type;

  mName->setText(name);
  mName->resize(normalWhite.calculateTextWidth(mName->text()), 20);

  mSoliders->setText(typeText);
  mSoliders->resize(normalGreen.calculateTextWidth(mSoliders->text()), 20);

  mMorale->setText(morale);
}
