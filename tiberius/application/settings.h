#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

#include "game/difficulty.h"
#include "graphics/resolution.h"

class Settings
    : public QSettings
{
public:
  enum MouseHelp
  {
    None = 0,
    Some = 1,
    All = 2
  };

public:
  Settings(const QString & orgName, const QString & appName);

public:
  bool citySoundsEnabled() const;
  int32_t citySoundsVolume() const;
  const Difficulty & difficulty() const;
  Difficulty & difficulty();
  bool fullscreen();
  int32_t gameSpeed() const;
  bool godEffectsEnabled() const;
  bool monthlyAutosaveEnabled() const;
  bool musicEnabled() const;
  int32_t musicVolume() const;
  bool soundEffectsEnabled() const;
  int32_t soundEffectsVolume() const;
  bool speechSoundsEnabled() const;
  int32_t speechSoundsVolume() const;
  bool warningsEnabled() const;
  Settings::MouseHelp mouseHelp();
  int32_t scrollSpeed();
  ScreenResolution screenResolution();
  void setCitySoundsEnabled(bool value);
  void setCitySoundsVolume(int32_t volume);
  void setDifficulty(const Difficulty & value);
  void setFullscreen(bool value);
  void setGameSpeed(int32_t value);
  void setGodEffectsEnabled(bool value);
  void setMonthlyAutosaveEnabled(bool value);
  void setMouseHelp(Settings::MouseHelp value);
  void setMusicEnabled(bool value);
  void setMusicVolume(int32_t value);
  void setScrollSpeed(int32_t value);
  void setScreenResolution(ScreenResolution value);
  void setSoundEffectsEnabled(bool value);
  void setSoundEffectsVolume(int32_t value);
  void setSpeechSoundsEnabled(bool value);
  void setSpeechSoundsVolume(int32_t value);
  void setWarningsEnabled(bool value);

private:
  template <typename T> void initSetting(const QString & key, const T & value);

private:
  Difficulty mDifficulty;
};

#endif // SETTINGS_H
