#ifndef SOUNDOPTIONSDIALOG_H
#define SOUNDOPTIONSDIALOG_H

#include "dialog/dialog.h"

class Button;
class Font;
class Label;
namespace Ui {
  class SoundOptionsDialog;
}

class SoundOptionsDialog
    : public Dialog
{
  Q_OBJECT

public:
  TIBERIUS_LIB_DECL explicit SoundOptionsDialog(QWidget *parent = nullptr);
  TIBERIUS_LIB_DECL ~SoundOptionsDialog();

public:
  TIBERIUS_LIB_DECL bool citySoundsOn() const;
  TIBERIUS_LIB_DECL int citySoundsVolume() const;
  TIBERIUS_LIB_DECL bool musicOn() const;
  TIBERIUS_LIB_DECL int musicVolume() const;
  TIBERIUS_LIB_DECL bool soundEffectsOn() const;
  TIBERIUS_LIB_DECL int soundEffectsVolume() const;
  TIBERIUS_LIB_DECL bool speechOn() const;
  TIBERIUS_LIB_DECL int speechVolume() const;
  TIBERIUS_LIB_DECL void setCitySoundsOn(bool value);
  TIBERIUS_LIB_DECL void setCitySoundsVolume(int value);
  TIBERIUS_LIB_DECL void setMusicOn(bool value);
  TIBERIUS_LIB_DECL void setMusicVolume(int value);
  TIBERIUS_LIB_DECL void setSoundEffectsOn(bool value);
  TIBERIUS_LIB_DECL void setSoundEffectsVolume(int value);
  TIBERIUS_LIB_DECL void setSpeechOn(bool value);
  TIBERIUS_LIB_DECL void setSpeechVolume(int value);

private slots:
  void handleCity();
  void handleCityDown();
  void handleCityUp();
  void handleMusic();
  void handleMusicDown();
  void handleMusicUp();
  void handleSounds();
  void handleSoundsDown();
  void handleSoundsUp();
  void handleSpeech();
  void handleSpeechDown();
  void handleSpeechUp();

private:
  void initButton(Button * button, const Font & font, const QString & text);
  void initUi();
  void updateData();

signals:
  void changed();

private:
  Ui::SoundOptionsDialog * mUi;
  bool mCitySoundsOn;
  bool mMusicOn;
  bool mSoundEffectsOn;
  bool mSpeechOn;
  int mCityVolume;
  int mMusicVolume;
  int mSoundEffectsVolume;
  int mSpeechVolume;
};

#endif // SOUNDOPTIONSDIALOG_H
