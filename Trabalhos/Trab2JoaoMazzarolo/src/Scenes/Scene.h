#ifndef SCENE_H
#define SCENE_H

class Scene
{
protected:
    int screenWidth, screenHeight;

public:
    Scene() = delete;

    virtual void render() = 0;
};

#endif // SCENE_H
