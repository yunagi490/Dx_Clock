#define _CRT_SECURE_NO_WARNINGS
#include "01_GuiButton.h"
#include <cstring>
#include "DxLib.h"
using namespace std;

GuiButton::GuiButton(int x_, int y_, int w_, int h_, const char* label_) {
  x = x_;
  y = y_;
  w = w_;
  h = h_;
  strncpy(label, label_, sizeof(label) - 1);
  label[sizeof(label) - 1] = '\0';
}

void GuiButton::SetLabel(const char* newLabel) {
  strncpy(label, newLabel, sizeof(label) - 1);
  label[sizeof(label) - 1] = '\0';
}

void GuiButton::Draw(int textColor, int bgColor, int borderColor, bool hover) const {
  DrawBox(x, y, x + w, y + h, borderColor, TRUE);
  DrawBox(x + 2, y + 2, x + w - 2, y + h - 2, hover ? GetColor(200, 200, 200) : bgColor, TRUE);
  DrawString(x + 10, y + 5, label, textColor);
}

bool GuiButton::isClicked() const {
  int mouseX, mouseY;
  GetMousePoint(&mouseX, &mouseY);
  return (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h &&
          (GetMouseInput() & MOUSE_INPUT_LEFT));
}
