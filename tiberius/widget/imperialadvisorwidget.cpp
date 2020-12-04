#include "imperialadvisorwidget.h"
#include "ui_imperialadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/financedata.h"
#include "city/imperialdata.h"
#include "city/resourcedata.h"

#include "dialog/donationdialog.h"
#include "dialog/giftdialog.h"
#include "dialog/messagedialog.h"
#include "dialog/salarydialog.h"

#include "game/game.h"
#include "game/player.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "imperial/request.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "widget/button.h"
#include "widget/label.h"

#include <QDebug>

ImperialAdvisorWidget::ImperialAdvisorWidget(QWidget *parent)
  : AdvisorWidget(parent)
  , mUi(new Ui::ImperialAdvisorWidget)
{
  init();
}

ImperialAdvisorWidget::~ImperialAdvisorWidget()
{
  delete mUi;
}

void ImperialAdvisorWidget::doUpdate()
{
  // Get data
  const StringData * stringData = Application::language()->stringData();
  ImperialData * imperialData = game()->city()->imperialData();
  Player * player = game()->player();

  Font normalBlack(Font::Type::NormalBlack);
  Font largeBlack(Font::Type::LargeBlack);

  int32_t favor = imperialData->favor();
  QString favorString = stringData->getString(52, 0);
  favorString += QStringLiteral("%1").arg(favor, 4);
  mUi->cFavor->setText(favorString);
  mUi->cFavor->resize(normalBlack.calculateTextWidth(favorString), 20);

  mUi->cName->setText(player->name());

  QString savingsText = stringData->getString(52, 1);
  savingsText += QStringLiteral("%1").arg(player->personalSavings(), 6);
  savingsText += "  " + stringData->getString(6, 0);
  mUi->cSavings->setText(savingsText);

  QString salaryString = player->salaryString();
  salaryString += " " + stringData->getString(6, 0);
  mUi->cSetSalary->setText(salaryString);

  mUi->cRank->setText(player->rankString());

  int32_t totalRequests = imperialData->totalRequests();
  ResourceData * resourceData = game()->city()->resourceData();
  mUi->cNoRequests->setVisible(totalRequests == 0);
  for (int32_t i = 0; i < 5; i++) {
    mRequestButtons[i]->setVisible(false);
    mRequests[i] = nullptr;
  }
  if (totalRequests > 0) {
    for (int32_t i = 0; i < std::min(totalRequests, 5); i++) {
      Request * request = imperialData->requestAt(i);
      Resource::Type resourceType = request->resource();
      Resource * resource = resourceData->getResource(resourceType);
      int32_t amountStored = resource->amountStored();
      mRequestButtons[i]->setRequest(request);
      mRequestButtons[i]->setAmountStored(amountStored);
      mRequestButtons[i]->setVisible(true);
      mRequests[i] = request;
      mAmountStored[i] = amountStored;
    }
  }
}

void ImperialAdvisorWidget::handleDispatch(Request * request, int32_t amountStored)
{
  MessageDialog dialog(this);
  dialog.setType(MessageDialog::DispatchGoods);
  if (request->amount() > amountStored) {
    dialog.setType(MessageDialog::InsufficientGoods);
  }
  int response = dialog.exec();
  if (response == QDialog::Rejected) {
    return;
  }

  ResourceData * resourceData = game()->city()->resourceData();
  ImperialData * imperialData = game()->city()->imperialData();
  imperialData->dispatchRequest(request, resourceData);
  doUpdate();
}

void ImperialAdvisorWidget::handleDispatch1()
{
  handleDispatch(mRequests[0], mAmountStored[0]);
}

void ImperialAdvisorWidget::handleDispatch2()
{
  handleDispatch(mRequests[1], mAmountStored[2]);
}

void ImperialAdvisorWidget::handleDispatch3()
{
  handleDispatch(mRequests[2], mAmountStored[2]);
}

void ImperialAdvisorWidget::handleDispatch4()
{
  handleDispatch(mRequests[3], mAmountStored[3]);
}

void ImperialAdvisorWidget::handleDispatch5()
{
  handleDispatch(mRequests[4], mAmountStored[4]);
}

void ImperialAdvisorWidget::handleDonation()
{
  Player * player = game()->player();
  int32_t savings = player->personalSavings();

  DonationDialog dialog(this);
  dialog.setPersonalSavings(savings);
  int response = dialog.exec();
  if (response == QDialog::Rejected)
    return;

  FinanceData * data = game()->city()->financeData();
  int32_t amount = dialog.donationAmount();
  data->increaseDenarii(amount);
  player->setPersonalSavings(savings-amount);

  doUpdate();
}

void ImperialAdvisorWidget::handleGift()
{
  Player * player = game()->player();
  ImperialData * data = game()->city()->imperialData();

  GiftDialog dialog(this);
  dialog.setPlayerSavings(player->personalSavings());
  dialog.setGenerousGiftId(data->generousGiftId());
  dialog.setModestGiftId(data->modestGiftId());
  dialog.setLavishGiftId(data->lavishGiftId());
  int response = dialog.exec();
  if (response == QDialog::Rejected)
    return;

  Gift * gift = dialog.selectedGift();
  int32_t cost = gift->calculateCost(player->personalSavings());
  player->decreaseSavings(cost);
  data->dispatchGift(gift);

  doUpdate();
}

void ImperialAdvisorWidget::handleSalary()
{
  Player * player = game()->player();

  SalaryDialog dialog(this);
  if (player->salaryRank() > player->rank())
    dialog.setEnableWarning(true);

  if (dialog.exec() == QDialog::Rejected)
    return;

  Player::Rank salaryRank = dialog.salaryRank();
  player->setSalaryRank(salaryRank);

  doUpdate();
}

void ImperialAdvisorWidget::init()
{
  const SgImageData * imageData = Application::climateImages();
  const StringData * stringData = Application::language()->stringData();
  uint32_t advisorsId = imageData->getGroupBaseImageId(GROUP_ADVISOR_ICONS);

  mUi->setupUi(this);

  mUi->cIconButton->setImage(imageData->getImageRecord(advisorsId+2)->createImage());

  mUi->cName->setTextFont(Font::Type::LargeBlack);

  mUi->cFavor->setTextFont(Font::Type::NormalBlack);
  mUi->cFavor->setText(stringData->getString(52, 0));

  mUi->cGiveGift->setTextFont(Font::Type::NormalWhite);
  mUi->cGiveGift->setText(stringData->getString(52, 49));
  mUi->cGiveGift->setToolTip(stringData->getString(52, 69));
  mUi->cGiveGift->setEnableBorder(true);
  mUi->cGiveGift->setEnableFocusBorder(true);

  mUi->cDonate->setTextFont(Font::Type::NormalWhite);
  mUi->cDonate->setText(stringData->getString(52, 2));
  mUi->cDonate->setToolTip(stringData->getString(68, 94));
  mUi->cDonate->setEnableBorder(true);
  mUi->cDonate->setEnableFocusBorder(true);

  mUi->cSetSalary->setTextFont(Font::Type::NormalWhite);
  mUi->cSetSalary->setText(stringData->getString(52, 7));
  mUi->cSetSalary->setToolTip(stringData->getString(68, 95));
  mUi->cSetSalary->setEnableBorder(true);
  mUi->cSetSalary->setEnableFocusBorder(true);

  mUi->cEmperorSentiment->setTextFont(Font::Type::NormalBlack);
  mUi->cEmperorSentiment->setText(stringData->getString(52, 32));

  mUi->cRank->setTextFont(Font::Type::LargeBrown);
  mUi->cRank->setText(stringData->getString(32, 0));

  mUi->cSavings->setTextFont(Font::Type::NormalWhite);
  mUi->cSavings->setText(stringData->getString(52, 1));

  mUi->cNoRequests->setTextFont(Font::Type::NormalGreen);
  mUi->cNoRequests->setText(stringData->getString(52, 21));

  int32_t yOffset = 96;
  for (int i = 0; i < 5; i++) {
    mRequestButtons[i].reset(new RequestButton(this));
    mRequestButtons[i]->move(36, yOffset);
    mRequestButtons[i]->resize(560, 40);
    mRequests[i] = nullptr;
    mAmountStored[i] = 0;
    yOffset += 42;
  }

  connect(mRequestButtons[0].get(), SIGNAL(clicked()), SLOT(handleDispatch1()));
  connect(mRequestButtons[1].get(), SIGNAL(clicked()), SLOT(handleDispatch2()));
  connect(mRequestButtons[2].get(), SIGNAL(clicked()), SLOT(handleDispatch3()));
  connect(mRequestButtons[3].get(), SIGNAL(clicked()), SLOT(handleDispatch4()));
  connect(mRequestButtons[4].get(), SIGNAL(clicked()), SLOT(handleDispatch5()));
  connect(mUi->cDonate, SIGNAL(clicked()), SLOT(handleDonation()));
  connect(mUi->cGiveGift, SIGNAL(clicked()), SLOT(handleGift()));
  connect(mUi->cSetSalary, SIGNAL(clicked()), SLOT(handleSalary()));
}

RequestButton::RequestButton(QWidget * parentWidget)
  : Button(parentWidget)
{
  Font font(Font::Type::NormalWhite);

  setEnableBorder(true);
  setEnableFocusBorder(true);

  mResourceStored = 0;

  mAmount.reset(new Label(this));
  mAmount->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mAmount->move(10, 6);
  mAmount->setTextFont(font);

  mResourceIcon.reset(new QLabel(this));
  mResourceIcon->move(74, 6);

  mResourceName.reset(new Label(this));
  mResourceName->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mResourceName->move(114, 6);
  mResourceName->setTextFont(font);

  mAmountStored.reset(new Label(this));
  mAmountStored->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mAmountStored->move(10, 24);
  mAmountStored->setTextFont(font);

  mAction.reset(new Label(this));
  mAction->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mAction->move(224, 24);
  mAction->setTextFont(font);

  mMonths.reset(new Label(this));
  mMonths->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  mMonths->move(310, 6);
  mMonths->setTextFont(font);
}

void RequestButton::setAmountStored(int32_t value)
{
  mResourceStored = value;
}

void RequestButton::setRequest(Request *request)
{
  const StringData * stringData = Application::language()->stringData();
  Font font(Font::Type::NormalWhite);

  mAmount->setText(QString::number(request->amount()));
  mAmount->resize(font.calculateTextWidth(mAmount->text()), 20);

  mResourceIcon->setPixmap(Resource::getImage(request->resource()));
  mResourceName->setText(Resource::getString(request->resource()));
  mResourceName->resize(font.calculateTextWidth(mResourceName->text()), 20);

  mAction->setText(mResourceStored >= request->amount() ? stringData->getString(52, 47): stringData->getString(52, 48));
  mAction->resize(font.calculateTextWidth(mAction->text()), 20);

  QString s = QString::number(mResourceStored);
  s += " " + stringData->getString(52, 43);
  mAmountStored->setText(s);
  mAmountStored->resize(font.calculateTextWidth(mAmountStored->text()), 20);

  int32_t months = request->monthsToComply();
  QString textString = QString::number(months) + " ";
  textString += (months == 1) ? stringData->getString(8, 4) : stringData->getString(8, 5) + " ";
  textString += stringData->getString(12, 2);
  mMonths->setText(textString);
  mMonths->resize(font.calculateTextWidth(textString), 20);
}
