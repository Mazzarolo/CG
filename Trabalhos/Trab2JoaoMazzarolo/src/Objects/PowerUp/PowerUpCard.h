#ifndef POWER_UP_CARD_H
#define POWER_UP_CARD_H

#include "../../Lib/gl_canvas2d.h"
#include "../../UI/Button.h"

class PowerUpCard : public Button
{
private:
    char text[50];

public:
    PowerUpCard(int x, int y, char* text, function<void()> onClick);

    void render();

    void setPosition(int x, int y);
    void setPosition(int x);
};

#endif // POWER_UP_CARD_H