#ifndef FESTIVALDIALOG_H
#define FESTIVALDIALOG_H

#include "dialog/dialog.h"

#include "entertainment/festival.h"

#include "religion/god.h"

#include "widget/button.h"
#include "widget/label.h"

#include <memory>

namespace Ui {
  class FestivalDialog;
}

class GodButton
    : public Button
{
public:
  GodButton(QWidget * parentWidget = nullptr);

public:
  void setSelected(bool value);

protected:
  void paintEvent(QPaintEvent * event);

private:
  bool mSelected;
};

class FestivalButton
    : public Button
{
public:
  FestivalButton(QWidget * parentWidget = nullptr);

public:
  int32_t cost() const;
  int32_t wine() const;
  void setCost(int32_t value);
  void setType(const QString & text);
  void setWineRequired(int32_t value);

private:
  void recalcLayout();

private:
  int32_t mCost;
  int32_t mWine;
  std::unique_ptr<Label> mType;
  std::unique_ptr<Label> mCostLabel;
  std::unique_ptr<Label> mWineLabel;
  std::unique_ptr<QLabel> mWineImage;
};

class FestivalDialog
    : public Dialog
{
  Q_OBJECT

public:
  explicit FestivalDialog(QWidget *parent = nullptr);
  ~FestivalDialog();

public:
  Festival::Type festivalType() const;
  int32_t festivalCost() const;
  int32_t festivalWine() const;
  God::Type selectedGod() const;
  void setSelectedGod(God::Type type);

private:
  void init();

private slots:
  void handleCeres();
  void handleGrandFestival();
  void handleLargeFestival();
  void handleMars();
  void handleMercury();
  void handleNeptune();
  void handleSmallFestival();
  void handleVenus();

private:
  Ui::FestivalDialog * mUi;
  int32_t mFestivalCost;
  Festival::Type mFestivalType;
  int32_t mFestivalWine;
  God::Type mSelectedGod;
};

#endif // FESTIVALDIALOG_H
