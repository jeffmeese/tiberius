#include "application/application.h"
#include "application/mainwindow.h"

#include <stdexcept>

int main(int argc, char *argv[])
{
  try {
    Application application(argc, argv);
    MainWindow mainWindow(application);
    mainWindow.show();
    return application.exec();
  }
  catch (std::invalid_argument & ex) {
    return -1;
  }
  catch (std::exception & ex) {
    return -1;
  }

  return 0;
}
