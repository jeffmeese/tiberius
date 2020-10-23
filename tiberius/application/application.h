#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "application/tiberiusapplication.h"
#include "settings.h"

class Application
    : public TiberiusApplication
{
public:
  Application(int argc, char ** argv);
  ~Application();

public:
  static Settings & settings();

private:
};

#endif // APPLICATION_H
