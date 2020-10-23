#include "missiondialog.h"
#include "ui_missiondialog.h"

#include "application/application.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/messagedata.h"
#include "language/stringdata.h"

#include "widget/scrollbar.h"
#include "widget/textedit.h"

MissionDialog::MissionDialog(QWidget *parent)
  : Dialog(parent)
  , mUi(new Ui::MissionDialog)
{
  init();
}

MissionDialog::~MissionDialog()
{
}

void MissionDialog::setMission(int missionNumber)
{
  const MessageData * messageData = TiberiusApplication::language()->messageData();
  const Message * message = messageData->getMessage(200);
  mUi->cMessage->insertText("Hello");
  //mUi->cMessage->setMessage(message);
}

void MissionDialog::init()
{
  mUi->setupUi(this);

  mUi->cMessage->setTextFont(Font::Type::NormalWhite);
  mUi->cMessage->insertText("Hello");

  //mUi->cMessage->setViewport(new TextEdit);
  //mUi->cMessage->setVerticalScrollBar(new ScrollBar);
  const StringData * stringData = Application::language()->stringData();
  const SgImageData * imageData = Application::climateImages();
  uint32_t sidebarButtonId = imageData->getGroupBaseImageId(GROUP_SIDEBAR_BUTTONS);

  //mUi->cMessage->setTextFont(Font::Type::NormalWhite);
  mUi->cObjectives->setTextFont(Font::Type::NormalWhite);

  mUi->cName->setTextFont(Font::Type::LargeBlack);
  mUi->cCityLabel->setTextFont(Font::Type::NormalBlack);
  mUi->cCityLabel->setText(stringData->getString(62, 7));
  mUi->cObjectives->setTextFont(Font::Type::NormalBlack);
  mUi->cObjectives->setText(stringData->getString(62, 10));
  mUi->cContinue->setImage(imageData->getImageRecord(sidebarButtonId+57)->createImage());
  mUi->cContinue->setPressedImage(imageData->getImageRecord(sidebarButtonId+58)->createImage());
  mUi->cContinue->setHoverImage(imageData->getImageRecord(sidebarButtonId+59)->createImage());

  connect(mUi->cContinue, SIGNAL(clicked()), SLOT(accept()));
}
