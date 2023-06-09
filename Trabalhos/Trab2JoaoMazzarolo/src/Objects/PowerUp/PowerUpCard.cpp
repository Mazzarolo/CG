#include "PowerUpCard.h"

PowerUpCard::PowerUpCard(int x, int y, char* text, function<void()> onClick) : Button(x, y, 300, 500, onClick)
{
    strcpy(this->text, text);
}

void PowerUpCard::render()
{
    CV::color(0, 0, 0);
    CV::rectFill(x - 5, y - 5, x + width + 5, y + height + 5);

    if(x < 400)
    {
        if(checkCollision())
            CV::color(0.5, 0, 0);
        else
            CV::color(1, 0, 0);
    }
    else
    {
        if(checkCollision())
            CV::color(0, 0, 0.5);
        else
            CV::color(0, 0, 1);
    }

    CV::rectFill(x, y, x + width, y + height);

    CV::color(1, 1, 1);
    CV::text(x + 10, y + 10, text);
}

void PowerUpCard::setPosition(int x, int y)
{
    x = x;
    y = y;
}
