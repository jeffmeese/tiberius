#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "application/tiberiusapplication.h"

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
#include <QProgressDialog>

#include <sstream>

MainWindow::MainWindow(TiberiusApplication & application, QWidget *parent)
  : QMainWindow(parent)
  , mUi(new Ui::MainWindow)
  , mApplication(application)
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
  if (c3Dir.isEmpty()) {
    return;
  }

  QApplication::setOverrideCursor(Qt::WaitCursor);
  initModel();
  mApplication.setC3Dir(c3Dir);
  QApplication::restoreOverrideCursor();

  QProgressDialog dialog("Reading directory", "Cancel", 0, 100, this);
  dialog.setWindowTitle("Reading Caesar 3 Data");
  dialog.setWindowModality(Qt::WindowModal);
  dialog.setMinimumDuration(4);
  dialog.setValue(0);

  QDir dir(c3Dir);
  QDir videoDir(c3Dir + QDir::separator() + "smk");
  QDir soundDir(c3Dir + QDir::separator() + "wavs");
  QStringList graphicsFiles = dir.entryList(QStringList("*.sg2"), QDir::Files);
  QStringList languageFiles = dir.entryList(QStringList("c3.eng"), QDir::Files);
  QStringList scenarioFiles = dir.entryList(QStringList("*.map"), QDir::Files);
  QStringList videoFiles = videoDir.entryList(QStringList("*.smk"), QDir::Files);
  QStringList soundFiles = soundDir.entryList(QStringList("*.wav"), QDir::Files);

  int totalFiles = graphicsFiles.size() + languageFiles.size() + scenarioFiles.size() + videoFiles.size() + soundFiles.size();
  dialog.setMaximum(totalFiles);

  dialog.setLabelText("Reading Graphics Files");
  int filesProcessed = 0;
  for (int i = 0; i < graphicsFiles.size(); i++) {
    QString pathName(c3Dir + QDir::separator() + graphicsFiles.at(i));
    GraphicsItem * group = new GraphicsItem(pathName);
    mGraphicsGroup->appendRow(group);
    dialog.setValue(++filesProcessed);
  }

  dialog.setLabelText("Reading Language Files");
  for (int i = 0; i < languageFiles.size(); i++) {
    QString pathName(c3Dir + QDir::separator() + languageFiles.at(i));
    LanguageItem * item = new LanguageItem(pathName);
    mLanguagesGroup->appendRow(item);
    dialog.setValue(++filesProcessed);
  }

  dialog.setLabelText("Reading Scenario Files");
  for (int32_t i = 0; i < scenarioFiles.size(); i++) {
    QString pathName(c3Dir + QDir::separator() + scenarioFiles.at(i));
    MapItem * item = new MapItem(pathName);
    mMapsGroup->appendRow(item);
    dialog.setValue(++filesProcessed);
  }

  dialog.setLabelText("Reading Video Files");
  for (int32_t i = 0; i < videoFiles.size(); i++) {
    QString pathName(videoDir.path() + QDir::separator() + videoFiles.at(i));
    SmkItem * item = new SmkItem(pathName);
    mVideosGroup->appendRow(item);
    dialog.setValue(++filesProcessed);
  }

  dialog.setLabelText("Reading Sound Files");
  for (int32_t i = 0; i < soundFiles.size(); i++) {
    QString pathName(soundDir.path() + QDir::separator() + soundFiles.at(i));
    QFileInfo fileInfo(pathName);
    QStandardItem * item = new QStandardItem(fileInfo.fileName());
    mSoundsGroup->appendRow(item);
    dialog.setValue(++filesProcessed);
  }



//  dialog.setLabelText("Reading Saved Game Files");
//  for (int32_t i = 0; i < savedGameFiles.size(); i++) {
//    QString fileName = savedGameFiles.at(i);
//    QString pathName = c3Dir + QDir::separator() + fileName;
//    std::unique_ptr<Game> game(new Game);
//    GameItem * item = new GameItem(std::move(game), pathName);
//    mSavedGamesGroup->appendRow(item);
//    dialog.setValue(++filesProcessed);
//  }
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
  mMapsGroup = new QStandardItem("Map Files");
  mSoundsGroup = new QStandardItem("Sound Files");
  mVideosGroup = new QStandardItem("Video Files");
  //mSavedGamesGroup = new QStandardItem("Saved Games");

  mResourceModel->appendRow(mGraphicsGroup);
  mResourceModel->appendRow(mLanguagesGroup);
  mResourceModel->appendRow(mMapsGroup);
  mResourceModel->appendRow(mVideosGroup);
  mResourceModel->appendRow(mSoundsGroup);
  //mResourceModel->appendRow(mSavedGamesGroup);

  mUi->cResourcesView->setModel(mResourceModel.get());

  QItemSelectionModel * selModel = mUi->cResourcesView->selectionModel();
  connect(selModel, SIGNAL(selectionChanged(QItemSelection, QItemSelection)), SLOT(handleItemChanged()));
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
