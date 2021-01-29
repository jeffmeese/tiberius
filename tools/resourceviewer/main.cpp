#include "application/mainwindow.h"
#include "application/tiberiusapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  TiberiusApplication application(argc, argv);
  application.setOrganizationName("JaMSoft");
  application.setApplicationName("ResourceViewer");

  MainWindow mainWindow(application);
  mainWindow.show();
  return application.exec();
}

