#ifndef RELIGIONADVISORWIDGET_H
#define RELIGIONADVISORWIDGET_H

#include "advisorwidget.h"

#include "religion/god.h"

class Label;
namespace Ui {
  class ReligionAdvisorWidget;
}

class ReligionAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit ReligionAdvisorWidget(QWidget *parent = nullptr);
  ~ReligionAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();
  void initGodRow(Label * label, God::Type type);

private:
  Ui::ReligionAdvisorWidget *mUi;
};

#endif // RELIGIONADVISORWIDGET_H
