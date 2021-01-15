#include "application/mainwindow.h"
#include "application/tiberiusapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  //QApplication application(argc, argv);
  TiberiusApplication application(argc, argv);
  MainWindow mainWindow(application);
  mainWindow.show();
  return application.exec();
}

