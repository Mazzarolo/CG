#ifndef SCENE_H
#define SCENE_H

#include "../Tools/Input.h"

class Scene : public Input
{
protected:
    int screenWidth, screenHeight;

public:
    Scene(int screenWidth, int screenHeight);

    virtual void render() = 0;
};

#endif // SCENE_H
