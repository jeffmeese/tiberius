#include "settings.h"

#include "game/difficulty.h"

template <typename T>
void Settings::initSetting(const QString & key, const T & value)
{
  if (!contains(key)) {
    setValue(key, value);
  }
}

Settings::Settings(const QString & orgName, const QString & appName)
  : QSettings(QSettings::UserScope, orgName, appName)
{
  initSetting("fullscreen", true);
  initSetting("godEffects", true);
  initSetting("citySounds", true);
  initSetting("music", true);
  initSetting("soundEffects", true);
  initSetting("speechSounds", true);
  initSetting("warnings", true);
  initSetting("monthlyAutosaveEnabled", true);
  initSetting("musicVolume", 100);
  initSetting("soundEffectsVolume", 100);
  initSetting("citySoundsVolume", 100);
  initSetting("speechSoundsVolume", 100);
  initSetting("scrollSpeed", 70);
  initSetting("gameSpeed", 70);
  initSetting("mouseHelp", Settings::All);
  initSetting("difficulty", static_cast<int>(Difficulty::Type::Normal));
  initSetting("screenResolution", ScreenResolution::Resolution1024x768);
}

bool Settings::citySoundsEnabled() const
{
  return value("citySoundsEnabled").toBool();
}

int32_t Settings::citySoundsVolume() const
{
  return value("citySoundsVolume").toInt();
}

Difficulty & Settings::difficulty()
{
  return mDifficulty;
}

const Difficulty & Settings::difficulty() const
{
  return mDifficulty;
}

bool Settings::fullscreen()
{
  return value("fullscreen").toBool();
}

int32_t Settings::gameSpeed() const
{
  return value("gameSpeed").toInt();
}

bool Settings::godEffectsEnabled() const
{
  return value("godEffects").toBool();
}

bool Settings::monthlyAutosaveEnabled() const
{
  return value("monthlyAutosaveEnabled").toBool();
}

Settings::MouseHelp Settings::mouseHelp()
{
  return Settings::MouseHelp(value("mouseHelp").toInt());
}

bool Settings::musicEnabled() const
{
  return value("musicEnabled").toBool();
}

int32_t Settings::musicVolume() const
{
  return value("musicVolume").toInt();
}

void Settings::setMouseHelp(Settings::MouseHelp value)
{
  setValue("mouseHelp", value);
}

int32_t Settings::scrollSpeed()
{
  return value("scrollSpeed").toInt();
}

ScreenResolution Settings::screenResolution()
{
  return ScreenResolution(value("screenResolution").toInt());
}

void Settings::setCitySoundsEnabled(bool value)
{
  setValue("citySoundsEnabled", value);
}

void Settings::setCitySoundsVolume(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("citySoundsVolume", value);
}

void Settings::setDifficulty(const Difficulty &value)
{
  mDifficulty = value;
}

void Settings::setFullscreen(bool value)
{
  setValue("fullscreen", value);
}

void Settings::setGameSpeed(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("gameSpeed", value);
}

void Settings::setGodEffectsEnabled(bool value)
{
  setValue("godEffects", value);
}

void Settings::setMonthlyAutosaveEnabled(bool value)
{
  setValue("monthlyAutosaveEnabled", value);
}

void Settings::setMusicEnabled(bool value)
{
  setValue("musicEnabled", value);
}

void Settings::setMusicVolume(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("musicVolume", value);
}

void Settings::setScrollSpeed(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("scrollSpeed", value);
}

void Settings::setScreenResolution(ScreenResolution value)
{
  setValue("screenResolution", value);
}

void Settings::setSoundEffectsEnabled(bool value)
{
  setValue("soundEffectsEnabled", value);
}

void Settings::setSoundEffectsVolume(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("soundEffectsVolume", value);
}

void Settings::setSpeechSoundsEnabled(bool value)
{
  setValue("setSpeechSoundsEnabled", value);
}

void Settings::setSpeechSoundsVolume(int32_t value)
{
  if (value < 0 || value > 100) {
    return;
  }

  setValue("speechSoundsVolume", value);
}

void Settings::setWarningsEnabled(bool value)
{
  setValue("warnings", value);
}

bool Settings::soundEffectsEnabled() const
{
  return value("soundEffectsEnabled").toBool();
}

int32_t Settings::soundEffectsVolume() const
{
  return value("soundEffectsVolume").toInt();
}

bool Settings::speechSoundsEnabled() const
{
  return value("speechSoundsEnabled").toBool();
}

int32_t Settings::speechSoundsVolume() const
{
  return value("speechSoundsVolume").toInt();
}

bool Settings::warningsEnabled() const
{
  return value("warnings").toBool();
}
