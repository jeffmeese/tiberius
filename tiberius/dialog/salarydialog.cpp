#include "salarydialog.h"
#include "ui_salarydialog.h"

#include "application/application.h"

#include "game/player.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include <QDebug>

SalaryDialog::SalaryDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::SalaryDialog)
  , mSalaryRank(Player::Rank::Citizen)
{
  init();
}

SalaryDialog::~SalaryDialog()
{
  delete mUi;
}

void SalaryDialog::handleAedile()
{
  qDebug() << "Aedile";
  mSalaryRank = Player::Rank::Aedile;
  accept();
}

void SalaryDialog::handleArchitect()
{
  mSalaryRank = Player::Rank::Architect;
  accept();
}

void SalaryDialog::handleCaesar()
{
  mSalaryRank = Player::Rank::Caesar;
  accept();
}

void SalaryDialog::handleCitizen()
{
  mSalaryRank = Player::Rank::Citizen;
  accept();
}

void SalaryDialog::handleClerk()
{
  mSalaryRank = Player::Rank::Clerk;
  accept();
}

void SalaryDialog::handleConsul()
{
  mSalaryRank = Player::Rank::Consul;
  accept();
}

void SalaryDialog::handleEngineer()
{
  mSalaryRank = Player::Rank::Engineer;
  accept();
}

void SalaryDialog::handlePraetor()
{
  mSalaryRank = Player::Rank::Praetor;
  accept();
}

void SalaryDialog::handleProconsul()
{
  mSalaryRank = Player::Rank::Proconsul;
  accept();
}

void SalaryDialog::handleProcurator()
{
  mSalaryRank = Player::Rank::Procurator;
  accept();
}

void SalaryDialog::handleQuaestor()
{
  mSalaryRank = Player::Rank::Quaestor;
  accept();
}

void SalaryDialog::init()
{
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  int32_t resourceId = imageData->getGroupBaseImageId(GROUP_RESOURCE_ICONS);

  Font largeBlack(Font::Type::LargeBlack);
  Font normalBlack(Font::Type::NormalBlack);

  mUi->setupUi(this);
  mUi->cTitle->setTextFont(largeBlack);
  mUi->cTitle->setText(stringData->getString(52, 15));
  mUi->cIcon->setImage(imageData->getImageRecord(resourceId+16)->createImage());

  mUi->cMessage->setTextFont(normalBlack);

  initSalaryString(mUi->cCitizen, 4, Player::Rank::Citizen);
  initSalaryString(mUi->cClerk, 5, Player::Rank::Clerk);
  initSalaryString(mUi->cEngineer, 6, Player::Rank::Engineer);
  initSalaryString(mUi->cArchitect, 7, Player::Rank::Architect);
  initSalaryString(mUi->cQuaestor, 8, Player::Rank::Quaestor);
  initSalaryString(mUi->cProcurator, 9, Player::Rank::Procurator);
  initSalaryString(mUi->cAedile, 10, Player::Rank::Aedile);
  initSalaryString(mUi->cPraetor, 11, Player::Rank::Praetor);
  initSalaryString(mUi->cConsul, 12, Player::Rank::Consul);
  initSalaryString(mUi->cProconsul, 13, Player::Rank::Proconsul);
  initSalaryString(mUi->cCaesar, 14, Player::Rank::Caesar);

  connect(mUi->cCancel, SIGNAL(clicked()), SLOT(reject()));
  connect(mUi->cCitizen, SIGNAL(clicked()), SLOT(handleCitizen()));
  connect(mUi->cClerk, SIGNAL(clicked()), SLOT(handleClerk()));
  connect(mUi->cEngineer, SIGNAL(clicked()), SLOT(handleEngineer()));
  connect(mUi->cArchitect, SIGNAL(clicked()), SLOT(handleArchitect()));
  connect(mUi->cQuaestor, SIGNAL(clicked()), SLOT(handleQuaestor()));
  connect(mUi->cProcurator, SIGNAL(clicked()), SLOT(handleProcurator()));
  connect(mUi->cAedile, SIGNAL(clicked()), SLOT(handleAedile()));
  connect(mUi->cPraetor, SIGNAL(clicked()), SLOT(handlePraetor()));
  connect(mUi->cConsul, SIGNAL(clicked()), SLOT(handleConsul()));
  connect(mUi->cProconsul, SIGNAL(clicked()), SLOT(handleProconsul()));
  connect(mUi->cCaesar, SIGNAL(clicked()), SLOT(handleCaesar()));

  setEnableWarning(false);

}

void SalaryDialog::initSalaryString(Label * label, int32_t textId, Player::Rank rank)
{
  const StringData * stringData = Application::language()->stringData();

  Font normalWhite(Font::Type::NormalWhite);
  Font normalRed(Font::Type::NormalRed);

  int32_t salary = Player::salaryForRank(rank);
  QString text = stringData->getString(52, textId);
  text += " " + QString::number(salary) + " ";
  text += stringData->getString(6, 0);

  int32_t textWidth = normalRed.calculateTextWidth(text);
  label->setTextFont(normalWhite);
  label->setHoverFont(normalRed);
  label->setEnableHover(true);
  label->resize(textWidth, 20);
  label->setText(text);
}

Player::Rank SalaryDialog::salaryRank() const
{
  return mSalaryRank;
}

void SalaryDialog::setEnableWarning(bool enable)
{
  const StringData * stringData = Application::language()->stringData();
  mUi->cMessage->setText(stringData->getString(52, 76));
  if (enable) {
    mUi->cMessage->setText(stringData->getString(52, 71));
  }
}
