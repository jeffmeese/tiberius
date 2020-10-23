#include "application/mainwindow.h"

#include <QApplication>

#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>

#include <algorithm>
#include <iomanip>
#include <sstream>

void readOffsetFile();

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();
  return application.exec();
}

void readOffsetFile()
{
  QString fileName("D:\\code\\development\\applications\\jcaesar\\source\\jcaesar\\offset.txt");
  QFile file(fileName);
  file.open(QIODevice::ReadOnly);

  std::ostringstream oss;
  std::ostringstream oss2;
  int index = 0;
  QTextStream textStream(&file);
  while (!textStream.atEnd()) {
    QString line = textStream.readLine();
    QStringList lineData = line.split("   ");
    QString offsetBitsString = lineData.at(0);
    QString reprString = lineData.at(1);
    std::reverse(reprString.begin(), reprString.end());
    int number = reprString.toShort(nullptr, 2);
    oss << std::setw(4) << number << ",";
    oss2 << reprString.length() << ", ";
    if (++index == 8) {
      oss << "\n";
      oss2 <<"\n";
      index = 0;
    }
  }

  qDebug().noquote() << QString::fromStdString(oss.str());
  qDebug().noquote() << QString::fromStdString(oss2.str());
}
