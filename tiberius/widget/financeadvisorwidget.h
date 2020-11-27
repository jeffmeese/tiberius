#ifndef FINANCEADVISORWIDGET_H
#define FINANCEADVISORWIDGET_H

#include "advisorwidget.h"

namespace Ui {
  class FinanceAdvisorWidget;
}

class FinanceAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit FinanceAdvisorWidget(QWidget *parent = nullptr);
  ~FinanceAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::FinanceAdvisorWidget *mUi;
};

#endif // FINANCEADVISORWIDGET_H
