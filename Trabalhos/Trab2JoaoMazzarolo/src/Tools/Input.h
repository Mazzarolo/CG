#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <functional>

using namespace std;

class Input
{
private:
    static int button, state, wheel, direction, mX, mY, keyUp, keyDown;
    static vector<function<void()>> keyUpListeners, keyDownListeners;

public:
    void setKeyUp(int key);

    void setKeyDown(int key);

    void setMouse(int button, int state, int wheel, int direction, int mX, int mY);

    void resetKeys();

protected:
    void addListeners(function<void()> keyUpListener, function<void()> keyDownListener);

    int getButton();

    int getState();

    int getWheel();

    int getDirection();

    int getMX();

    int getMY();

    int getKeyUp();

    int getKeyDown();
};

#endif  // INPUT_H
