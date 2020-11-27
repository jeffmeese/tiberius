#ifndef TRADEADVISORWIDGET_H
#define TRADEADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class TradeAdvisorWidget;
}

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

private:
  Ui::TradeAdvisorWidget *mUi;
};

#endif // TRADEADVISORWIDGET_H
