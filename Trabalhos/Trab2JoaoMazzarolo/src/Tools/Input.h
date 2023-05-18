#ifndef INPUT_H
#define INPUT_H

class Input
{
private:
    static int button, state, wheel, direction, mX, mY;
    static int keyUp, keyDown;

public:
    void setKeyUp(int key);

    void setKeyDown(int key);

    void setMouse(int button, int state, int wheel, int direction, int mX, int mY);

    void resetKeys();

protected:
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
