#ifndef LEGIONADVISORWIDGET_H
#define LEGIONADVISORWIDGET_H

#include "advisorwidget.h"

class City;
namespace Ui {
  class LegionAdvisorWidget;
}

class LegionAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit LegionAdvisorWidget(QWidget *parent = nullptr);
  ~LegionAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private:
  Ui::LegionAdvisorWidget *mUi;
};

#endif // LEGIONADVISORWIDGET_H
