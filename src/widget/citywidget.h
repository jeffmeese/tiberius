#ifndef CITYWIDGET_H
#define CITYWIDGET_H

#include <QWidget>

#include <QPaintEvent>
#include <QWidget>

#include "tiberius.h"

class Game;

class CityWidget
    : public QWidget
{
public:
  TIBERIUS_LIB_DECL explicit CityWidget(QWidget * parentWidget = nullptr);

protected:
  void paintEvent(QPaintEvent *event) override;

//public:
//  TIBERIUS_LIB_DECL Game * game();
//  TIBERIUS_LIB_DECL const Game * game() const;
//  TIBERIUS_LIB_DECL void setGame(Game * game);

//public slots:
//  TIBERIUS_LIB_DECL void cancelConstruction();
//  TIBERIUS_LIB_DECL void orientNorth();
//  TIBERIUS_LIB_DECL void rotateRight();
//  TIBERIUS_LIB_DECL void rotateLeft();
//  TIBERIUS_LIB_DECL void showAcademyOverlay();
//  TIBERIUS_LIB_DECL void showAmpitheaterOverlay();
//  TIBERIUS_LIB_DECL void showBarberOverlay();
//  TIBERIUS_LIB_DECL void showBathsOverlay();
//  TIBERIUS_LIB_DECL void showClinicOverlay();
//  TIBERIUS_LIB_DECL void showColoseumOverlay();
//  TIBERIUS_LIB_DECL void showCrimeOverlay();
//  TIBERIUS_LIB_DECL void showDamageOverlay();
//  TIBERIUS_LIB_DECL void showDesirabilityOverlay();
//  TIBERIUS_LIB_DECL void showEducationOverlay();
//  TIBERIUS_LIB_DECL void showEntertainmentOverlay();
//  TIBERIUS_LIB_DECL void showFireOverlay();
//  TIBERIUS_LIB_DECL void showFoodOverlay();
//  TIBERIUS_LIB_DECL void showHippodromeOverlay();
//  TIBERIUS_LIB_DECL void showHospitalOverlay();
//  TIBERIUS_LIB_DECL void showLibraryOverlay();
//  TIBERIUS_LIB_DECL void showNativeOverlay();
//  TIBERIUS_LIB_DECL void showNormalOverlay();
//  TIBERIUS_LIB_DECL void showProblemsOverlay();
//  TIBERIUS_LIB_DECL void showReligionOverlay();
//  TIBERIUS_LIB_DECL void showSchoolOverlay();
//  TIBERIUS_LIB_DECL void showTaxOverlay();
//  TIBERIUS_LIB_DECL void showTheaterOverlay();
//  TIBERIUS_LIB_DECL void showWaterOverlay();

//protected:
//  void paintEvent(QPaintEvent *event) override;
//  void resizeEvent(QResizeEvent *event) override;

//private:
//  void drawTerrain(QPainter & painter);

//private:
//  Game * mGame;
//  int32_t mHeight;
//  int32_t mHeightTiles;
//  int32_t mWidth;
//  int32_t mWidthTiles;
//  std::vector<std::vector<int>> mViewToGrid;
};

#endif // CITYWIDGET_H
