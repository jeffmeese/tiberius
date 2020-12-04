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
  explicit SoundOptionsDialog(QWidget *parent = nullptr);
  ~SoundOptionsDialog();

public:
  bool citySoundsOn() const;
  int citySoundsVolume() const;
  bool musicOn() const;
  int musicVolume() const;
  bool soundEffectsOn() const;
  int soundEffectsVolume() const;
  bool speechOn() const;
  int speechVolume() const;
  void setCitySoundsOn(bool value);
  void setCitySoundsVolume(int value);
  void setMusicOn(bool value);
  void setMusicVolume(int value);
  void setSoundEffectsOn(bool value);
  void setSoundEffectsVolume(int value);
  void setSpeechOn(bool value);
  void setSpeechVolume(int value);

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
