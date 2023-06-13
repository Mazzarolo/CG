// Classe que representa um botão com sprites

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
    // Construtor
    SpriteButton(int x, int y, function<void()> onClick, vector<char*> pathToSprites);

    // Destrutor
    ~SpriteButton();

    // Renderiza o botão
    void render();
};

#endif // SPRITEBUTTON_h