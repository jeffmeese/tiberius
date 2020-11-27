#include "educationadvisorwidget.h"
#include "ui_educationadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

EducationAdvisorWidget::EducationAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::EducationAdvisorWidget)
{
  init();
}

EducationAdvisorWidget::~EducationAdvisorWidget()
{
  delete mUi;
}

void EducationAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+8)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(57, 0));
}

void EducationAdvisorWidget::doUpdate()
{

}
