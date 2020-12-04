#ifndef TRADEADVISORWIDGET_H
#define TRADEADVISORWIDGET_H

#include "advisorwidget.h"

#include "widget/label.h"

#include <memory>

#include <QLabel>

class Resource;
namespace Ui {
  class TradeAdvisorWidget;
}

class TradeAdvisorWidgetRow
    : public QWidget
{
  Q_OBJECT

public:
  TradeAdvisorWidgetRow(QWidget * parentWidget = nullptr);

public:
  void setResource(const Resource * resource);

protected:
  void enterEvent(QEvent * event) override;
  void leaveEvent(QEvent * event) override;
  void mouseReleaseEvent(QMouseEvent * event) override;
  void paintEvent(QPaintEvent * event) override;

signals:
  void clicked();

private:
  bool mFocused;
  std::unique_ptr<Label> mName;
  std::unique_ptr<Label> mAmount;
  std::unique_ptr<Label> mIndustryOff;
  std::unique_ptr<Label> mTradeStatus;
  const Resource * mResource;
};

class TradeAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit TradeAdvisorWidget(QWidget *parent = nullptr);
  ~TradeAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private slots:
  void handleClick1();
  void handleClick2();
  void handleClick3();
  void handleClick4();
  void handleClick5();
  void handleClick6();
  void handleClick7();
  void handleClick8();
  void handleClick9();
  void handleClick10();
  void handleClick11();
  void handleClick12();
  void handleClick13();
  void handleClick14();
  void handleClick15();
  void handleShowPrices();

private:
  void showResourceDialog(Resource * resource);

private:
  using RowPtr = std::unique_ptr<TradeAdvisorWidgetRow>;

private:
  Ui::TradeAdvisorWidget *mUi;
  RowPtr mRows[15];
  Resource * mResources[15];
  QLabel * mLeftIcons[15];
  QLabel * mRightIcons[15];
};

#endif // TRADEADVISORWIDGET_H
