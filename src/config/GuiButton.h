class GuiButton
{
public:
    GuiButton(int x, int y, int w, int h, const char* label);
    void Draw(bool highlighted = false) const;
    bool isClicked() const;
    void setLabel(const char* newlabel);

private:
    int x, y, w, h;
    char* label[64];
};


