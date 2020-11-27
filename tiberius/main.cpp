#include "application/application.h"
#include "window/mainwindow.h"
#include "tinyfiledialogs/tinyfiledialogs.h"

#include <QDebug>
#include <QMessageBox>
#include <QSoundEffect>

#include "media/sound.h"
#include "media/sounds.h"
#include "media/sounddata.h"

int main(int argc, char *argv[])
{
  try {
    Application application(argc, argv);
    MainWindow mainWindow(application);
    mainWindow.show();
    return application.exec();
  }
  catch (std::invalid_argument & ex) {
    tinyfd_messageBox("Fatal Error", ex.what(), "ok", "error", 1);
    return -1;
  }
  catch (std::exception & ex) {
    tinyfd_messageBox("Fatal Error", ex.what(), "ok", "error", 1);
    return -1;
  }

  return 0;
}
