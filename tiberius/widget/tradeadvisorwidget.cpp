#include "tradeadvisorwidget.h"
#include "ui_tradeadvisorwidget.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

TradeAdvisorWidget::TradeAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::TradeAdvisorWidget)
{
  init();
}

TradeAdvisorWidget::~TradeAdvisorWidget()
{
  delete mUi;
}

void TradeAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+4)->createImage());

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(stringData->getString(54, 0));
}

void TradeAdvisorWidget::doUpdate()
{

}
