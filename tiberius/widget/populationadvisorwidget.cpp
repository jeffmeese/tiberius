#include "populationadvisorwidget.h"
#include "ui_populationadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

PopulationAdvisorWidget::PopulationAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::PopulationAdvisorWidget)
{
  init();
}

PopulationAdvisorWidget::~PopulationAdvisorWidget()
{
  delete mUi;
}

void PopulationAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+5)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(55, 0));
}

void PopulationAdvisorWidget::doUpdate()
{

}
