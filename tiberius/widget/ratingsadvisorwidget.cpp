#include "ratingsadvisorwidget.h"
#include "ui_ratingsadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

RatingsAdvisorWidget::RatingsAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::RatingsAdvisorWidget)
{
  init();
}

RatingsAdvisorWidget::~RatingsAdvisorWidget()
{
  delete mUi;
}

void RatingsAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+3)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(53, 0));
}

void RatingsAdvisorWidget::doUpdate()
{

}
