#include "application.h"
#include "settings.h"

#include "tinyfiledialogs/tinyfiledialogs.h"

#include <QDir>

static const QString C3_DIR_SETTING("c3Dir");
static const QString ORG_NAME("JaMSoft");
static const QString APP_NAME("Tiberius");

Application::Application(int & argc, char ** argv)
  : TiberiusApplication(argc, argv)
{
  setOrganizationName(ORG_NAME);
  setApplicationName(APP_NAME);

  QString c3Dir = settings().value(C3_DIR_SETTING).toString();
  if (c3Dir.isEmpty()) {
    char title[] = {"Choose Caesar3 Directory"};
    const char * path = tinyfd_selectFolderDialog(title, QDir::currentPath().toStdString().c_str());
    if (path == nullptr) {
      throw std::invalid_argument("No Casear 3 directory specified");
    }
    c3Dir = path;
    settings().setValue(C3_DIR_SETTING, path);
  }
  setC3Dir(c3Dir);
}

Application::~Application()
{
}

Settings & Application::settings()
{
  static Settings settings(ORG_NAME, APP_NAME);
  return settings;
}
