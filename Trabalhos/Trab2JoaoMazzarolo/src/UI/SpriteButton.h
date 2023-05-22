#ifndef SPRITEBUTTON_h
#define SPRITEBUTTON_h

#include <vector>
#include "Button.h"
#include "../Objects/Bitmap.h"

class SpriteButton : public Button
{ 
private:
    vector<Bitmap*> sprites;

public:
    SpriteButton(int x, int y, function<void()> onClick, vector<char*> pathToSprites);

    void render();
};

#endif // SPRITEBUTTON_h