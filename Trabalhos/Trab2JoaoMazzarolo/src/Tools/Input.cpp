#include "Input.h"

int Input::keyDown;
int Input::keyUp;
int Input::button;
int Input::state;
int Input::wheel;
int Input::direction;
int Input::mX;
int Input::mY;

void Input::setKeyUp(int key)
{
    keyUp = key;
}

void Input::setKeyDown(int key)
{
    keyDown = key;
}

void Input::setMouse(int button, int state, int wheel, int direction, int mX, int mY)
{
    this->button = button;
    this->state = state;
    this->wheel = wheel;
    this->direction = direction;
    this->mX = mX;
    this->mY = mY;
}

void Input::resetKeys()
{
    keyUp = -1;
    keyDown = -1;
}

int Input::getButton()
{
    return button;
}

int Input::getState()
{
    return state;
}

int Input::getWheel()
{
    return wheel;
}

int Input::getDirection()
{
    return direction;
}

int Input::getMX()
{
    return mX;
}

int Input::getMY()
{
    return mY;
}

int Input::getKeyUp()
{
    return keyUp;
}

int Input::getKeyDown()
{
    return keyDown;
}
