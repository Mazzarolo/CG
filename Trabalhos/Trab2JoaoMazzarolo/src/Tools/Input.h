#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <functional>

using namespace std;

class Input
{
private:
    static int button, state, wheel, direction, mX, mY, keyUp, keyDown;
    static vector<function<void()>> keyUpListeners, keyDownListeners, mouseListeners;

public:
    Input();

    void setKeyUp(int key);

    void setKeyDown(int key);

    void setMouse(int button, int state, int wheel, int direction, int mX, int mY);

    void resetKeys();

protected:
    virtual void onKeyboardDown() { };

    virtual void onKeyboardUp() { };

    virtual void onMouse() { };

    int getButton();

    int getState();

    int getWheel();

    int getDirection();

    int getMX();

    int getMY();

    int getKeyUp();

    int getKeyDown();

private:
    void addKeyboardListeners(function<void()> keyUpListener, function<void()> keyDownListener, function<void()> mouseListener);

};

#endif  // INPUT_H
