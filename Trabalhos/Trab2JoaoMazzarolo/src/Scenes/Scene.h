#ifndef SCENE_H
#define SCENE_H

#include "../Tools/Input.h"
#include "../Tools/Clock.h"

class Scene : public Input, public Clock
{
protected:
    int screenWidth, screenHeight, nextScene;

public:
    Scene(int screenWidth, int screenHeight);

    virtual ~Scene() {  };
    
    virtual void render() = 0;
    
    int getNextScene();

    virtual void reset() { };

    virtual void setNextScene(int nextScene);
};

#endif // SCENE_H
