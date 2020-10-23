#include "filedialog.h"
#include "ui_filedialog.h"

#include "application/tiberiusapplication.h"

#include "graphics/imagedata.h"
#include "graphics/imagegroups.h"
#include "graphics/imageset.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"
#include "language/stringdata.h"

#include "widget/label.h"
#include "widget/listwidget.h"
#include "widget/textedit.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QThread>

#include <cmath>

FileDialog::FileDialog(QWidget * parentWidget)
  : Dialog(parentWidget)
  , mUi(new Ui::FileDialog)
{
  init();
  setType(LoadGame);
  updateData();
}

FileDialog::~FileDialog()
{
}

QString FileDialog::fileName() const
{
  return mFileName;
}

QString FileDialog::getTitleString()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  QString titleString = stringData->getString(43, 1);
  if (mType == SaveGame || mType == SaveMap) {
    titleString = stringData->getString(43, 0);
  }
  else if (mType == DeleteGame || mType == DeleteMap) {
    titleString = stringData->getString(43, 6);
  }

  return titleString;
}

void FileDialog::handleCancel()
{
  reject();
}

void FileDialog::handleItemChanged(QListWidgetItem * currentItem, QListWidgetItem * )
{
  if (currentItem != nullptr) {
    mUi->cFileName->setText(currentItem->text());
    mUi->cFileName->setFocus();
  }
}

void FileDialog::handleOk()
{
  QString c3Dir = TiberiusApplication::c3Dir();
  QString fileTitle = mUi->cFileName->text().trimmed();
  if (fileTitle.isEmpty()) {
    return;
  }

  QString fileName = c3Dir + QDir::separator() + fileTitle + mExtension;
  if (mType == LoadGame || mType == LoadMap || mType == DeleteGame) {
    QFile file(fileName);
    if (!file.exists()) {
      warnFileExistence();
      return;
    }
  }

  if (mType == SaveGame || mType == SaveMap) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
      qDebug() << "Could open file " << fileName << " for writing";
      return;
    }
  }

  accept();
}

void FileDialog::handleScroll(int value)
{
  mUi->cFileList->setFirstVisibleItem(value);
  mUi->cFileList->viewport()->update();
}

void FileDialog::init()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();
  const SgImageData * imageData = TiberiusApplication::climateImages();

  mUi->setupUi(this);

  mUi->cTitle->setTextFont(Font::Type::LargeBlack);
  mUi->cTitle->setText(getTitleString());
  mUi->cFileName->setText(stringData->getString(9, 6));
  mUi->cProceedLabel->setTextFont(Font::Type::NormalBlack);
  mUi->cProceedLabel->setText(stringData->getString(43, 5));
  mUi->cFileName->setTextFont(Font::Type::NormalWhite);

  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_OK_CANCEL_SCROLL_BUTTONS);
  mUi->cOkButton->setImage(imageData->getImageRecord(baseImageId)->createImage());
  mUi->cOkButton->setPressedImage(imageData->getImageRecord(baseImageId+2)->createImage());
  mUi->cOkButton->setHoverImage(imageData->getImageRecord(baseImageId+1)->createImage());
  mUi->cOkButton->setDisabledImage(imageData->getImageRecord(baseImageId+3)->createImage());
  mUi->cCancelButton->setImage(imageData->getImageRecord(baseImageId+4)->createImage());
  mUi->cCancelButton->setPressedImage(imageData->getImageRecord(baseImageId+6)->createImage());
  mUi->cCancelButton->setHoverImage(imageData->getImageRecord(baseImageId+5)->createImage());

  connect(mUi->cScrollBar, SIGNAL(valueChanged(int)), SLOT(handleScroll(int)));
  connect(mUi->cCancelButton, SIGNAL(clicked()), SLOT(handleCancel()));
  connect(mUi->cOkButton, SIGNAL(clicked()), SLOT(handleOk()));
  connect(&mFileWarnTimer, SIGNAL(timeout()), SLOT(resetFileWarning()));
  connect(mUi->cFileName, SIGNAL(textChanged(const QString &)), SLOT(updateData()));
  connect(mUi->cFileList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
          SLOT(handleItemChanged(QListWidgetItem*,QListWidgetItem*)));
}

void FileDialog::loadFiles()
{
  QString c3Dir = TiberiusApplication::c3Dir();
  QStringList nameFilters;
  nameFilters << QString("*" + mExtension);

  mUi->cFileList->clear();
  QDir dir(c3Dir);
  QStringList fileList = dir.entryList(nameFilters);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString fileName = fileList.at(i);
    QFileInfo fileInfo(fileName);
    QString name = fileInfo.baseName();
    QListWidgetItem * item = new QListWidgetItem(name);
    mUi->cFileList->addItem(item);
  }

  int count = fileList.size();
  mUi->cScrollBar->hide();
  if (count > mUi->cFileList->totalVisibleItems()) {
    count -= mUi->cFileList->totalVisibleItems();
    mUi->cScrollBar->show();
    mUi->cScrollBar->setMinimum(0);
    mUi->cScrollBar->setMaximum(count-1);
    mUi->cScrollBar->setStepSize(1);
  }
}

void FileDialog::resetFileWarning()
{
  mFileWarnTimer.stop();
  mUi->cTitle->setText(getTitleString());
  update();
}

void FileDialog::setFileName(const QString & fileName)
{
  mUi->cFileName->setText(fileName);
}

void FileDialog::setType(Type type)
{
  mType = type;
  mUi->cTitle->setText(getTitleString());
  mExtension = ".sav";
  if (mType == SaveMap || mType == DeleteMap || mType == LoadMap)
    mExtension = ".map";

  loadFiles();
}

void FileDialog::showEvent(QShowEvent *)
{
  mUi->cFileName->setFocus();
}

void FileDialog::updateData()
{
  QString fileName = mUi->cFileName->text().trimmed();
  bool enableOk = true;
  if (fileName.isEmpty()) {
    enableOk = false;
  }

  mFileName = fileName + mExtension;
  mUi->cOkButton->setEnabled(enableOk);
}

void FileDialog::updateScrollBar()
{
//  int firstItem = mUi->cFileList->firstVisibleItem();
//  int maxItemsToScroll = mUi->cFileList->count() - mUi->cFileList->totalVisibleItems();
//  if (maxItemsToScroll > 0) {
//    int scrollHeight = mUi->cFileList->height() - mUi->cScrollUpButton->height() - mUi->cScrollDownButton->height() - mUi->cSlider->height() - 4;
//    float pixelsPerScroll = static_cast<float>(scrollHeight) / maxItemsToScroll;
//    int pixelOffset = static_cast<int>(firstItem * pixelsPerScroll);

//    QRect listRect(mUi->cFileList->rect());
//    QPoint topRight = mUi->cFileList->mapToParent(listRect.topRight());
//    mUi->cSlider->move(topRight.x()+8, topRight.y() + mUi->cScrollUpButton->height() + pixelOffset + 2);
//  }
}

void FileDialog::warnFileExistence()
{
  const StringData * stringData = TiberiusApplication::language()->stringData();

  mUi->cTitle->setText(stringData->getString(43, 2));
  update();

  mFileWarnTimer.start(1000);
}
