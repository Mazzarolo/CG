#ifndef BUTTON_H
#define BUTTON_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Input.h"
#include <functional>

using namespace std;

class Button : public Input
{
protected:
    int x, y, width, height;
    function<void()> onClick;
    bool selected, clicked;

protected:
    Button(int x, int y, int width, int height, function<void()> onClick);
    Button(int x, int y, function<void()> onClick);

    virtual void render() = 0;

    bool checkCollision();

    void onMouse();

};

#endif // BUTTON_H