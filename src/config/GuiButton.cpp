#include "GuiButton.h"
#include <cstring>
#include "DxLib.h"
using namespace std;

GuiButton::GuiButton(int x, int y, int w, int h, const char *label)
{
  x = x_;
  y = y_;
  w = w_;
  h = h_;

  strncpy(label, label_, sizeof(label) - 1);
  label[sizeof(label) - 1] = '\0';
}

void GuiButton::setLabel(const char *newlabel)
{
  strncpy(label, newlabel, sizeof(label) - 1);
  label[sizeof(label) - 1] = '\0';
}

void GuiButton::Draw(int textColor, int bgColor, int borderColor, bool hover) const
{
  DrawBox(x, y, x + w, y + h, borderColor, TRUE);
  DrawBox(x + 2, y + 2, x + w - 2, y + h - 2, hover ? GetColor(200, 200, 200) : bgColor, TRUE);
  DrawString(x + 10, y + 5, label, textColor);
}

bool GuiButton::isClicked() const
{
  int mouseX, mouseY;
  GetMousePoint(mouseX >>= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h && (GetMouseInput() & MOUSE_INPUT_LEFT));
}
