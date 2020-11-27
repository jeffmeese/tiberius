#include "healthadvisorwidget.h"
#include "ui_healthadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

HealthAdvisorWidget::HealthAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::HealthAdvisorWidget)
{
  init();
}

HealthAdvisorWidget::~HealthAdvisorWidget()
{
  delete mUi;
}

void HealthAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+6)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(56, 0));
}

void HealthAdvisorWidget::doUpdate()
{

}
