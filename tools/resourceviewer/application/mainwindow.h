#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>

class TiberiusApplication;
class PropertiesModel;

namespace Ui
{
  class MainWindow;
}

class MainWindow
    : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(TiberiusApplication & application, QWidget *parent = nullptr);
  ~MainWindow();

private:
  QWidget * createEmptyView();
  void initModel();


private slots:
  void handleChooseDirectory();
  void handleExit();
  void handleItemChanged();

private:
  Ui::MainWindow * mUi;
  TiberiusApplication & mApplication;
  std::unique_ptr<QStandardItemModel> mResourceModel;
  std::unique_ptr<PropertiesModel> mPropertiesModel;
  QStandardItem * mGraphicsGroup;
  QStandardItem * mLanguagesGroup;
  QStandardItem * mMapsGroup;
  QStandardItem * mSavedGamesGroup;
  QStandardItem * mVideosGroup;
  QStandardItem * mSoundsGroup;
};
#endif // MAINWINDOW_H
