#include "religionadvisorwidget.h"
#include "ui_religionadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

ReligionAdvisorWidget::ReligionAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::ReligionAdvisorWidget)
{
  init();
}

ReligionAdvisorWidget::~ReligionAdvisorWidget()
{
  delete mUi;
}

void ReligionAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+9)->createImage());
  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(59, 0));
}

void ReligionAdvisorWidget::doUpdate()
{

}
