#include "smkwidget.h"
#include "ui_smkwidget.h"

#include "media/video.h"

SmkWidget::SmkWidget(Video * video, QWidget *parent)
  : QWidget(parent)
  , mUi(new Ui::SmkWidget)
  , mVideo(video)
{
  mUi->setupUi(this);
  connect(mUi->cPlayPause, SIGNAL(clicked()), SLOT(handlePlayButton()));
  connect(mUi->cStop, SIGNAL(clicked()), SLOT(handleStopButton()));
}

SmkWidget::~SmkWidget()
{

}

void SmkWidget::handlePlayButton()
{
  mVideo->play(mUi->cVideoWidget);
}

void SmkWidget::handleStopButton()
{
  mVideo->stop();
}
