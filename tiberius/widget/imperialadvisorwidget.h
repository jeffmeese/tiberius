#ifndef IMPERIALADVISORWIDGET_H
#define IMPERIALADVISORWIDGET_H

#include "advisorwidget.h"

class ImperialData;
class Player;
class Request;
namespace Ui {
  class ImperialAdvisorWidget;
}

class ImperialAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit ImperialAdvisorWidget(QWidget *parent = nullptr);
  ~ImperialAdvisorWidget();

protected:
  void doUpdate() override;

private:
  QString createFavorString(ImperialData * imperialData) const;
  void createRequests(ImperialData * imperialData);
  QString createRankString(Player * player) const;
  QString createSalaryString(Player * player) const;
  QString createSavingsString(Player * player) const;
  void createRequestButton(Request * request, int32_t yOffset);
  void init();

private slots:
  void handleDonation();
  void handleGift();
  void handleSalary();

private:
  class RequestButton
      : public QObject
  {
  public:
    RequestButton(QWidget * parentWidget, Request * request, int yOffset);

  private:
    Request * mRequest;
  };

private:
  Ui::ImperialAdvisorWidget *mUi;
  std::vector<std::unique_ptr<RequestButton>> mRequestButtons;
};

#endif // IMPERIALADVISORWIDGET_H
