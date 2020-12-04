#ifndef DISPLAYOPTIONSDIALOG_H
#define DISPLAYOPTIONSDIALOG_H

#include "dialog/dialog.h"
#include "graphics/resolution.h"

class Application;
class Button;
class Font;
namespace Ui
{
  class DisplayOptionsDialog;
}

class DisplayOptionsDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit DisplayOptionsDialog(QWidget *parent = nullptr);
  ~DisplayOptionsDialog();

public:
  bool fullscreen() const;
  ScreenResolution resolution() const;
  void setFullscreen(bool value);
  void setScreenResolution(ScreenResolution value);

private slots:
  void handleFullscreen();
  void handle640x480();
  void handle800x600();
  void handle1024x768();

private:
  void initButton(Button * button, const Font & font);
  void initUi();
  void updateData();

signals:
  void applyFullScreen(bool value);
  void changeResolution(ScreenResolution resolution);
  void changed();

private:
  Ui::DisplayOptionsDialog * mUi;
  bool mFullscreen;
  ScreenResolution mScreenResolution;
};

#endif // DISPLAYOPTIONSDIALOG_H
