#include "Button.h"

Button::Button(int x, int y, int width, int height, function<void()> onClick)
{
    clicked = selected = false;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->onClick = onClick;
}

Button::Button(int x, int y, function<void()> onClick)
{
    clicked = selected = false;
    this->x = x;
    this->y = y;
    this->onClick = onClick;
}

bool Button::checkCollision()
{
    int mouseX = getMX();
    int mouseY = getMY();

    if(mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        return true;
    }
    return false;
}

void Button::onMouse()
{
    int state = getState();

    if(checkCollision())
    {
        selected = true;

        if(state == 0)
        {
            clicked = true;
        }

        if(clicked && state == 1)
        {
            clicked = false;
            selected = false;
            onClick();
        }
    }
    else
    {
        selected = false;
        if((state = 1) || (state == 0))
        {
            clicked = false;
        }
    }
}
