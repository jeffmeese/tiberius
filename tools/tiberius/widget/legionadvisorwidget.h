#ifndef LEGIONADVISORWIDGET_H
#define LEGIONADVISORWIDGET_H

#include "advisorwidget.h"

#include "widget/button.h"

#include <QLabel>

#include <memory>
#include <vector>

class City;
class Label;
class Legion;
namespace Ui {
  class LegionAdvisorWidget;
}

class LegionButton
    : public Button
{
public:
  LegionButton(QWidget * parentWidget = nullptr);

public:
  void setLegion(Legion * legion);

private:
  void init();

private:
  std::unique_ptr<QLabel> mIcon;
  std::unique_ptr<Label> mName;
  std::unique_ptr<Label> mSoliders;
  std::unique_ptr<Label> mMorale;
  std::unique_ptr<Button> mGotoLegion;
  std::unique_ptr<Button> mReturnToFort;
  std::unique_ptr<Button> mEmpireService;
};

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
  using LegionButtonPtr = std::unique_ptr<LegionButton>;
  using LegionButtonVector = std::vector<LegionButtonPtr>;

private:
  Ui::LegionAdvisorWidget *mUi;
  LegionButtonPtr mLegionButtons[6];
  Legion * mLegions[6];
};

#endif // LEGIONADVISORWIDGET_H
