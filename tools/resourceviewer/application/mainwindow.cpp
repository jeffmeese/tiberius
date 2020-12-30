#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "game/game.h"

#include "graphics/sgimagegroup.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"

#include "language/language.h"

#include "model/gameitem.h"
#include "model/graphicsitem.h"
#include "model/languageitem.h"
#include "model/mapitem.h"
#include "model/smkitem.h"

#include "properties/propertiesmodel.h"
#include "properties/property.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QLabel>

#include <sstream>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , mUi(new Ui::MainWindow)
  , mResourceModel(new QStandardItemModel)
{
  mUi->setupUi(this);

  initModel();
  connect(mUi->actionChoose_Directory, SIGNAL(triggered()), SLOT(handleChooseDirectory()));
  connect(mUi->actionExit, SIGNAL(triggered()), SLOT(handleExit()));
}

MainWindow::~MainWindow()
{
  delete mUi;
}

QWidget * MainWindow::createEmptyView()
{
  QFont font;
  font.setPointSize(12);

  QLabel * label = new QLabel;
  label->setAlignment(Qt::AlignCenter);
  label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  label->setText("There is no view associated with this item");
  label->setFont(font);

  return label;
}

void MainWindow::handleChooseDirectory()
{
  QString c3Dir = QFileDialog::getExistingDirectory(this, "Choose Caesar directory", QDir::currentPath());
  //QString c3Dir = "C:\\applications\\Impressions Games\\Caesar3";
  //QString c3Dir = "C:\\applications\\Caesar3\\SIERRA\\Caesar3";
  if (c3Dir.isEmpty()) {
    return;
  }

  QApplication::setOverrideCursor(Qt::WaitCursor);
  setEnabled(false);

  initModel();
  loadGraphicsFiles(c3Dir);
  loadLanguageFiles(c3Dir);
  loadMapFiles(c3Dir);
  //loadSmkFiles(c3Dir);
  //loadSavedGames(c3Dir);

  QApplication::restoreOverrideCursor();
  setEnabled(true);
}

void MainWindow::handleExit()
{
  QApplication::quit();
}

void MainWindow::handleItemChanged()
{
  mUi->cPropertiesView->setModel(nullptr);

  QModelIndexList indexList = mUi->cResourcesView->selectionModel()->selectedIndexes();
  if (indexList.size() != 1) {
    return;
  }

  mPropertiesModel.reset(new PropertiesModel);

  QWidget * currentWidget = mUi->scrollArea->widget();
  if (currentWidget != nullptr) {
    delete currentWidget;
    currentWidget = nullptr;
  }

  QModelIndex selectedIndex = indexList.at(0);
  QStandardItem * selectedItem = mResourceModel->itemFromIndex(selectedIndex);
  ResourceItem * resourceItem = dynamic_cast<ResourceItem*>(selectedItem);
  if (resourceItem != nullptr) {

    // Get the view associated with this item
    currentWidget = resourceItem->createView();

    // Get the properties associated with this item
    QList<Property> propertyList = resourceItem->getProperties();
    for (int32_t i = 0; i < propertyList.size(); i++) {
      mPropertiesModel->addProperty(propertyList.at(i));
    }
  }

  // If there is no view associated with the
  // current item create a default one
  if (currentWidget == nullptr) {
    currentWidget = createEmptyView();
  }

  mUi->scrollArea->setWidget(currentWidget);
  mUi->cPropertiesView->setModel(mPropertiesModel.get());
  mUi->cPropertiesView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::initModel()
{
  mResourceModel.reset(new QStandardItemModel);

  mGraphicsGroup = new QStandardItem("Graphics Files");
  mLanguagesGroup = new QStandardItem("Language Files");
  mVideosGroup = new QStandardItem("Video Files");
  mMapsGroup = new QStandardItem("Map Files");
  mSavedGamesGroup = new QStandardItem("Saved Games");

  mResourceModel->appendRow(mGraphicsGroup);
  mResourceModel->appendRow(mLanguagesGroup);
  mResourceModel->appendRow(mVideosGroup);
  mResourceModel->appendRow(mMapsGroup);
  mResourceModel->appendRow(mSavedGamesGroup);

  mUi->cResourcesView->setModel(mResourceModel.get());

  QItemSelectionModel * selModel = mUi->cResourcesView->selectionModel();
  connect(selModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), SLOT(handleItemChanged()));
}

void MainWindow::loadGraphicsFiles(const QString & dirName)
{
  QDir dir(dirName);

  QStringList nameFilters;
  nameFilters << "*.sg2";

  QStringList fileList = dir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString pathName(dirName + QDir::separator() + fileList.at(i));
    GraphicsItem * group = new GraphicsItem(pathName);
    mGraphicsGroup->appendRow(group);
  }
}

void MainWindow::loadLanguageFiles(const QString & dirName)
{
  QDir dir(dirName);

  QStringList nameFilters;
  nameFilters << "c3.eng";
  nameFilters << "c3.rus";

  QStringList fileList = dir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString pathName(dirName + QDir::separator() + fileList.at(i));
    LanguageItem * item = new LanguageItem(pathName);
    mLanguagesGroup->appendRow(item);
  }
}

void MainWindow::loadMapFiles(const QString &dirName)
{
  QDir dir(dirName);

  QStringList nameFilters;
  nameFilters << "*.map";

  QStringList fileList = dir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString pathName(dirName + QDir::separator() + fileList.at(i));
    MapItem * item = new MapItem(pathName);
    mMapsGroup->appendRow(item);
  }
}

void MainWindow::loadSavedGames(const QString &dirName)
{
  QStringList nameFilters;
  nameFilters << "*.sav";

  QDir dir(dirName);
  QStringList fileList = dir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString fileName = fileList.at(i);
    QString pathName = dirName + QDir::separator() + fileName;
    GameItem * item = new GameItem(pathName);
    mSavedGamesGroup->appendRow(item);
  }
}

void MainWindow::loadSmkFiles(const QString & dirName)
{
  QString smkDir(dirName + QDir::separator() + "smk");
  QStringList nameFilters;
  nameFilters << "*.smk";

  QDir dir(smkDir);
  QStringList fileList = dir.entryList(nameFilters, QDir::Files);
  for (int32_t i = 0; i < fileList.size(); i++) {
    QString pathName = fileList.at(i);
    SmkItem * item = new SmkItem(pathName);
    mVideosGroup->appendRow(item);
  }
}
