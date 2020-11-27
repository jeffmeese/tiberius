#include "financeadvisorwidget.h"
#include "ui_financeadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

FinanceAdvisorWidget::FinanceAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::FinanceAdvisorWidget)
{
  init();
}

FinanceAdvisorWidget::~FinanceAdvisorWidget()
{
  delete mUi;
}

void FinanceAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+10)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(60, 0));
}

void FinanceAdvisorWidget::doUpdate()
{

}
