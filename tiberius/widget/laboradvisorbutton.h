#ifndef LABORADVISORBUTTON_H
#define LABORADVISORBUTTON_H

#include "widget/borderedbutton.h"

#include <QLabel>

class Label;

class LaborAdvisorButton
    : public BorderedButton
{
public:
  LaborAdvisorButton(QWidget * parentWidget = nullptr);

public:
  void setHave(int value);
  void setNeed(int value);
  void setPriority(int level);
  void setSector(const QString & text);

private:
  void init();

private:
  std::unique_ptr<QLabel> mLock;
  std::unique_ptr<Label> mPriority;
  std::unique_ptr<Label> mSector;
  std::unique_ptr<Label> mHave;
  std::unique_ptr<Label> mNeed;
};

#endif // LABORADVISORBUTTON_H
