#include "imperialadvisorwidget.h"
#include "ui_imperialadvisorwidget.h"

#include "application/application.h"

#include "city/city.h"
#include "city/financedata.h"
#include "city/imperialdata.h"

#include "dialog/donationdialog.h"
#include "dialog/giftdialog.h"
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
#include "widget/borderedbutton.h"
#include "widget/label.h"

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

QString ImperialAdvisorWidget::createFavorString(ImperialData * imperialData) const
{
  const StringData * stringData = Application::language()->stringData();
  int32_t favor = imperialData->favor();
  QString textString = stringData->getString(52, 0);
  textString += QStringLiteral("%1").arg(favor, 4);
  return textString;
}

void ImperialAdvisorWidget::createRequests(ImperialData * imperialData)
{
  mUi->cNoRequests->setVisible(false);
  mRequestButtons.clear();
  int32_t totalRequests = imperialData->totalRequests();
  if (totalRequests <= 0) {
    mUi->cNoRequests->setVisible(true);
  }
  else {
    int32_t yOffset = 96;
    for (int32_t i = 0; i < std::min(imperialData->totalRequests(), 5); i++) {
      Request * request = imperialData->requestAt(i);
      std::unique_ptr<RequestButton> requestButton(new RequestButton(this, request, yOffset));
      mRequestButtons.push_back(std::move(requestButton));
      yOffset += 42;
    }
  }
}

QString ImperialAdvisorWidget::createRankString(Player * player) const
{
  const StringData * stringData = Application::language()->stringData();

  switch (player->rank())
  {
  case Player::Rank::Citizen:
    return stringData->getString(32, 0);
  case Player::Rank::Clerk:
    return stringData->getString(32, 1);
  case Player::Rank::Engineer:
    return stringData->getString(32, 2);
  case Player::Rank::Architect:
    return stringData->getString(32, 3);
  case Player::Rank::Quaestor:
    return stringData->getString(32, 4);
  case Player::Rank::Procurator:
    return stringData->getString(32, 5);
  case Player::Rank::Aedile:
    return stringData->getString(32, 6);
  case Player::Rank::Praetor:
    return stringData->getString(32, 7);
  case Player::Rank::Consul:
    return stringData->getString(32, 8);
  case Player::Rank::Proconsul:
    return stringData->getString(32, 9);
  case Player::Rank::Caesar:
    return stringData->getString(32, 10);
  }

  return stringData->getString(40, 0);
}

QString ImperialAdvisorWidget::createSalaryString(Player * player) const
{
  const StringData * stringData = Application::language()->stringData();

  QString salaryString;
  switch (player->salaryRank())
  {
  case Player::Rank::Citizen:
    salaryString += stringData->getString(52, 4);
    break;
  case Player::Rank::Clerk:
    salaryString += stringData->getString(52, 5);
    break;
  case Player::Rank::Engineer:
    salaryString += stringData->getString(52, 6);
    break;
  case Player::Rank::Architect:
    salaryString += stringData->getString(52, 7);
    break;
  case Player::Rank::Quaestor:
    salaryString += stringData->getString(52, 8);
    break;
  case Player::Rank::Procurator:
    salaryString += stringData->getString(52, 9);
    break;
  case Player::Rank::Aedile:
    salaryString += stringData->getString(52, 10);
    break;
  case Player::Rank::Praetor:
    salaryString += stringData->getString(52, 11);
    break;
  case Player::Rank::Consul:
    salaryString += stringData->getString(52, 12);
    break;
  case Player::Rank::Proconsul:
    salaryString += stringData->getString(52, 13);
    break;
  case Player::Rank::Caesar:
    salaryString += stringData->getString(52, 14);
    break;
  }
  salaryString += QStringLiteral("%1").arg(player->salary(), 4);
  salaryString += "  " + stringData->getString(52, 3);

  return salaryString;
}

QString ImperialAdvisorWidget::createSavingsString(Player * player) const
{
  const StringData * stringData = Application::language()->stringData();

  QString savingsText = stringData->getString(52, 1);
  savingsText += QStringLiteral("%1").arg(player->personalSavings(), 6);
  savingsText += "  " + stringData->getString(6, 0);
  return savingsText;
}

void ImperialAdvisorWidget::doUpdate()
{
  // Get data
  ImperialData * imperialData = game()->city()->imperialData();
  Player * player = game()->player();
  Player::Rank salaryRank = player->salaryRank();

  mUi->cName->setText(player->name());
  mUi->cFavor->setText(createFavorString(imperialData));
  mUi->cSavings->setText(createSavingsString(player));
  mUi->cSetSalary->setText(createSalaryString(player));
  mUi->cRank->setText(createRankString(player));

  createRequests(imperialData);
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

  mUi->cDonate->setTextFont(Font::Type::NormalWhite);
  mUi->cDonate->setText(stringData->getString(52, 2));
  mUi->cDonate->setToolTip(stringData->getString(68, 94));

  mUi->cSetSalary->setTextFont(Font::Type::NormalWhite);
  mUi->cSetSalary->setText(stringData->getString(52, 7));
  mUi->cSetSalary->setToolTip(stringData->getString(68, 95));

  mUi->cEmperorSentiment->setTextFont(Font::Type::NormalBlack);
  mUi->cEmperorSentiment->setText(stringData->getString(52, 32));

  mUi->cRank->setTextFont(Font::Type::LargeBrown);
  mUi->cRank->setText(stringData->getString(32, 0));

  mUi->cSavings->setTextFont(Font::Type::NormalWhite);
  mUi->cSavings->setText(stringData->getString(52, 1));

  mUi->cNoRequests->setTextFont(Font::Type::NormalGreen);
  mUi->cNoRequests->setText(stringData->getString(52, 21));

  connect(mUi->cDonate, SIGNAL(clicked()), SLOT(handleDonation()));
  connect(mUi->cGiveGift, SIGNAL(clicked()), SLOT(handleGift()));
  connect(mUi->cSetSalary, SIGNAL(clicked()), SLOT(handleSalary()));
}

ImperialAdvisorWidget::RequestButton::RequestButton(QWidget * parentWidget, Request * request, int yOffset)
{
  const StringData * stringData = Application::language()->stringData();

  BorderedButton * button = new BorderedButton(parentWidget);
  button->resize(560, 40);
  button->move(38, yOffset);

  Label * amount = new Label(parentWidget);
  amount->move(46, yOffset+6);
  amount->resize(20, 11);
  amount->setTextFont(Font::Type::NormalWhite);
  amount->setText(QString::number(request->amount()));

  QLabel * resourceImage = new QLabel(parentWidget);
  resourceImage->move(110, yOffset+6);
  resourceImage->setPixmap(Resource::getImage(request->resource()));

  Label * resourceLabel = new Label(parentWidget);
  resourceLabel->move(150, yOffset+6);
  resourceLabel->resize(100, 11);
  resourceLabel->setTextFont(Font::Type::NormalWhite);
  resourceLabel->setText(Resource::getString(request->resource()));

  Label * warehouseAmount = new Label(parentWidget);
  warehouseAmount->move(46, yOffset+24);
  warehouseAmount->resize(200, 11);
  warehouseAmount->setTextFont(Font::Type::NormalWhite);
  warehouseAmount->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

  QString s = QString::number(request->amount());
  s += " " + stringData->getString(52, 43);
  warehouseAmount->setText(s);

  Label * dispatch = new Label(parentWidget);
  dispatch->move(260, yOffset+24);
  dispatch->resize(250, 11);
  dispatch->setTextFont(Font::Type::NormalWhite);
  dispatch->setText(stringData->getString(52, 48));
}
