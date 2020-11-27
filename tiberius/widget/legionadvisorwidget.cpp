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
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
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
}

void LegionAdvisorWidget::doUpdate()
{
  MilitaryData * data = game()->city()->militaryData();
  mUi->cNoLegions->setVisible(false);
  if (data->totalLegions() <= 0) {
    mUi->cNoLegions->setVisible(true);
  }
  else {

  }
}
