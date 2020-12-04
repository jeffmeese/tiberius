#ifndef RATINGSADVISORWIDGET_H
#define RATINGSADVISORWIDGET_H

#include "advisorwidget.h"

#include "widget/button.h"

#include <memory>

class Label;
namespace Ui {
  class RatingsAdvisorWidget;
}

class RatingsButton
    : public Button
{
public:
  RatingsButton(QWidget * parentWidget = nullptr);

public:
  void setTarget(int32_t target);
  void setTitle(const QString & title);
  void setValue(int32_t value);

private:
  void init();

private:
  std::unique_ptr<Label> mTitle;
  std::unique_ptr<Label> mValue;
  std::unique_ptr<Label> mTarget;
};

class RatingsAdvisorWidget
    : public AdvisorWidget
{
  Q_OBJECT

public:
  explicit RatingsAdvisorWidget(QWidget *parent = nullptr);
  ~RatingsAdvisorWidget();

protected:
  void doUpdate() override;

private:
  void init();

private slots:
  void handleClickCulture();
  void handleClickFavor();
  void handleClickPeace();
  void handleClickProsperity();

private:
  Ui::RatingsAdvisorWidget *mUi;
};

#endif // RATINGSADVISORWIDGET_H
