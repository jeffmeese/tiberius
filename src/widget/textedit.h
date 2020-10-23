#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "tiberius.h"
#include "scrollwidget.h"

#include <vector>

class TextEdit
    : public ScrollWidget
{
public:
  TIBERIUS_LIB_DECL explicit TextEdit(QWidget * parentWidget = nullptr);

public:
  TIBERIUS_LIB_DECL void insertImage(const QImage & image);
  TIBERIUS_LIB_DECL void insertText(const QString & text);

private:
  class Viewport
      : public QWidget
      , public TiberiusWidget
  {
    friend class TextEdit;

  public:
    Viewport(QWidget * parent = nullptr);

  protected:
    void paintEvent(QPaintEvent *) override;

  private:
    std::vector<QChar> mText;
    std::vector<QImage> mImages;
  };

private:
  Viewport * mViewport;
};

#endif // TEXTEDIT_H
