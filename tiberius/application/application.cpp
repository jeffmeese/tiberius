#include "application.h"
#include "settings.h"

#include <QDir>

Application::Application(int argc, char ** argv)
  : TiberiusApplication(argc, argv)
{
}

Application::~Application()
{
}

Settings & Application::settings()
{
  static Settings settings("JaMSoft", "Tiberius");
  return settings;
}
