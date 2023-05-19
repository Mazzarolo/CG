#include "Input.h"

int Input::keyDown;
int Input::keyUp;
int Input::button;
int Input::state;
int Input::wheel;
int Input::direction;
int Input::mX;
int Input::mY;
vector<function<void()>> Input::keyUpListeners;
vector<function<void()>> Input::keyDownListeners;

void Input::setKeyUp(int key)
{
    keyUp = key;
    for (vector<function<void()>>::iterator func = keyUpListeners.begin(); func != keyUpListeners.end(); func++)
       	(*func)();
}

void Input::setKeyDown(int key)
{
    keyDown = key;
    for (vector<function<void()>>::iterator func = keyDownListeners.begin(); func != keyDownListeners.end(); func++)
       	(*func)();
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

void Input::addListeners(function<void()> keyUpListener, function<void()> keyDownListener)
{
    keyUpListeners.push_back(keyUpListener);
    keyDownListeners.push_back(keyDownListener);
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
