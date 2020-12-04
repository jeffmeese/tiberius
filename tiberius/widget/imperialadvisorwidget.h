#ifndef IMPERIALADVISORWIDGET_H
#define IMPERIALADVISORWIDGET_H

#include "advisorwidget.h"

#include "widget/button.h"

#include <QLabel>

class Label;
class ImperialData;
class Player;
class Request;
namespace Ui {
  class ImperialAdvisorWidget;
}

class RequestButton
    : public Button
{
public:
  RequestButton(QWidget * parentWidget = nullptr);

public:
  void setAmountStored(int32_t value);
  void setRequest(Request * request);

private:
  int32_t mResourceStored;
  Request * mRequest;
  std::unique_ptr<Label> mAmount;
  std::unique_ptr<Label> mAmountStored;
  std::unique_ptr<Label> mResourceName;
  std::unique_ptr<QLabel> mResourceIcon;
  std::unique_ptr<Label> mAction;
  std::unique_ptr<Label> mMonths;
};

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
  void init();

private slots:
  void handleDispatch(Request * request, int32_t amountStored);
  void handleDispatch1();
  void handleDispatch2();
  void handleDispatch3();
  void handleDispatch4();
  void handleDispatch5();
  void handleDonation();
  void handleGift();
  void handleSalary();

private:
  using RequestButtonPtr = std::unique_ptr<RequestButton>;

private:
  Ui::ImperialAdvisorWidget *mUi;
  RequestButtonPtr mRequestButtons[5];
  Request * mRequests[5];
  int32_t mAmountStored[5];
};

#endif // IMPERIALADVISORWIDGET_H
