#include "application/application.h"
#include "application/mainwindow.h"

#include <QDebug>

#include <stdexcept>

int main(int argc, char *argv[])
{
  uint8_t v = 13;
  qDebug() << QString::number(v, 2);

  for (int i = 0; i < 256; i++) {
    qDebug() << (i << 1);
    //uint16_t val = (uint16_t)(i << 1);
    //qDebug() << (uint16_t)(i << 1);
  }

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
