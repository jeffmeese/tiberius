#ifndef POPULATIONADVISORWIDGET_H
#define POPULATIONADVISORWIDGET_H

#include "advisorwidget.h"

class Label;
namespace Ui {
  class PopulationAdvisorWidget;
}

class PopulationAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit PopulationAdvisorWidget(QWidget *parent = nullptr);
  ~PopulationAdvisorWidget();

protected:
  void doUpdate() override;

private:
  enum class GraphType
  {
    Census = 0,
    History = 1,
    Society = 2
  };

private:
  void init();
  void setGraphLabel(Label * label, GraphType graphType, bool small);
  void setTitle(Label * label, GraphType graphType);
  void updateImmigrantString();

private:
  Ui::PopulationAdvisorWidget *mUi;
  GraphType mBottomGraphType;
  GraphType mMainGraphType;
  GraphType mTopGraphType;
};

#endif // POPULATIONADVISORWIDGET_H
