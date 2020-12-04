#ifndef FINANCEADVISORWIDGET_H
#define FINANCEADVISORWIDGET_H

#include "advisorwidget.h"

#include "graphics/font.h"

class Label;
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
  void setLabelText(Label * label, const QString & text, Font font, int32_t height);

private slots:
  void handleDecreaseTaxes();
  void handleIncreaseTaxes();

private:
  Ui::FinanceAdvisorWidget *mUi;
};

#endif // FINANCEADVISORWIDGET_H
