#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QMediaPlayer>
#include <memory>

class Button;
namespace Ui
{
  class MenuWindow;
}

class MenuWindow
    : public QWidget
{
  Q_OBJECT

public:
  explicit MenuWindow(QWidget *parent = nullptr);
  ~MenuWindow();

protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private slots:
  void handleExit();
  void handleLoadGame();
  void handleNewCareer();
  void handleOptions();

private:
  void init();
  void initButton(Button * button, const QString & text);

signals:
  void loadGame(const QString & fileName);
  void startNewCareer(const QString & playerName);

private:
  std::unique_ptr<Ui::MenuWindow> mUi;
  QMediaPlayer mPlayer;
};

//class MenuWindow
//    : public QWidget
//{
//  Q_OBJECT

//public:
//  explicit MenuWindow(QWidget *parent = nullptr);
//  ~MenuWindow();

//protected:
//  void paintEvent(QPaintEvent *event) override;
//  void resizeEvent(QResizeEvent *event) override;

//private:
//  void init();
//  void initButton(Button * button, const QString & text);
//  void showButtons(bool show);

//private slots:
//  void handleCityConstruction();
//  void handleExit();
//  void handleLoadGame();
//  void handleOptions();
//  void handleStartCareer();

//signals:
//  void startCareer(const QString & playerName);
//  void loadGame(const QString & fileName);

//private:
//  std::unique_ptr<Ui::MenuWindow> mUi;
//};

#endif // MENUWINDOW_H
