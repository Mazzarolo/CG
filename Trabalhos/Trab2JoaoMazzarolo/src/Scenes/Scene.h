#ifndef SCENE_H
#define SCENE_H

#include "../Tools/Input.h"

class Scene : public Input
{
protected:
    int screenWidth, screenHeight, nextScene;

public:
    Scene(int screenWidth, int screenHeight);

    virtual ~Scene() {  };
    
    virtual void render() = 0;
    
    int getNextScene();

    void setNexScene(int nextScene);
};

#endif // SCENE_H
