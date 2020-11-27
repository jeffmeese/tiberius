#include "lineedit.h"

#include "application/tiberiusapplication.h"

#include "core/painter.h"

#include "graphics/imagegroups.h"
#include "graphics/sgimagedata.h"
#include "graphics/sgimagerecord.h"
#include "graphics/stitchedimage.h"

#include <QDebug>
#include <QImage>
#include <QKeyEvent>
#include <QPainter>

LineEdit::LineEdit(QWidget * parentWidget)
  : QLineEdit(parentWidget)
  , mCursorVisible(true)
{
  setFocusPolicy(Qt::StrongFocus);
  mTimer.setInterval(300);
  mTimer.start();

  connect(&mTimer, SIGNAL(timeout()), SLOT(updateCursor()));
}

void LineEdit::addCharacter(const QString &newText)
{
  QString text = this->text();
  if (text.length() < maxLength()) {
    text.insert(cursorPosition(), newText);
    setCursorPosition(cursorPosition() + 1);
    setText(text);
  }
}

void LineEdit::drawBackground(Painter & painter)
{
  const SgImageData * imageData = TiberiusApplication::climateImages();
  uint32_t baseImageId = imageData->getGroupBaseImageId(GROUP_SUNKEN_TEXTBOX_BACKGROUND);

  int32_t w = width();
  int32_t h = height();
  StitchedImage image(16, 16, 7, 7, baseImageId);
  painter.drawImage(0, 0, image.constructImage(w, h));
}

void LineEdit::drawCursor(Painter & painter)
{
  if (!hasFocus())
    return;

  if (!mCursorVisible)
    return;

  QBrush brush(Qt::white);
  painter.setBrush(brush);

  Font f = textFont();
  QString txt = text().mid(0, cursorPosition());
  int xOffset = f.spaceWidth();
  if (!txt.isEmpty()) {
    std::string s = txt.toStdString();
    xOffset += f.calculateTextWidth(s);
  }
  painter.drawRect(xOffset, height()-3, f.spaceWidth(), 4);
}

void LineEdit::drawText(Painter & painter)
{
  QString textString = text();
  if (textString.isEmpty())
    return;

  std::string s = textString.toStdString();

  Font f = textFont();
  int32_t maxHeight = -1;
  for (std::size_t i = 0; i < s.size(); i++) {
    char c = s.at(i);
    int32_t letterHeight = f.calculateLetterHeight(c);
    if (letterHeight > maxHeight) {
      maxHeight = letterHeight;
    }
  }

  int32_t xOffset = f.spaceWidth();
  int32_t yOffset = (height()-(f.lineHeight()+2)) / 2;
  painter.drawText(xOffset, yOffset, textString, f);
}

void LineEdit::handleDelete()
{
  QString text = this->text();
  if (text.length() > 0 && cursorPosition() != text.length()) {
    text.remove(cursorPosition(), 1);
    setCursorPosition(cursorPosition()-1);
    setText(text);
  }
}

void LineEdit::handleBackspace()
{
  QString text = this->text();
  if (text.length() > 0 && cursorPosition() != 0) {
    text.remove(cursorPosition()-1, 1);
    setCursorPosition(cursorPosition()-1);
    setText(text);
  }
}

void LineEdit::keyPressEvent(QKeyEvent * e)
{
  QString text = this->text();

  switch (e->key()) {
    case Qt::Key_Backspace:
      handleBackspace();
      break;
    case Qt::Key_Left:
    case Qt::Key_Up:
      moveCursorLeft();
      break;
    case Qt::Key_Right:
    case Qt::Key_Down:
      moveCursorRight();
      break;
    case Qt::Key_Delete:
      handleDelete();
      break;
    case Qt::Key_Home:
      moveCursorHome();
      break;
    case Qt::Key_End:
      moveCursorEnd();
      break;
    case Qt::Key_A:
    case Qt::Key_B:
    case Qt::Key_C:
    case Qt::Key_D:
    case Qt::Key_E:
    case Qt::Key_F:
    case Qt::Key_G:
    case Qt::Key_H:
    case Qt::Key_I:
    case Qt::Key_J:
    case Qt::Key_K:
    case Qt::Key_L:
    case Qt::Key_M:
    case Qt::Key_N:
    case Qt::Key_O:
    case Qt::Key_P:
    case Qt::Key_Q:
    case Qt::Key_R:
    case Qt::Key_S:
    case Qt::Key_T:
    case Qt::Key_U:
    case Qt::Key_V:
    case Qt::Key_W:
    case Qt::Key_X:
    case Qt::Key_Y:
    case Qt::Key_Z:
    case Qt::Key_0:
    case Qt::Key_1:
    case Qt::Key_2:
    case Qt::Key_3:
    case Qt::Key_4:
    case Qt::Key_5:
    case Qt::Key_6:
    case Qt::Key_7:
    case Qt::Key_8:
    case Qt::Key_9:
    case Qt::Key_Space:
    case Qt::Key_Minus:
    case Qt::Key_Underscore:
      addCharacter(e->text());
      break;
  }
  update();
}

void LineEdit::moveCursorEnd()
{
  QString s(text());
  if (s.length() > 0) {
    setCursorPosition(s.length());
    update();
  }
}

void LineEdit::moveCursorHome()
{
  setCursorPosition(0);
  update();
}

void LineEdit::moveCursorLeft()
{
  if (cursorPosition() > 0) {
    setCursorPosition(cursorPosition()-1);
    update();
  }
}

void LineEdit::moveCursorRight()
{
  if (cursorPosition() < text().length()) {
    setCursorPosition(cursorPosition()+1);
    update();
  }
}

void LineEdit::paintEvent(QPaintEvent *)
{
  Painter painter(this);
  drawBackground(painter);
  drawText(painter);
  drawCursor(painter);
}

void LineEdit::removeCharacter()
{
}

void LineEdit::updateCursor()
{
  mCursorVisible = !mCursorVisible;
  update();
}
