#include "entertainmentadvisorwidget.h"
#include "ui_entertainmentadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

EntertainmentAdvisorWidget::EntertainmentAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::EntertainmentAdvisorWidget)
{
  init();
}

EntertainmentAdvisorWidget::~EntertainmentAdvisorWidget()
{
  delete mUi;
}

void EntertainmentAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+7)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(58, 0));
}

void EntertainmentAdvisorWidget::doUpdate()
{

}
