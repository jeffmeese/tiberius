#ifndef SPEEDOPTIONSDIALOG_H
#define SPEEDOPTIONSDIALOG_H

#include "dialog/dialog.h"

class Button;
class Font;
namespace Ui {
  class SpeedOptionsDialog;
}

class SpeedOptionsDialog : public Dialog
{
  Q_OBJECT

public:
  explicit SpeedOptionsDialog(QWidget *parent = nullptr);
  ~SpeedOptionsDialog();

public:
  int gameSpeed() const;
  int scrollSpeed() const;
  void setGameSpeed(int value);
  void setScrollSpeed(int value);

private:
  void initButton(Button *button, const Font &font, const QString &text);
  void initUi();
  void updateData();

private slots:
  void handleDecreaseGameSpeed();
  void handleDecreaseScrollSpeed();
  void handleIncreaseGameSpeed();
  void handleIncreaseScrollSpeed();

signals:
  void changed();

private:
  Ui::SpeedOptionsDialog * mUi;
  int mGameSpeed;
  int mScrollSpeed;
};

#endif // SPEEDOPTIONSDIALOG_H
