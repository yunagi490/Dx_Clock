#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

class GuiButton {
public:
  GuiButton(int x, int y, int w, int h, const char* label);
  void Draw(int textColor, int bgColor, int borderColor, bool hover = false) const;
  bool isClicked() const;
  void SetLabel(const char* newLabel);

private:
  int x, y, w, h;
  char label[64];
};

#endif
